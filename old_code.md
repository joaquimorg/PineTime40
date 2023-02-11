
#include <math.h>

#include <lvgl.h>
#include <pinetime40.h>
#include "pinetime_board.h"
#include "ui.h"
#include "ui_events.h"

//#include <Wire.h>
#include <bluefruit.h>
//#include <Adafruit_LittleFS.h>
#include <InternalFileSystem.h>
//#include "flash/flash_nrf5x.h"


//using namespace Adafruit_LittleFS_Namespace;

//#define MAX_LEVEL 2


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define COMMAND_BASE 0x00
#define COMMAND_TIME_UPDATE COMMAND_BASE + 0x01
#define COMMAND_NOTIFICATION COMMAND_BASE + 0x02
#define COMMAND_DELETE_NOTIFICATION COMMAND_BASE + 0x03
#define COMMAND_SET_ALARMS COMMAND_BASE + 0x04
#define COMMAND_SET_CALL COMMAND_BASE + 0x05
#define COMMAND_SET_MUSIC COMMAND_BASE + 0x06
#define COMMAND_SET_MUSIC_INFO COMMAND_BASE + 0x07
#define COMMAND_ACTIVITY_STATUS COMMAND_BASE + 0x08
#define COMMAND_FIND_DEVICE COMMAND_BASE + 0x09
#define COMMAND_VIBRATION COMMAND_BASE + 0x0a
#define COMMAND_WEATHER COMMAND_BASE + 0x0b

#define COMMAND_PT_VERSION COMMAND_BASE + 0x01
#define COMMAND_PT_BATTERY COMMAND_BASE + 0x02
#define COMMAND_PT_STEPS COMMAND_BASE + 0x03
#define COMMAND_PT_HEARTRATE COMMAND_BASE + 0x04


int packFloat(void *buf, float x) {
  unsigned char *b = (unsigned char *)buf;
  unsigned char *p = (unsigned char *)&x;
  b[0] = p[3];
  b[1] = p[2];
  b[2] = p[1];
  b[3] = p[0];
  return 4;
}

int packInt(void *buf, int x) {
  unsigned char *b = (unsigned char *)buf;
  unsigned char *p = (unsigned char *)&x;
  b[0] = p[3];
  b[1] = p[2];
  b[2] = p[1];
  b[3] = p[0];
  return 4;
}

int packByte(void *buf, uint8_t x) {
  unsigned char *b = (unsigned char *)buf;
  unsigned char *p = (unsigned char *)&x;
  b[0] = p[0];
  return 1;
}

void send_data_ble(const uint8_t *content, size_t len) {
  bleuart.write(content, len);
}

void ble_send_version(void) {
  uint8_t data[4] = {
    0x00,
    COMMAND_PT_VERSION,
    0x00,
    0x01
  };
  send_data_ble(data, 4);
}

float round_to_dp(float in_value, int decimal_place) {
  float multiplier = powf(10.0f, decimal_place);
  in_value = roundf(in_value * multiplier) / multiplier;
  return in_value;
}

void ble_send_battery(void) {

  uint8_t data[11] = {};
  uint8_t status = 0;


  //status = 0x01; // Error
  //status = 0x02;  // charging
  status = 0x03;  // normal

  if (is_charging) {
    status = 0x02;
  }


  uint8_t i = 0;
  data[i++] = 0x00;
  data[i++] = COMMAND_PT_BATTERY;

  i += packInt(&data[i], vbat_per);
  i += packFloat(&data[i], round_to_dp((vbat_mv / 1000), 3));
  i += packByte(&data[i], status);

  send_data_ble(data, i);
}

static uint32_t get_int() {
  return bleuart.read8() << 24 | bleuart.read8() << 16 | bleuart.read8() << 8 | bleuart.read8();
}

static uint8_t get_byte() {
  return bleuart.read8();
}

void decode_message(uint8_t msgType, int16_t msgSize) {
  switch (msgType) {
    case COMMAND_TIME_UPDATE:
      if (msgSize == 4) {
        rtctime.set_time(get_int());
        old_min = 99;
        //backlight.restore_dim();
      }
      
      bleuart.flush();
      Serial.println(">>BL MSG : COMMAND_TIME_UPDATE");
      ble_send_battery();
      //ble_send_version();
      break;

    case COMMAND_NOTIFICATION:
      Serial.println(">>BL MSG : COMMAND_NOTIFICATION");
      break;

    case COMMAND_DELETE_NOTIFICATION:
      Serial.println(">>BL MSG : COMMAND_DELETE_NOTIFICATION");
      break;

    case COMMAND_WEATHER:
      Serial.println(">>BL MSG : COMMAND_WEATHER");
      break;

    case COMMAND_FIND_DEVICE:
      Serial.println(">>BL MSG : COMMAND_FIND_DEVICE");
      break;

    case COMMAND_VIBRATION:
      Serial.println(">>BL MSG : COMMAND_VIBRATION");
      break;

    default:
      Serial.println(">>BL MSG : unknown");
      break;
  }
}

uint16_t countrx = 0;
uint8_t inputEnd = 1;

int16_t msgSize = 0;
uint8_t msgType = 0;

// Invoked when receiving data from bleuart
void bleuart_rx_callback(uint16_t conn_hdl) {
  (void)conn_hdl;

  if (inputEnd == 1 && bleuart.read8() == COMMAND_BASE) {
    inputEnd = 0;
    msgType = bleuart.read8();
    msgSize = bleuart.read16();
  }

  if (bleuart.available() >= msgSize && inputEnd == 0) {

    decode_message(msgType, msgSize);

    bleuart.flush();
    inputEnd = 1;
    msgSize = 0;
    msgType = 0;
  }
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// callback invoked when central connects
void connect_callback(uint16_t conn_handle) {
  // Get the reference to current connection
  BLEConnection *connection = Bluefruit.Connection(conn_handle);

  char central_name[32] = { 0 };
  connection->getPeerName(central_name, sizeof(central_name));

  Serial.print(">>BL Connected to ");
  Serial.println(central_name);

  // request PHY changed to 2MB
  Serial.println(">>BL Request to change PHY");
  connection->requestPHY();

  // request to update data length
  Serial.println(">>BL Request to change Data Length");
  connection->requestDataLengthUpdate();

  // request mtu exchange
  //Serial.println(">>BL Request to change MTU");
  //connection->requestMtuExchange(247);


  delay(1000);
}

// Callback invoked when a connection is dropped
void disconnect_callback(uint16_t conn_handle, uint8_t reason) {
  (void)conn_handle;
  (void)reason;

  Serial.println();
  Serial.printf(">>BL Disconnected, reason = 0x%02X (%s)", reason, dbg_hci_str(reason));
  Serial.println();
}


void connection_secured_callback(uint16_t conn_handle) {
  BLEConnection *conn = Bluefruit.Connection(conn_handle);

  if (!conn->secured()) {
    // It is possible that connection is still not secured by this time.
    // This happens (central only) when we try to encrypt connection using stored bond keys
    // but peer reject it (probably it remove its stored key).
    // Therefore we will request an pairing again --> callback again when encrypted
    conn->requestPairing();
  } else {
    Serial.println(">>BL Secured");
  }
}

void startAdv(void) {
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  // Include bleuart 128-bit uuid
  Bluefruit.Advertising.addService(bleuart);

  // Secondary Scan Response packet (optional)
  // Since there is no room for 'Name' in Advertising packet
  Bluefruit.ScanResponse.addName();

  //* Start Advertising
  //   * - Enable auto advertising if disconnected
  //   * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
  //   * - Timeout for fast mode is 30 seconds
  //   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
  //   *
  //   * For recommended advertising interval
  //   * https://developer.apple.com/library/content/qa/qa1931/_index.html

  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);  // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);    // number of seconds in fast mode
  Bluefruit.Advertising.start(0);              // 0 = Don't stop advertising after n seconds
}

// Static PIN is 6 digits from 000000-999999
#define PAIRING_PIN "123456"

void bl_init() {
  // -------------------------------------------------

  Bluefruit.begin();
  Bluefruit.setName("Pinetime Arduino");
  Bluefruit.setAppearance(BLE_APPEARANCE_GENERIC_WATCH);
  Bluefruit.setTxPower(4);  // Check bluefruit.h for supported values
  Bluefruit.Periph.setConnectCallback(connect_callback);
  Bluefruit.Periph.setDisconnectCallback(disconnect_callback);

  //Serial.println(">>BL Setting pairing PIN to: " PAIRING_PIN);
  //Bluefruit.Security.setPIN(PAIRING_PIN);
  // Set connection secured callback, invoked when connection is encrypted
  //Bluefruit.Security.setSecuredCallback(connection_secured_callback);

  // To be consistent OTA DFU should be added first if it exists
  //bledfu.begin();

  // Configure and Start Device Information Service
  bledis.setManufacturer("joaquim.org");
  bledis.setModel("Pinetime");
  bledis.begin();

  // Configure and Start BLE Uart Service
  bleuart.setRxCallback(bleuart_rx_callback, true);
  bleuart.bufferTXD(false);
  // Set Permission to access BLE Uart is to require man-in-the-middle protection
  // This will cause central to perform pairing with static PIN we set above
  bleuart.setPermission(SECMODE_ENC_WITH_MITM, SECMODE_ENC_WITH_MITM);
  bleuart.begin();

  // Start BLE Battery Service
  //blebas.begin();
  //blebas.write(100);

  // Set up and start advertising
  startAdv();
}

// ---------------------------------------------------------------------------------------------------------------------------------

/**************************************************************************/
/*!
    @brief  Print out whole directory tree of an folder
            until the level reach MAX_LEVEL

    @note   Recursive call
*/
/**************************************************************************/

void printTreeDirInt(const char *cwd, uint8_t level) {
  // Open the input folder
  Adafruit_LittleFS_Namespace::File dir(cwd, Adafruit_LittleFS_Namespace::FILE_O_READ, InternalFS);

  // Print root
  if (level == 0) Serial.println("root");

  // File within folder
  Adafruit_LittleFS_Namespace::File item(InternalFS);

  // Loop through the directory
  while ((item = dir.openNextFile(Adafruit_LittleFS_Namespace::FILE_O_READ))) {
    // Indentation according to dir level
    for (int i = 0; i < level; i++) Serial.print("|  ");

    Serial.print("|_ ");
    Serial.print(item.name());

    if (item.isDirectory()) {
      Serial.println("/");

      // ATTENTION recursive call to print sub folder with level+1 !!!!!!!!
      // High number of MAX_LEVEL can cause memory overflow
      if (level < MAX_LEVEL) {
        char dpath[strlen(cwd) + strlen(item.name()) + 2];
        strcpy(dpath, cwd);
        strcat(dpath, "/");
        strcat(dpath, item.name());

        printTreeDirInt(dpath, level + 1);
      }
    } else {
      // Print file size starting from position 30
      int pos = level * 3 + 3 + strlen(item.name());

      // Print padding
      for (int i = pos; i < 30; i++) Serial.print(' ');

      // Print at least one extra space in case current position > 50
      Serial.print(' ');

      Serial.print(item.size());
      Serial.println(" Bytes");
    }

    item.close();
  }

  dir.close();
}


void printTreeDir(const char *cwd, uint8_t level) {
  // Open the input folder
  Adafruit_LittleFS_Namespace::File dir(cwd, Adafruit_LittleFS_Namespace::FILE_O_READ, ExternalFS);

  // Print root
  if (level == 0) Serial.println("root");

  // File within folder
  Adafruit_LittleFS_Namespace::File item(ExternalFS);

  // Loop through the directory
  while ((item = dir.openNextFile(Adafruit_LittleFS_Namespace::FILE_O_READ))) {
    // Indentation according to dir level
    for (int i = 0; i < level; i++) Serial.print("|  ");

    Serial.print("|_ ");
    Serial.print(item.name());

    if (item.isDirectory()) {
      Serial.println("/");

      // ATTENTION recursive call to print sub folder with level+1 !!!!!!!!
      // High number of MAX_LEVEL can cause memory overflow
      if (level < MAX_LEVEL) {
        char dpath[strlen(cwd) + strlen(item.name()) + 2];
        strcpy(dpath, cwd);
        strcat(dpath, "/");
        strcat(dpath, item.name());

        printTreeDir(dpath, level + 1);
      }
    } else {
      // Print file size starting from position 30
      int pos = level * 3 + 3 + strlen(item.name());

      // Print padding
      for (int i = pos; i < 30; i++) Serial.print(' ');

      // Print at least one extra space in case current position > 50
      Serial.print(' ');

      Serial.print(item.size());
      Serial.println(" Bytes");
    }

    item.close();
  }

  dir.close();
}



/*
#define FILENAME "/boot.txt"
#define CONTENTS "Pinetime 40 BOOT"
*/

/*
  Adafruit_LittleFS_Namespace::File file(ExternalFS);
  Serial.println("External FS read Boot file ");
  file.open(FILENAME, FILE_O_READ);
  //while (1) delay(1);
  // file existed 
  if (file) {
    Serial.println(FILENAME " file exists");

    uint32_t readlen;
    char buffer[64] = { 0 };
    readlen = file.read(buffer, sizeof(buffer));

    buffer[readlen] = 0;
    Serial.println(buffer);
    file.close();
  }
  else {
    Serial.print("Open " FILENAME " file to write ... ");

    if (file.open(FILENAME, FILE_O_WRITE)) {
      Serial.println("OK");
      file.write(CONTENTS, strlen(CONTENTS));
      file.close();
    } else {
      Serial.println("Failed!");
    }
  }

  Serial.println("External FS read Boot file Done");
  Serial.println("");
*/



/*
  //while (1) delay(1);

  Serial.println("");
  Serial.println("> File system, Internal and External ");
  Serial.println("");
  // Initialize Internal File System
  InternalFS.begin();

  Serial.println("> Internal FS List Files");
  // Print whole directory tree of root whose level is 0
  printTreeDirInt("/", 0);
  Serial.println("");

  if (!ExternalFS.begin()) {
    Serial.println(">> Error: filesystem not found, mount error.");
    while (1) delay(1);
  }

  //ExternalFS.mkdir("/config");
  Serial.println("");
  Serial.println("> External FS List Files");
  // Print whole directory tree of root whose level is 0
  printTreeDir("/", 0);
  Serial.println("");
  Serial.println("> Smartwatch running...");
  Serial.println("");
  */
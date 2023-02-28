#ifndef NOTIFICATION_H
#define NOTIFICATION_H

//#include "Vector.h"

//typedef struct _Notification Notification;

typedef struct {
  uint32_t notificationID;
  uint8_t type;
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
  uint32_t timestamp;
  char *subject;
  char *message;
} Notification;

/*
class Notification {
protected:

  uint8_t notification_index = 0;

  static constexpr uint8_t TotalNotifications = 4;

public:
  Notification(void) {}

  Vector<_Notification> notifications;

  void add_notification(uint32_t notificationID, uint8_t type, uint32_t timestamp, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, const char *subject, uint8_t sizeSubject, const char *message, uint8_t sizeMessage) {

    if (notifications.Size() == TotalNotifications) {
      free(notifications[0].subject);
      free(notifications[0].message);
      notifications.Erase(0);
    }
    _Notification notification;
    notification.notificationID = notificationID;
    notification.type = type;
    notification.timestamp = timestamp;
    notification.year = year;
    notification.month = month;
    notification.day = day;
    notification.hour = hour;
    notification.minute = minute;

    notification.subject = (char *)malloc(sizeSubject + 1);
    memcpy(notification.subject, subject, sizeSubject);
    notification.subject[sizeSubject + 1] = 0x00;

    notification.message = (char *)malloc(sizeMessage + 1);
    memcpy(notification.message, message, sizeMessage);
    notification.message[sizeMessage + 1] = 0x00;

    //notifications.push_back(notification);
    notifications.PushBack(notification);
    set_notification_index(0);
  }

  uint8_t get_notification_count(void) {
    return notifications.Size();
  }
  uint32_t get_notification_id(uint8_t index) {
    return notifications[index].notificationID;
  }
  uint32_t get_notification_timestamp(uint8_t index) {
    return notifications[index].timestamp;
  }
  uint16_t get_notification_year(uint8_t index) {
    return notifications[index].year;
  }
  uint8_t get_notification_month(uint8_t index) {
    return notifications[index].month;
  }
  uint8_t get_notification_day(uint8_t index) {
    return notifications[index].day;
  }
  uint8_t get_notification_hour(uint8_t index) {
    return notifications[index].hour;
  }
  uint8_t get_notification_minute(uint8_t index) {
    return notifications[index].minute;
  }
  const char *get_notification_subject(uint8_t index) {
    return notifications[index]
      .subject;
  }
  const char *get_notification_message(uint8_t index) {
    return notifications[index]
      .message;
  }

  void clear_notifications(void) {
    notifications.Clear();
    notification_index = 0;
  }

  void clear_notification(uint8_t index) {
    notifications.Erase(index);

    if (notification_index > get_notification_count()) {
      notification_index = get_notification_count();
    }
  }

  void clear_notification_by_id(uint32_t id) {
    for (uint8_t i = 0; i < get_notification_count(); i++) {
      if (notifications[i].notificationID == id) {
        clear_notification(i);
        return;
      }
    }
  }

  uint8_t get_notification_index(void) {
    return notification_index;
  }
  void set_notification_index(uint8_t index) {
    notification_index = index;
  }
};
*/
#endif  //NOTIFICATION_H
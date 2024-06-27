
#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

typedef enum event_src {
  EVENT_SYSTEM,
  EVENT_SENSOR,
  EVENT_UI
} event_src_t;

typedef enum event_type {
  // System events
  EVENT_SYSTEM_BATTERY_LOW,

  // Sensor events
  EVENT_SENSOR_DATA_AVAILABLE,

  // UI events
  EVENT_UI_BUTTON_PRESSED,
} event_type_t;

typedef struct event {
  event_src_t src;
  event_type_t type;
} event_t;

int event_queue_init(void);
int event_queue_push(event_t event);

#endif // EVENT_QUEUE_H

#include "event_queue.h"

#include "sensor.h"
#include "system.h"
#include "ui.h"

#define NUM_EVENTS 10
EVENT_QUEUE_DEFINE(event_queue, NUM_EVENTS);

static void event_handler(void)
{
  while (1) {
    // Wait for events
    event_t event;
    EVENT_QUEUE_GET(event_queue, &event);

    // Process events
    switch (event.src) {
      case EVENT_SYSTEM:
        sensor_evt_handler(event.type);
        ui_evt_handler(event.type);
        break;

      case EVENT_SENSOR:
        system_evt_handler(event.type);
        ui_evt_handler(event.type);
        break;

      case EVENT_UI:
        sensor_evt_handler(event.type);
        system_evt_handler(event.type);
        break;

      default:
        // Error
        break;
    }
  }
}

int event_queue_init(void)
{
  START_THREAD(event_handler);
  return 0;
}

int event_queue_push(event_t event)
{
  EVENT_QUEUE_PUT(event_queue, event);
  return 0;
}

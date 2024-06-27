
#include "event_queue.h"

#include "sensor.h"

static void sensor_task(void)
{
  while (1) {
    // Process external events
    // ...
    // Collect sensor data
    // ...
    // When sensor data is available
    event_queue_push((event_t) {
      .src = EVENT_SENSOR,
      .type = EVENT_SENSOR_DATA_AVAILABLE
    });
  }
}

int sensor_init(void)
{
  START_THREAD(sensor_task);
  return 0;
}

int sensor_evt_handler(event_type_t event)
{
  switch (event) {
    case EVENT_SYSTEM_BATTERY_LOW:
      // Handle battery low event
      break;
    
    case EVENT_UI_BUTTON_PRESSED:
      // Handle button pressed event
      break;

    // Don't handle your own events
    case EVENT_SENSOR_DATA_AVAILABLE:
    default:
      // Error
      break;
  }
}

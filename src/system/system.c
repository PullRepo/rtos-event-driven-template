
#include "event_queue.h"

#include "system.h"

static void system_task(void)
{
  while (1) {
    // Process external events
    // ...
    // Collect system data and metrics
    // ...
    // When battery is low
    event_queue_push((event_t) {
      .src = EVENT_SYSTEM,
      .type = EVENT_SYSTEM_BATTERY_LOW
    });
  }
}

int system_init(void)
{
  START_THREAD(system_task);
  return 0;
}

int system_evt_handler(event_type_t event)
{
  switch (event) {
    case EVENT_SENSOR_DATA_AVAILABLE:
      // Handle sensor data available event
      break;
    
    case EVENT_UI_BUTTON_PRESSED:
      // Handle button pressed event
      break;

    // Don't handle your own events
    case EVENT_SYSTEM_BATTERY_LOW:
    default:
      // Error
      break;
  }
}

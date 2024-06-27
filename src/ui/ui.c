
#include "event_queue.h"

#include "ui.h"

static void ui_task(void)
{
  while (1) {
    // Process external events
    // ...
    // Collect UI inputs and commands
    // ...
    // When button is pressed
    event_queue_push((event_t) {
      .src = EVENT_UI,
      .type = EVENT_UI_BUTTON_PRESSED
    });
  }
}

int ui_init(void)
{
  START_THREAD(ui_task);
  return 0;
}

int ui_evt_handler(event_type_t event)
{
  switch (event) {
    case EVENT_SENSOR_DATA_AVAILABLE:
      // Handle sensor data available event
      break;
    
    case EVENT_SYSTEM_BATTERY_LOW:
      // Handle battery low event
      break;

    // Don't handle your own events
    case EVENT_UI_BUTTON_PRESSED:
    default:
      // Error
      break;
  }
}

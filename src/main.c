
#include "event_queue.h"

// Application Threads
#include "sensor.h"
#include "system.h"
#include "ui.h"

int main(void) {
  event_queue_init();
  
  sensor_init();
  system_init();
  ui_init();

  while (1) {
    // IDLE loop
    WATCHDOG_RESET();
    SLEEP(1);
  }

  return 0;
}

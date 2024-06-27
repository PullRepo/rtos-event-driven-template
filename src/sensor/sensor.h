
#ifndef SENSOR_H
#define SENSOR_H

#include "event_queue.h"

int sensor_init(void);
int sensor_evt_handler(event_type_t event);

#endif // SENSOR_H

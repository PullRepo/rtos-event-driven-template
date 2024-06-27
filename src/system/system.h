
#ifndef SYSTEM_H
#define SYSTEM_H

#include "event_queue.h"

int system_init(void);
int system_evt_handler(event_type_t event);

#endif // SYSTEM_H

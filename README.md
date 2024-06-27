# Event-Driven Application Template for an RTOS
This template demonstrates a simple application structure for use in an embedded system application. Good use-cases:
- IoT sensor
- Simple pump or motor control

## Project Structure

The project has three application tasks/threads: sensor, system, and UI. The sensor task is responsible for collecting and pre-processing sensor data. The system tasks monitors the system performance: battery data, memory, up-time, and other metrics you'd like to collect. The UI is responsible for handling user inputs and outputs.

    /src
    --/sensor
        sensor.c
        sensor.h
    --/system
        system.c
        system.h
    --/ui
        ui.c
        ui.h
        
      event_queue.c
      event_queue.h
      main.c

## Master Event Queue
The event queue is used to synchronize the tasks. The queue itself is a simple FIFO queue - often the RTOS provides and intrinsic message queue data structure for this purpose. Use it if provided, but it should be simple to roll your own. Each tasks is responsible for having an event handler function that the event queue can interact with as messages are received.

## License
See [LICENSE](LICENSE) file for usage information.
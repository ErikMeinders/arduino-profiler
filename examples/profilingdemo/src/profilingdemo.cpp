#include <Arduino.h>

/* Profiling Demo

This sketch demonstrates the use of the profiling macros.
Compile with -DPROFILING to enable profiling.
The profiling macros are defined in profiling.h

Use timeThis(task) to profile a task
Only if the task takes longer than PROFILING_THRESHOLD (default 3ms) it will be printed to the serial port
 
Expected output of this sketch:

    Function longer_running_task() [called from loop:53] took 999 ms
    Function longer_running_task() [called from loop:53] took 1000 ms
    Function longer_running_task() [called from loop:53] took 1000 ms
    Function longer_running_task() [called from loop:53] took 1000 ms
    Function longer_running_task() [called from loop:53] took 1000 ms
    5 seconds elapsed

    ... etc ...

Note that the shorter_running_task is not printed because it takes less than PROFILING_THRESHOLD (300ms for this sketch)
*/

#define PROFILING_THRESHOLD 300 // defaults to 3ms - don't show any output when duration below TH. set before including profiling.h

#include <timers.h>
#include <profiling.h>

DECLARE_TIMER(screenUpdate, 5) // update screen every 5 seconds

void setup()
{
    Serial.begin(115200);
}

void shorter_running_task()
{
    delay(100);
}

void longer_running_task()
{
    delay(1000);
}

void loop()
{
    if ( DUE(screenUpdate) ) 
      Serial.printf("5 seconds elapsed\n");

    timeThis(longer_running_task());
    timeThis(shorter_running_task());
        
}
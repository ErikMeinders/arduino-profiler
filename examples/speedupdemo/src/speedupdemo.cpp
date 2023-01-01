#include <Arduino.h>

/* TIMER Demo with SPEEDUP

This sketch demonstrates the use of some of the timer macros.

__TIMER(timerName, interval) declares a timer with the given name and interval
in this example, screenUpdate is declared with an interval of 1 minute

the __TIMER macro can be speeded up by defining SPEEDUP before including timers.h
in this example, SPEEDUP is defined in the platformio.ini file

DUE(timerName) returns true if the timer has expired
and resets the timer if it has expired
in this example, DUE(screenUpdate) returns true every minute, 
or every second if SPEEDUP is defined

More advanced timers can be created using the macros in timers.h
See the documentation for more information (found in include/timers.h)

*/

#include <timers.h>

__TIMER(screenUpdate, 1) // update screen every 1 minute or 1 seconds if SPEEDUP is defined

void setup()
{
    Serial.begin(115200);
}


void loop()
{
    if ( DUE(screenUpdate) ) 
      Serial.println("timer triggered");

    delay(1000);
}
#include <Arduino.h>

/* TIMER Demo

This sketch demonstrates the use of some of the timer macros.

DECLARE_TIMER(timerName, interval) declares a timer with the given name and interval
in this example, screenUpdate is declared with an interval of 5 seconds

DUE(timerName) returns true if the timer has expired
and resets the timer if it has expired
in this example, DUE(screenUpdate) returns true every 5 seconds

More advanced timers can be created using the macros in timers.h
See the documentation for more information (found in include/timers.h)

*/

#include <timers.h>

DECLARE_TIMER(screenUpdate, 5) // update screen every 5 seconds

void setup()
{
    Serial.begin(115200);
}


void loop()
{
    if ( DUE(screenUpdate) ) 
      Serial.println("5 seconds elapsed");

    delay(1000);
}
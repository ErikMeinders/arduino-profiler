# timers.h

A set of macros to manipulate time. Well, kind of ...

# Declare timers

```
DECLARE_TIMER(timername, interval) // declare timer for interval seconds
```

Declares two unsigned longs: 
```
  unsigned long <timername>_last;     // for last execution
  unsigned long <timername>_interval; // for interval in milliseconds
```
with 'random noise' to avoid aligned timers.

The same macro with a '_' postfix doesn't add noise (see below).

Timers can be declared with different units; seconds, minutes, hours and milliseconds

DECLARE_TIMERms is same as DECLARE_TIMER **but** uses milliseconds!
DECLARE_TIMERm and DECLARE_TIMERh are for minutes and hours respectively.

## random noise

The idea of adding 'random noise' is to try to avoid that in a single loop all timers are due
during the same loop iteration. Consider the following code for Arduino:
```
DECLARE_TIMER(fiveSecondsTimer,5);
DECLARE_TIMER(tenSecondsTimer,10);
DECLARE_TIMER(twentySecondsTimer,20);

loop()
{
    handle_something_important();

    if (DUE(fiveSecondsTimer)) ....
    if (DUE(tenSecondsTimer)) ...
    if (DUE(twentySecondsTimer)) ...
}
```
Whithout adding noise, every twenty seconds all three timers are due and something important will have to wait longer.
Adding noise is implemented by essentially shifting the timer somewhat in its interval so in the example above the timers won't align.

# Elapsed time

ELAPSED(msStart, msEnd) returns ms between times, even after rollover at MAXMS (2^32-1) milliseconds.
SINCE(timername) returns the number of elapsed ms since last time due-time on the timer.

# Due
```
DUE(timername) 
```

Returns false (0) if interval hasn't elapsed since last DUE-time and true (current millis) if it has
The new interval starts NOW.

Add the _ character to the Macro name to align it to the rythm of the timer:
```
DUE_(timername)
```

Works as DUE but tries to align new interval at interval beat.
In other words, new interval doesn't start now, but at previous timer expiration

# Speedup

To expedite testing where timers are defined in minutes, declare timers as __TIMER(....):

- without SPEEDUP defined BEFORE including timers.h __TIMER is in minutes!
- with SPEEDUP defined BEFORE including timers.h __TIMER is in seconds!

See speedupdemo for more.


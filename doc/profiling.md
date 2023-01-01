# Profiling

Measure duration of code execution and report on code running longer than defined threshold.

```
#include <profiling.h>

main()
{
    timeThis(some_function());
}
```

If ``PROFILING`` is defined before including ``profiling.h``, the ``timeThis`` macro will expand to code
that reports how long ``some_function()`` took. Reporting is limited to durations above ``PROFILING_THRESHOLD``
which can be defined before including ``profiling.h`` and defaults to 3ms.

When ``PROFILING`` is not defined the timeThis macro expands to only ``some_function()`` in the above example.

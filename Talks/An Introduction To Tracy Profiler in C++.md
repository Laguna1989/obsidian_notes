---
tags:
  - Talk
  - cpp
  - performance
---

> [!info] See [[Tracy]]

<iframe width="560" height="315" src="https://www.youtube.com/embed/ghXk3Bk5F2U?si=6BfKYJ1AT2cU3Py2" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Pro

- free and open source
- uses imgui
- super easy to set up
- can even do gpu profiling

# Closing the Profiling Zoo

- Tracing:
	- Program execution logging
	- function calls, system events, state changes
	- mostly for debugging
- Sampling
	- callstack snapshopt profiling
	- system wide, automatic os kernel events or hardware counters
	- issue: information overload, bound by sampling frequency
- Instrumentation
	- annotiations
	- automatic or selective (manual)
- Analysis
	- Pre-record? Real Time?
	- Giant Log file? GUI
	- Is it responsive?

> [!info] Tracy can do all of the above

# Quake Showcase

- Click connect on the server (normally port 8086)
- Start the program with the Tracy client compiled into it
- If the application can be divided into frames, Tracy is super helpful
- Top row in tracy shows frame times
	- Clicking a frame zooms to it
- Below that is the callstack
- You get CPU usage with 100ms intervals for free
- Memory Usage can be shown
- Statistics are very useful
	- number of calls
	- MTPC = mean time per call
	- right click on the source code jumps to the file
- Right click on backround:
	- Limit statistics to range
- Right clicking on a call shows statistics (min, mean, max time)
- Click on info in main window: Some more details on a trace
	- e.g. what is the cost of running the trace?

# Tracy Architecture

- Tracing can be done locally or via the network
- Profiler
	- There is a precompiled windows binary
	- Build yourself on linux and mac

# Tracy Zoning 101

- `ZoneScoped` is the bread and butter of tracy
- Only one zone per c++ scope!
- zone name ins inferred (function name) or cstom
- color is automatic (thread and nesting depth)
	- color either `0xRRGGBB`or from tracy namespace

# Tracy Zoning 201, 301

- You can programmatically change the name or color
	- E.g. change in case of an error via `ZoneColor()`in an if
	- Be careful when chaging names as this will not show the new name in statistics
- Add `ZoneValue(i)`which will show in the trace
	- Multiple values can be used and will be shown in the Profiler
	- `ZoneText("abcd");` or `ZoneText("defense", 7);`
- `ZoneNamedN(initzone, "int", true)` last argument is the active argument, can be used to easily disable specific parts of the tracing

# Tracy Zoning 401

- Transient zones
- Changing the name of a zone will use the original name
- `ZoneTransientN(pokezone, pokemen.name, true);`
- name a zone with a non-persistent string
- will show up correctly in statistics
- increase the runtime cost to record the zone (because of string copy)

# Tracy Zoning 501

- Get a callstack of the frame
- `ZoneScopedS(60);`
- Get the callstack of this zone up to the respective depth
- Adds some overhead

# TracyMessage() Is the New Printf

- `TracyMessageL`, `TracyMessageC`, `TracyMessageS`
- A new console with time info, filter options, automatic thread synchronization
- Click on "Messages" in the top of the Profiler

# Plots

- `TracyPlot(name, value);`
	- Value can be float, double, int, ...
- `TracyPlotConfig(name, type, step, fill, color);` (only needed once on setup)

# Tracking Memory Allocations

- `TracyAlloc(ptr, size, ...)`
- `TracyFree(ptr, ...)`
- Click on "Memory" in Profiler

# Lock Instrumentation

```cpp
std::mutex my_mutex;
TracyLockable(std::mutex, my_mutex);
std::lock_guard<LockableBase(std::mutex)> lock(my_mutex);
```

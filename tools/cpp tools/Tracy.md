---
tags:
  - tool
  - cpp
  - performance
---

> [!info] A real time, nanosecond resolution, remote telemetry, hybrid frame and sampling profiler for games and other applications.

# Build the Profiler for Linux

- Clone

```bash
git clone https://github.com/wolfpld/tracy.git
cd tracy
git checkout v0.11.1
```

- Install dependencies

```bash
sudo apt install build-essential libdbus-1-dev libfreetype-dev libtbb-dev libxkbcommon-dev libwayland-dev libglvnd-dev
```

- Build profiler (server) via cmake

```bash
cmake -B profiler/build -S profiler -DCMAKE_BUILD_TYPE=Release
cmake -- build profiler/build --config Release --parallel
```

- Execute

```bash
profiler/build/tracy-profiler
```

# Setup in Your Project

```cmake
CPMAddPackage(
        NAME tracy
        GITHUB_REPOSITORY wolfpld/tracy
        GIT_TAG v0.11.1
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)

FetchContent_GetProperties(tracy)

target_link_libraries(<Target> PUBLIC TracyClient)
```

# Code Instrumentation

```cpp
#include <tracy/Tracy.hpp>

void update()
{
	ZoneScoped;
	ZoneScopedN("identifier");
	ZoneScopedNC("identifier", tracy::Color::Aqua);
}
```

# 

---
tags:
  - tool
  - cpp
  - windows
---

> [!info] A build analysis tool for MSVC

# Compilation

- Clone repo

```bash
git clone https://github.com/microsoft/vcperf.git
```

- Open `*.sln` in visual studio
- Make sure that the `C++ Build Insights` NuGet package is installed
- Build for your architecture, preferably in Release mode

# Run Build Performance Analysis

- Open terminal **with admin rights**
	- needed for cpu
- Go to out directory

 ```bash
cd .\vcperf\out\Release\x64\
```

- start profiling

```bash
.\vcperf.exe /start /level3 2024-10-30_session_name
```

- arguments explained:
	- `/start` start profiling
	- `/level3` highest profiling level
	- `2024-10-30_session_name` vcperf session name to be used
- clean project to be built working directory
	- `ccache -C`
	- delete `build` folder content
- open project for build performance analysis in visual studio
- instantiate build

# Create Analysis File

```bash
.\vcperf.exe /stop /templates 2024-10-30_test_session 2024-10-30_test_session.etl
```

- arguments explained
	- `/stop` stop tracing session and create report
	- `/templates` analyze template instantiation events
	- `2024-10-30_test_session` session name (same as with the `/start` command)
	- `2024-10-30_test_session.etl` output `etl` file
- Creates an `etl` file that can be opened with windows
- Coneole Output

```
Stopping and analyzing tracing session 2024-10-30_test_session...
Dropped MSVC events: 0
Dropped MSVC buffers: 0
Dropped system events: 0
Dropped system buffers: 0
The trace "[path]" may contain personally identifiable information. This includes, but is not limited to, paths of files that were accessed and names of processes that were running during the collection. Please be aware of this when sharing this trace with others.
Tracing session stopped successfully!
```

- Open the file via double click

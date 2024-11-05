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
- clean project to be analyzed
	- `ccache -C`
	- delete `build` folder content
- open project to be analyzed in visual studio
- start build

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

## Analyze Build Performance

- Open the file via double click
- [C++ Build Insights SDK: event table | Microsoft Learn](https://learn.microsoft.com/en-us/cpp/build-insights/reference/sdk/event-table?view=msvc-170)

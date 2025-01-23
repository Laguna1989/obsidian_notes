---
tags:
  - tool
  - performance
  - windows
---

> [!info] Windows Tool to analyze performance or loaded DLLs

Can be started by calling

```bash
perfmon.exe
```

# Learn Which DLLs Are Loaded by an Executable

- Have the exe running
- Open perfmon
	- Search for it in the list of processes
	- tick the checkbox for the executable
	- Expand "Assigned Modules" at the bottom of the screen
	- See which dlls are loaded by an executable

---
tags:
  - tool
  - cpp
links: "[[Tools MOC]]"
---
# Setup Process

- Settings -> Marketplace -> Install `File Watchers` -> `Apply`
- Settings -> Tools -> File Watchers -> new rule
  - File Type: C++ files
  - Program: `/usr/bin/astyle`
  - Arguments: `$FilePath$ --options=[Path_to_astyle_style_file]`
  . Advanced Options:
    - Disable `Auto Save edited files to trigger watcher`
    - Disable `Trigger the watcher on external changes`

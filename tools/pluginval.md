---
tags:
  - tool
links: "[[Tools MOC]]"
---
> [!quote] Can be used to verify AU, VST and VST3 plugins

[https://github.com/Tracktion/pluginval](https://github.com/Tracktion/pluginval)

# Process

- build vst3 release of plugin
- open pluginval
- remove old version of plugin to be tested
- drag and drop vst3 file into pluginval
- set strictness level to 10
- select plugin in list
- click `Test Selected`
- Wait until tests complete
- Click `save log`
- open log file, scroll to bottom and check for `ALL TESTS PASSED`

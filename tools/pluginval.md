---
tags:
  - tool
  - audio
---
# Overview

> [!quote] Can be used to verify AU, VST and VST3 plugins

- [github repo](https://github.com/Tracktion/pluginval)
- [blog post describing how to use pluginval](https://melatonin.dev/blog/pluginval-is-a-plugin-devs-best-friend/)
- [online version of pluginval](https://validatemyplugin.com/)

# Process

## Manual Verification

- Build vst3 release of plugin
- Open pluginval
- Remove old version of plugin to be tested
- Drag and drop vst3 file into pluginval
- Set strictness level to 10
- Select plugin in list
- Click `Test Selected`
- Wait until tests complete
- Click `save log`
- Open log file, scroll to bottom and check for `ALL TESTS PASSED`

## CLI Verification

call

```bash
--verbose --strictness-level 10 "<path_to_plugin>"
```

Optional cli arguments
- `--skip-gui-tests` helpful for headless mode
- `--timeout-ms` Set this to a high value when debugging to avoid timeouts

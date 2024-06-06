---
tags:
  - tool
---
# Overview

There is `fmod core` and `fmod studio`

# Processing Modes

- Asynchronous: Default
	- Works with shadow data and calls are very fast
	- next call to `update()` is very fast and just submits the queued command buffer to the async thread
	- all processing is done in the Studio update thread
- Synchronous: Can be started with specific flag `FMOD_STUDIO_INIT_SYNCHRONOUS_UPDATE`
	- All processing of queued commands and event playback and automation is performed when `update()` is called

# Studio Bank File Layout

![[IMG-2024-06-06-143828000.png]]

- when loading a bank, all metadata is loaded
- Metadata contains information about all events, parameters and other data
- Sound data is splitted into "sample" and "streaming" -> decided by designer in fmod studio

## Special Banks

- strings bank: lookup of event path to GUID
- Master bank: global mixer, creates events
- Bank Separation metadata and assets can be split to minimize patch filesize
- Referenced Events: Event definition and usage can be separated

# Bank Loading

- synchronous ([FMOD_STUDIO_LOAD_BANK_NORMAL](https://www.fmod.com/docs/2.03/api/studio-api-system.html#fmod_studio_load_bank_normal) )or asynchronous ([FMOD_STUDIO_LOAD_BANK_NONBLOCKING](https://www.fmod.com/docs/2.03/api/studio-api-system.html#fmod_studio_load_bank_nonblocking))
- After a bank has completed loading, all metadata can be accessed

# Sample Data Loading
Three options
- [Studio::Bank::loadSampleData()](https://www.fmod.com/docs/2.03/api/studio-api-bank.html#studio_bank_loadsampledata)
- [Studio::EventDescription::loadSampleData()](https://www.fmod.com/docs/2.03/api/studio-api-eventdescription.html#studio_eventdescription_loadsampledata)
- [Studio::EventDescription::createInstance()](https://www.fmod.com/docs/2.03/api/studio-api-eventdescription.html#studio_eventdescription_createinstance)

Reference counting: If all instances of banks/events are unloaded, they are left out of memory
# Live Update

- Set [`FMOD_STUDIO_INIT_LIVEUPDATE`](https://fmod.com/docs/2.01/api/studio-api-system.html#fmod_studio_initflags) when initializing
- FMOD Studio listens for connections on port `9264`, different port can be specified by [System::setAdvancedSettings()](https://fmod.com/docs/2.01/api/core-api-system.html#system_setadvancedsettings) 

# 3D Positioning
Need to call once per frame:
- [Studio::System::setListenerAttributes()](https://www.fmod.com/docs/2.03/api/studio-api-system.html#studio_system_setlistenerattributes) 
- [Studio::EventInstance::set3DAttributes()](https://www.fmod.com/docs/2.03/api/studio-api-eventinstance.html#studio_eventinstance_set3dattributes)
- 
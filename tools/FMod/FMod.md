---
tags:
  - tool
  - audio
---
# Overview

There are two versions of libraries available
- `fmod core`:
	- Audio library
	- Can be used in code #cpp , #csharp , #unity and #unreal
- `fmod studio`:
	- Uses (and provides) the above above
	- Offers additional integration with [[fmod studio]],
	- This allows sound designers to do work in a DAW-like environment
	- Support for Bank files

# Processing Modes

> [!hint] See also [[C++ Concurrency]]

- Asynchronous: Default
	- Works with shadow data and calls are very fast
	- Next call to `update()` is very fast and just submits the queued command buffer to the async thread
	- All processing is done in the Studio update thread
- Synchronous: Can be started with specific flag `FMOD_STUDIO_INIT_SYNCHRONOUS_UPDATE`
	- All processing of queued commands and event playback and automation is performed when `update()` is called

# Studio Bank File Layout

> [!info] A bank file contains all data for audio events

>[!info] A Bank file is the link between [[fmod studio]] and the code

![[IMG-2024-06-07-065959695.png]]

- When loading a bank, all metadata is loaded
- Metadata contains information about all events, parameters and other data
- Sound data is splitted into "sample" and "streaming" -> decided by designer in fmod studio

## Special Banks

- Strings bank: lookup of event path to GUID
- Master bank: global mixer, creates events
- Bank Separation metadata and assets can be split to minimize patch filesize
- Referenced Events: Event definition and usage can be separated

# Bank Loading

- Loading Type:
	- Synchronous ([FMOD_STUDIO_LOAD_BANK_NORMAL](https://www.fmod.com/docs/2.03/api/studio-api-system.html#fmod_studio_load_bank_normal) ) or
	- Asynchronous ([FMOD_STUDIO_LOAD_BANK_NONBLOCKING](https://www.fmod.com/docs/2.03/api/studio-api-system.html#fmod_studio_load_bank_nonblocking))
- After a bank has completed loading, all metadata can be accessed
	- **???** There is a `getLoadingState()` function **???**

# Sample Data Loading

Three options
- [Studio::Bank::loadSampleData()](https://www.fmod.com/docs/2.03/api/studio-api-bank.html#studio_bank_loadsampledata)
- [Studio::EventDescription::loadSampleData()](https://www.fmod.com/docs/2.03/api/studio-api-eventdescription.html#studio_eventdescription_loadsampledata)
- [Studio::EventDescription::createInstance()](https://www.fmod.com/docs/2.03/api/studio-api-eventdescription.html#studio_eventdescription_createinstance)

Reference counting: If all instances of banks/events are unloaded, they are left out of memory

# Live Update ([[fmod studio]])

- This allows fmod studio to call into the code
	- I assume this enables hot-reload from fmod studio
- Set [`FMOD_STUDIO_INIT_LIVEUPDATE`](https://fmod.com/docs/2.01/api/studio-api-system.html#fmod_studio_initflags) when initializing
- FMOD Studio listens for connections on port `9264`, different port can be specified by [System::setAdvancedSettings()](https://fmod.com/docs/2.01/api/core-api-system.html#system_setadvancedsettings)

# 3D Positioning

Need to call once per frame:
- [Studio::System::setListenerAttributes()](https://www.fmod.com/docs/2.03/api/studio-api-system.html#studio_system_setlistenerattributes)
- [Studio::EventInstance::set3DAttributes()](https://www.fmod.com/docs/2.03/api/studio-api-eventinstance.html#studio_eventinstance_set3dattributes)
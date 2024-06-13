---
tags:
  - presentation
links: 
maxScale: "2.0"
---
# Intro to FMod Studio

## 2024-06-13

---

# What is FMod?

- Proprietary sound effects engine for video games
- Bindings for `C`, `C++` and `C#`
- Integration for Unity and Unreal
- Runs on Win, Mac, Linux, Android, WiiU, Playstation 3/4, XBox, XBox360 and HTML5

---

# Licensing

- Three models
	- Indie (including free)
	- Basic
	- Premium
- No feature-stripped versions
- Increased support and source code access

---

# Alternatives

- wWise
	- Similar commercial product
- OpenAL
	- Open source, way closer to the hardware

---

# Reference Games

- Dark Souls 3
- StarCraft 2
- Kingdom Come Deliverance
- Crysis Series
- Fall Guys
- Forza Series
- Just Cause
- Celeste
- Torchlight 3
- ...
---

# Overview

- FMod core:
	- Basic audio library functionality (load and play sounds)
- FMod studio
	- Uses (and provides) the above
	- Dynamic Audio
	- This allows sound designers to do work in a DAW-like environment

---

# FMod Studio

## Demo

- Assets
	- Streaming
- Events
	- Action (volume, effects)
	- Timeline (loops, markers)
	- Path
- Busses
- 2D/3D sounds
- Instances
- Banks

---

# Banks

> [!info] Bank files are the interface between [[fmod studio]] and the code

![[IMG-2024-06-07-065959695.png]]

- Metadata contains information events, parameters, busses, ...
- Sounds can be arbitrarily distributed on banks (split by game-level)

---

# Special Banks

- Master bank: Global mixer (busses, vca groups, ...)
- Strings bank: Lookup of event paths to GUID

---

# CMake Integration

- Download zip file and extract
- `target_include_directories`
- `target_link_libraries`

```cmake
target_include_directories(myTarget PUBLIC 
    ${FMOD_DIR}/api/core/inc)
target_include_directories(myTarget PUBLIC 
    ${FMOD_DIR}/api/studio/inc)
target_link_directories(myTarget PUBLIC 
    ${FMOD_DIR}/api/core/lib/x86_64)
target_link_directories(myTarget PUBLIC 
    ${FMOD_DIR}/api/studio/lib/x86_64)

target_link_libraries(myTarget PUBLIC 
    ${FMOD_DIR}/api/core/lib/x86_64/libfmod.so)
target_link_libraries(myTarget PUBLIC 
    ${FMOD_DIR}/api/studio/lib/x86_64/libfmodstudio.so)
```

---

# Initialize Studio

```cpp
FMOD::Studio::System* studioSystem;
FMOD::Studio::System::create(&studioSystem);

studioSystem->initialize(
    <channels>, // effectively the max number of sounds playing 
    <FMOD_STUDIO_INITFLAGS>, 
    <FMOD_INITFLAGS>, 
    nullptr
);
```

Flag options:
- live update
- sync update / mix update
- memory tracking
- ...
- clip output
- profiling

---

# Cleanup

```cpp
studioSystem->initialize(...);

// ...
// run game loop
// ...

studioSystem->release();
```

---

# Loading a Bank

```cpp
FMOD::Studio::Bank* bank;

studioSystem->loadBankFile(
	"path/to/my.bank", 
	FMOD_STUDIO_LOAD_BANK_NORMAL, 
	&bank)
```

Other flags include
- Non-blocking
- Decompress samples
- Unencrypted

---

# Playing a Sound

```cpp
FMOD::Studio::EventDescription* eventDescription;
studioSystem->getEvent(<eventPath>, &eventDescription);

FMOD::Studio::EventInstance* eventInstance;
eventDescription->createInstance(&eventInstance);

eventInstance->play();
```

Nothing happens! <!-- element class="fragment" data-fragment-index="1" -->

---

# Update

```cpp
studioSystem->update();
```

- Call regularly from gameloop
- Async mode (default) <!-- element class="fragment" data-fragment-index="1" -->
	- Processing takes place in studio async thread, triggered by `update()`
	- Works with shadow data
- Sync mode <!-- element class="fragment" data-fragment-index="2" -->
	- All processing happens from within blocking `update()`

---

# Playing a Sound II

- Calling `start()` a second time, will restart the sound
- `stop(FMOD_STUDIO_STOP_MODE)`
	- immediate or fadeout options
- `setPaused(bool)`

---

# Positioning 3D Sounds

## Camera

```cpp
FMOD_3D_ATTRIBUTES listenerAttributes;
studioSystem->setListenerAttributes(
	0,                      // listener ID
	&listenerAttributes,    // attributes
);
```

## SoundInstance

```cpp
FMOD_3D_ATTRIBUTES sound3DAttributes;
eventInstance->set3DAttributes(&sound3DAttributes)
```

Check if Event is 3D:

```cpp
bool is3D{false};
eventDescription->is3D(&is3D);
```

---

# Positioning 3D Sounds

```cpp
typedef struct FMOD_3D_ATTRIBUTES  
{  
    FMOD_VECTOR position;  
    FMOD_VECTOR velocity;  
    FMOD_VECTOR forward;  
    FMOD_VECTOR up;  
} FMOD_3D_ATTRIBUTES;
```

---

# Controlling Volume

```cpp
FMOD::Studio::Bus *bus;   
studioSystem->getBus("bus:/UI", &bus);
bus->setVolume(0.5f);
```

- Alternative option: VCA groups <!-- element class="fragment" data-fragment-index="2" -->
	- Only Volume controls

---

# More Bus Functions

- Busses can also be used to pause/mute/stop all event instances that play on this bus <!-- element class="fragment" data-fragment-index="1" -->

```cpp
bus->setPaused(true);
bus->setMute(false);
bus->stopAllEvents(FMOD_STUDIO_STOP_MODE);
``` 

---

# Instance Management?

```cpp
eventInstance->release();
```

- `release()` marks a sound for deletion
- can be directly called after `start()`
- fmod studio automatically disposes sounds after they have stopped
- Reuse one `eventInstance` by not calling `release()`.
- EventInstances are leightweight handles

-> No extra effort needed on implementation side

---

# Handles

- `eventInstance`is a pointer type
- Actually consist of packed handle data
- If the underlying type has been destroyed by FMod, an error is be returned

---

# Instance Stealing

- It is possible to limit the number of event instances
- FMod Studio offers:
	- Oldest
	- Quietest
	- Furthest
	- None
	- Virtualize (effectively: "continues to play in silence")

---

# Thread Safety

- All API functions are thread safe, except for
	- `FMOD::Studio::System::create()`
	- `FMOD::Studio::System::release()`

> [!danger] Those two functions must not overlap with any other API calls

---

# FMod Live Update

- FMod Studio listens on Port `9264`
- Allows live audio adjustments for sound designers

---

# Further Topics

- Parameters
	- Control the crowd sound based on the number of guests in the part

---

# Questions?

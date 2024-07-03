---
tags:
  - presentation
  - tool
  - audio
links: 
maxScale: "2.0"
---
# Intro to FMod Studio

## 2024-06-29

---

# Werbeblock

![[IMG-2024-06-29-100629048.png]]

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

> [!info] The interface between fmod studio and the code

![[IMG-2024-06-07-065959695.png]]

- Metadata contains information events, busses, ...
- Distribute Sounds to banks (split by game-level)

---

# Special Banks

- Master bank: Global mixer (busses, vca groups, ...)
- Strings bank: Lookup of event paths to GUID

---

# CMake Integration (linux)

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

# CMake Integration (emscripten)

```cmake
set(CMAKE_EXECUTABLE_SUFFIX ".html")

add_link_options("SHELL:--use-preload-plugins"  
        "SHELL:--preload-file assets")

add_link_options("SHELL:-s EXPORTED_RUNTIME_METHODS=
    ['cwrap','setValue','getValue']")
    
target_link_options(fmod_web PRIVATE 
    "SHELL:-s TOTAL_MEMORY=256MB")
target_link_options(fmod_web PRIVATE 
    "SHELL:-s ALLOW_MEMORY_GROWTH=1")
```

```cmake
target_include_directories(myTarget PUBLIC 
    ${FMOD_DIR}/api/core/inc)  
target_include_directories(fmod_web PUBLIC 
    ${FMOD_DIR}/api/studio/inc)

target_link_libraries(myTarget PUBLIC 
    ${FMOD_LIB_DIR}/upstream/w32/fmod_wasm.a)
target_link_libraries(myTarget PUBLIC 
    ${FMOD_LIB_DIR}/upstream/w32/fmodstudio_wasm.a)
```

---

# Initialize Studio

```cpp
FMOD::Studio::System* studioSystem;
FMOD::Studio::System::create(&studioSystem);

studioSystem->initialize(
    <channels>, // the max number of sounds playing 
    <FMOD_STUDIO_INITFLAGS>, 
    <FMOD_INITFLAGS>, 
    nullptr
);
```

---

# Init Flags

- live update
- sync update / mix update
- memory tracking
- clip output
- profiling
- ...

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
	&bank);
```

Other flags include
- Non-blocking
- Decompress samples
- Unencrypted

---

# Playing Sounds

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

---

# Update Modes

- Async mode (default)
	- Processing takes place in studio async thread, triggered by `update()`
	- Works with shadow data
- Sync mode <!-- element class="fragment" data-fragment-index="1" -->
	- All processing happens from within blocking `update()`

---

# Playing Sounds II

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

---

# Positioning 3D Sounds

## SoundInstance

```cpp
FMOD_3D_ATTRIBUTES sound3DAttributes;
eventInstance->set3DAttributes(&sound3DAttributes);
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

# Volume

```cpp
eventInstance->setVolume(1.0f);
```

---

# Volume

```cpp
FMOD::Studio::Bus *bus;   
studioSystem->getBus("bus:/UI", &bus);
bus->setVolume(0.5f);
```

- Alternative option: VCA groups (only Volume control) <!-- element class="fragment" data-fragment-index="2" -->

---

# More Bus Functions

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

-> No extra effort needed on implementation side

---

# Handles

- `eventInstance` is a pointer type
- Actually consist of packed handle data
- If the underlying type has been destroyed by FMod, an error is be returned

---

# Instance Stealing

Limit the number of event instances

- Oldest
- Quietest
- Furthest
- None
- Virtualize ("continues to play in silence")

---

# Thread Safety

- All API functions are thread safe, except for
	- `FMOD::Studio::System::create()`
	- `FMOD::Studio::System::release()`

> [!danger] Those two functions must have strictly-before/strictly-after relations with any other API call

---

# FMod Live Update

- FMod Studio listens on Port `9264`
- Allows live audio adjustments for sound designers
- Demo

---

# Further Topics

- Parameters
	- e.g. Control the crowd sound based on the number of guests in the park
- Error handling:
	- Almost all API functions return `FMOD_RESULT`

---

# Questions?

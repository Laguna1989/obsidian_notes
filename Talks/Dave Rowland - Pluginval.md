---
tags:
  - Talk
  - audio
  - plugin
---

<iframe width="560" height="315" src="https://www.youtube.com/embed/Q97LBXqgMus?si=Ywriwhe3UaxRrO9s" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

> [!info] See also [[pluginval]]

# Landscape of Plugin DEv

- 3 Operating Systems (Win, Mac, Linux)
- 4 Major Plugin Formats (VST3, (vst), AU, AAX)
- Architectures (32bit, 64bit)
- Hosts (at least 12 major hosts, 12 minor, .... )
- => 288 Environments to test on

# History

- Early plugin development
	- Started with VST standard, 23 API functions
- More formats
- -> JUCE as a common denominator
	- Around 40 API functions
- Today
	- More concepts have been added

# Features

Huge number of features (parameters, processing, playhead, channel layout, latency, listeners,automation state, editors, ...)

-> Around 100 features/API calls

# Per Release

- 100 features
- 288 environments
- ->huge number of possibilities where things can go wrong

# Threading

- Most APIs don't mention threads
- Many don't agree on a threading model
- Assume the worst
- Best case: 2x, worst case as many as your host gives you

# But it Works in ....

- Simple things:
	- Host not calling broken methods
	- Plugins not testing all methods
- Hosts doing unexpected things
	- Prepared to play called with size x, process called with size y < x
- Plugins doing unexpected things
	- Blocking the message thread, authorization deadlocks
- Plugins writing files on instantiation
	- file system access
- "Disagreements" in threading models
	- race conditions, heap corruption, ...
	- Plugin assumptions don't match Hosts assumptions

# Reasons

- Not poor coding, but because of different formats
- Plugin and Host development based on precendent (whoever did it first...)

# Solution

- Assume the worst
- Test every possibility

# Manual Testing is no Longer Viable

- Humans can help, but cannot deal with the massive landscape
- Cost involved in doing manual tests (support, dev, qa, marketing, ...)

# Catch Issues EARLY

![[IMG-2025-07-13-101818744.png]]

-> [[valgrind]]
-> [[fuzzing]]

- Exponential cost increase
- Detect issues as early as possible

# Pluginval

- See [[pluginval]]
- Looking for auval-like tool
- Can easily be used as part of the CI
- Open source
- Documentation

# Pluginval History

- Added UI so it can be used by QA
- Now more than auval

# What Does it Test?

- Plugin Info
- Parameters
- Editor
- Plugin State saving and restoration
- Audio Processing (different block size and sample rates)
- Audio Processing (sub blocks)
- Automation
- Multi Threaded state/value setting
- Bus/Channel layouts
- Memory allocation on the audio thread
- Parameter fuzzing

# Use Cases for Plugin Devs

- Quick way for CI
- Improve confidence for releases

# Use Cases for Host Devs

- Quick way to test compatibility with juce based host
- If plugin fails validation: Why
- Much quicker way of getting QA to test plugins
- Easy to share [[pluginval]] logs with developers
- Open source for documentation

# Use Cases for End Users

- Easy way of reporting
- Simple to look at pluginval log file
- Providing more information (e.g. via a log) will make issues easier to fix for the dev

# Architecture

- UI and cli
- In- and out-of-process validation
- Validate one or multiple plugins
- Based in JUCE Unit test framework

# Future Development

- JUnit output formatting
- Javascript bindings (write tests in js)
- More bespoke testing
	- Provide known midi/audio input
	- Compare to known/expected output

---
tags:
  - Talk
  - audio
created: 2024-07-31
---
# Reference

<iframe width="560" height="315" src="https://www.youtube.com/embed/9kuP87ZMHJo?si=FFTkU7StGecxGArC" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Overview

## Why Use CLAP?

- Modern, Simple, Robust and Extendable
- Clear and Precise Specification
- Permissive License (MIT)
	- Can be adopted to everything
- Collection of tools and helper libraries
- open and welcoming participation

## C Interface

- Easy to use in different languages: C++, Rust, C#, Python
- Works on all operating Systems and CPU architectures

## C++ Glue Layer and Contract Programming

- Configurable Checking level (none, minimum, maximum)
- Configurable Error handler (ignore, crash)
- Checks that you are on the right thread
- Checks that your in the right state
- Check that you are passing and receiving valid arguments

## Process Loop

- One input and one output event queue, sorted by time
	- Parameter changes are events
	- Midi and Midi 2 raw events
	- See events.h

## Modern Features

- Fast Plugin scanning
- Polyphonic Parameter Modulations
- Host's thread pool
	- Reuse the host thread pool, plugin does not need to take care of thread creation
- ARA
- Preset Discovery + Remote Controls + Parameter Indications
- Surround and Ambisonic

# Libraries and Tools

# CLAP and JUCE

- Very easy juce integration with [clap-juce-extensions](https://github.com/free-audio/clap-juce-extensions)

# CLAP Wrapper

- Adapt your existing CLAP plugin to VST3 or AU

# CLAP Validator

- See [clap validator](https://github.com/free-audio/clap-validator)
- Checks if the plugin behaves correctly

# Summary

- Clap is universal, modern and successful

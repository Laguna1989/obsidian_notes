---
tags:
  - Talk
  - audio
  - juce
created: 2024-08-04
links: "[[Talks MOC]]"
---

<iframe width="560" height="315" src="https://www.youtube.com/embed/ILMdPjFQ9ps?si=5aVMPgJXQPfv0Mwf" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Components and Their Responsibilities

## Components / Classes

- Plugin Processor
	- Runs on the audio thread
	- Time Critical. This will cause audio glitches if you are to slow
	- `processBlock()`, `prepareToPlay()`
	- There is only a single instance
	- Only concerned about itself
- Plugin Editor
	- responsible for everything on screen
	- Runs on the Message thread
	- Multiple instances possible
	- Can be destroyed/recreated at any time
	- Dependent on the Plugin Processor and can access it

Dependencies between Objects:
- Rendering must be done in the Editor
- It depends on audio, which happens to exist only in the Processor
- Plugin Processor gets a function `getRmsLevel(channel)` that can be called from the editor
	- Processor calculates, updates and stores the rms value on a regular interval
	- The Editor will fetch the value at some points when it needs to redraw.

# RMS Level and Calculations

## Audio Level Calculations

- Audio Rate information is way too much for displaying it
- Calculate an averaged audio level

## RMS

- RMS = Root Mean Square
- Audio Values are in range `[-1; 1]` so the average is 0. We are interested in the actual deviation from zero, s we need to square before averaging

$$
\sqrt{\frac{\sum_i x^2_i}{n}}
$$

`n` is the number of samples, which correspond to a time window for the average.

> [!warning] For this tutorial we use however many samples are provided to the `processBlock()` call. If you want different averaging sizes, you need to use a lock free queue.

# Coding

## In PluginProcessor

- Add two floats `rmsLevelLeft` and `rmsLevelRight` in the header
- in `processBlock` call `buffer.getRMSLevel()`
![[IMG-2024-08-06-163610404.png]]

`n`is around 200-400.

This is a linear scale, we need to convert the result to decibels

- Add `float getRmsValue(channel)`

# Graphics Class and how to Animate

## HorizontalMeter

- Derive from juce::Component
- Override `paint` method
- Add a `setLevel` method

# Plugin Editor

- Contains two Meters, one for L and R
- Add the child components
- set bounds
- `paint` just calls `fillAll
- Derive Editor from timer to get the value from the processor redraw the meters
- Start the timer

# Value Looks Jittery -> Smoothing

- Logic:
	- If new value is larger, don't do any smoothing
	- If new value is smaller, we apply smoothing
- Juce offers a `LinearSmoothedValue` class
- Instead of the raw float values, we use the `LinearSmoothedValue<float>` instance for the rms values in the Processor
- When sample rate changes, we need to call `reset` on the rms value -> prepareToPlay
	- reset takes sampleRate ad a decay time
- in `processBlock` update the rms values
	- skip is needed, as we do not progress sample by sample, but in blocks
![[IMG-2024-08-06-165742025.png]]


* in getRmsValue: use the `getCurrentValue()` from `LinearSmoothedValue`
---
tags:
  - design-patterns
links: "[[00 Structural Design Patterns]]"
---
# Overview

- First structural design pattern
- Getting the interface you want by the interface you are given
- Same as e.g. with power adapters
- We can not support every possible interface
- “A construct which adapts an existing interface X to the required interface Y”

# Example: Drawing Points and Lines

MFC technology with `CAboutDilg`

Interface: `DrawPoints`
![Enter image alt description](IMG-2024-05-31-113429804.png)
- `DrawPoints`, but we have lines
- Define geometric objects
![Enter image alt description](IMG-2024-05-31-113430120.png)
- Vector object is made out of lines
![Enter image alt description](IMG-2024-05-31-113430304.png)
- `Rectangle`s are basically `VectorObject`s
![Enter image alt description](IMG-2024-05-31-113430511.png)
- => We need a conversion from `VectorObject`s to `Point`s,
- This is where the `Adapter` comes into play
![Enter image alt description](IMG-2024-05-31-113430670.png)
![Enter image alt description](IMG-2024-05-31-113430852.png)

Concrete implementation (of converting points to lines) is not that important
![Enter image alt description](IMG-2024-05-31-113431018.png)

# Add Caching

> [!warning] Problem
> No caching. Can be added with the adapter easily

Let’s build a caching adapter
![Enter image alt description](IMG-2024-05-31-113431275.png)

If no cache found, recalculate and add to static cache

> [!warning] General Problem
> The adapter often spawns temporary objects and if this is a problem.

> [!check]
> Caching is a massive improvement

# Summary

> [!summary]
> - Implementing an Adapter is easy
> 	- Determine the API you have and the API you need and then create a component which has a reference to the origin and provides access to the destination.
> - Be careful about caching and other optimizations to avoid spawning too much data and cleaning up correctly

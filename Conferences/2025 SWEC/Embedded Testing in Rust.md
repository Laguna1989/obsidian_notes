---
tags:
  - SWEC-2025
  - rust
---

> [!info] See also [[Rust]]

# TDD

- Normally: Specification implies
	- impl
	- tests
- In [[TDD]]
	- Specification implies test
	- Test do not compile (red)
	- Link
	- Write a minimal implementation that satisfies the test
- Uncle Bob
	- Do not write production code unless it makes test pass
	- Do not write more of a test sufficient to fail
- Requirements:
	- Specification
	- Quick Feedback
	- Modularity (Encapsulated Dependencies)
	- Discipline

# Challenges of Embedded Testing

- Software Design in Embedded is difficult (mostly done by technichians, not programmers)
- Tooling -> Debugging capabilities means testability
- Speed -> Embedded hardware is slow
- Execution Environment -> Test Doubles

# Task (Our Specification)

- SFM32F411 Board
- Four LEDs, should be on/off in specific states

# In Rust

- Emedded Rust Working Group provides Embedded Traits [Embedded HAL](https://github.com/rust-embedded/embedded-hal)
- Can be used for single bits or even bus communication
- Code can directly be moved to the board

# Test on Hardware

- It is not sufficient to test on the Host, always test on Hardware


---
tags:
  - Talk
---

- C++26 will ship on time in 2026
	- Train Model (if a feature is ready, it will be shipped with the release)
	- There is a good understanding of what will be in c++26
- Many of the features are already available in cutting edge compilers

# Priorities for c++26

- Bug Fixes
- Concurrency support (std::execution)
- ~~networking~~
- Reflection, ~~contracts~~, ~~pattern matching~~
- addition to ranges, format

# Priorities for This Talk

- Discuss the smaller features
- Focus more on everyday programmer features

# Language and Library

## Debugging

- functions taking a string argument now
	- `static_assert` can take a string that is printed
		- including std::format
	- `delete("reason why function is deleted")`
	- `delete` can be used on free functions
	- `assert`can take a string
- Conditional breakpoints
	- `std::breakpoint_if_debugging`
	- will be a platform independent breakpoints
	- `is_debugger_present`
- Structured Bindings
	- Use a structure binding as a condition
	- Nice Placeholder with no name
		- Use `_`
	- Attributes for Structured Bindings
		- `auto [a, b[[maybe_unused]], c]`
		- b is unused
	- `std::complex` can be converted to a structured binding

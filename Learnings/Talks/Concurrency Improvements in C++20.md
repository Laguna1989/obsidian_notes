---
tags:
  - Talk
  - concurrency
created: 2024-06-27
links: "[[Talks MOC]]"
---
# There is a Lot of New Features in Cpp20

- concepts, modules, ranges, coroutines
- Core language: Three Way comparison,...
- But also concurrency

# Atomics

- The foundations of the c++ memory model
- They define synchronization and ordering constraints
- They are the basic building block for all high-level threading inerfaces

## Atomics in Cpp11

- ```std::atomic_flag```
	- `clear` and `test_and_set`
	- The only data type guaranteed to be lock free
- all other `std::atomic<T>` with different specializations

## Cpp 20

- Adds atomic flags for floating point types and smart pointers

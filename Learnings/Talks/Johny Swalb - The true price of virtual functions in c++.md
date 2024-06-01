---
tags:
  - Talk
created: 2021-01-04
links: "[[Talks]]"
---
> [!info] VTables
> ![[IMG-2024-06-01-102526984.png]]

# Memory Layout and Performance

- Memory Layout is tremendously important for program performance
- VTables are not the core problems (compilers/cpus are very good at dealing with vtables)
- The real problem with performance is memory layout and jump destination guessing (jump prediction)
- Virtual functions cannot be inlined, thus they inhibit compiler optimizations

# Alternatives to `std::vector<T*>`

- `std::variant` with `std::visitor`
- `polymorphic_vector` It uses virtual dispatching, but doesn't use pointers.
	- Downside: increased memory performance
- Per-Type-Vector, very useful, if you do not need specific ordering in the vector
	- (e.g. `boost: :base_collection`)
	- [multivector](https://github.com/ibogosavljevic/johnysswlab/blob/master/2021-02-virtualfunctions/multivector.h)
> [!hint] See also [[Johnathan Gopel - Remove virtual]]

# Type Based Processing

- Don't mix types
- Each type has it's own vector and processing loop
- The compiler can freely inline
- Jump prediction works as expected

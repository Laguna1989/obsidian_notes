---
tags:
  - SoCraTes-2025
  - testing
---

> [!info] See Also [[tools/testing/Property Based Testing|Property Based Testing]] and [[2025-06-17_PropertyBasedTesting]]
- Problems with Example Based Tests
- PBT Frameworks
- Introduction to Generators/Shrinkers

# Example Based Tests

```
add (a, b)

test add(1,2) == 3
// ... parametrized test
```

# Developer from Hell

-  Only implements enough to makes tests pass
- Problem with TDD is that people takes a shortcut

# Properties

- Reverse List
	- List has same size
	- Result first elment is last elelemt of input
	- Reversing a list twice returns the original list
	- Reversing an empty list returns an Empty list
	- ...
- Add_Two
	- Symmetry a+b = b+a
	- Neutral Element (+0)
- With random input the expected result is not clear upfront
- Implementation should not be present in test

# BPT Framework Basics

- Generator
- Shrinker
- Arbitrary = Generator + Shrinker

# Philosophy

- In Science one cannot verify anything, but only falsify
- "Kritischer Rationalismus"

# c# Framework: FsCheck

- `[Property]` attribute for the test

# Generators

- Custom Generators allow to change distribution, limit range, ...

# Shrinking

- Tries to get a minimal example that fails the test
- Can be customized to shrink for specific properties (e.g. max limit instead of min limit)

# Repeat

- In FsCheck the repeat string is an attribute per test
- This allows to just run the specific test

# Live Example

> [!info] See also [[FizzBuzz]]

-> Mark Seeman Property Based Tests"ploeh Property Based Testing"
blog.ploeh.dk fizzbuzz property based testing

# Strategies Um Properties Zu Finden

 - There and Back again
	 - forward operation and backwards operation
	 - E.g. Reverse twice
 - Some Things never change
	 - Invariants
	 - Good for mapping or transformations
	 - E.g. sorting: Size, Permutation
 - Test Oracle
	 - Old and new version of a function
	 - legacy and refactored function
 - The more things change the more they stay the same
	 - Neutral element
	 - e.g. add 0
 - Nuclear Exception
	 - We expect that the called function does not throw an exception

# More Complex Types

Often just combinations of fundamental types

# When not to Use PBT

- When you don't have standard unit tests (start with Unit tests)
- When Unit tests are fully sufficient
- If you want to test a specific case
- When you cannot identify good properties
- When your models are not suitable
- When the SUT is slow

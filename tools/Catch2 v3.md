---
tags:
  - tool
  - cpp
  - testing
links: "[[tools]]"
---

- Modern c++14 testing framework
- No external dependencies
- header only or as a library
- test code is natural to read
	- ordinary strings as test names (no c++ identifier)
- Tagging of test cases
- divide test cases into sections
	- very easy common setup/teardown
- generator expressions
	- parametrization on steroids
	- can easily produce copies or references
	- associative helper functions

```
auto i = GENERATE(take(100, filter([](int i) { return i % 2 == 1; }, random(-100, 100))));
```

- Supports benchmarks
- Supports BDD-style
- Supports matchers
	- A lot of useful options for stl datatypes (vector, string, ...)
	- Easily write your own via a simple lambda
	- Combination of matchers
- Output is fully customizable via `Reporters`

---
marp: true
theme: uncover
class: invert
style: |
  :root {
    --color-background: #1a1a1a;
    --color-heading: #ffffff;
    --color-text: #e0e0e0;
    --color-link: #64b5f6;
  }
  section {
    background-color: var(--color-background);
    color: var(--color-text);
    font-family: 'Helvetica Neue', Arial, sans-serif;
  }
  h1, h2, h3, h4, h5, h6 {
    color: var(--color-heading);
  }
  a {
    color: var(--color-link);
  }
  code {
    background: rgba(255, 255, 255, 0.1);
    border-radius: 4px;
    padding: 0.2em 0.4em;
  }
  pre {
    background: #2d2d2d;
    border-radius: 8px;
    padding: 1em;
  }
title: Cpp Undefined Behavior
author:
  name: Simon Weis
  email: simon.weis@posteo.de
  github: laguna1989
date: 2025-07-29
tags:
  - presentation
  - code
  - testing
---

<!--
%% Begin Waypoint %%
- [[2025-07-29_CppUndefinedBehavior]]

%% End Waypoint %%
-->

<!--
Build with:
npx @marp-team/marp-cli@latest 2025-07-29_CppUndefinedBehavior.md --pdf --allow-local-files
-->

# Cpp Undefined Behavior

2025-07-29

---

# What Code Leads to Undefined Behavior (UB)?

---

# Let's Take a Look at Dangerous Code

---

## Dangerous Code Example 1

```cpp
int* p = nullptr;

int value = *p;
```

---

## Dangerous Code Example 2

```cpp
std::mutex mtx;

mtx.lock();
mtx.lock();
```

---

## Dangerous Code Example 3

```cpp
int a = 10;
int b = 0;

int c = a / b;
```

---

## Dangerous Code Example 4

```cpp
int x;
int y = x + 5;
```

---

## Dangerous Code Example 5

```cpp
int* ptr = new int(10);
delete ptr;

std::cout << *ptr << std::endl;
```

---

## Dangerous Code Example 6

```cpp
int arr[5] = {1, 2, 3, 4, 5};

std::cout << arr[10] << std::endl;
```

---

## Dangerous Code Example 7

```cpp
char* p = "Yello"; // pre c++11

p[0] = 'H';
```

---

# Dangerous Code Example 8

```cpp
int i = 5;

i++ + ++i;
```

---

# Dangerous Code Example 9

```cpp
int f(int a) {
	if (a < 5) return 0;
}
```

---

# Dangerous Code Example 10

```cpp
std::cout << sizeof(char) << std::endl;
```

---

# UB Examples

- Dereference a nullptr
- Lock twice in one thread
- Divide by zero
- Read uninitialized memory
- Use after free

---

# UB Examples (cont)

- Array access outside bounds
- Allegedly clever expressions
- ODR violations
- Non-void function without return statement

---

# Effects of UB

- SIGSEV
- Hard Crash
- Deterministic Program yields random results
- Invoking contained but uninvoked code
- Compiler/Linker refuse to build with unrelated errors
- Sudden call to `std::terminate`
- Finite Loops becoming infinite and vice versa
- Starting to play games [Link](https://feross.org/gcc-ownage/)

---

# Definitions

---

## Specification-Defined Behavior

 > The programming language completely defines what happens when executing this program.

---

## Ill Formed

> The code has syntax errors or diagnosable semantic errors.

- Compilation fails

---

## Ill Formed, no Diagnostics

> The code has semantic errors which cannot be diagnosed.

- e.g. ODR violations
- This is UB

---

## Implementation-Defined Behavior

> The exact behavior varies between compiler, operating system, or hardware and must be documented.

- E.g. exact number of bits in a `char`

---

## Unspecified Behavior

> The exact behavior varies between compiler, operating system, or hardware (no documentation).

- E.g. order of evaluations

---

## Undefined Behavior

> There are no restrictions on the behavior of the program.

> UB may be expected when the standard omits any explicit definition of behavior

---

# How to Avoid UB

- compiler warnings
- clang-tidy
- cppcheck
- sanitizers

---

# The Compiler's point of view

- UB -> Anything is allowed to happen
- The compiler is a big optimizer
- Aggressive optimizations, including "time travel"

---

# `std::unreachable`

> Invokes undefined behavior at a given point.

- Clearly stating the intent of the code

---

## Example from Our Code

```c++
assert(false); // assert logs
std::unreachable();
```

---

## Behavior

- with MSVC 17.14.7, c++23

Both Debug and Release
- print assert log
- terminate the program

---

## End of Time-Travel with c++26

- With C++26 output happening before undefined behavior is guaranteed to happen
- Earlier versions still show the same behavior

---

# References

- [C++ programmer′s guide to undefined behavior: part 1 of 11](https://pvs-studio.com/en/blog/posts/cpp/1129/)
- [GCC Easter Egg: C++ Undefined Defined Behavior » Feross.org](https://feross.org/gcc-ownage/)
- [Undefined behavior - Wikipedia](https://en.wikipedia.org/wiki/Undefined_behavior#Examples_in_C_and_C++)
- [Dangerous optimizations - C++ meetup - YouTube](https://www.youtube.com/watch?v=MddV3jwqcTk)

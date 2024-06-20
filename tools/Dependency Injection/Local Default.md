---
tags:
  - dependency-injection
---
# Overview

> [!info] A *Local Default* is a default implementation of a Dependency, which originates in the same module or layer

# Notes

- When building a class you might have a specific implementation in mind. It might be tempting to directly use that implementation, but it is rather helpful to create an interface. This helps with the [[Dependency Inversion Principle]]
- A class can consume a dependency via [[Constructor Injection]] but still provide a local default to be used.

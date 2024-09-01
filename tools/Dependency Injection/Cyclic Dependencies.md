---
tags:
  - tool
  - design-flaw
---
Cyclic dependencies occur when two objects are depending on each other.

```
A -> B
B -> A
```

This can be avoided by applying the [[Dependency Inversion Principle]], i.e. by the abstraction of an interface.

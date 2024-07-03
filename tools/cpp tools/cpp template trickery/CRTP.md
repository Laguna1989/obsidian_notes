---
tags:
  - cpp
  - templates
---
# Overview

> [!quote] Curiously recurring template pattern

> [!note] The CRTP enables Compile Time Polymorphism

> [!note]
> - Normal public inheritance forms as "is-a" relationship
> - CRTP means "the derived class expands its api" by using the Base classes functionality

# CRTP Consists of Two Things

- Inheriting from a templated base class
- Use the derived class itself as the template argument of the base class

```c++
template <typename T>
class Base { };

class Derived : Base<Derived> { };
```

The idea is to use the `Derived` class type in the `Base` class. With that, the base class can access the `Derived` class by casting into it.

```c++
template <typename T>
class Base
{
public:
    void doSomething()
    {
        T& derived = static_cast<T&>(*this);
        // use derived...
    }
};
```

# Possible Pitfalls

## Passing the Wrong Class as the Template Argument

```c++
class Derived1 : public Base<Derived1> { };

// bug in this line of code, should be Derived2
class Derived2 : public Base<Derived1> { };
```

## Shadowing Methods

- If the `Base` and `Derived` classes use the same method names, this results in shadowing.

# References

- [The Curiously Recurring Template Pattern (CRTP) - Fluent C++](https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/)

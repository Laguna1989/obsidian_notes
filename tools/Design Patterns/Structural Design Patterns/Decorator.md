---
tags:
  - design-patterns
links: "[[Structural Design Patterns]]"
---
# Overview

- Allows to augment an object with additional functionality
- No need to rewrite existing code
- Keeping existing functionality
- In C++ there are two options:
	- Aggregate decorated object
	- Inherit from the decorated object
- “Facilitates the addition of behavior to individual objects”

# Dynamic Decorator

- Base class `Shape` and implementation `Circle`
![Enter image alt description](IMG-2024-05-31-133321410.png)

- We can also add `Square`s
![Enter image alt description](IMG-2024-05-31-133321546.png)

- Now we want to have color. Bad idea: Add two more classes “colorsquare” and “colorcircle”
- Instead: Use Decorator
![Enter image alt description](IMG-2024-05-31-133321623.png)

- Dynamic because we use inheritance
- Let’s add TransparentShape
![Enter image alt description](IMG-2024-05-31-133321711.png)

- -> both colored and transparent
> [!warning] Downside
Once you decorate a type, you are restricted to the interface

# Static Decorator

- Use some c++ tricks to bake information about decorator into the type
	- Mixin Inheritance ([[CRTP]])
	- Perfect Forwarding
- [[CRTP]] allows to call members of the base class

![Enter image alt description](IMG-2024-05-31-133321774.png)

- Use concepts to check that decorator is used in the correct underlying types
- Let’s use constructor forwarding with argument packs to use constructors of the base class

![Enter image alt description](IMG-2024-05-31-133321846.png)

- We hope that the baseclass has a matching constructor that works with the passed arguments
![Enter image alt description](IMG-2024-05-31-133321897.png)

- We still need to write functions manually of course
- Applying decorator on a decorator:
![Enter image alt description](IMG-2024-05-31-133321948.png)

- Through inheritance, `bis` is a `Square`, a `ColoredShape2` and a `TransparentShape2`.
- Members can be modified easily, even if they are not part of the interface

# Functional Decorator

- For now we were decorating a class
- Now let’s make a functional decorator to decorate functions

![Enter image alt description](IMG-2024-05-31-133321990.png)

- Instead of storing `std::function`, we can use a Template (which has some challenges)
- Template argument of class can not be inferred
![Enter image alt description](IMG-2024-05-31-133322039.png)

- We can create a helper function that avoids the error by explicitly providing the template argument
![Enter image alt description](IMG-2024-05-31-133322094.png)

- Currently no arguments and no return value. Now it gets interesting
![Enter image alt description](IMG-2024-05-31-133322141.png)

- The decorator now needs to be more complicated. We will need to use variadic templates.
- Also we need to allow for partial specialization by providing a generic template (line 45)
![Enter image alt description](IMG-2024-05-31-133322180.png)

- We will need another helper function. We take a function pointer and create an std::function from it.
![Enter image alt description](IMG-2024-05-31-133322228.png)
![Enter image alt description](IMG-2024-05-31-133322272.png)

# Summary

> [!summary]
> - A dynamic decorator keeps the reference to the decorated object(s)
> - A static decorator uses mixin inheritance
> 	- `ColoredShape<Square>`
> - Both approaches allow limitless composition
> 	- `TransparentShape<ColoredShape<Circle>>`

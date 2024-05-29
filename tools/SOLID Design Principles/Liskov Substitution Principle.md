---
tags:
  - design-patterns
  - solid
---

> [!quote] Subtypes should be immediately usable for their parent types

- `Rectangle` and `Square` classes
- Now threre is the `process` function that takes a `Rectangle` and has some internal assumptions
![Enter image alt description](Images/CP8_Image_9.png)

- Extend by `Square` class:
	- This will break the existing functionality
	- In the code: Not every rectangle is a square ("behaves like")
- A `Square` does not need (or offer) independent `width` and `height` setters
![Enter image alt description](Images/tY1_Image_10.png)

> [!quote] If there is a base class, every derived class has to be fully substitutable for the base class.

> [!hint] How to fix this?
> - Inheriting `Square` from `Rectangle` is a **bad** idea.
> - In mathematics this dependency chain is acceptable
> 	- In our code, it is not acceptable, because of the assumptions in `process()`
> - A factory could solve this.
> 	- Always returns a rectangle, but sets the values on creation.

---
tags:
  - design-patterns
  - solid
---
## Interface Segregation Principle

- Create interfaces that are not too large

- Example: Documents and Machines (multi function printer)

- Initial Idea: Every machine needs to support all functions

![Enter image alt description](Images/nTT_Image_11.png)

- If there is a “only printer”, it needs to implement all of the functions, even if it does not support it

- Raising an exception s bad (liskov)

- Not implementing is also bad (no response)

- Solution: Separate interfaces

![Enter image alt description](Images/xBR_Image_12.png)

- If you want to have a “multi function machine”, it can simply implement bot interfaces

![Enter image alt description](Images/tqJ_Image_13.png)

- Combinations can be created using Decorators

![Enter image alt description](Images/aM1_Image_14.png)

- => Make interfaces smaller

---
tags:
  - design-patterns
  - solid
---
## Dependency Inversion Principle

- General:

- High level should not depend on low level. Both should depend on abstractions

- Abstractions should not depend on details. Details should depend on Abstractions

- Examples: Relationships and Persons

![Enter image alt description](Images/pGD_Image_15.png)

- Low level modules

![Enter image alt description](Images/nCl_Image_16.png)

- High level module: Research

![Enter image alt description](Images/jXO_Image_17.png)

- Introduce a new layer: Relationship Browser as an interface

![Enter image alt description](Images/jGF_Image_18.png)

- Research does now only use the relationship browser interface instead of the actual relationships data


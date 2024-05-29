---
tags:
  - design-patterns
  - solid
---

> [!quote] A class/function should have one reason to change

Focus on the primary responsibility
> [!example]+ Journal containing entries
>  ![Enter image alt description](Images/FHX_Image_1.png)

> [!warning] Problem description: Serializing the journal

- `Journal`class should **NOT** be responsible for serializing/deserializing!
- If that functionality is added, the journal has **two** responsibilities.
	- Avoid classes that have multiple responsibilities/concerns
	- Hard to change, because if you want to save to a file or a database you need to go through all files again
- Better: `PersistenceManager` class
![Enter image alt description](Images/GAg_Image_2.png)

> [!hint] This separates the concerns nicely.

> [!hint] Each class does only one thing.

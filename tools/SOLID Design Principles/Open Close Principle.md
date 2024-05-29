---
tags:
  - design-patterns
  - solid
---

> [!quote] Code should be open for extension but closed for modification

> [!example] Filtering products, e.g. by color or size
>  ![Enter image alt description](Images/3TD_Image_3.png)
>  - Problems occur when second filtering is needed, e.g. by size
>  ![Enter image alt description](Images/Nsc_Image_4.png)

> [!warning] Problem:
> - This does not scale well for more parameters
> - Modifying existing code -> bad

Let’s use the specification pattern
- Create two new classes: `Specification` and `Filter`
- Use inheritance to extend without modifying existing code
![Enter image alt description](Images/lhW_Image_5.png)

Introduce `BetterFilter` that does not need to be modified anymore
![Enter image alt description](Images/Bcc_Image_6.png)

Now we can create and combine `Specification`s, e.g.
![Enter image alt description](Images/H6o_Image_7.png)

- With this we can also write a `Specification` for Size or a `Specification` combination, like `AndSpecification`
- Note that most `Specification` are very generic, but combinations can be combined
![Enter image alt description](Images/HNw_Image_8.png)

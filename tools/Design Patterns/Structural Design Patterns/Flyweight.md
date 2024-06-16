---
tags:
  - design-patterns
links: "[[Structural Design Patterns MOC]]"
---

- Concerned with Space optimization, avoid redundancy when storing data
- E.g. MMORPG user name storage. Many names are very common, so let’s not waste space on storing all of them individually
	- Store a list of names, use indices or pointers to the names
- E.g. ranges/stringview
- A space optimization technique which lets us use less memory by storing externally the data associated with similar objects and reference to it, when needed
- Let’s stick with the mmorpg example

![Enter image alt description](IMG-2024-05-31-134031796.png)

- How to create users and get names?

![Enter image alt description](IMG-2024-05-31-134032003.png)

- Boost offers a convenient library for flyweights
![Enter image alt description](IMG-2024-05-31-134032013.png)

- Flyweight can also be used for text formatting
- Formatted text is initialized by plain text. Some part of the plain text should be capitalized.
- Naive approach: Store an array of bools as long as the text and check the array while printing
![Enter image alt description](IMG-2024-05-31-134032200.png)

- Actually we do not need to store a bool array for each class. Using a range is sufficient

- Create a nested class TextRange, which stores begin and end

![Enter image alt description](IMG-2024-05-31-134032258.png)

> [!summary]
>  - Store common data externally
> 	 - e.g. static map
>  - Define the idea of `ranges`on homogeneous collections
> 	 - store data related to those ranges

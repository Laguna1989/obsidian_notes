---
tags:
  - design-patterns
links: "[[Creational Design Patterns]]"
---

## Idea

- All about object copying
- Complicated Objects are not designed from scratch. Most of them start from an existing object. A prototype
- Create a copy of the prototype and then modify it
- Deep copies are needed, because we want to keep the prototype unchanged

> [!quote] A partially or fully initialized object that you can clone and make use of

> [!example] Employees with name and address
>  ![Enter image alt description](IMG-2024-05-31-134636037.png)

- With this we can easily create any `Contact`
- If they share the same address
![Enter image alt description](IMG-2024-05-31-134636245.png)

- Everything here works, because everything that is used are value objects
- Things break, if e.g. an address pointer is used, e.g.
![Enter image alt description](IMG-2024-05-31-134636258.png)

- This breaks the current modification for `jane`

![Enter image alt description](IMG-2024-05-31-134636404.png)

- `operator=` for assignment does a shallow copy, not a deep copy
- Create the copy constructor

![Enter image alt description](IMG-2024-05-31-134636524.png)

- Better: give Address it’s own copy constructor
![Enter image alt description](IMG-2024-05-31-134636623.png)

## Prototype Factory

- Having to create a prototype every time is not very convenient. This can be handled by having a global variable or a factory.
![Enter image alt description](IMG-2024-05-31-134636753.png)

- How to constrain users to only use the prototype
- Have a Prototype Factory
- Let’s start with an `EmployeeFactory` that takes a `prototype` argument
![Enter image alt description](IMG-2024-05-31-134637067.png)

- This allows to easily create instances with specifying just the necessary information, taking the rest from the Prototype

## Prototype via Serialization

- Pain Point: You have to implement the object copying yourself
	- Copy assignment
	- Copy constructor
	- Explicit clone() function
- Problematic when objects contain Pointers
- No reflection in C++, no magic silver bullet
- Writing code for Serialization/Deserialization
	- Boost serialization can help here
	- One function for saving/loading
	- Contact needs an empty constructor
	- For this all parts of the object graph needs to be serializable 🙁
![Enter image alt description](IMG-2024-05-31-134637335.png)

- Boost will automatically deserialize pointers
- & willt ake care of loading AND saving
- Application:
	- Cloning will serialize and then deserialize and by that, create a deep copy of the object
![Enter image alt description](IMG-2024-05-31-134637528.png)

- This can be a free function
- => Serialization is basically a free implementation of the Prototype pattern
- => Boost takes care of dereferencing pointers

## Summary

> [!summary]
> - To implement a prototype,
> 	- you need to create a partially or completely instantiated object and store it somewhere
> 	- You clone or deep copythe object
> 		- This involves some manual work in C++, copy ctor, copy assign, clone or serialization (which might be needed anyway)
> 	- Customize the result and use the new instance.

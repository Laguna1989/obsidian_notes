---
tags:
  - design-patterns
links: "[[Creational Design Patterns]]"
---

> [!quote]
> - Operation logics becomes too complicated/convoluted
> 	- E.g. constructor is not descriptive
> 	- Constructor does not allow for overloads with same arguments
> 	- Optionally parameters
> - Non-Piecewise construction is outsourced
> 	- Separate function
> 	- Separate class
> 	- Abstract factory
> - Component responsible for the wholesale creation of objects

> [!example] Life without factories
>  Create Point with cartesian or polar coordinates
>   ![Enter image alt description](IMG-2024-05-31-134636012.png)
>   You could add an enum class (type: cartesian/polar) and create one constructor that does both.
>   ![Enter image alt description](IMG-2024-05-31-134636187.png)
>    > [!warning] Bad: `a` and `b` are not descriptive. Constructor now does two things

## Factory Method

- Uses a method or member function to initialize the object
- E.g. in the point example.
	- Have a private constructor
	- Add static member functions to construct the object
![Enter image alt description](IMG-2024-05-31-134636354.png)

- This prohibits “normal” construction
- Better than the original version
- This of violates the [[Single Responsibility Principle]] as the class now needs to care about all construction possibilities and might blow the class up
- => Better Separation of Concerns:
	- Have a separate Factory Class
![Enter image alt description](IMG-2024-05-31-134636479.png)

- Private constructor not actually needed. `Point` can be a POD type

## Inner Factory

- Drawback: There is no obvious link from `Point` to `PointFactory`, which might confuse users
- Make `PointFactory` an Inner class
- This allows to avoid the friend class as inner classes have access to private members
- Inner class can be private and then use a singleton to expose the inner class instance that only exists once
![Enter image alt description](IMG-2024-05-31-134636585.png)

## Abstract Factory

- Bit of a convoluted example
- Example: Family of Hot Drinks
![Enter image alt description](IMG-2024-05-31-134636709.png)

- Lets create a similar Family of Hot Drinks
![Enter image alt description](IMG-2024-05-31-134636820.png)

- Abstract Factory is the `HotDrinkFactory`
- Add a free dispatching function or a class to decide which factory to instantiate
![Enter image alt description](IMG-2024-05-31-134637186.png)

> [!warning] Drawback: a lot of classes needed

## Functional Factory

- We used classes in the abstract factory, but this can be done in a procedural way.
- Use lambdas instead of inheritance
![Enter image alt description](IMG-2024-05-31-134637261.png)

## Summary

> [!Summary]
> - A factory is a (static) method to create objects
> - Takes care of wholesale object creation
> - Can be external or internal (inner class)
> - Hierarchies of Factories can be used to create related objects
> - Factories should not have any state

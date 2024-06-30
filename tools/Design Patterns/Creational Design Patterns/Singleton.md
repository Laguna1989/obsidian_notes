---
tags:
  - design-patterns
links: "[[Creational Design Patterns]]"
---

- Singleton is the only one that the GoF wanted to drop
- The use is almost always a design smell
- Reason to use:
	- For some systems, it makes sense to have a specific object only once
		- Database,Object Factory,
		- E.g. if constructions are expensive
		- Lazy initialization
	- Prevent users from creating objects multiple times
	- “A component that is instantiated only once”
	- Example: Read Cities and Citizens into a database
> [!note] Singletons should have deleted copy operations

![Enter image alt description](IMG-2024-05-31-134635971.png)

- Access to database
- Static get function
![Enter image alt description](IMG-2024-05-31-134636060.png)

# Testability Issues

> [!warning] Problem:
> Rather inflexible, especially for testing

![Enter image alt description](IMG-2024-05-31-134636277.png)

- Strongly coupled to the actual data file
- This is not a unit test, but an integration test as it needs the “production” database
- With the singleton it is not possible to disentangle this

# Singleton Dependency Injection

- Depending directly on the singleton is bad. [[Dependency Injection]] can help
- This will help by allowing to hook in a Mock Database
- In our example the `get_population()` is the function we are interested in varying
![Enter image alt description](IMG-2024-05-31-134636428.png)

- This allows to have a DummyDatabase to vary the behavior for the test
- We need to change the `RecordFinding`

> [!hint] Takeaway:
> The singleton itself is not a bad idea, but having a hard dependency on a singleton is bad.

# Singleton Lifetime in DI Containers

- Absolute minimum example of boost di
- Interface `IFoo` and concrete implementation
![Enter image alt description](IMG-2024-05-31-134636545.png)

- Lets have a `Bar` that wants a singleton instance of `foo`
- `main` will use a di injector that binds to a singleton instance

![Enter image alt description](IMG-2024-05-31-134636649.png)

# Monostate Design Pattern

> [!quote] Think about a printer

- Not a singleton, but all the members are static
![Enter image alt description](IMG-2024-05-31-134636778.png)

- Number of printers does not matter, but all instances go to the same instance
- Does not work with inheritance (static members are not inheriterd
- Bad idea because the users are not informed about the instance being a monostate

> [!warning] Monostate is basically a bad idea

# Multiton

> [!quote] Another variation of the singleton

- Sets up a key value store where you can optionally restrict the number of elements
- Example: We use an enum class Importance

![Enter image alt description](IMG-2024-05-31-134637105.png)

- We will build a class that returns a unique singleton for each of those values
- If item is already in the map, return it, otherwise create it
![Enter image alt description](IMG-2024-05-31-134637413.png)

![Enter image alt description](IMG-2024-05-31-134637565.png)

# Summary

> [!summary]
> - Making a “safe singleton is easy
> - Hide or delete copy and assignment and ctors
> - Create a static method that returns a reference to a static member
> - Meyers singleton is even threadsafe
> - Any class with direct dependencies to a singleton is very hard to test
> - Always depend on abstractions, not on direct implementation details (like a singleton)
> - Use DI Singleton lifetimes

---
tags:
  - design-patterns
---
# Builder

## Overview

> [!quote] When construction gets a bit too complicated

- Some Objects require a lot of ceremony to be created
- Having a Constructor with 10 arguments is not that good
	- Arguments can be confused
	- Bad to maintain
	- What about default values?
- Build allows for piecewise construction of an object succinctly

> [!example] Without a builder: creating html 
>  Manually add `<p> </p> tags  or <ul><li>` 
> ![Enter image alt description](bfg_Image_1.png) 
> Instead of piecing together a string that pieces together the different tags, lets represent the inherent html structure in classes

## Builder

- Create an `HtmlElement` class
![Enter image alt description](pfh_Image_2.png)

- How to build up the structure? This is where a builder comes into play -> `HtmlBuilder`
- User wants to use `std::string`s, so provide a constructor
- Children can be added
- Add a `str()` function
![Enter image alt description](smh_Image_3.png)

![Enter image alt description](Pae_Image_4.png)

- Better now: using #oop structures to avoid piecing together individual strings manually. Can be easily tested.
- Use a dedicated component to build the objects we want
- Fluent Interface:
	- Change return type from void to HtmlBuilder&
	- Give a Hint to the user to actually use the Builder
	- Give te HtmlElement a static build function

![Enter image alt description](gmI_Image_5.png)

- You can add an implicit conversion to return an HtmlElement on the HtmlBuilder
- FluentBuilder can be built use “reference api or pointer api (best with an unique_ptr)
- You can force the user e.g. by making the constructors in Element private and add Builder as a friend class

## Further Improvements

- Example: Still html, but now with attributes
![Enter image alt description](dof_Image_6.png)

- Create concrete types, e.g. paragraph
- Note: Use initializer list to avoid templates
![Enter image alt description](VkK_Image_7.png)

- Lets add an image tag
	- Image does not contain anything
	- Url in image is stored as an attribute
![Enter image alt description](XEl_Image_8.png)

- Now we have a very nice unique dsl
![Enter image alt description](hvX_Image_9.png)

- This heavily relies on uniform initialization

## Builder Facades

- When an object is too complex to build in one step you can have two builders where each builds a specific part
- Example: Person with address and employment information

![Enter image alt description](l21_Image_10.png)

- Be careful that this is not overengineer
- Introduce `PersonBuilder`, `PersonJobBuilder` and `PersonAddressBuilder`
- Static function to return `PersonBuilder` that just returns a new object.
- `PersonBuilder` is the base class for `Job`- and `AddressBuilder`
	- Storing the `Person` inside `PersonBuilder` is a bad idea because this duplicates the Person for every subclass
- Let’s introduce `PersonBuilderBase` that contains a `Person&`
- Now we can inherit from `PersonBuilderBase` and thus only store references, which is cheap.

![Enter image alt description](EyF_Image_11.png)

- `Address`- and `JobBuilder` come out of `PersonBuilderBase`
- `Address`- and `JobBuilder` will have fluent builder interfaces
![Enter image alt description](aoq_Image_12.png)

- This allows to write very nice usage
![Enter image alt description](6gd_Image_13.png)

- `PersonBuilder` is the Facade for the Builder

## Summary:

> [!summary] 
> - Builder is a separate component with the purpose of building objects
> - Fluent builders by return `*this`
> - Facets allow to combine builders together with the baseclass linking the different builder types together

# Factories

> [!quote]
> - Operation logics becomes too complicated/convoluted
> 	- E.g. constructor is not descriptive
> 	- Constructor does not allow for overloads with same arguments
> 	-  Optionally parameters
> - Non-Piecewise construction is outsourced
> 	- Separate function
> 	- Separate class
> 	- Abstract factory
> - Component responsible for the wholesale creation of objects


> [!example] Life without factories
>  Create Point with cartesian or polar coordinates
>   ![Enter image alt description](JXZ_Image_14.png)
>   You could add an enum class (type: cartesian/polar) and create one constructor that does both.
>   ![Enter image alt description](amT_Image_15.png)
>    > [!warning] Bad: `a` and `b` are not descriptive. Constructor now does two things

## Factory Method

- Uses a method or member function to initialize the object
- E.g. in the point example.
	- Have a private constructor
	- Add static member functions to construct the object
![Enter image alt description](PBZ_Image_16.png)

- This prohibits “normal” construction
- Better than the original version
- This of violates the [[Single Responsibility Principle]] as the class now needs to care about all construction possibilities and might blow the class up
- => Better Separation of Concerns:
	- Have a separate Factory Class
![Enter image alt description](e41_Image_17.png)

- Private constructor not actually needed. `Point` can be a POD type
## Inner Factory

- Drawback: There is no obvious link from `Point` to `PointFactory`, which might confuse users
- Make `PointFactory` an Inner class
- This allows to avoid the friend class as inner classes have access to private members
- Inner class can be private and then use a singleton to expose the inner class instance that only exists once
![Enter image alt description](eyv_Image_18.png)

## Abstract Factory

- Bit of a convoluted example
- Example: Family of Hot Drinks
![Enter image alt description](gEK_Image_19.png)

- Lets create a similar Family of Hot Drinks
![Enter image alt description](9zy_Image_20.png)

- Abstract Factory is the `HotDrinkFactory`
- Add a free dispatching function or a class to decide which factory to instantiate
![Enter image alt description](l6k_Image_21.png)

> [!warning] Drawback: a lot of classes needed
## Functional Factory

- We used classes in the abstract factory, but this can be done in a procedural way.
- Use lambdas instead of inheritance
![Enter image alt description](6nW_Image_22.png)

## Summary

> [!Summary]
> - A factory is a (static) method to create objects
> - Takes care of wholesale object creation
> - Can be external or internal (inner class)
> - Hierarchies of Factories can be used to create related objects
> - Factories should not have any state

# Prototype

## Idea
- All about object copying
- Complicated Objects are not designed from scratch. Most of them start from an existing object. A prototype
- Create a copy of the prototype and then modify it
- Deep copies are needed, because we want to keep the prototype unchanged

> [!quote] A partially or fully initialized object that you can clone and make use of

> [!example] Employees with name and address
>  ![Enter image alt description](RqK_Image_23.png)

- With this we can easily create any `Contact`
- If they share the same address
![Enter image alt description](1dK_Image_24.png)

- Everything here works, because everything that is used are value objects
- Things break, if e.g. an address pointer is used, e.g.
![Enter image alt description](2I4_Image_25.png)

- This breaks the current modification for `jane`

![Enter image alt description](uMA_Image_26.png)

- `operator=` for assignment does a shallow copy, not a deep copy
- Create the copy constructor

![Enter image alt description](XEs_Image_27.png)

- Better: give Address it’s own copy constructor
![Enter image alt description](ZPX_Image_28.png)

## Prototype Factory

- Having to create a prototype every time is not very convenient. This can be handled by having a global variable or a factory.
![Enter image alt description](Qjq_Image_29.png)

- How to constrain users to only use the prototype
- Have a Prototype Factory
- Let’s start with an `EmployeeFactory` that takes a `prototype` argument
![Enter image alt description](VX5_Image_30.png)

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
![Enter image alt description](z4J_Image_31.png)

- Boost will automatically deserialize pointers
- & willt ake care of loading AND saving
- Application:
	- Cloning will serialize and then deserialize and by that, create a deep copy of the object
![Enter image alt description](li3_Image_32.png)

- This can be a free function
- => Serialization is basically a free implementation of the Prototype pattern
- => Boost takes care of dereferencing pointers

## Summary:

> [!summary]
> - To implement a prototype,
> 	- you need to create a partially or completely instantiated object and store it somewhere
> 	- You clone or deep copythe object
> 		- This involves some manual work in C++, copy ctor, copy assign, clone or serialization (which might be needed anyway)
> 	- Customize the result and use the new instance.

# Singleton

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
	- 
> [!note] Singletons should have deleted copy operations

![Enter image alt description](7TN_Image_33.png)

- Access to database
- Static get function
![Enter image alt description](tJx_Image_34.png)

## Testability Issues

> [!warning] Problem:
> Rather inflexible, especially for testing

![Enter image alt description](Nco_Image_35.png)

- Strongly coupled to the actual data file
- This is not a unit test, but an integration test as it needs the “production” database
- With the singleton it is not possible to disentangle this

## Singleton Dependency Injection

- Depending directly on the singleton is bad. [[Mark Seeman - Dependency Injection]] can help
- This will help by allowing to hook in a Mock Database
- In our example the `get_population()` is the function we are interested in varying
![Enter image alt description](GLh_Image_36.png)

- This allows to have a DummyDatabase to vary the behavior for the test
- We need to change the `RecordFinding`

> [!hint] Takeaway: 
> The singleton itself is not a bad idea, but having a hard dependency on a singleton is bad.

## Singleton Lifetime in DI Containers

- Absolute minimum example of boost di
- Interface `IFoo` and concrete implementation
![Enter image alt description](qzK_Image_37.png)

- Lets have a `Bar` that wants a singleton instance of `foo`
- `main` will use a di injector that binds to a singleton instance

![Enter image alt description](91i_Image_38.png)

## Monostate Design Pattern

> [!quote] Think about a printer

- Not a singleton, but all the members are static
![Enter image alt description](36E_Image_39.png)

- Number of printers does not matter, but all instances go to the same instance
- Does not work with inheritance (static members are not inheriterd
- Bad idea because the users are not informed about the instance being a monostate

> [!warning] Monostate is basically a bad idea

## Multiton

> [!quote] Another variation of the singleton

- Sets up a key value store where you can optionally restrict the number of elements
- Example: We use an enum class Importance

![Enter image alt description](s0r_Image_40.png)

- We will build a class that returns a unique singleton for each of those values
- If item is already in the map, return it, otherwise create it
![Enter image alt description](Ndl_Image_41.png)

![Enter image alt description](Ne0_Image_42.png)

> [!summary] 
> - Making a “safe singleton is easy
> - Hide or delete copy and assignment and ctors
> - Create a static method that returns a reference to a static member
> - Meyers singleton is even threadsafe
> - Any class with direct dependencies to a singleton is very hard to test
> - Always depend on abstractions, not on direct implementation details (like a singleton)
> - Use DI Singleton lifetimes

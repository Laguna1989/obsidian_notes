---
tags:
  - design-patterns
links: "[[Creational Design Patterns MOC]]"
---
# Overview

> [!quote] When construction gets a bit too complicated

- Some Objects require a lot of ceremony to be created
- Having a Constructor with 10 arguments is not that good
	- Arguments can be confused
	- Bad to maintain
	- What about default values?
- Build allows for piecewise construction of an object succinctly

> [!example] Without a builder: creating html
>  Manually add `<p> </p> tags  or <ul><li>`
> ![Enter image alt description](IMG-2024-05-31-134528472.png)
> Instead of piecing together a string that pieces together the different tags, lets represent the inherent html structure in classes

# Builder

- Create an `HtmlElement` class
![Enter image alt description](IMG-2024-05-31-134528547.png)

- How to build up the structure? This is where a builder comes into play -> `HtmlBuilder`
- User wants to use `std::string`s, so provide a constructor
- Children can be added
- Add a `str()` function
![Enter image alt description](IMG-2024-05-31-134528657.png)

![Enter image alt description](IMG-2024-05-31-134528821.png)

- Better now: using #oop structures to avoid piecing together individual strings manually. Can be easily tested.
- Use a dedicated component to build the objects we want
- Fluent Interface:
	- Change return type from void to HtmlBuilder&
	- Give a Hint to the user to actually use the Builder
	- Give te HtmlElement a static build function

![Enter image alt description](IMG-2024-05-31-134528890.png)

- You can add an implicit conversion to return an HtmlElement on the HtmlBuilder
- FluentBuilder can be built use “reference api or pointer api (best with an unique_ptr)
- You can force the user e.g. by making the constructors in Element private and add Builder as a friend class

# Further Improvements

- Example: Still html, but now with attributes
![Enter image alt description](IMG-2024-05-31-134528968.png)

- Create concrete types, e.g. paragraph
- Note: Use initializer list to avoid templates
![Enter image alt description](IMG-2024-05-31-134529032.png)

- Lets add an image tag
	- Image does not contain anything
	- Url in image is stored as an attribute
![Enter image alt description](IMG-2024-05-31-134529104.png)

- Now we have a very nice unique dsl
![Enter image alt description](IMG-2024-05-31-134529167.png)

- This heavily relies on uniform initialization

# Builder Facades

- When an object is too complex to build in one step you can have two builders where each builds a specific part
- Example: Person with address and employment information

![Enter image alt description](IMG-2024-05-31-134529216.png)

- Be careful that this is not overengineer
- Introduce `PersonBuilder`, `PersonJobBuilder` and `PersonAddressBuilder`
- Static function to return `PersonBuilder` that just returns a new object.
- `PersonBuilder` is the base class for `Job`- and `AddressBuilder`
	- Storing the `Person` inside `PersonBuilder` is a bad idea because this duplicates the Person for every subclass
- Let’s introduce `PersonBuilderBase` that contains a `Person&`
- Now we can inherit from `PersonBuilderBase` and thus only store references, which is cheap.

![Enter image alt description](IMG-2024-05-31-134529270.png)

- `Address`- and `JobBuilder` come out of `PersonBuilderBase`
- `Address`- and `JobBuilder` will have fluent builder interfaces
![Enter image alt description](IMG-2024-05-31-134529324.png)

- This allows to write very nice usage
![Enter image alt description](IMG-2024-05-31-134529379.png)

- `PersonBuilder` is the Facade for the Builder

# Summary

> [!summary]
> - Builder is a separate component with the purpose of building objects
> - Fluent builders by return `*this`
> - Facets allow to combine builders together with the baseclass linking the different builder types together

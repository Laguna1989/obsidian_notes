---
tags:
  - book-chapter
---
# Intro

- Based on 1994 [[Gang Of Four]] Book
	- Smalltalk and oldschool c++
	- This course: Modern C++
- Design Patterns are universally relevant in all programming languages
- [[SOLID Design Principles]]
- Contents:
	- [[2 - Creational Design Patterns]]
		- Builder, Factory, Prototype, Singleton
	- [[1 - Structural Design Patterns]]
		- Adapter, Bridge, Composite, Decorator, Facade, Flyweight, Proxy
	- [[3 - Behavioral Design Patterns]]:
		- Chain of Responsibility
		- Command
		- Interpreter
		- Iterator
		- Mediator
		- Memento
		- Observer
		- State
		- Strategy
		- Template Method
		- Visitor
- End of section coding exercises
- Heavy use of clion editing features
- Simplification
	- Liberally using access modifiers for demo purposes
	- No use of move, …
- Prerequisites
	- Object orientation
	- Good understanding of c++ features, also modern features

# Solid Design Principles

![[SOLID Design Principles]]

# Gamma Categorization (from GoF book):

- Creational patterns (builder applies here)
	- Wholesale creation (single call) vs piecewise (step by step)
- Structural Patterns
	- Concerned with class members, patterns are wrappers mimicking the underlying class interface
	- Importance of good API design
- Behavioural Patterns
	- No central theme

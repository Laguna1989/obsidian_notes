---
tags:
  - design-patterns
  - solid
---
# Interface Segregation Principle

> [!quote] Create interfaces that are not too large

> [!Quote] No code should be forced to depend on methods it does not use.

> [!example] Example: Documents and Machines (Multi Function Printer "MFP")

## Bad Solution

Initial Idea: Every machine needs to support all functions

```cpp
struct IMachine
{
	virtual void print(Document& doc) = 0;
	virtual void scan(Document& doc) = 0;
	virtual void fax(Document& doc) = 0;
};

struct MFP : IMachine
{
	void print(Document& doc) override 
	{
		// implementation
	}
	void scan(Document& doc) override 
	{
		// implementation
	}
	void fax(Document& doc) override 
	{
		// implementation
	}
};
```

If there is a “only printer”, it needs to implement all of the functions, even if it does not support it

> [!danger] Problems:
> - Raising an exception s bad (liskov)
> - Not implementing is also bad (no response)

## Good Solution: Separate Interfaces

```cpp
struct IPrinter
{
	virtual void print(Document& doc) = 0;
};
struct IScanner
{
	virtual void scan(Document& doc) = 0;
};
struct IFax
{
	virtual void print(Document& doc) = 0;
};
```

Only Printer implementation is now easily possible

```cpp
struct Scanner : IScanner
{
	void scan(Document& doc) override
	{
		// implementation
	}
}
```

If you want to have a “multi function machine”, it can simply implement bot interfaces

```cpp
struct MFP : IPrinter, IScanner, IFax
{
	void print(Document& doc) override 
	{
		// implementation
	}
	void scan(Document& doc) override 
	{
		// implementation
	}
	void fax(Document& doc) override 
	{
		// implementation
	}
}
```

> [!check] Interfaces are way smaller

> [!check] No implementation needs to implement methods that they don't need

## Combinations Using Decorators

> [!hint] See [[Decorator]]

```cpp
struct IMachine : IPrinter, IScanner {};

struct Machine: IMachine
{
	IPrinter& printer;
	IScanner& scanner;

	Machine(IPrinter& printer, IScanner& scanner) : printer{printer}, scanner{scanner} {}

	void print(Document& doc) override
	{
		printer->print(doc);
	}
	
	void scan(Document& doc) override
	{
		scanner->scan(doc);
	}
}
```

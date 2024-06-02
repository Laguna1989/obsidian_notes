---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns]]"
---
# Overview

> [!quote] Typically a tool for structural traversal rather than anything else.

> [!quote] A pattern where a component (visitor) is allowed to traverse the entire inheritance hierarchy. Implemented by propagating a single `visit()` method throughout the hierarchy.

## Motivation

- Need to define a new operation on an entire class hierrarchy
	- e.g. make a document model printable to HTML/Markdown
- We do not want to keep modifying every class in the hierarchy
- Need to access to the non-common aspects of classes in the hierarchy
	- It is not possible to put every element in the document to a common single interface
- Create an external component to handle rendering
	- but preferably avoid type checks

# Intrusive Visitor

Example: Mathematical Expressions, e.g. `1+2+3`

```cpp
struct Expression
{
	virtual ~Expression() = default;
	
	// visit function
	virtual void print(std::ostringstream oss) = 0;
};

struct DoubleExpression : Expression
{
	double value;
	
	DoubleExpression(double value) : value{value} {}
	
	void print(std::ostringstream oss) override
	{
		oss << value
	};
}

struct AdditionExpression : Expression
{
	Expression* left;
	Expression* right;

	AdditionExpression(Expression* left, Expression* right): left{left}, right {right} {}
	
	~AdditionExpression()
	{
		delete left;
		delete right;
	}
	
	void print(std::ostringstream oss) override
	{
		oss << "(";
		left->print();
		oss << "+";
		right -> print();
		oss << ")";
	};
}

int main()
{
	auto e = new AdditionExpression(
		new DoubleExpression(1),
		new AdditionExpression(
			new DoubleExpression(2),
			new DoubleExpression(3)
		)
	);

	std::ostringstream oss;
	e->print(oss);
	std::cout << oss.str() << std::endl;
	delete e;
}
```

This works, but needs to modify existing code. That's why it is called *Intrusive* visitor.

> [!danger] This violates the [[Single Responsibility Principle]] as Expressions now also need to deal with printing.

# Reflective Visitor

```cpp

```

# Classic Visitor (Double Dispatch)

# Summary

> [!summary]
>  - asda

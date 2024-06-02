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

> [!danger] We would like to write the following, but cannot do so

```cpp
struct ExpressionPrinterBroken
{
	void print(DoubleExpression* de, std::ostringstream oss) const
	{
		oss << de->value;
	}
	
	void print(AdditionExpression* ae, std::ostringstream oss) const
	{
		oss << "(";
			print(ae->left, oss); // does not work, as left is an Expression, and at compile time we do not know what is stored in there.
	}
};
```

> [!check] Somewhat Better solution

```cpp
struct ExpressionPrinter
{
	std::osstringstream oss;
	
	std::string str() const { return oss.str(); }
	
	void print(Expression* e)
	{
		if(auto de = dynamic_cast<DoubleExpression*>(e))
		{
			oss << de-> value;
		} else if (auto ae = dynamic_cast<AdditionExpression*>(e))
		{
			oss << "(";
			print(ae->left);
			oss << "+";
			print(ae->right);
			oss << ")";
		}
	}
};
```

> [!danger] Downsides
> - `dynamic_cast` has a runtime cost
> - Not extensibel (e.g. the user cannot print a MultiplicationExpression)

> [!info] See also [[Non-intrusive Design]]

# Classic Visitor (Double Dispatch)

We really want a mechanism to extend the hierarchy's mechanisms, without changing existing classes and without big if statements (including a lot of dynamic casts).

> [!hint] The double dispatch tricks the system to perform the vtable lookup at runtime

```cpp
struct Expression
{
	virtual void accept(ExpressionVisitor* visitor) = 0;
};
```

A `ExpressionVisitor` is a component that is able to visit all elements of the hierarchy

```cpp
// fwd decl.
struct DoubleExpression;
struct AdditionExpression

struct ExpressionVisitor
{
	virtual void visit(DoubleExpression* de) = 0;
	virtual void visit(AdditionExpression* ae) = 0;
}
```

Let's see how this works with printing

```cpp
struct ExpressionPrinter : ExpressionVisitor
{
	std::ostringstream oss;
	std::string str() const { return oss.str(); }
	
	void visit(DoubleExpression* de) override
	{
		oss << de->value;
	}
	
	void visit(AdditionExpression* ae) override
	{
		oss << "(";
		ae->left->accept(this);
		oss << "+";
		ae->right->accept(this);
		oss << ")";
	}
};
```

The `visit()` functions are implemented inside the `accept()` functions of `AdditionExpression` and `DoubleExpression` classes.

> [!warning] It is important to **NOT** implement `accept()` in the base class, as we need to know which specific Expression we are in.

```cpp
struct DoubleExpression : Expression
{
	// stuff from above
	
	void accept(ExpressionVisitor* visitor) override
	{
		visitor->visit(this);
	}
};

struct AdditionExpression : Expression
{
	// stuff from above
	
	void accept(ExpressionVisitor* visitor) override
	{
		visitor->visit(this);
	}
};
```

## Using the Double Dispatch

```cpp
int main()
{
	auto e = new AdditionExpression(
		new DoubleExpression(1),
		new AdditionExpression(
			new DoubleExpression(2),
			new DoubleExpression(3)
		)
	);
	
	ExpressionPrinter ep;
	e->accept(ep);
}
```

# Acyclic Visitor

very different from the [[Gang Of Four]] [[Visitor]].

> [!hint] The Acyclic Visitor runs on RTTI

```cpp
template <typename Visitable>
struct Visitor
{
	virtual void visit(Visitable& obj) = 0;
};

struct VisitorBase // marker interface
{
	virtual ~VisitorBase() = deafult;
};
```

`Expression` base class

```cpp
struct Expression
{
	virtual ~Expression() = default;
	
	virtual void accept(VisitorBase& obj)
	{
		using EV = Visitor<Expression>;
		if(auto ev = dynamic_cast<EV*>(&obj))
			ev->visit(*this);	
	}
};
```

Let's implement the `DoubleExpression` and `AdditionExpression` classes

```cpp
struct DoubleExpression : Expression
{
	double value;
	
	virtual void accept(VisitorBase& obj)
	{
		using DEV = Visitor<DoubleExpression>;
		if(auto dev = dynamic_cast<DEV*>(&obj))
			dev->visit(*this);	
	}
};

struct AdditionExpression : Expression
{
	Expression* left;
	Expression* right;
	
	~AdditionExpression()
	{
		delete left;
		delete right;
	}
	
	virtual void accept(VisitorBase& obj)
	{
		using AEV = Visitor<AdditionExpression>;
		if(auto aev = dynamic_cast<AEV*>(&obj))
			aev->visit(*this);	
	}
};
```

Now for the `ExpressionPrinter`

```cpp
struct ExpressionPrinter : VisitorBase ,
							Visitor<DoubleExpression>,
							Visitor<AdditionExpression>
{
private:
	std::ostringstream oss;
	
public:
	void visit(DoubleExpression& obj) override
	{
		oss << obj.value;
	}
	
	void visit(AdditionExpression& obj) override
	{
		oss << "(";
		obj.left->accept(*this);
		oss << "+";
		obj.right->accept(*this);
		oss << ")";
	}
};
```

## Start Using it

```cpp
int main()
{
	auto e = new AdditionExpression(
		new DoubleExpression(1),
		new AdditionExpression(
			new DoubleExpression(2),
			new DoubleExpression(3)
		)
	);
	
	ExpressionPrinter ep;
	ep.visit(*e);
}
```

> [!hint] This allows for a more malleable hierarchy compared to te Double Dispatch

# Multimethods

if you want to add braces to the expression only when needed.

# Variant and std::visit

`std::variant` gets a list of template arguments of types you want to store

```cpp
std::variant<std::string, int> house;
// house = 123;
house = "Montefiore Castle";
```

`std::visit(callable, visitable)`

## With a Functor

```cpp
struct AddressPrinter
{
	operator() (std::string const& str)
	{
		// print house name
	}
	operator() (int number)
	{
		// print house number
	}
};

AddressPrinter ap;
std::visit(ap, house);
```

>[!hint] This is a specific visitor that only works with `std::variant`

## With Lambdas

```cpp
std::visit([](auto& arg)
{
	// figure out type of the argument
	using T = std::decay_t<decltype>(arg);
	// std::decay_t is to get rid of the reference.
	
	if consexpr (std::is_same_v<T, std::string>)
	{
		std::cout << "house name " << arg << "\n";
	} else if consexpr (std::is_same_v<T, int>)
	{
		std::cout << "house number " << arg << "\n";
	}
}, house);

```

# Summary

> [!summary]
>  - Propagate an `accept()` method throughout the entire hierarchy
>  - Create a visitor with `visit(Foo*)` , `visit(Bar*)`, ... for each element in the hierarchy
>  - Each `accept()` simply calls `visitor.visit(this)`

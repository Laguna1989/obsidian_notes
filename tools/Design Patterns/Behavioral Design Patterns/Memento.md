---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns MOC]]"
---
# Overview

>[!quote] Keem some sort of token of an object's state to return to that state

> [!quote] A token/handle representing the system state. This allows to roll back to the state when the token was generated. The token may or may not directly expose state information.

> [!hint] Typically a `Memento` is an immutable object

> [!hint] *Memento* and *Token* are often used with the same meaning

## Motivation

- An object or a system can go through some changes
	- e.g. bank account gets deposits and withdrawls
- There are different ways to navigate those changes
	- e.g. [[Command]] to record and be able to `undo()` the change
- Another approach is to store a snapshot -> `Memento`

# Memento

Let's start with a simple `BankAccount`

```cpp
class BankAccount
{
	int balance{0};
public:
	BankAccount(int balance) : balance{balance} {}
	void deposit(int amount)
	{
		balance += amount;
	}
};
```

Let's introduce the `Memento` object

```cpp
class Memento
{
	int balance;
	Memento(int balance) : balance{balance} {}
	
	friend class BankAccount;
};
```

>[!hint] Memento can also be an inner class, thus avoiding the `friend` class definition.

with this, the `deposit()` function should not return `void` anymore, but the `Memento`

```cpp
class BankAccount
{
	// same as above
	
	
	Memento deposit(int amount)
	{
		balance += account;
		return Memento{balance};
	}
};
```

How to restore the `BankAccount` state?
-> add a `restore` function

```cpp
class BankAccount
{
	// same as above
	
	void restore(Memento const& m)
	{
		balance = m.balance;
	}
};
```

Let's put this to use

```cpp
int main()
{
	BankAccount ba{100};
	auto m1 = ba.deposit(50); // 150
	auto m2 = ba.deposit(25); // 175
	
	ba.restore(m1); // 150;
	ba.restore(m2); // 175
}
```

> [!hint] This is some sort of *discrete* undo/redo mechanism.

# Undo and Redo

Threoretically we can use the `Memento` to build `undo()`/`redo()` functionality

Idea: Store every single memento inside the bank account

```cpp
class BankAccount2
{
	int balance{0};
	std::vector<std::shared_ptr<Memento>> changes;
	int current; // index to the timeline
	
	BankAccount2(int balance) : balance{balance}
	{
		changes.emplace_back(std::make_shared<Memento>(balance));
		current = 0;
	}
	
	std::shared_ptr<Memento> deposit(int amount)
	{
		balance += amount;
		auto m = std::make_shared<Memento>(balance);
		changes.push_back(m);
		++current;
		return m;
	}
	
	void restore(std::shared_ptr<Memento> const& m)
	{
		if(m)
		{
			balance = m->balance;
			// record this change
			changes.push_back(m);
			current = changes.size() - 1;
		}
	}
};
```

Now we can start implementing undo/redo

```cpp
class BankAccount2
{
	// code from above
	
	std::shared_ptr<Memento> undo()
	{
		if (current > 0) // cannot undo initialization
		{
			--current;
			auto m = changes[current];
			balance = m->balance;
			return m;
		}
		return {}; // constructs empty shared_ptr
	}
	
	std::shared_ptr<Memento> redo()
	{
		if(current +1 < changes.size())
		{
			++current;
			auto m = changes[current];
			balance = ->balance;
			return m;
		}
		return {}; // constructs empty shared_ptr
	}
};
```

Let's play with this

```cpp
int main()
{
	BankAccount ba{100};
	ba.deposit(50); // 150
	ba.deposit(25); // 175
	
	ba.undo(); // 150
	ba.undo(); // 100
	ba.redo(); // 150
}
```

# Automatic Memento

Previous examples show explicitly taking `Memento`s.

But we can also have a `Memento` that causes the restoration in the `Memento`s destructor.

- Building c++ objects
- `ScopeToken` type acts as `Memento`
	- has a reference to a `Printer`
		- `Printer` stores the current indentation level
	- On Creation `Printer.indent` is increased
	- On Destruction `Printer.indent` is decreased

> [!hint] RAII-controlled indentation

# Summary

> [!summary]
> - Mementos are used to roll back states arbitrarily
> - A memento is simply a Token and does not allow modification
> - A memento is not required to expose the states to which the system is reverted
> - If all states are stored as tokens, it is possible to implement `undo()`/`redo()` functionality
> 	- If the system has lots of states `Memento` does not make so much sense, as the states take up way too much memory.

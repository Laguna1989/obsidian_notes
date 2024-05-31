---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns]]"
---

## Overview

> [!quote] An object which represents an instruction to perform a particular action. The object contains all the information necessary for the action to be taken

- When assigning a field, no history is kept
- Cannot serialize a sequence of actions (calls)

Objects that represent an operation
- Very helpful for multi-level undo/redo, macro recordings and more

### Command Query Separation

[[Command Query Separation]]

## Command Design Pattern

Bank account example

```cpp
struct BankAccount
{
	int balance{0};
	int overdraft_limit{-500};

	void deposit(int amount)
	{
		balance += amount;
		std::cout << "deposited " << amount << ", balance is now: " << balance << std::endl;
	}
	void withdraw(int amount)
	{
		if(balance - amount >= overdraft_limit)
		{
			balance -= amount;
			std::cout << "withdrew " << amount << ", balance is now: " << balance << std::endl;
		}
	}
};
```

Let's create command objects for `deposit()`and `withdraw()` methods.

```cpp
struct Command
{
	virtual void call() = 0;
};

struct BankAccountCommand : Command
{
	BankAccount& account;
	enum Action {deposit, withdraw} action;
	int amount;

	void call() override
	{
		swith(action)
		{
			case deposit:
				account.deposit(amount);
				break;
			case withdraw:
				account.withdraw(amount);
				break;
		}
	}
};
```

We can start using this command

```cpp
int main()
{
	BankAccount ba;

	std::vector<BankAccountCommand> commands
	{
		BankAccountComman{ba, BankAccountCommand::deposit, 100},
		BankAccountComman{ba, BankAccountCommand::withdraw, 200},
	};

	std::cout << ba << std::endl;

	for(auto& command : commands)
	{
		command.call();
		std::cout << ba << std::endl;
	}
}
```

## Undo Functionality

A `undo()` method can easily be added to the `Command` interface

> [!warning] Be careful with `undo()` if operations can fail
> If a `withdraw` fails, undoing it would increase amount of money

Interface:

```cpp
struct Command
{
	virtual void call() = 0;
	virtual void undo() = 0;
};
```

Implementation for now assumes that `withdraw` and `deposit` are symmetric

```cpp
struct BankAccountCommand : Command
{
	// stuff as above

	// swapped switch cases
	void undo() override
	{
		swith(action)
		{
			case deposit:
				account.withdraw(amount);
				break;
			case withdraw:
				account.deposit(amount);
				break;
		}
	}
};
```

One solution is to make `withdraw()` return a `bool`

```cpp
struct BankAccount
{
	// stuff from above

	// returns a bool now
	bool withdraw(int amount)
	{
		if(balance - amount >= overdraft_limit)
		{
			balance -= amount;
			std::cout << "withdrew " << amount << ", balance is now: " << balance << std::endl;
			return true;
		}
		return false;
	}
};
```

The `Command` needs to store a flag if the transaction was successful

```cpp
struct Command
{
	virtual void call() = 0;
	virtual void undo() = 0;

	bool succeeded {false};
}
```

The `BankAccountCommand` checks for the returned value

```cpp
struct BankAccountCommand : Command
{
	// stuff from above 

	void call() override
	{
		swith(action)
		{
			case deposit:
				account.deposit(amount);
				succeeded = true;
				break;
			case withdraw:
				succeeded = account.withdraw(amount);
				break;
		}
	}

	// swapped switch cases
	void undo() override
	{
		if (!succeeded)
			return;

		swith(action)
		{
			case deposit:
				account.withdraw(amount);
				break;
			case withdraw:
				account.deposit(amount);
				break;
		}
	}
};
```

> [!danger] `undo()` operations need to be called in reverse order

## Composite Command

recording commands in macros

> [!hint] Merge of [[Composite]] and Command Pattern

```cpp
struct CompositeBankAccountCommand
: std::vector<BankAccountCommand>, Command
{
	CompositeBankAccountCommand(const initializer_list<BankAccountCommand> items) : vector{items} {}

	// command interface
	void call() override
	{
		for(auto&cmd : *this)
		{
			cmd.call();
		}
	}
	void undo() override
	{
		for(auto it = rbegin(); it != rend(); ++it)
		{
			it->undo();
		}
	}
}
```

>[!danger] inheriting from `std::vector` is dangerous

Let's do a `Transfer`, which is basically taking money from one account and putting it into another account.

```cpp
struct MoneyTransferCommand : CompositBankAccountCommand
{
	MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount)
	: CompositeBankAccountCommand
	{
		{
			BankAccountCommand{from, BankAccountCommand::withdraw, amount}
			BankAccountCommand{to, BankAccountCommand::deposit, amount}
		}
	}
	{}
}

int main()
{
	BankAccount ba1;
	BankAccount ba2;

	ba1.deposit(100);

	MoneyTransferCommand cmd{ba1, ba2, 50};

	cmd.call();

	cout << ba1 << std::endl; << ba2 << std::endl;
	
	cmd.undo();

	cout << ba1 << std::endl; << ba2 << std::endl;
}
```

> [!error] This works, but fails to `undo()` if the initial withdrawl is too big

### DependentCompositeCommand

> [!hint] Idea
> If the previous command fails, all following command(s) fail as well

```cpp
struct DependentCompositeCommand : CompositeBankAccountCommand
{
	void call() override
	{
		bool ok = true;
		for(auto& command : *this)
		{
			if(ok)
			{
				cmd.call()
				ok = cmd.succeeded;
			}
			else 
			{
				cmd.succeeded = false;
			}
		}
	}
};
```

> [!info] Note
> `undo()` does not need to be chanced


## Summary
- Encapsulate all details of an operation in a separate object
- Define instruction for applying the command (either in the command or somewhere else)
- Optionally define instructions for undoing the command
- Optionally create composite commnds (a.k.a. macros)
---
tags:
  - design-patterns
---
# Chain of Responsibility

## Overview

> [!example] Real world example
>  Unethical behavior by an employee. Who takes the blame?
>  - Employee, Manager or CEO?

> [!example] UI Button, who handles an `Event`?
> - Button can handle the event immediately, and stop any further processing
> - Underlying `Groupbox`
> - Underlying `Window`

> [!example] Collectible Card Game
> - Creature has attack and defense
> - Those values can be boosted by other cards
>
>To find resulting attack/defense values, you need to check all other cards, which boosted the card

> [!quote] Definition:
> A chain of components who all gets a chance to process a command, query and optionally having a default processing implementation and an ability to terminate the processing chain.

## Pointer Chain

- Classic Implementation from GoF book
- Singly linked list of pointers
- Example Creature roaming the ground, with attack and defense values

> [!hint] We do not use a `std::vector<>` as iterators can get invalidated

```cpp
struct Creature
{
	std::string name;
	int attack;
	int defense;

	Creature(std::string const& name, int attack, int defense): name{name}, attack{attack}, defense{defense} {}

	friend std::ostream& operator<<(...) = default;
};
```

- Some of the abilities are modified (e.g. by picking up a magic sword). This is done by the `CreatureModifier`, basically a singly linked list.
- `CreatureModifier` has a pointer to the next `Modifier` (or `nullptr` if the chain ends)
- `CreatureModifier` has a `Creature&` and a function `add` (to put something into the list)

```cpp
class CreatureModifier
{
	CreatureModifier* next{nullptr};
protected:
	Creature& creature;
public:
	CreatureModifier(Creature& creature) : creature{creature} {}
	void add(CreatureModifier* cm)
	{
		if(next) next->add(cm);
		else next = cm;
	}

	// applies modifiers
	virtual void handle()
	{
		// default behavior is to call handle next
		if (next) next->handle();
	}
};
```

Lets start with a `DoubleAttackModifier`

```cpp
class DoubleAttackModifier : public CreatureModifier
{
public:
	DoubleAttackModifier(Creature& creature) : CreatureModifier{creature} {}
	
	void handle() override
	{
		creature.attack *= 2;       // perform action
		CreatureModifier::handle();	// walk the chain
	} 
}
```

Another Modifier: `IncreaseDefenceModifier`

```cpp
class IncreaseDefenceModifier : public CreatureModifier
{
public:
	IncreaseDefenceModifier(Creature& creature) : CreatureModifier{creature} {}

	void handle() override
	{
		if(creature.attack <= 2)
			creature.defense++;
		CreatureModifier::handle();	// walk the chain
	}
}
```

- Start using them
- Root modifier is the base `Modifier` type

```cpp
int main()
{
	Creature goblin{"Goblin", 1, 1};
	CreatureModifier root{goblin};
	DoubleAttackModifier r1{goblin};
	DoubleAttackModifier r2{goblin};
	IncreaseDefenseModifier r3{goblin};
	
	root.add(r1);
	root.add(r2);
	root.add(r3);

	root.handle();
}
```

> [!danger] Problem
> Modifiers of the same `root` can actually work on different `Creature`s.

Stop processing via a `NoBonusesModifier`

```cpp
class NoBonusesModifier : public CreatureModifier
{
	public:
	DoubleAttackModifier(Creature& creature) : CreatureModifier{creature} {}
	
	void handle() override
	{
		// explicitily no baseclass call
	} 
}
```

> [!hint]
> Every `CreatureModifier` added **after** a `NoBonusModifier` is discarded

## Event Broker Chain

> [!quote] Much more sophisticated implementation of the Chain of Responsibility

Also uses the [[Observer]] , [[Mediator]] and [[Command Query Separation]].

```cpp

struct Query
{
	string creature_name;
	enum Argument { attack, defense } argument;
	int result;

	Query(string creature_name, Argument argument, int result) = default;
};

struct Game 
{
	// from boost
	signal<void(Query&)> queries;
};

struct Creature
{
	Game& game; // Mediator
	string name;
	int attack;
	int defense;
	

	int get_attack()
	{
		Query q{ name, Query::Argument::attack, attack };
		game.queries(q);
		return q.result;
	}

	friend ostream& operator<<(ostream& os, const Creature& creature)
	{
		os << "attack:" creature.get_attack() << std::endl;
		return os;
	}
};
```

No `CreatureModifiers` so far

```cpp
class CreatureModifier
{
	Game& game;
	Creature &creature;
public:
	CreatureModifier(Game& g, Creature& c) : game{g}, creature{c} {}
	virtual ~CreatureModifier() = default;
};

class DoubleAttackModifier : public CreatureModifier
{
	connection conn;
	CreatureModifier(Game& g, Creature& c) : CreatureModifier{g, c} 
	{
		// this connects to the queries
		conn = const game.queries.connect([&](Query& q)
		{
			if(q.creature_name == creature.name && q.argumet == Query::Argument::attack)
				q.result *= 2;
		});
	}

	~DoubleAttackModifier() 
	{
		conn.disconnect();
	}
}
```

Let's put all of this to use

```cpp
int main()
{
	Game game;
	Creature goblin{game, "Strong Goblin", 2, 2};

	std::cout << goblin << std::endl;

	{
		DoubleAttackModifier dam{game, goblin};
		std::cout << goblin << std::endl;
	}  // dam destructor called, disconnects signal
	
	std::cout << goblin << std::endl;
}
```

## Summary

> [!summary]
> Chain of responsibility can be implemented as
> - Chain of pointers/references (singly linked list)
> - Centralized list via event Broker Chain
>
>
> Enlist objects in the chain, possibly controling their order
>
>Object removal from chain

# Command

## Overview

> [!quote] An object which represents an instruction to perform a particular action. The object contains all the information necessary for the action to be taken

- When assigning a field, no history is kept
- Cannot serialize a sequence of actions (calls)

Objects that represent an operation
- Very helpful for multi-level undo/redo, macro recordings and more

### Command Query Separation

![[Command Query Separation]]

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
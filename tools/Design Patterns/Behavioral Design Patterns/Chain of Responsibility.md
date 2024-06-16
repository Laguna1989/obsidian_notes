---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns MOC]]"
---
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

Also uses the [[Observer]], [[Mediator]] and [[Command Query Separation]].

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

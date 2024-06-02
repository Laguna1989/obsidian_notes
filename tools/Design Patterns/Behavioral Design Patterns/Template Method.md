---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns]]"
---
# Overview

>[!quote] A high level blueprint for an algorithm to be completed by inheritors

> [!quote] Allows us to define the *Skeleton* of the algorithm with concrete implementations defined in subclasses

## Motivation

- Algorithms can be decomposed into common parts and specifics
- The [[Strategy]] patterns does this through composition
	- High level algorithm uses an interface
	- Concrete implementations implement the interface
- Template Method does this though inheritance
	- Overall algorithm makes use of abstracn members
	- Inheritors override the abstract members
	- Parent template method invoked

# Template Method

```cpp
class Game
{
public:
	Game(int number_of_players) : number_of_players{number_of_players} {}
	
	void run()
	{
		start();
		while(!have_winner())
			take_turn();
		cout << "Player " << get_winner() << " wins.\n";
	}
protected:
	int number_of_players;
	int current_player{0};
	
	virtual void start() = 0;
	virtual bool have_winner() = 0;
	virtual void take_turn() = 0;
	virtual int get_winner() = 0;
};
```

## Chess Example

```cpp
class Chess : public Game
{
public:
	Chess() : Game{2} {}

protected:
	void start() override 
	{
		std::cout << "start chess with " << number_of_players << " Players.\n";
	}
	bool have_winner() override 
	{
		return turn == max_turns;
	}
	void take_turn() override 
	{
		std::cout << "turn " << turn << " by player " current_player << "\n";
		++turn;
		current_player = (current_player + 1) % number_of_players;
	}
	int get_winner() override 
	{
		return current_player;
	}

private:
	int turn{0};
	int max_turns{10};
};
```

## Using the Template Method

```cpp
int main()
{
	Chess chess;
	chess.run();
}
```

# Summary

> [!summary]
>  - Define an algorithm at a high level in a base class
>  - Define constituent parts as abstract methods
>  - Inherit the algorithm class providing neccessary overrides

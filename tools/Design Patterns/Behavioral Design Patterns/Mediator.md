---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns MOC]]"
---
# Overview

> [!quote] Facilitates communication between componets, without them being aware of each other or having direct (reference) access to each other

Motivation:
- Components may go in and out of a system at any time
	- E.g. in a chatroom, participants can join or leave at any time

> [!check] Solution
> Have all participants refer to a central component that facilitates communication

# Chat Room

> [!example] Classic Example: Chat Room

Start by a `Person` class

```cpp
/// Person.hpp

// fwd declare
struct ChatRoom;

struct Person
{
	std::string name;
	ChatRoom* room{nullptr};
	std::vector<std::string> chat_log;
	
	Person(std::string const& name) : name{name} {}
	void say(std::string const& message) const;  // broadcast operation
	void pm(std::string const& who, std::string const& message) const; // one to one operation
	void receive(std::string const& origin, std::string const& message);

	bool operator==(Person const& rhs); // compares just the name
	bool operator!=(Person const& rhs); // compares just the name
};


// Person.cpp

#include "chatroom.h"
void Person::say(std::string const& message) const
{
	room->broadcast(name, message);
}
void Person::pm(std::string const& who, std::string const& message) const
{
	room->pm(name, who, message);
}
void Person::receive(std::string const& origin, std::string const& message)
{
	
	std::string s{origin + ": '"+ message + "'"};
	std::cout << s << std::endl;
	chat_log.emplace_back(s);
}
```

`ChatRoom` implementation

> [!hint] The chatroom acts as the * Mediator*

```cpp
// chatroom.hpp

struct Person;

struct ChatRoom
{
	std::vector<Person*> people;
	
	void broadcast(std::string const& origin, std::string const& message)
	void join(Person* p);
	void message(std::string const& origin, std::string const& who, std::string const& message);
};

// chatroom.cpp

void ChatRoom::broadcast(std::string const& origin, std::string const& message)
{
	for(auto p : people)
	{
		if (p->name != origin)
			p->receive(origin, message);
	}
}

void ChatRoom:join(Person* p)
{
	std::string join_msg = p->name + " joins the chat";
	broadcast("room", join_msg);
	p->room = this;
	people.push_back(p);
}

void ChatRoom::message(std::string const& origin, std::string const& who, std::string const& message)
{
	auto target = std::find_if(std::begin(people), std::end(people), [&](Person const* p){return p->name == who});
	if(target != std::end(people))
	{
		(*target)->receive(origin, message);
	}
}
```

Using this

```cpp
int main()
{
	ChatRoom room;
	Person john{"john"};
	Person jane{"jane"};
	room.join(john);
	room.join(jane);
	
	john.say("hi room");
	jane.say("oh hi john");
	
	Person jill{"jill"};
	jill.say("hi everyone");
	
	jane.pm("jill", "glad you found us");
	
}

```

> [!hint] All participants communicate exclusively via the `ChatRoom`

# Event Broker

Already shown as part of [[Chain of Responsibility]]

Here we focus on handling events centrally

Example: Football gang and the football coach. Using `boost::signal`

```cpp

struct EventData
{
	virtual void print() const = 0;
};

struct PlayerScordData : EventData
{
	std::string player_name;
	int goals_scored_so_far;
	virtual print() const override
	{
		std::cout << player_name << "has scored their " << goals_scored_so_far << " goal\n";
	}
};

struct Game{
	signal<void(EventData*)> events;
};

struct Player
{
	std::string name;
	int goals_scored{0};
	Game& game;
	
	void score()
	{
		goals_scored++;
		PlayerScoredData ps{name, goals_scored};
		game.events(&ps);
	}
};

struct Coach
{
	Game& game;
	
	Coach(Game& game) : game{game} 
	{
		// The coach is specifically interested in the PlayerScoredEvents
		game.events.connect([](EventData* e)
		{
			PlayerScoredData ps = dynamic_cast<PlayerScoredData*>(e);
			if(ps && ps->goals_scored_so_far < 3)
			{
				std::cout << "coach says: well done, " << ps->player_name << "!\n";
			}
		});
	}
};

```

Let's hook this up

```cpp
int main()
{
	Game game;
	Player player{"sam", game};
	Coach coach{game};
	
	player.score();
	player.score();
	player.score();  // last call will no longer trigger the coach congratulating the player
}
```

# Summary

> [!summary]
> - Create the `Mediator` and have all objects refer to it
> 	- e.g. via [[Dependency Injection]]
> - `Mediator` engages in bidirectional communication with the connected `Component`s
> 	- `Mediator` has functions the `Component`s can call
> 	- `Component`s have functions the `Mediator` can call
> - Event processing libraries make communication easier to implement

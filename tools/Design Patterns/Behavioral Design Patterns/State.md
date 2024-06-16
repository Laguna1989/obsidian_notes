---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns MOC]]"
---
# Overview

> [!quote] Fun with finite state machines

> [!quote] A pattern in which the object's behavior is determined by its state. The Objects transitions from one state to another

 > [!quote] A formalized construct which manages state and transitions is called *state machine*

## Motivation

- Consider an ordinary Telephone
- What you can do with the telephone, depends on the state of the phone/line
	- You need to pick it up if you want to pick it up
	- Phone must be off the hook to make a call
	- If you try calling out and the line is busy, you put the handset down
- Changes in state can be explicit or in response to events ([[Observer]] patter)

# Classic State Implementation

> [!note] The original [[Gang Of Four]] implementation differs from modern state machine implementations

Example: switch the lights on and off

```cpp

// fwd decl
class LightSwitch;

struct State
{
	virtual void on(LightSwitch* ls)
	{
		std::cout << "light is already on\n";
	}
	virtual void off(LightSwitch* ls)
	{
		std::cout << "light is already of\n";
	}
};

struct OnState : State
{
	OnState()
	{
		std::cout << "Light is turned on\n";
	}
	

	virtual void off(LightSwitch* ls) override
	{
		ls->set_state(new OffState());
		delete this; // careful: do not do this unless you know what you do
	}
};

struct OffState : State
{
	OffState()
	{
		std::cout << "Light is turned off\n";
	}
	
	virtual void on(LightSwitch* ls) override
	{
		ls->set_state(new OnState());
		delete this;
	}
};

class LightSwitch
{
	State* state;
public:
	LightSwitch()
	{
		state = new OffState();
	}
	
	void set_state(State* state)
	{
		this->state = state;
	}
	
	void on()
	{
		state->on(this);
	}
	void off()
	{
		state->off(this);
	}
}

```

## Put it to Use

```cpp
int main()
{
	LightSwitch ls;
	ls.on();
	ls.off();
	ls.off();
}
```

> [!note] `LightSwitch` acts as some sort of [[Mediator]]

# Handmade State Machine

> [!note] Simpler and more efficient than the default virtual functions above

```cpp
enum class State 
{
	off_hook,
	connectiong,
	connected,
	on_hold,
	on_hook
};

inline std::ostream& operator<<(std::ostream& os, State const& s)
{
	// prints the respective state
}

```

Let's define `Trigger`s

```cpp
enum class Trigger
{
	call_dialed,
	hung_up,
	call_connected,
	placed_on_hold,
	taken_off_hold,
	left_message,
	stop_using_phone
};

inline std::ostream& operator<<(std::ostream& os, Trigger const& t)
{
	// prints the respective trigger
}
```

## Model the State Machine in Main

```cpp
int main()
{
	std::map<State, std::vector<std::pair<Trigger, State>>> rules;
	
	rules[State::off_hook] = {
		{Trigger::call_dialed, State::connecting},
		{Trigger::stop_using_phone, State::on_hook},
	};
	// more rules as desired
	
	State currentState{State::off_hook};
	State exitState{State::on_hook};
	
	while(true)
	{
		std::cout << "the phone is currently " << currentState << "\n";
		std::cout << "Select a trigger \n";
		int i = 0;
		for(auto item : rules[currentState])
		{
			std::cout << i++ << item.first << "\n";
		}
		int input;
		std::cin >> input;
		if(input < 0 || (input+1) > rules[currentState].size())
		{
			std::cout << "Incorrect option\n"
			continue;
		}
		currentState = rules[currentState][input].second;
		if(currentState == existingState) break;
	}
std::cout << "Done using the phone\n";
}

```

# Summary

> [!summary]
> - Given sufficient complexity of a system, it pays to formally define possible states and events/triggers
> - Can define
> 	- State entry/exit behavior
> 	- Actions when a particular event causes a transition
> 	- Guard conditions (enable/diable a transitions)
> 	- Default actions

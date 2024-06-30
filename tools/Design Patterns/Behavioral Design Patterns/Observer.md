---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns]]"
---
# Overview

> [!quote] Getting notification when things happen

> [!quote] An *observer* is an object that wishes to be informed about events happening in the system. The entity generating the evnts is an *observable*.

## Motivation

- We need to be informed when a certain thing happens
	- Object's field changes
	- Object does something
	- An external event occurs
- We want to listen to events and notified when they occur

> [!hint] Terminologies
> - *event* and *subscriber*
> - *signal* and *slot* (boost, qt)

# Observer

```cpp
struct Person{
	int age;
public:
	int get_age() const
	{
		return age;
	}
	void set_age(int age)
	{
		Person::age = age;
	}
};
```

We need two components *observer* and *observable*.

Let's start with the `Observer` base class

```cpp
template<typename T>
class Observer
{
	virtual void field_changed(T& source, std::string const& field_name) = 0;
};
```

Lets make a simple `Observer` implementation that prints to the console

```cpp
struct ConsolePersonObserver : public Observer<Person>
{
	virtual void field_changed(T& source, std::string const& field_name)
	{
		std::cout << "Person's " << field_name << " has changed to ";
		if(field_name == "age")
			std::cout << source.get_age();
		 std::cout << "\n";
	}
};
```

# Observable

We alredy have the `Observer` Interface. Now let's build the `Observable` interface.

```cpp

// fwd declaration
template <typename T>
class Observer;

template <typename T>
class Observable
{
private:
	// list of subscribers
	std::vector<Observer<T>*> observer;
	
public:
	void notify(T& source, std::string const& field_name)
	{
		for(auto observer : observers)
		{
			observer->field_changed(source, field_name);
		}
	}
	
	void subscribe(Observer<T>& observer)
	{
		observers.push_back(&observer);
	}
	void unsubscribe(Observer<T>& observer)
	{
		observers.erase(
			remove(observers.begin(), observers.end(), observer),
			observers.end();
		);
	}
};
```

Modify the `Person` class, using [[CRTP]]

```cpp
struct Person : public Observable<Person>
{
	// rewrite set_age
	void set_age(int age)
	{
		if(Person::age == age)
			return;
		
		Person::age = age;
		notify(*this, "age");
	}
};
```

# Usage

```cpp
int main()
{
	Person person{10};
	
	ConsolePersonObserver cpo;
	person.subscribe(cop);
	
	person.set_age(11);
	person.set_age(12);
	person.unsbscribe(cpo);
	person.set_age(13);  // no printout generated here
}
```

# Observable Using `boost::signals2`

Build a new version of `Person`

```cpp
template <typename T> 
struct Observable2
{
	signal<void(T&, std::string const&)> field_changed;
};


struct Person2 : public Observable2<Person>
{
	int age;
public:
	void set_age() const
	{
		if(Person::age == age)
			return;
		
		Person::age = age;
		field_changed(*this, "age");
	}
};
```

How to subscribe in this case?

> [!hote] no new `Observer` class needed

```cpp
int main()
{
	Person p2;
	auto conn = p2.field_changed.connect([](Person2& p, std::string const& field_name)
	{
		std::cout << field_name << "has changed\n";
	});
	p2.set_age(20);
	conn.disconnect();
	p2.set_age(21);
}
```

# The Problem of Dependent Properties

There is a problem with dependent properties.

Introduce a flag if a person can vote

```cpp
class Person // code as above
{
	// code from above
public:
	bool get_can_vote() const
	{
		return age >= 16;
		
	}
};
```

> [!danger] Problem
> There is no way to call notify from within `get_can_vote`

> [!check] Solution
> The right place to call notify are setters

Rewrite `set_age()`

```cpp
struct Person // as above
{
	// code as above
	
	void set_age(int age)
	{
		if(Person::age == age)
			return
		
		// cache old can_vote
		auto old_can_voge = get_can_vote();
		this->age = age;
		notify(*this, "age");
		
		if(old_can_vote != get_can_vote())
			notify(*this, "can_vote");
	}
};
```

Put this to use

```cpp
int main()
{
	Person person{10};
	
	ConsolePersonObserver cpo;
	person.subscribe(cop);
	
	person.set_age(15);
	person.set_age(16);
}
```

> [!warning] Warning: This approach does not scale

# Thread Safety and Reentrancy

We have not talked about thread safety yet. What if `subscribe`, `unsubscribe` and `notfy` are called from different threads?

Introduce a new class `SaferObservable`, which uses a mutex and a `scoped_lock`.

```cpp
// fwd declaration
template <typename T>
class Observer;

template <typename T>
class SaverObservable
{
	// code from above 
	
private:
	// list of subscribers
	std::vector<Observer<T>*> observer;
	typedef std::mutex mutex_t;
	mutex_t mtx;
	
public:
	void notify(T& source, std::string const& field_name)
	{
		std::scoped_lock<mutex_t> lock{mtx};
		for(auto observer : observers)
		{
			observer->field_changed(source, field_name);
		}
	}
	
	void subscribe(Observer<T>& observer)
	{
		std::scoped_lock<mutex_t> lock{mtx};
		observers.push_back(&observer);
	}
	void unsubscribe(Observer<T>& observer)
	{
		std::scoped_lock<mutex_t> lock{mtx};
		observers.erase(
			remove(observers.begin(), observers.end(), observer),
			observers.end();
		);
	}
};
```

Problem of re-entrancy? What if we call `unsubscribe` from within `notify`?

```cpp
struct TrafficAdministration : Observer<Person>
{
	void field_changed(Person& source, std::string const& field_name) override
	{
		if(field_name == "age")
		{
			if(source.get_age() < 17)
			{
				std::cout << "whoa, you are too young to drive!\n";
			}
			else
			{
				std::cout << "ok, we no longer care!\n"
				source.unsubscribe(*this);
			}
		}
	}
};
```

> [!note] Never hold a mutex while invoking callouts

## Solution 1

In `SaferObservable::unsubscribe()`, do not call unsubscribe, but set the observer to `nullptr`

```cpp

void notify(T& source, std::string const&)
{
	std::scoped_lock<mutex_t> lock{mtx};
	for(auto observer : observers)
	{
		if(observer)
			observer->field_changed(source, field_name);
	}
}

void unsubscribe(Observer<T>& observer)
{
	auto it = std::find(std::begin(observers), std::end(observer), observer);
	if( it != std::end(observers))
	{
		*it = nullptr;
	}
}
```

## Solution 2 Use a Recursive Mutex

# Summary

>[!summary]
> - Two participants
> 	- Observable provides a way of subscribing to an event(signal)
> 	- Observer performs the subscription
> - `Observable` implementation is always intrusive
> 	- `Observer` doesn't need to be
> - Multithreaded / reentrant use case can cause issues
> - Ready-made implementations of Observer are available

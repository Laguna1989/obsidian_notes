---
tags:
  - design-patterns
  - solid
---
# Dependency Inversion Principle

> [!quote] General Idea
> - High level should not depend on low level. Both should depend on abstractions
> - Abstractions should not depend on details. Details should depend on Abstractions

# Example: Relationships and Persons

```cpp
enum class Relationship
{
	parent,
	child,
	sibling
};
```

Low level modules

```cpp
struct Person
{
	std::string name;
};

struct Relationships // low level
{
	std::vector<std::tuple<Person, Relationship, Person>> relations;

	void add_parent_and_child(Person const& parent, Person const& child)
	{
		relations.push_back({parent, Relationship::parent, child});
		relations.push_back({child, Relationship::child, parent});
	}
};

int main()
{
	Person parent{"John"};
	Person child1{"Chris"};
	Person child2{"Matt"};
	Relationships relationships;
	relationships.add_parent_and_child(parent, child1);
	relationships.add_parent_and_child(parent, child2);
}
```

High level module: Research

```cpp
struct Research // high level
{
	Research(Relationships& relationships)
	{
		for(auto&& [first, rel, second] : relationships.relations)
		{
			if(first.name == "John" && rel == Relationship::parent)
				std::cout << "John has a child called " second.name << std::endl;
		}
	}
};
```

> [!danger] High level module depends directly on low level module

# Good Solution

Introduce a new layer: `RelationshipBrowser` as an interface

```cpp
struct RelationshipBrowser
{
	virtual std::vector<Person> find_all_children_of(std::string const& name) = 0;
};

struct Relationships : RelationshipBrowser // low level
{
	// as above

	std::vector<Person> find_all_children_of(std::string const& name) override 
	{
		std::vector<Person> result;
		for(auto&& [first, rel, second])
		{
			if (first.name == name && rel == Relationship::Parent)
				result.push_back(second);
		}
		return result;
	}
};
```

> [!check] Low level module depends on abstraction (implements)

Rewrite `Research` (high level module) to use `RelationshipBrowser`

```cpp
struct Research // high level
{
	Research(RelationshipBrowser& browser)
	{
		for(auto&& child : browser.find_all_children_of("John"))
		{
			std::cout << "John has a child called " child.name << std::endl;
		}
	}
};
```

> [!check] High level module depends on abstraction (uses)

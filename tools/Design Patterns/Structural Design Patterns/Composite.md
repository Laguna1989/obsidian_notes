---
tags:
  - design-patterns
links: "[[00 Structural Design Patterns]]"
---

> [!quote] Composite allows to use both single and composite objects uniformly

- Allowing us to handle aggregate objects and individual components in the same way.
- Objects work through inheritance and composition
- Composition lets us make compound objects

> [!example]
> - Math expression built from simple applications
> - Shape or grouping of shapes

> [!hint] Basic Idea
> `Foo` and `Collection<Foo>` have common APIs

# Shapes and Groups of Shapes

```cpp
struct GraphicObject
{
	virtual void draw() = 0;
};

struct Circle : GraphicObject
{
	void draw() override 
	{
		std::cout << "Circle\n";
	}
};
```

Now let’s add a `Group`

```cpp
struct Group : GraphicObject
{
	std::string name;
	std::vector<GraphicObject*> objects;
	explicit Group(std::string const& name) : name{name} {}

	void draw() override
	{
		std::cout << "Group " << name << " contains: " << std::endl;
		for(auto&& o : objects)
		{
			o->draw;
		} 
	}
}
```

`Group`s can be added to other `Group`s

```cpp
int main()
{
	Group root{"root"};
	Circle c1, c2;
	root.objects.push_back(&c1);

	Group subgroup{"sub"};
	subgroup.objects.push_back(&c2);
	root.objects.push_back(&subgroup);

	root.draw();
}
```

>[!hint] In this case the common behavior is enforced by the interface

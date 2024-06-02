---
tags:
  - design-patterns
links: "[[Structural Design Patterns]]"
---
# Overview

> [!quote] Connecting Classes together, avoiding cartesian product complexity explosion

> [!example] Bad design
>  ![Enter image alt description](IMG-2024-05-31-113651686.png)

> [!example] Good design
> ![Enter image alt description](IMG-2024-05-31-113651851.png)

> [!note] Aggregation over inheritance
> A bridge is a pattern that decouples an interface from an implementation

# Pimpl

- Manifestation of the bridge design pattern, hiding the implementation details
- The implementation details are deferred

> [!example] Person and PersonImpl classes
>
> ```cpp
> // header
> struct Person 
> {
> 	std::string name;
> 	struct PersonImpl;
> 	PersonImpl* impl;
> 
> 	Person();
> 	~Person();
> 
> 	void greet();
> };
>
> ////////////////////////////////////////////////////////////
> // source
> #include "PersonImpl.hpp"
> Person::Person()
> : impl{new PersonImpl}
> {}
> 
> Person::~Person()
> {
> 	delete impl;
> }
> ```
>
> - Does not need to be an inner class, important is the forward declaration of the impl class
> - `Person` does not need any Details of what `PersonImpl` does

> [!check] Benefits
> - No need to give away inner details of a class (that would normally be in the header files)
> - Improves compilation speed
> - Ensures Binary compatibility

# Shrink-Wrapped Pimpl

Library-fied version of pimpl

```cpp
template <typename T> class pimpl
{
private:
	std::unique_ptr<T> impl;
public:
	pimpl();
	~pimpl();

	template <typename ...Args> pimpl (Args&& ...args);
};
```

- Horrible looking template is the forwarding constructor
- Also add `operator*` and `operator->`

# Bridge Design Pattern

Rendering different kinds of shapes

```cpp
// shapes - circle, square
// Renderer - raster, vector

struct Renderer
{
	virtual void render_circle(floatx, float y, float radius) = 0;
}
```

Now we have different types of renderers

```cpp
struct VectorRenderer : Renderer
{
	void render_circle(floatx, float y, float radius) override
	{
		std::cout << "Draing a vector circle\n";
	}
}

struct RasterRenderer : Renderer
{
	void render_circle(floatx, float y, float radius) override
	{
		std::cout << "rasterizing circle\n";
	}
}
```  

 Let’s introduce a `Shape` class that acts as a bridge

```cpp
struct Shape
{
protected:
	Renderer& renderer;
	Shape(Renderer& renderer) : renderer{renderer} {}
public:
	virtual void draw() = 0;
	virtual void resize(float factor) = 0;
};

struct Circle : Shape
{
	Circle(Renderer& renderer, float x, float y, float radius) :Shape{renderer}, x{x}, y{y}, radius{radius} {}
	float x;
	float y;
	float radius;

	void draw() override
	{
		renderer.render_circle(x,y,radius);
	}

	void resize(float factor) override
	{
		radius *= factor
	}
};
```

 > [!info]
 [[Non-intrusive Design]] by Igelberger seems more powerful (but also way more complex)

> [!summary]
> - Decouple abstraction from implementation
> - A stronger form encapsulation

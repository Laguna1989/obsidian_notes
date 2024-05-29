---
tags:
  - design-patterns
  - solid
---

> [!quote] Subtypes should be immediately usable for their parent types

`Rectangle` class

```cpp
class Rectangle
{
protected:
	int width;
	int height;

public:
	Rectangle(int width, int height) : width{width}, height{height} {}

	int getWidth() const { return width; }
	int getHeight() const { return height; }

	virtual void setWidth(int width) { Rectangle::width = width; }
	virtual void setHeight(int height) { Rectangle::height = height; }

	int area() const { return width * height; }
};
```

Now threre is the `process` function that takes a `Rectangle&` and has some internal assumptions

```cpp
void process(Rectangle& r)
{
	int w = r.getWidth();
	r.setHeight(10);

	std::cout << "expected area: " << w*10 << "\n";
	std::cout << "resulting area: " << r.area() << "\n";
}
```

Extend `Rectangle` by `Square` class

```cpp
class Square : public Rectangle
{
public:
	Square(int size) : Rectangle{size, size} {}

	void setWidth(int width) override { this->width = this->height = width; }
	void setHeight(int height) override { this->width = this->height = height; }
};
```

> [!danger] This will break existing functionality in `process()`
> Not every `Rectangle` implementation behaves like a `Rectangle`

A `Square` does not need (or offer) independent `width` and `height` setters

> [!quote] If there is a base class, every derived class has to be fully substitutable for the base class.

> [!hint] How to fix this?
> - Inheriting `Square` from `Rectangle` is a **bad** idea.
> - In mathematics this dependency chain is acceptable
> 	- In our code, it is not acceptable, because of the assumptions in `process()`
> - A factory could solve this.
> 	- Always returns a rectangle, but sets the values on creation.

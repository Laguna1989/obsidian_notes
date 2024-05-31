---
tags:
  - design-patterns
  - solid
---

> [!quote] Code should be open for extension but closed for modification

# Example: Filtering Products

```cpp
struct Product 
{
	std::string name;
	Color color;
	Size size;
};

struct ProductFilter
{
	std::vector<Product*> by_color(std::vector<Product*> items, Color color)
	{
		std::vector<Product*> result;
		for(auto &i : items)
			if(i->color == color)
				result.push_back(i);
		return result;
	}
};
```

> [!warning] Problem Description
> Different filters required, e.g. by size or combined filters

## Bad Solution

Add a new function that handles the filtering

```cpp
std::vector<Product*> by_size(std::vector<Product*> items, Size size)
{
	std::vector<Product*> result;
	for(auto &i : items)
		if(i->size == size)
			result.push_back(i);
	return result;
}

std::vector<Product*> by_size_and_color(std::vector<Product*> items, Size size, Color color)
{
	std::vector<Product*> result;
	for(auto &i : items)
		if(i->size == size && i->color == color)
			result.push_back(i);
	return result;
}

```

> [!danger] This does not scale at all for more parameters
> For any new parameters existing code/classes need to be modified

## Good Solution

Let’s use the [[Specification]] pattern
- Create two interfaces: `Specification` and `Filter`
- Use inheritance to extend without modifying existing code

```cpp
template <typename T> 
struct Specification
{
	virtual bool is_satisfied(T* item) = 0;
};

template <typename T> 
struct Filter
{
	virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};
```

Introduce `BetterFilter` class that does the filtering. It will not need to be modified anymore in the future.

```cpp
struct BetterFilter : Filter<Product>
{
	std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override
	{
		std::vector<Product*> result;
		for(auto& item : items)
			if(spec.is_satisfied(item))
				result.push_back(item);
		return result;
	}
};
```

Now we can create `Specification`s, e.g.

```cpp
struct ColorSpecification : Specification<Product>
{
	Color color;
	bool is_satisfied(Product* item) override
	{
		return item->color == color;
	}
};

struct SizeSpecification : Specification<Product>
{
	Size size;
	bool is_satisfied(Product* item) override
	{
		return item->size == size;
	}
};
```

Combinations of `Specification`s are possible via an `AndSpecification`

```cpp
template <typename T>
struct AndSpecification : Specification<T>
{
	Specification<T> &specA;
	Specification<T> &specB;
	AndSpecification(Specification<T>& a, Specification<T>& b) : specA{a}, specB{b} {}
	
	bool is_satisfied(T* item) override
	{
		return specA->is_satisfied(item) && specB->is_satisfied(item);
	}
};
```

> [!check] Open for extension
> New properties can easily be added by a new `Specification` implementation

> [!check] Closed for modification
> Existing code in `Filter` and `Specification` does not need to be modified when new functionality is required

We can even do better and provide a custom `operator&&` in `Specification`

```cpp
template <typename T> struct Specification
{
	// code from above...

	AndSpecification<T> operator&&(Specification<T>&& other)
	{
		return AndSpecification<T>(*this, other);
	}
}
```

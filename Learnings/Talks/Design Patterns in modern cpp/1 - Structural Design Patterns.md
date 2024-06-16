---
tags: []
---

>[!hint] See also [[Structural Design Patterns MOC]]

# Adapter

[[Adapter]]

# Bridge

[[Bridge]]

# Composite

[[Composite]]

## ML Example

- `Neuron` struct
- `Neuron`s have connections for other Neurons (in and out)
- Every Neuron has a unique ID

```cpp
struct Neuron
{
	std::vector<Neuron*> in, out;
	unsigned int id;

	Neuron() 
	{
		static int id{1};
		this->id = id++;
	}

	void connect_to(Neuron& other)
	{
		out.push_back(&other);
		other.in.push_back(this);
	}
};
```

Neuron also has a stream output operator
![Enter image alt description](IMG-2024-06-01-102526960.png)

- This does not yet allow to connect multiple neurons
- Let’s add `NeuronLayers`
> [!warning] Bad style
> Do not inherit from vector

![Enter image alt description](IMG-2024-06-01-102527069.png)

- Problem: We want to connect
	- All neurons from a layer to a single neuron
	- Single neuron to layer
	- Layer to layer
	- Neuron to neuron (all done)

- => State space explosion for connections
- Let’s introduce a new interface using [[CRTP]] `SomeNeurons`
- This will be used in Neuron and NeuronLayer
- [[CRTP]] is used to deduct which type we have
![Enter image alt description](IMG-2024-06-01-102527125.png)

- 👆 This is the single function that connects all Neurons together
- Ranged based for loop will need to be implemented by adding begin and end functions
- For single neuron (arrrg!)
![Enter image alt description](IMG-2024-06-01-102527172.png)

## Intersection of Composite and Proxy

- Example of creature in computer game with certain statistics
	- Str, int, agi , …
	- This requires some getters and setters
	- Some aggregate statistics might be required (max, average, sum …)
	- This approach does not scale for multiple properties
- Having separate fields does not bring any benefit
- Let’s use something called “array backed properties”
![Enter image alt description](IMG-2024-06-01-102527217.png)

- Same for setter. Calculating aggregate statistics becomes very simple
![Enter image alt description](IMG-2024-06-01-102527266.png)

> [!summary]
> - Objects can use other objects either by composition or inheritance
> - Sometimes they need similar behaviours
> - The Composite design pattern lets us treat scalar and composite objects similarly
> - C++ supports “duck typing” when using `begin()` and `end()` objects and ranged based for loops

# Decorator

[[Decorator]]

# Facade
[[Facade]]
# Flyweight
[[Flyweight]]
# Proxy
[[Proxy]]

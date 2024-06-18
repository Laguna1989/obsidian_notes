---
tags:
  - dependency-injection
---
# Overview

> [!info] *Property Injection* allows a [[Local Default]] to be replaced via a public settable property.

# Notes

- Property Injection is also known as Setter Injection
- Only use this if there is a good local default

# Example

```cpp
class IWriter
{
public:
	virtual ~IWriter () = default;
	void writeToFile(std::string const& str) = 0;
};

class DefaultWriter : public IWriter
{
	// implementation
};

class GameSaver
{
public:
	// Local default
	GameSaver(): writer{std::make_unique<DefaultWriter>()} {}

	void save()
	{
		writer->writeToFile("my save data");
	}
	
	//  property setter
	void setWriter(std::unique_ptr<IWriter>&& ptr)
	{
		writer = std::move(ptr);
	}
	
private:
	std::unique_ptr<IWriter> writer;
};
```

---
tags:
  - tool
  - dependency-injection
---
# Overview

> [!info] *Method Injection* supplies a consumer with a dependency by passing it as a method argument called outside the [[Composition Root]]

Alternatives are [[Constructor Injection]] and [[Property Injection]].

# Example

```cpp
class IWriter
{
public:
	virtual ~IWriter () = default;
	void writeToFile(std::string const& str) = 0;
};

class GameSaver
{
public:
	void save(IWriter& writer)
	{
		writer.writeToFile("my save data");
	}
};
```

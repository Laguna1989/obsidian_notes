---
tags:
  - tool
  - dependency-injection
---
# Overview

*Constructor Injection* is a technique used in [[Dependency Injection]]. The idea is to pass a dependency via the constructor. This allows to have a completely constructed and usable object.

Alternatives are [[Method Injection]] and [[Property Injection]].

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
	GameSaver(IWriter& writer): writer{writer} {}

	void save()
	{
		writer->writeToFile("my save data");
	}
private:
	IWriter& writer;
};
```

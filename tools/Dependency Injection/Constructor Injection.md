---
tags:
  - tool
  - dependency-injection
---
# Overview

> [!info] *Constructor Injection* is the act of statically defining the list of required dependencies by specifying them as parameters to the class's constructor
>

Used as the preferred way for [[Dependency Injection]]. Constructor Injection allows to have a completely constructed and usable object.

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
		writer.writeToFile("my save data");
	}
private:
	IWriter& writer;
};
```

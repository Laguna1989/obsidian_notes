---
tags:
  - design-patterns
  - solid
---

> [!quote] A class/function should have one reason to change

Focus on the primary responsibility

# Example: Journal Containing Entries

```cpp
struct Journal 
{
	std::string title;
	std::vector <string> entries;
	
	Journal(std::string const& title) : title{title} {}

	void add_entry(std::string const& entry)
	{
		static int count = 1;
		entries.push_back(lexical_cast<std::string>(count++) + ": " + entry); 
	}
};

int main()
{
	Journal journal{"Dear Diary"};
	jorunal.add_entry("I ate a bug");
	jorunal.add_entry("I cried today");
}
```

> [!warning] Problem description: Serializing the journal

## Bad Solution

We could add `serialize()`/`deserialize()` methods to the `Journal` class.

> [!danger] `Journal`class should **NOT** be responsible for serializing/deserializing!

- If that functionality is added, the journal has **two** responsibilities.
- Avoid classes that have multiple responsibilities/concerns
- `Journal`is hard to change, e.g. if you want to save to a file or a database.
## Good Solution
- Better: `PersistenceManager` class
![Enter image alt description](Images/GAg_Image_2.png)

> [!check] This separates the concerns nicely.

> [!check] Each class does only one thing.

---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns MOC]]"
---
# Overview

> [!quote] System behavior partially specified at runtime

> [!quote] Enables the exact behacior of a system to be selected either at run-time (dynamic) or compile time (static)

> [!note] Also know as the *Policy* Pattern

## Motivation

- Many algorithms can be decomposed into higher- and lower level parts
- Making tea can be decomposed into
	- High Level: The process of making a hot beverage (boil water, pour into cup)
	- Low Level: Tea Specific things (put teabag into water)
- The high level algorithm can be reused for making coffee or hot chocolate

# Dynamic Strategy

Printing list of items in different formats (MD, HTML)

## Defining Output Formats

```cpp
enum class OutputFormat
{
	markdown,
	html
};

```

We are going to have three different functions

```cpp
struct ListStrategy
{
	virtual void start(std::ostringstream oss) {}
	virtual void add_list_item(std::ostringstream oss, std::string const& item) = 0;
	virtual void end(std::ostringstream oss) {}
};
```

> [!info] Using default implementation supports the [[Interface Segregation Principle]] as e.g. markdown does not need to implement `start()` and `end()`functionality

## Create a Text Processor

Create a `TextProcessor` component (the high level component)

```cpp
struct TextProcessor
{
public:
	void set_output_format(OutputFormat const& format)
	{
		switch (format)
		{
			case OutputFormat::markdown:
				list_strategy = std::make_unique<MarkdownListStrategy>();
				break;
			case OutputFormat::html:
				list_strategy = std::make_unique<HtmlListStrategy>();
				break;
		}
	}
	
	void append_list(std::vector<std::string> const& items)
	{
		list_strategy->start(oss);
		for(auto& item : items)
		{
			list_strategy->add_list_item(oss, item);
		}
		list_strategy->end(oss);
	}
	
	void clear()
	{
		oss.clear();
	}
	
	std::ostringstream oss;
	
private:
	std::unique_ptr<ListStrategy> list_strategy;
};
```

## Strategy Implementations

```cpp
struct MarkdownListStrategy : public ListStrategy
{
	// implementation for markdown output, just the add_list_item()
};

struct HtmlListStrategy : public ListStrategy
{
	// implementation for html output for all interface functions
};
```

## Usage

```cpp
int main()
{
	std::vector<std::string> items {"foo", "bar", "baz"};
	TextProcessor tp;
	tp.set_output_format(OutputFormat::markdown);
	tp.append_list(items);
	cout << tp.oss;
	
	tp.clear();
	
	tp.set_output_format(OutputFormat::html);
	tp.append_list(items);
	cout << tp.oss;
}
```

# Static Strategy

The [[Decorator]] can be implemented in a static or dynamic way. Same applies here.

Instead of a `std::unique_ptr<ListStrategy>` we will have a template argument
```cpp
template <typename LS>
struct TextProcessor
{
	// almost the same code as above
	LS list_strategy;

	// no more set_output_format() function
}
```

## Usage
```cpp
TextProcessor<MarkdownListStrategy> tpm;
tpm.appendList({"foo", "bar", "baz"});
std::cout << tpm.oss;

TextProcessor<HtmlListStrategy> tph;
hpm.appendList({"foo", "bar", "baz"});
std::cout << hpm.oss;
```
# Summary

> [!summary]
>  - Define an algorithm at a high level
>  - Define the interface you expect each strategy to follow
>  - Provide for either dynamic or static composition o strategy in the overall algorithm



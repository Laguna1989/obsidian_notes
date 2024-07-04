---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns]]"
---
# Overview

> [!quote] A component that processes structured text data. Does so by turning it into separate lexical tokens (lexing) and then interpretin sequences of said tokens (parsing)

- Interpreters are everywhere round us, e.g. in the compiler/interpreter
- Not neccessarily a design pattern, but more in the domain of parsers

> [!example] Examples
> General: Textual input needs to be processed
>
> - Programming language compilers, interpreters or IDEs
> - Numeric expressions (`3+4/5`)
> - [[Regular expressions]]
> - Turning strings into #OOP based structures in a complicated process

# Handmade Interpreting: Lexing

> [!example] Example:
>  Interpret a numeric expression
>
>  ```cpp 
>  std::string input{"(13-4)-(12+1)"};
>  ```

- We do not want to split on character level, as that would rip the numbers apart

Start by defining the `Token`s that we can have in our system

```cpp
struct Token
{
	enum Type {integer, plus, minus, lparen, rparen} type;
	std::string text;

	Token(Type type, std::string const& text) : type{type}, text{text} {}

	friend std::ostream& operator<<(std::ostream&os, Token const& token)
	{
		os << "'" << token.text  << "'";
		return os;
	}
};
```

Let's write a `lex()` function

```cpp
std::vector<Token> lex(std::string const& input)
{
	std::vector<Token> result;

	for(int i = 0; i < input.size(); i++)
	{
		switch(input[i])
		{
			case '+':
				result.push_back(Token{Token::plus, "+"});
				break;
			case '-':
				result.push_back(Token{Token::minus, "-"});
				break;
			case '(':
				result.push_back(Token{Token::lparen, "()"});
				break;
			case ')':
				result.push_back(Token{Token::rparen, ")"});
				break;
			default: // default section for integers
				ostringstream buffer;
				buffer << input[i];
				for(int j = i+1; j < input.size(); j++)
				{
					if(isdigit(input[j]))
					{
						buffer << input[j];
						++i;
					}
					else
					{
						result.push_back(Token{Token::integer, buffer.str()});
						break;
					}
				}
				break;
				
		}
	}
	return result;
}
```

How to use this

```cpp
int main()
{
	std::string input{"(13-4)-(12+1)"}

	auto tokens = lex(input);

	for(auto& t : tokens)
	{
		std::cout << t << " ";
	}
	std::cout << std::endl;
}
```

# Handmare Interpreter: Parsing

The second part of the handmare interpreting. Use the set of tokens to build an actual expression that we can evaluate.

## The Elements

We start with an abstract base class `Element`, which uses the [[Visitor]] pattern.

```cpp
struct Element
{
	virtual int eval() const = 0;
};
```

Structure for Integers

```cpp
struct Integer : Element
{
	int value;
	Integer(int value) : value{value} {}

	int eval() const override
	{
		return value;
	}
};
```

The binary operations are more interesting

> [!hint] We start using smart pointers as we want to pass `Element`s around

```cpp
struct BinaryOperation : Element
{
	enum Type {addition, subtraction} type;
	std::shared_ptr<Element> lhs, rhs;

	int eval() const override
	{
		auto left = lhs->eval();
		auto right = rhs->eval();
		
		if (type == Type::addition)
			return left + right;
		else 
			return right + left;
	}
};
```

> [!note]
> Parentheses do not show up as elements, they just give hints while parsing how to convert `Token`s to `Element`s

# The Parse Function

> [!note]
> The input will always be a singular expression, which means our top level `Element` will always be a binary expression (in this specific example)

```cpp
std::shared_ptr<Element> parse(std::vector<Token> const& tokens)
{
	auto result = make_shared<BinaryOperation>();
	bool have_lhs{false};

	for(int i = 0; i < tokens.size(); i++)
	{
		auto& token = tokens[i];
		switch (token.type)
		{
			case Token::integer:
				int value = lexical_cast<int>(token.text);
				auto integer = std::make_shared<Integer>(value);
				if(!have_lhs)
				{
					result->lhs = integer;
					have_lhs = true;
				}
				else
					result->rhs = integer;
					
				break;
			case Token::plus:
				result.type = BinaryOperation::addition;
				break;
			case Token::minus:
				result.type = BinaryOperation::subtraction;
				break;
			case Token::lparen:
				{
					int j = i;
					// find the matching right parenthesis
					// we ignore the case with nested braces
					for(; j < tokens.size(); ++j)
					{
						if(tokens[j].type == Tokens.rparen)
							break;
					}
					
					// we found the matching right parenthesis at j
					// feed the vect
					
					std::vector<Token> subexpression(&tokens.at[i+1], &tokens[j]);
					auto element = parse(subexpression);
					if(!have_lhs)
					{
						result->lhs = element;
						have_lhs = true;
					}
					else 
					{
						result->rhs = element;
					}
					i = j;
					break;
				}
		}
		return result;
	}
}
```

Extend our main to parse the input tokens

```cpp
// in main
auto parsed = parse(tokens);
std::cout << input << " = " << parsed->eval() << std::endl; 
```

# Building Parsers with Boost.Spirit

# Summary

> [!summary]
> An Interpreters acts in two stages
> - Lexing : Turning Text into Tokens
> - Parsing Turning Tokens into Meaningful expressions
>
> Parsed data can then be traversed

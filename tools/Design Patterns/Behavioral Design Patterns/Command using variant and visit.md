---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns]]"
---
# A Modern **Command** Design Pattern Using `std::variant` and `std::visit`

# Overview

Do not use inheritance, but use `std::variant` to hold all possible commands.
> [!check] No runtime overhead

> [!danger] Not extendable

## Reference

> [!hint] See also [Reference](https://trussel.ch/cpp/design%20patterns/2020/10/18/command-pattern.html)

> [!hint] Can benefit nicely from the [[Overload pattern]]

# Define Basic Commands

```cpp
namespace cmd {

struct SetBrightness {
  unsigned val = 0;
};

struct SetColor {
  unsigned r = 0;
  unsigned g = 0;
  unsigned b = 0;
};

using Command = std::variant<SetBrightness, SetColor>;

}
```

# Create a Command Executor

```cpp

namespace cmd 
{

struct CommandExecutor
{
  CommandExecutor(Lightbulb& bulb) : bulb_(bulb){};

  void operator()(const SetBrightness& cmd){
    bulb_.set_brightness(cmd.val);
  }

  void operator()(const SetColor& cmd){
    bulb_.set_color(cmd.r, cmd.g, cmd.b);
  }

private:
  Lightbulb& bulb_;
};

} // namespace cmd

```

> [!hint] This class provides a call operator for each command.

```cpp

Lightbulb bulb("LED");
cmd::CommandExecutor executor(bulb);
std::vector<Command> commands;

// fill commands vector

for (const auto& command : commands) 
{
	std::visit(executor, command);
}
```

# Summary

> [!summary]
> - Define simple POD structs that represent your commands and use `std::variant` to pass them around
> - Define a visitor object that performs different actions based on the actual value of the `std::variant`

---
tags:
  - cpp
  - templates
---
# Varargs Strip First Argument

```
template <typename ... Args>
void otherFunction(Args &&... args);

const auto withStrippedArguments = [](auto&& /*first*/, auto&&... args_)
{  
    otherFunction(std::forward<decltype(args_)>(args_)...);   
};  
withStrippedArguments(args...);
```

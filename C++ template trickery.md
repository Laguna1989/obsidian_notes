# varargs strip first argument

```
const auto addWithStrippedArguments = [](auto&& /*first*/, auto&&... args_){  
    otherFunction(std::forward<decltype(args_)>(args_)...);   
};  
addWithStrippedArguments(args...);
```

```cpp
template<typename ... Ts>
struct Overload : Ts ... {                                  // (1)
    using Ts::operator() ...;                               // (2)
};

template<class... Ts> Overload(Ts...) -> Overload<Ts...>;   // (3)
```

- `(1)` The template struct can have an arbitrary number of public base classes.
- `(2)` The using declarative pulls the call operator of all base classes into the local scope
- `(3)` The deduction guide is a helper for #cpp17 (and not needed in #cpp20 ). It forwards the constructor arguments as template arguments.

```cpp
std::variant<int, std::string> var = 2017;        // (1)

auto TypePrinter = Overload {                     // (2)
        [](int) { return "int"; },
        [](std::string) { return "string"; },
        [](auto) { return "unknown type"; },      // (3)
    };

std::visit(TypePrinter, var);                     // (4) 
```

- `(1)` Create a `std::variant` that can hold either an `int` or a `std::string`. In this case it holds a `std::string`
- `(2)` Create a `TypePrinter` *Overload Set* that makes use of the Overload pattern. The lambdas passed as constructor arguments are forwarded as template arguments. The resulting instance has all lambdas as public call operators.
- `(3)` Generic overload with `auto` argument. Not strictly needed
- `(4)` Use `std::visit` with the Overload Set and the variant. The compiler will automatically pick the correct overload depending on the type stored in the variant.

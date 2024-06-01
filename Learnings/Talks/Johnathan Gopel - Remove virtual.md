---
tags:
  - cpp
  - Talk
  - templates
links: "[[Talks]]"
created: 2024-05-04
---
# Reference

<iframe width="560" height="315" src="https://www.youtube-nocookie.com/embed/gTNJXVmuRRA?si=JMCcGy_Ib2EbbXXM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Not about

- `std::vector<std::any>`
- `std::vector<std::variant>`
- type erasure

# Binding Interfaces

```cpp
struct FooInterface {
  virtual auto func() const -> int = 0;
};


struct Foo final : public FooInterface {
  auto func() const -> int override {
    return 42;
  }
};

// usage
std::unique_ptr<FooInterface> foo = std::make_unique<Foo>();
auto func (std::unique_ptr<FooInterface foo2) {
  // implementation
}
```

> [!warning] Rule of five

- pointer use

# Templates/Concepts

```cpp
template <typename T>
concept CFoo = requires(T foo) {
  { foo.func() } -> std::same_as<int>;
};

struct Foo {
  auto func() const -> int {
    return 42;
  }
};

// mostly done in test code
static_assert(CFoo<FOO>);

// usage
Foo foo{};
auto func(CFoo auto& foo2) {
  // implementation
}
```

- simple object creation and passing
- Here we can use **Rule of zero** instead of **Rule of five**
- We can bind more loosely (Concepts vs Interfaces) -> Duck Typing

# Owning Polymorphic Types (e.g. for DI)

## With Virtual

```cpp
class Bar {
public:
  constexpr Bar(std::unique_ptr<FooInterface> input_foo;) : foo(std::move(input_foo)) {}

  void set_foo(std::unique_ptr<FooInterface> input_foo) {
    foo = std::move(input_foo);
  }
private:
  std::unique_ptr<FooInterface> foo{};
};
```

## Without Virtual

```cpp
template <typename TFoo>
class Bar {
public:
  constexpr Bar(TFoo input_foo) 
  : foo{input_foo} {}

private:
  TFoo foo{};
};
```

- Type cannot be changed after compilation

## Now with Concepts

```cpp
template <CFoo... TFoos>
class Bar {
public:
  constexpr Bar(auto input_foo) 
  : foo{input_foo} {}

  constexpr auto set_foo(auto input_foo) -> void {
    foo = input_foo;
  }
private:
  std::variant<TFoos...> foo{};
};
```

- This will give ugly template errors if the wrong type is provided. `auto` argument just takes everything
- We want to get the concept error instead.
- Apply concept constraint to function?

```cpp
auto set_foo(CFOO auto input_foo) -> void {foo = input_foo;}
```

- -> **No**: Not every type that conforms to `CFoo` might be in the list `TFoos`

- We only want to accept types in `TFoos`
- Let's write another concept

```cpp
template <typename T, typename... Ts>
concept same_as_any = (... or std::same_as<T, Ts>);
```

-> fold over list of types with or, so any T out of ... Ts will work.

```cpp
auto set_foo(same_as_any<TFoos...> auto input_foo) -> void { foo = input_foo;}


// usage
Bar bar{Foo{}};
Bar<Foo1, Foo2> bar{Foo1{}};
```

**Is this good design?**
- Variant has runtime cost. This might be more clouded than with vtables
- Types are often known at compile time
- Not possible for users to expand the list (this is possible with Interfaces)
- List of types can be stored in `using`

# Storing Multiple Types

```cpp
class Baz {
public:
  auto store(std::unique_ptr<FooInterface> value) -> void {
    data.emplace_back(std::move(value));
  }
private:
  std::vector<std::unique_ptr<FooInterface> data{};
};
```

Desired properties:
- list of types that might be stored
- container that can hold different types simultaneously
- container that can hold multiple objects of a single type

```cpp
template <CFoo... TFoos>
class Baz {
public:
  template <same_as_any<TFoos...> T>
  auto store (T value) {
    return std::get<std::vector<T>>(data).push_back(value);
  }
private:
  // vector allows to store multiple of the Same TFoo, tuple is used to store multiple vectors of different TFoos
  std::tuple<std::vector<TFoos>...> data{};
};

using foo_storage_t = Baz<Foo1, Foo2>;
foo_storage_t baz{};

baz.store(Foo1{});
baz.store(Foo2{});
```

- quite efficient code (no type erasure)
- there is the overhead of empty vectors for every type in the list that is not used (vtable is one vector, here we have N vectors for N types)
- ordering within each vector is stable. Ordering is **not** stable between different types

# Downsides of Avoiding Virtual

- Increase translation unit size
  - For interfaces you just need the interface
  - For templates you need to know all types in advance and all users need to know the different types potentially used
- Increase binary size
  - linker can sometimes solve this (LTO)
- Increase in compile time
- May add complexity to your code (vtables are pretty easy to understand and common knowledge)

# Benefits of Avoiding Virtual

- static and virtual is not possible at the same time
- without virtual, finally static can be used

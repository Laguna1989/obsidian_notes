---
tags:
  - Talk
  - cpp
  - cpp20
created: 2020-09-30
links: "[[Talks MOC]]"
---
# Reference

<iframe width="560" height="315" src="https://www.youtube.com/embed/FRkJCvHWdwQ?si=O6UDFpW_Mxvigy_Y" title="YouTube video player" frameborder="0" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Overview

- C++20 is big
- formally puglish is planned for end of 2020
- Video is a high level overview

# New Keywords

- regarding concepts
    - `concept`
    - `requires`
- `constinit`
- `consteval`
- [[C++ Coroutines]]
    - `co_await`
    - `co_return`
    - `co_yield`
- `char8_t`	(similat to char16_t from c++17)

# New Identifiers {#new-identifiers}

- `import`
- `module`

Identifiers are reserved tokens only in certain places, e.g. `final` or `override`

# Modules {#modules}

- Replace header files
- What should be exported (classes/functions)
- Module interface files / module implementation files
    - Only signatures are part of the exported interface
    - Modification of function implementation, no rebuild of dependent modules required
- Structure! -> submodules and module partitions
- No need for
    - include guards
    - Unique names (in different modules)
- Faster build times
- Preprocessor macros will not leak outside of modules
- Order of module imports is no longer important

## How to Write and Use a Module {#how-to-write-and-use-a-module}

> [!example]+ Create a module
>
> ```cpp
> export module cppcon
> namespace CppCon
> {
> 	auto GetWelcomeHelper() { return "Welcome to CppCon2020"; }
> 	export auto GetWelcome() { return GetWelcomeHelper(); } 
> }
> ```
>
> [!example]+ Consume a module
>
> ```cpp
> // main.cpp
> import cppcon;
> int main()
> {
> 	std::cout << CppCon::GetWelcome() << std::endl;
> }
> ```

- Regarding the STL
    - c++20 does not specify how to modularize the STL
    - STL headers are importable as modules
    - Macros will be exported from stl headers
- Custom headers can be made importable, but this is compiler dependent

# Ranges {#ranges}

- Object referring to a sequence of elements
- Similar to begin()/end() iterators
- Why ranges?
> [!example]+
>
> ```cpp
> std::vector data {1,2,3,4,5};
> std::sort(data.begin(), data.end()); // old way of sorting 
> ranges::sort(data); // new way of sorting
> ```

- Impossible to have mismatching begin()/end() iterators
- Range adaptors e.g. a filter

## Major Components

- Range
    - All containers supporting `begin()` and `end()` are valid rangers
- Range based algorithm
    - STL algorithms, accepting ranges instead of iterators
- Projection
    - Transform Elements before handing them to an algorithm
- View
    - transform range lazily, not owning, non-modifying the content (but the range)
- Range factories
    - generate sequence of integers
- Pipelining
    - Views can be combined using pipes

> [!example]+
>
> ```cpp
> std::vector data {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
> auto result {
> 	data
> 	| views::filter([](const auto& value) { return value % 2 == 0; })
> 	| views::transform([](const auto& value){ return value * 2.0; })
> 	| views::drop(2)
> 	| views::reverse
> 	| views:: transform([](int i){ return std::to_string(i); })
> };
> ```

- Executed on evaluation Lazily
- Supporting infinite sequences

# Coroutines

- A functions that contains one of the following
    - `co_await` (suspends coroutine while waiting for another computation to finish
    - `co_yield` returns a value from a coroutine to the caller and suspends the coroutine, subsequently calling the coroutine again, continuesexecution
    - `co_return` returns from a coroutine (simple return is not allowed)
- usage:
    - Generators
    - Asynchronous IO
    - Lazy computation
    - event driven programming
- STL does not contain generators yet

# Concepts

- Named requirements to constrain template parameters
- Predicates evaluated at compile time

```cpp
template <typename T>
concept Incrementable = requires(T x) {x++; ++x;};

template <Incrementable T>
void foo(T t);

template <typename T> requires Incrementable<T>
void foo(T t);

template <typename T> 
void foo(T t) requires Incrementable<T>;

void foo(Incrementable auto T);
```

- Combining with requires `A<T> && B<T>`
- Or `concept C = A<T> && B<T>`
- The standard defines a whole collection of standard concepts
    - `same`, `derived_from`, `convertible_to`, `integral`, `constructible`, `sortable`, `mergeable`, `permutable`
- Helps the compiler to generate useful error messages

# Small Changes

- Lambda expression changes
    - `[=]` will not capture this anymore
    - template syntax with lambda expressions+
        - `[] <typename T> (T x) { /* … */ }`
    - gets rid of of decltype and `decay_t`
> [!danger] `[=] is a breaking change
- `constexpr` changes
    - virtual functions can be constexpr
    - `constexpr` can use dynamic_cast and typeid
    - Can use new/delete
    - Contain try/catch
        - But has to catch all exceptions
    - `string` and `vector` are now constexpr
- Concurrency changes
    - Is `shared_ptr` threadsafe?
        - Control block is threadsafe
        - Accessing a `shared_ptr` is not thread safe
    - Make it thread_safe?
        - Use mutex or atomic_load/atomic_store, …
    - c++20 has `std::atomic<shared_ptr<T>>`
    - `std::jthread`
        - Destructor will cancel thread and call join()

> [!example]+ Without jthread
>
> ```cpp
> std::thread job {[] { ... }};
> try {
> 	// Do something here
> } catch(...) {
> 	job.join(); // very easy to forget!
> 	throw; // rethrow
> }
> job.join();
> ```

> [!example]+ With jthread
>
> ```cpp
> std::jthread job{[]{ ... }};
> // Do something here 
> 
> // jthread destructor automatically calls join() 
> ```

- Supports cooperative cancellation
	- `std::stop_token`
		- Check if check was requested
		- Compatible with condition variable
	- `std::stop_source`
		- Used to request a thread to stop execution
		- Stops are visible to all associated stop_sources and stop_tokens
	- `std::stop_callback`
		- Callback is invoked when stop is requested

- Semaphores
	- Lightweight synchonization primitives
	- Counting semaphores/binary semaphores
	- Can be used to create other types
- `std::latch` and `std::barrier`
    - `std::atomic`
        - new functions: wait(), notify_one(), notify_all()
    - Atomic references
        - Normally atomics copies values, now pass by ref allowed
    - Designated init

> [!example]+
>
> ```cpp
> Data d { .aString = "Hello" };
> ```

- Spaceship operator `<=>`
    - If operator `<=> = default` is provided, all 6 operators == , `<`, `!=`, `<=`, `>`, `>=` will be provided
    - Strong/partial/weak ordering
    - STL has full support for spaceship operator
- Range-based-for loop initializer
> [!example]+
>
> ```cpp
> for (auto data {GetData()}; auto& value : data.values)
> {
> 	...
> }
> ```

- Non type template parameters
    - e.g. strings at compile time
- `[[likely]]`, `[[unlikely]]` attributes (compiler optimization hints)
    - helps with compiler optimization
- Chrono library extended
    - Calendar support (gregorian for now)
    - Timezones
        - Timezone conversion
    - New clocks
        - gps / tai clock
    - New durations weeks, moths, years, …
- `std::span`
    - Never owning
    - Pointer to begin and size
    - Passed by copy
    - Stringview is only read, span can be read or write
        - `span<const int>` and not `span<int> const`
    - Support for iterators
- Feature testing macros
    - Does a compiler support a certain language/library feature?
- Version header
    - cpp compiler version number, release date, copyright notice
- `consteval`
    - For function instead of constexpr
    - Can only be used at compile time, if called with non const values, compiler error
- `constinit`
    - Help with static initialization fiasco
- Using directive for class enums
- Text formatting (std::format)
    - Safe and extensible
    - Rasy to read
    - separation of format string and arguments
    - Easily localizable
    - More performant than sprintf, ostringstream and to_string()

> [!example]+
>
> ```cpp
> cout << format("{:=^19}", "CooCon 2020");
> cout << format("Read {0} bytes from {1}", n, "file1.txt");
> ```

- Math constants in std::numbers
    - e, log2e, log10e
    - pi, inv_pi,
    - ln2, ln10
    - sqrt(2), sqrt(3), sqrt(10)
    - egamma
    - phi
- `std::source_location`
    - line number, column, file name, function mane
    - super useful for logging
    - evaluation is happening at the call site
- `[[nodiscard(reason)]]`
- Bit operations
- Small STL additions
    - `starts_with` and `ends_with` for `std::string`, `std::stringview`
    - `contains()` for associative containers
    - `remove()`, `remove_if()` return how many items were removed
    - `erase()`, `erase_if()`, no more remove-erase idiom ndeeded
    - `midpoint()`, `lerp()`

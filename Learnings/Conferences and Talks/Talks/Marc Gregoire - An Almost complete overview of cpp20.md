---
tags:
  - Talk
  - cpp
  - cpp20
created: 2020-09-30
links: "[[Confrerences and Talks]]"
---
# Overview

* C++20 is big
* formally puglish is planned for end of 2020
* Video [https://www.youtube.com/watch?v=FRkJCvHWdwQ&feature=emb_logo&ab_channel=CppCon](https://www.youtube.com/watch?v=FRkJCvHWdwQ&feature=emb_logo&ab_channel=CppCon) is a high level overview
# New Keywords
* regarding concepts
    * `concept`
    * `requires`
* `constinit`
* `consteval`
* coroutines
    * `co_await`
    * `co_return`
    * `co_yield`
* `char8_t`	(similat to char16_t from c++17)
# New Identifiers {#new-identifiers}

* `import`
* `module`

identifiers are reserved tokens only in certain places, e.g. `final` or `override`

# Modules {#modules}

* replace header files
* what should be exported (classes/functions)
* module interface files / module implementation files
    * only signatures are part of the exported interface
    * modification of function implementation, no rebuild of dependent modules required
* Structure! -> submodules and module partitions
* no need for 
    * include guards
    * unique names (in different modules)
* faster build times
* preprocessor macros will not leak outside of modules
* order of module imports is no longer important

## How to write and use  a module {#how-to-write-and-use-a-module}

> [!example]+ Create a module
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


* Regarding the STL
    * c++20 does not specify how to modularize the STL
    * stl headers are importable as modules
    * macros will be exported from stl headers
* custom headers can be made importable, but this is compiler dependent
# Ranges {#ranges}

* object referring to a sequence of elements 
* similar to begin()/end() iterators
* Why ranges?
> [!example]+
> ```cpp
> std::vector data {1,2,3,4,5};
> std::sort(data.begin(), data.end()); // old way of sorting 
> ranges::sort(data); // new way of sorting
> ```
* impossible to have mismatching begin()/end() iterators
* range adaptors e.g. a filter
## Major components
* Range
    * All containers supporting `begin()` and `end()` are valid rangers
* Range based algorithm
    * STL algorithms, accepting ranges instead of iterators
* Projection
    * Transform Elements before handing them to an algorithm
* View
    * transform range lazily, not owning, non-modifying the content (but the range)
* Range factories 
    * generate sequence of integers
* Pipelining
    * Views can be combined using pipes

> [!example]+ 
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

* executed on evaluation Lazily
* Supporting infinite sequences

# Coroutines {#coroutines}

* a functions that contains one of the following
    * co_await (suspends coroutine while waiting for another computation to finish
    * co_yield returns a value from a coroutine to the caller and suspends the coroutine, subsequently calling the coroutine again, continuesexecution
    * co_return returns from a coroutine (simple return is not allowed)
* usage:
    * Generators
    * Asynchronous IO
    * Lazy computation
    * event driven programming
* STL does not contain generators yet

# Concepts
* named requirements to constrain template parameters
* predicates evaluated at compile time

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

* combining with requires `A<T> && B<T>`
* or `concept C = A<T> && B<T>`
* The standard defines a whole collection of standard concepts
    * `same`, `derived_from`, `convertible_to`, `integral`, `constructible`, `sortable`, `mergeable`, `permutable`
* Helps the compiler to generate useful error messages


# Small changes

* Lambda expression changes
    * `[=]` will not capture this anymore
        * !! breaking change
    * template syntax with lambda expressions+
        * `[] <typename T> (T x) { /* … */ }`
    * gets rid of of decltype and `decay_t`
* constexpr changes
    * virtual functions can be constexpr
    * constexpr can use dynamic_cast and typeid
    * can use new/delete
    * contain try/catch
        * but has to catch all exceptions
    * string and vector are now constexpr
* concurrency changes
    * is `shared_ptr` threadsafe?
        * control block is threadsafe
        * accessing a `shared_ptr` is not thread safe
    * make it thread_safe?
        * use mutex or atomic_load/atomic_store, …
    * c++20 has `std::atomic<shared_ptr<T>>`
    * `std::jthread`
        * destructor will cancel thread and call join()
        
> [!example]+ Without jthread
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
> ```cpp
> std::jthread job{[]{ ... }};
> // Do something here 
> 
> // jthread destructor automatically calls join() 
> ```

* supports cooperative cancellation
	* std::stop_token 
		* check if check was requested
		* compatible with condition variable
	* std::stop_source
		* used to request a thread to stop execution
		* stops are visible to all associated stop_sources and stop_tokens
	* std::stop_callback
		* callback is invoked when stop is requested

* semaphores
	* lightweight synchonization primitives
	* counting semaphores/binary semaphores
	* can be used to create other types
* latch and barriers
    * std::atomic
        * new functions: wait(), notify_one(), notify_all()
    * atomic references
        * normally atomics copies values, now pass by ref allowed
    * designated init

> [!example]+ 
> ```cpp
> Data d { .aString = "Hello" };
> ```


* Spaceship operator ⇔
    * if operator &lt;=>  = default is provided, all 6 operators ==, &lt;,  !=, &lt;=, >, >=  will be provided
    * strong/partial/weak ordering
    * STL has full support for spaceship operator
* ranged based for loop initializer
> [!example]+
> ```cpp
> for (auto data {GetData()}; auto& value : data.values)
> {
> 	...
> }
> ```

* non type template parameters
    * e.g. strings at compile time
* `[[likely]]`, `[[unlikely]]` attributes (compiler optimization hints)
    * helps with compiler optimization
* chrono library extended
    * calendar support (gregorian for now)
    * timezones
        * timezone conversion
    * new clocks
        * gps / tai clock
    * new durations weeks, moths, years, …
* std::span
    * never owning
    * pointer to begin and size
    * passed by copy
    * stringview is only read, span can be read or write
        * span&lt;const int> and not span&lt;int> const
    * support for iterators
* feature testing macros
    * does a compiler support a certain language/library feature?
* version header
    * cpp compiler version number, release date, copyright notice
* consteval 
    * for function instead of constexpr
    * can only be used at compile time, if called with non const values, compiler error
* constinit
    * help with static initialization fiasco
* using directive for class enums
* text formatting (std::format)
    * safe and extensible
    * easy to read
    * separation of format string and arguments
    * easily localizable
    * more performant than sprintf, ostringstream and to_string()

> [!example]+ 
> ```cpp
> cout << format("{:=^19}", "CooCon 2020");
> cout << format("Read {0} bytes from {1}", n, "file1.txt");
> ```
* math constants in std::numbers
    * e, log2e, log10e
    * pi, inv_pi, 
    * ln2, ln10
    * sqrt(2), sqrt(3), sqrt(10)
    * egamma
    * phi
* std::source_location
    * line number, column, file name, function mane
    * super useful for logging
    * evaluation is happening at the call site
* `[[nodiscard(reason)]]`
* bit operations
* small stl additions
    * starts_with and ends_with for string, stringview
    * contains() for associative containers
    * remove(), remove_if() return how many items were removed
    * erase(), erase_if() no more remove erase idiom &lt;- nice!
    * midpoint(), lerp()
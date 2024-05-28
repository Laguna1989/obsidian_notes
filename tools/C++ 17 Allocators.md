---
tags:
  - cpp
  - cpp17
  - tool
links: "[[Tools]]"
created: 2022-04-12
---
# C++17 Allocators

## Resources

* [Getting Allocators out of the way](https://www.youtube.com/watch?v=RLezJuqNcEQ) 
* [C++Weekly, 3.5x faster containers](https://www.youtube.com/watch?v=q6A7cKFXjY0) - good intro, short and understandable, with examples
* Lakos: Local Allocators - In depth explanation, lots of measurements shown
    * [Part 1](https://www.youtube.com/watch?v=nZNd5FjSquk)	
    * [Part 2](https://www.youtube.com/watch?v=CFzuFNSpycI)
* [Polymorphic Memory Resources](https://www.cppstories.com/2020/06/pmr-hacking.html/)
* [PMR Hacking](https://www.cppstories.com/2020/06/pmr-hacking.html/)
* [PMR stl for embedded](https://www.rkaiser.de/wp-content/uploads/2021/03/embo2021-pmr-STL-for-Embedded-Applications-en.pdf)
* [Taming Dynamic Memory](https://www.youtube.com/watch?v=FcpmMmyNNv8) - Detailed explanation of the pmr memory resource types
* [pmr comes with a cos](https://www.youtube.com/watch?v=FLbXjNrAjbc)t - basically what can go wrong with pmr

## PMR Example 
```cpp
int main()
{
	static LoggingResource memoryResource{std::pmr::new_delete_resource()};
	std::pmr::set_default_resource(&memoryResource);

	std::sout << "## vector<int> test" << std::endl;
	std::mpr::vector<int> ints;
	ints.push_back(33);
	ints.push_back(44);
}
```
* `static` because meyer singletons (function statics) are deallocated after `main()`. Same for detached threads that might outlive the main thread.
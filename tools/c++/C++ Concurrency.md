---
tags:
  - cpp
  - concurrency
  - tool
links: "[[Cpp Tools MOC]]"
---
# References

- <https://www.youtube.com/watch?v=ZQFzMfHIxng>
- <http://svr-pes20-cppmem.cl.cam.ac.uk/cppmem/>
- [[Williams - Cpp Concurrency In Action]]
- See also [[Concurrency Improvements in C++20]]]]

# Parallel for

```
#include <algorithm>  
#include <execution>  
#include <ranges>

std::ranges::iota_view indexes((size_t)0, positions.size());  
std::for_each(std::execution::par, indexes.begin(), indexes.end(), [this, &elapsed](size_t i) {  
    // concurrently update array[i];
});
```

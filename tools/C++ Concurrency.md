#concurrency 
Good sources
- https://www.youtube.com/watch?v=ZQFzMfHIxng
- http://svr-pes20-cppmem.cl.cam.ac.uk/cppmem/

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
---
tags:
  - cpp
  - concurrency
---
 - `store()`: first increment counter, then store value, then increment counter again
- `load()`: check if counter is odd -> early return. Load value. Check if counter has increased afterwards again

![[2024-01-31_seqlock1.png]]

![[2024-01-31_seqlock2.png]]

![[2024-01-31_seqlock3.png]]

Taken from [this talk](https://www.youtube.com/watch?v=8uAW5FQtcvE) 


Todo: check with [[C++ Concurrency]]
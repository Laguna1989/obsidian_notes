---
tags:
  - cpp
  - concurrency
---

 - `store()`: first increment counter, then store value, then increment counter again
- `load()`: check if counter is odd -> early return. Load value. Check if counter has increased afterwards again

![[IMG-2024-05-30-162408341.png]]

![[IMG-2024-05-30-162408389.png]]

![[IMG-2024-05-30-162408454.png]]

Taken from [this talk](https://www.youtube.com/watch?v=8uAW5FQtcvE)

Todo: check with [[C++ Concurrency]]

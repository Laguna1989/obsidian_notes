---
tags:
  - cpp
  - concurrency
---

> [!hint] Reference:
> <iframe width="560" height="315" src="https://www.youtube.com/embed/8uAW5FQtcvE?si=tKzPEwVp4OqSVvE6" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

- `store()`: first increment counter, then store value, then increment counter again
- `load()`: check if counter is odd -> early return. Load value. Check if counter has increased afterwards again

![[IMG-2024-05-30-162408341.png]]

![[IMG-2024-05-30-162408389.png]]

![[IMG-2024-05-30-162408454.png]]

Todo: check with [[C++ Concurrency]]

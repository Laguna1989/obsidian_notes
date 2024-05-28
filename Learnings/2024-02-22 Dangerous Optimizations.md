---
tags:
  - cpp
---

- Premise: Compiler writers use undefined behavior to perform optimizations
	- after all, a compiler is a big optimizer
- Difficult for programmers but for static analysis tools as well
- UD: 
	- implementations may ignore UD completely with unpredictable results
	- UD "might start to play game of life in your program"
	- might behave in a documented manner of the environment (without issuing a diagnostic)
	- best case: UD might terminate the program with a diagnostic
- Optimization: replace a computation with a more efficient method that computes the same result
- There is an **as if** rule: compiler can remove unused code if it produces the same output
- Three optimization strategies:
	- **hardware**: generate corresponding assembly and let the hardware do whatever it does -> almost the universal policy in c and c++
	- **Super debug**: trapping undefined behaviour (e.g. in debugging) but very slow performance
	- **total license**: UB can't happen, just terminate
# Constant Folding:
- simplify constant expressions at compile time
- ![[Pasted image 20240222181558.png]]
- Compilers can refuse to compile detected UB. MSVCv19 `over flow in constant devision is undefined behavior`
- -> Compilers can produce different results on UB
- -> Tests may not account for unexpected optimizations. Use your values (return from main, print to console, ...)
# Pointer Arithmetics
- Be careful when adding pointer type (int) and `size_t`.
-  Be careful  when using `NULL` with pointer arithmetic `NULL + len/2` is UB
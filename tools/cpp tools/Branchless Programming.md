---
tags:
  - tool
  - cpp
  - performance
  - branchless
---

<iframe width="560" height="315" src="https://www.youtube.com/embed/bVJ-mWWL7cE?si=77_olZl7_V9rRtOb" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# What is a Branch

Basically when there is a condition in the coed
- `if`
- switch case
- ternary operator

CPU tries to stay ahead of what is going to happen (branch prediction/guessing)

If prediction is wrong, the cpu needs to flush and reload the branch

-> Branchless programming can be faster as flushing and reloading takes a long time

# Example 1

```cpp
int smaller(int a, int b)
{
	if (a < b)
		return a;
	else 
		return b;
}
```

If `a` and `b` are equally distributed, you have a 50/50 chance, which is fine

```cpp
// branchless, not good!!
int smaller_branchless(int a, int b)
{
	return a*(a<b) + b*(b<=a);
}
```

- No if statement, just arithmetic with comparison
- Additions and multiplications can of course be stringed together

> [!warning] Compilers a very good at optimizing

The branchless example is way slower than the branching example.

> [!info] Always check assembler code if attempting this

# Example 2

```cpp
void toUpper(char* d, int count)
{
	for (int i = 0; i < count; ++i)
	{
		if (d[i] >= 'a' && d[i] <='z')
		{
			d[i] -= 32;
		}
	}
}
```

look for `ja`instructions in assembler

## Branchless Version (1)

```cpp
void toUpper_branchless(char* d, int count)
{
	for(int i= 0; i < count; ++i)
	{
		auto const check = d[i] >= 'a' && d[i] <= 'z');
		d[i] = 
		(d[i] * !check) +
		(d[i]-32)) * check);
	}
}
```

Branchless version is 1s to 3s (speedup of x3)

## Branchless Version (2)

```cpp
void toUpper_branchless(char* d, int count)
{
	for(int i= 0; i < count; ++i)
	{
		d[i] -= 32 * d[i] >= 'a' && d[i] <= 'z');
	}
}
```

Much faster than the original

# Conclusion

- Branches are slow
- Compiler often is a very good optimizer
- Can have massive performance gain
- Always check with a concrete measurement if it is worth the effort

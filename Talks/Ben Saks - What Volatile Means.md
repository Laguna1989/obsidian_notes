---
tags:
  - Talk
  - cpp
  - cppcon2024
---

> [!info] Meaning of Volatile
> - `volatile` informs the compiler that the object may change state even tough the program did not change it
> - The compiler must assume that reading or writing a `volatile` value may have side effects
> - Side effects from multiple `volatile` accesses might be related.
> - The compiler must not "optimize away" an access to a volatile object, even when it seems safe to do so

<iframe width="560" height="315" src="https://www.youtube.com/embed/GeblxEQIPFM?si=iJJtkr2BDaHZl5Op" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

- `volatile` is a vital tool for preventing compiler opzimizations
- Often misapplied
	- Prevents optimizations
	- Fail to provide th expected protection, leading to runtime bugs

# Why Volatile?

- How to place volatile in object declarations
- What protections `volatile` does and and does not provide
- Workarounds for compiler issues regarding `volatile`

# When is it Neccesary: Device Drivers

- When writing device drivers
	- A subsystem that controls and reads external devices
	- "outside" the CPU
- Communication via device registers
	- **control** registers
		- configuring the device or initiate an operation
	- **status** registers
		- provides information about the device's status
	- **transmit** register
		- sends data values to the device
	- **receive** reigisters
		- recieve data values from the device
- Device drivers have multiple of those registers
- Hardware design uses memory map addressing
	- A registers is made to look as if it were in a specific memory location

## UART Output

- Buffers:
	- Transmit Buffer: UTXBUF
	- Status Buffer: USTAT
- Check USTAT for TBE (transmit buffer empty) bit == 1
- Do **not** write anything to UTXBUF until TBE is 1
- Storing a character in UTXBUF will initiate output to the port and clears TBE in USTAT
- The hardware sets the TBE back to 1 when the operation is completed

## Example Code

```cpp
std::uint32_t& USTAT0 = *reinterpret_cast<special_register*>(0x0FFD008);
std::uint32_t& UTXBUF = *reinterpret_cast<special_register*>(0x03FFD00C);
```

> [!warning] volatile explicitly omitted here to demonstrate why it is necessary.

- Write a single byte to the UTXBUF:

```cpp
while((USTAT0 & TBE) == 0) {}
UTXBUF0 = c;
```

- The busy loop is obviously not optimal
- Besides that, this code looks like it should work. But the optimizer will just make this code fail.

# The Issue with Device Registers

- Although they look like ordinary memory, the are not.
- Writing and reading from them has massive side effects.
- The optimizer will optimize away the crucial logic

In the example above, the loop will either loop forever or turn into a noop.

# Solutions

- Avoid optimizations for a region of code
	- Might be overkill as we still want fast hardware devices
- `volatile` can provide a more precise solution

# Example with Solution

```cpp
std::uint32_t volatile& USTAT0 = *reinterpret_cast<special_register*>(0x0FFD008);
std::uint32_t volatile& UTXBUF = *reinterpret_cast<special_register*>(0x03FFD00C);
```

# Cv Qualifiers

- C++ talks about cv qualifiers (const/volatile)
- Almost all rules regarding the placement and meaning of `const` also apply to volatile
- `cons`/`volatile` is a type specifier, so it contributes to the type
	- `int const *p;`
- `cons`/`volatile` can appear as a declarator specifier
	- `int * const p;`

# Atomicity is not Guarnteed

- `volatile` is not capable of synchronizing between threads
- Use `mutex`s and `semaphore`s for that

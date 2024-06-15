- If all data used by threads is read-only, there is no problem
- Update of complex data structures needs to break invariants while update is running (e.g. removing an node from a linked list)

# Race Condition

> [!quote] This is a race to see who is first to access the resource.

> [!quote] Data races cause dreaded undefined behaviour.

- Race conditions are hard to identify and even harder to debug,
    - The debugger changes timings (even slightly)
- Either or:
    - Create guarding mechanisms or
    - Lock-Free Programming (very hard to get right)

## Using Mutexes

- Basic Idea: create a `std::mutex` and `lock()` it whenever a variable is used. Call `unlock()` when using the variable is finished.
- Bad Idea, because of exceptions.
- Better: RAII class: `std::lock_guard guard{mutex};`
- C++17 will introduce `std::scoped_lock`, which can lock one or multiple mutexes, while `std::lock_guard` only locks one mutex at a time.
- DO NOT hand out references or pointers to variables which need to be protected via mutex -> loophole
- Be also careful with functions taking pointers or references.
- Be especially careful with user provided member functions.

## Problems Can Be Inherent in the Interface

- `Stack` class provides `top()`, `pop()` and `empty()`
- In a multithreaded environment it is unsafe, because any other thread might access a push or pop between two of those calls in the main thread. This will lead to data races.
- Possible solutions:
    - Create one function that combines `top()` and `pop()` and protects the data internally with a mutex and throws an exception if stack is empty.
        - If copy construction of T throws? e.g. `stack<vector<int>>` this will not work.
    - Return reference `void pop(T&);`
        - Undesirable for T which needs complex initialization.
    - Return a pointer to the popped Item: `std::shared_ptr<T> pop();`
        - Stack owns the memory until it is popped.
        - After that, the user of the stack class has full control over memory via the `std::shared_ptr`.

# Deadlocks

> [!quote] A deadlock is the opposite of a data race.

> [!quote] Instead of racing to be first, each thread waits for the other one to finish first.

- [Example](https://ideone.com/0Ql0S2) for deadlock avoiding swap
- Always acquire a lock first and block second to avoid cases where mutexes cannot be locket at the same time
- Another case would be two threads calling `join()` on the other one
- [!] Don’t wait on another thread if there is the chance it is waiting for you.
- [!] Don’t acquire a lock if you already have one.
- [!] Don’t keep any locks while calling user code
- [!] Acquire locks always in the same order
- [!] Use a lock hierarchy (see code example in the book)

# std::unique_lock

- can be used to `lock`/`unlock` mutexes (useful when calling user code)
- can be used with `std::defer_lock` (leaves mutex unlocked on construction)
- `owns_lock()` can be used to query if the unique_lock actually owns the mutex.
- is bigger and slower than a `std::lock_guard` (storing/checking flags, …)
- is movable but not copyable
- move allows to transfer ownership (e.g. when returning a `unique_lock` from a function)
- Example: function acquires lock, passes it to the caller, who can then perform additional actions (e.g. a gateway class to access data)

# Lock Granularity

- Fine granularity: Lock protects only very little data
- Coarse granularity: Lock protects a lot of data
- Balance granularity:
- It is necessary to choose a sufficiently coarse lock granularity to protect the data
- It is important to hold a lock only for the operations required to avoid slowdowns (threads waiting for locks to be released)
- Try to process data outside of a lock
- Don’t do any time consuming operations (I/O, waiting for another lock, …) while already holding a lock.
- BUT: Always hold a lock for the entire time of an operation to avoid race conditions

# Protecting Data (only) during Initialization

- Imagine a costly type to initialize (e.g. database connection, big class that needs a lot of memory)
- [infamous double check](https://ideone.com/p3FZLI) is a bad idea
- Use of [call_once](https://de.cppreference.com/w/cpp/thread/call_once) and [once_flag](https://de.cppreference.com/w/cpp/thread/once_flag): see this [correct example](https://ideone.com/uFYDuD).
- Can also be used as class members
- `once_flag` is not copyable and not moveable. If those operators are required by a class, they have to be created

# Protecting Rarely Updated Data

- This is also call reader-writer mutex
- If data is only updated from now to then, but frequently read, using a mutex seems over-protective.
- Example: [DNS Storage](https://ideone.com/S6aNxx)

# Recursive Locking

- Most often a sign of sloppy design (function a calls function b, while a holds a mutex. This means b must work with broken invariants, which complicates interfaces)
- Try to avoid, if possible. Redesign the class.

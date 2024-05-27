

## Managing Threads

* Every Program has at least one thread ( `main()` )
* Program can launch additional threads via `std::thread t{callable};`
* callable can be any callable object, e.g. a [function](https://ideone.com/tdR2oU), a [functor](https://ideone.com/1scn59) or a [lambda](https://ideone.com/rRAkOi).
    * Careful: “object” is copied to the thread. It is essential, that the copy behaves as the original.
* threads have to be joined (wait for thread to finish) or detached (keep it alive) before thread object goes out of scope. Otherwise, `std::terminate` will be called from the thread destructor.
* data has to be valid until thread function ends (which will end also a detached thread).
* => Thread functions should be self contained and own the data they use, e.g. by copy.
* => Careful when using pointers or references
* `t.join()` can only be called once for a thread.
* After `join()`,  `t` is no longer attached to the thread and `joinable()` will return false.


## Exceptions and threads

* `detach`: no problem, thread destruction will not call `std::terminate()`
* `join`: when dealing with exceptions, make sure to call join in exceptional & non-exception cases (both)
    * Better solution: Use a [Thread_guard class](https://ideone.com/UjbbYG) that calls join in the destructor
* `joinable()` has to be checked, before calling `join()` or `detach()`.
* You can only call detach if joinable() returns true.


## Passing Arguments to threads

* just pass it as additional arguments to `std::thread` constructor: [example](https://ideone.com/7eJhfw)
* Make sure that data is still valid when thread execution happens (e.g. pointers)
* Arguments are copied, even if function takes an parameter by reference
    * Use `std::ref` if required.
* If argument can only be moved, it has to be done so by an explicit call to `std::move` (leaving the original data empty), e.g. `unique_ptr`


## Thread Ownership

* threads can only be moved (but not copied!)
* Be careful not to overwrite a non-joined thread (by accident). This will call terminate. [Example](https://ideone.com/YmazCV)

[Concurrent Accumulate example](https://ideone.com/gQF0Gi)


## Identifying Threads

* `t.get_id()` member function of `std::thread`.
* `std::this_thread::get_id()` static member function.
* identifiers cann be copied and fully compared. Hashing is also possible.
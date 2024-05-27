

# The c++ memory model



* Two important aspects: Structure and concurrency
* Every Object is defined as a region of storage.
* An object can be something simple like an int or a complex class
* bitfields are a bit special.

Modification Order



* Every Program has a modification order, which can (read will) vary between runs.
* starts with object initialization.
* normally the programmer needs to take care of modification order by implementing some sort of synchronization.
* atomics place the responsibility for choosing the modification order with the compiler.

Atomic operations



* More basic than mutexes.
* they do not prevent race conditions, but remove the undefined behavior.
* “invisible operation” = cannot be watched half-done
* example:
    * A non-atomic data type is written from one thread and read from another one. The reader thread can see e.g. half of the data written, while the other thread is still in the process of writing it.
    * This cannot happen with atomic data types. Here the reading thread sees either the initial or the completely modified value.
* mutexes can be used to make any operation “appear” atomic.
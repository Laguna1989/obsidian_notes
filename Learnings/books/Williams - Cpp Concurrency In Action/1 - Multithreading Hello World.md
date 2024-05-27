## Concurrency Basics
* Concurreny: Two or more activities happening at the same time
* OS schedules tasks even on single core machines (appear to run parallel)
* Overhead of Task Switching
* Concurrency with multiple processes
    * One Thread per process
    * Separated memory
    * Communication between processes is hard to setup / restricted by the OS
    * Can be used e.g. over a network
    * not supported by C++
* Concurrency with multiple threads in one process
    * Shared memory
    * less overhead
    * intrinsically supported by C++


## Why Concurrency:

* Separation of Concerns
    * grouping related bits of code
    * keeping e.g. GUI responsive
* Performance
    * Speed by Running multiple tasks in parallel
    * Task Parallelism
        * One thread performs a task at a time
        * “embarrassingly parallel” algorithms
    * Data Parallelism
        * Each thread works on its own set of data, thus getting the whole set done faster.


## Why Not Concurrency:

* Not worth the cost (maintaining, logical complexity)
* Overhead of launching a Thread and context switching
* Too many threads make a system slow (e.g. reuse threads in a thread pool)
* Scalability (Server creates one thread for every connection -- will crash for large networks)


## History

* No Multithreading in C++98
* Boost or ACE libraries, C APIs 
* C++11 supports threading based on Boost
* C++14 only little changes (shared_mutex)
* C++17 (parallel algorithms)

[Multithreaded Hello World C++ Programm](https://ideone.com/tdR2oU)

* Every new thread needs an initial function (like main for the main thread of the program).
* `t.join()` will make the main program wait, otherwise it will eventually finish before `t` was scheduled.
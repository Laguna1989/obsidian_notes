## Synchronizing Data

* Analogy: driving on a night train and waiting for the stop:
    * Staying awake all night, waiting for your stop (actively waiting for shared data flag)
    * Short sleeps (same as above, but with this_thread::sleep_for()) - possible overslpeeing & still ineffective: talking to the train operator keeps him from working
    * Best: Synchronization via condition variables/futures


### Waiting for a condition via condition variables

* Used via 
    * std::condition_variable (works for std::mutex)
    * std::condition_variable_any (works with anything mutex-like, possible additional overhead)

[Example program](https://ideone.com/okWFOJ)


* wait() executes the lambda. 
    * If the lambda returns true, the thread will continue with the processing of data (pop in this case)
    * If the lambda returns false, the lock will be unlocked, until the condition_variable will be notified from the write thread.
* notify_one() can be used to start work one waiting worker thread (pop a value)
* notify_all() can be used to start work on all waiting threads (all threads process the same data without change) -- could possibly be replaced by std::call_once()...


## Futures

* One-off events
* Cannot be reset
* Can be associated with data
* Analogy: Waiting at the airport for your plane.
* std::future (like unique_ptr) and std::shared_future (like shared_ptr)
* shared futures will all become ready at the same time.
* std::async works like spawning a thread, but they return a future with the result. [Example](https://ideone.com/trdZ0I)
* same syntax as with threads, regarding copy or reference parameters
* async can be launched deferred (in the same thread when wait/get is called) or async (new thread). By default the implementation chooses.


### Package_task

* Binds a future to a callable object
* can be used in threadpools
* arguments/return value don’t have to match exaclty (conversions are ok)
* If std::package_tast&lt;void()> is called with a function returning anything but void, the return value is silently discarded.


### Promise and Future

* Future is tied to promise (promise.get_future())
* promise.set_value() makes the future ready
* future.get() can only be called once!
* discarding the promise before calling set_value sets an exception on the future.
* exceptions can be set directly via promise.set_exception(std::current_exception()) or std::make_exception_ptr(...)

std::shared_future



* concurrently accessing std::future is not possible (without further mechanisms)
* std::shared_future is copyable (std::future is only movable)
* every thread has its own copy of std::shared_future
* concurrent access is allowed by the library.
* std::shared_future can be created by moving a std::future into a std::shared_future.
* the future needs to be valid before moving and is invalid after the move.
* or simpler:
* auto sf = p.get_future().share();


### Waiting with a timeout

* wait_for (duration)
* wait_until (timepoint) 
* most wait functions offer both variants
* functions offer a std::future_status, which can be timout, ready or deferred


### Clocks

* A clock is defined by the following informations:
    * the time now()
    * type of the value used to represent the time
    * tick period
    * uniform or not (_steady)
* standard clocks:
    * std::chrono::system_clock (system time, not steady)
    * std::chrono::steady_clock (steady clock)
    * std::chrono::high_resolution_clock (might be a typedef to one of the others)


### Continuation Futures

* currently only available throughout std::experimental, see this [example](https://ideone.com/WDbzX7)
* std::future.then() is executed when the task is ready, without having to call get() or wait()
* continuation runs in “an unspecified thread”, which gives the implementor the freedom to run it e.g. in a threadpool
* passing parameters to continuation functions is not possible, because the argument is already known: the experimental future.
* if the first future holds an exception, this eception is passed to the continuation future as well.

### Latches and Barriers

* A latch is a lightweight object, that becomes ready once it’s counter is reduced to zero. It can be used to wait until a series of events has occurred. It is not important, which thread(s) decrease the counter
* A barrier is blocking in each thread, until all threads have reached the barrier in a cycle. A thread waits at the barrier for all other threads. After that, a barrier can be reused.
* Flex_barrier can be provided with a completion function, which is called, whenever all threads havev reached the barrier.
---
tags:
  - book-chapter
  - testing
---

> [!info] from [[Khorikov - Unit Testing - Principles, Practices and Patterns]]

> There is much more to unit testing than the act of writing tests

- Learn to differentiate between good and bad tests

# The Current State of Unit Testsing

- Unless you are working on a throw-away project, the answer to "should you do unit testing?" is "you do!"
- Ratio of impl to test code is 1:1, up to 1:10
- How to write **good** unit tests?
- Writing good tests is a matter of succeeding or failing at this critical project you are working on
- Next level: Not just writing tests, but doing so in a way that provides best return on your efforts
- Most suitable for enterprise applications, but applicable elsewhere
	- Enterprise application criteria
		- High business logic complexity
		- long project lifespan
		- Moderate amount of data
		- Low or moderate performance requirements

# The Goal of Unit Testing

- The requirement to write tests for a code base normally leads to a better design, but that is often just a pleasant side effect

> [!info] Relationship between unit testing and code design
> - Code that is hard to test is a strong sign that the code needs improvement
> - The ability to easily unit tests does not make the code design good quality by itself

- The Goal of Unit Testing is to enable sustainable growth of the software project
	- Without Tests the time spent for making more progress increases exponentially.
	- With Tests the time increases linearily
	- This is called *Software Entropy*
- Tests provide insurance against a vast majority of regressions
- Sustainability and Scalability are the keys

> [!warning] Note
> - The downside of writing tests is that they require initial, sometimes significant effort
> - They pay for themselves in the long run by helping grow the project in the long run

## What Makes a Good or a Bad Test?

- It is not enough to just write tests
- Bad Tests help a tiny bit, but in the grand scheme of things they do not make a difference
- Bad Tests
	- Raise false alarms
	- don't help to catch regressions
	- Slow and difficult to maintain or run
- When writing tests, consider
	- The value of the test
	- The upkeep cost
- Upkeep is determined by
	- Refactoring the test when refactoring the underlying test
	- Running the test on each code change
	- Dealing with false alarms
	- Spending time reading the test when understanding how the underlying code behaves
- Ideally focus on hi quality tests

> [!info] Production Coed vs Test Code
> - Code is a liability, not an asset
> - Tests are also code
> - More tests is not always better
> - It is better to solve problems with as little code as possible
> - Just as normal code, tests are vulnerable to bugs and require maintenance

# Using Coverage Metrics

> [!info] See also [[Mutation Tests - 100 Percent Test Coverage]]

> [!info] Coverage metrics
>  - A High coverage metric does not imply good code quality
>  - A High quality code will have good coverage nevertheless

> Coverage metrics only provide information that specific code was executed, not that it did behave correctly.

## Understanding Test Coverage Metrics

```
Line Coverage = Lines of Code Executed / Total Number of Lines
```

- Line coverage strongly depends on the actual formatting (e.g. if converted into boolean return or ternary operator)
- More compact code usually has a higher line coverage. That does not mean that those tests have higher value

```
Branch Coverage = Branches Traversed / Total Number of Branches
```

- Branch Coverage is more robust under formatting/refactoring, but not oblivious to it

## Problems with Coverage Metrics

- You cannot guarantee the test to verify all possible outcomes
	- The tests need to have appropriate assertions for the respective code paths
	- You need to verify all components of an outcome for the coverage to be truly meaningful
	- This includes any side effect (static or global data, printouts, ...)
	- ⚠ Assertion Free tests are completely meaningless
- No coverage metric can take into account code paths from external libraries
	- Even calls as simple as parsing an int might have an unexpected high number of branches
	- Examples are: null values, exceptions, in-/output too large, exceeding memory, ...

## Aiming at a Particular Number

- Relying on any specific coverage target does not make sense at all
- Coverage is only an indicator and never a goal in itself
- Coverage goals always creates an perverse incentive. Instead of testing things that matter, people focus on meeting this artificial target and "game" the system

# What Makes a Successful Test Suite?

- **NOT**: coverage metrics
- Evaluation for tests one by one, gradually
- No automated way, only personal judgement
- Properties:
	- Integrated into the development cycle
		- Automated, running at least with every commit/push
	- Targets the most important parts of your code
		- Most important part is the business logic
		- This requires an isolated domain model (isolated from: infrastructure, external dependencies, glue code, ...)
	- Provides maximum value with minimum maintenance

# What You Will Learn in This Book

- A frame of reference to analyze any test
- Analysis of existing testing techniques and practices

# Summary

- Code tends to deteriorate (entropy)
- Tests help with keeping quality high, allowing for fast development
- Writing tests is important
- The goal of Unit tests is to enable sustainable growt
- Tests have a cost (as all code)
- Testability and Test Metrics as a way to detect bad code

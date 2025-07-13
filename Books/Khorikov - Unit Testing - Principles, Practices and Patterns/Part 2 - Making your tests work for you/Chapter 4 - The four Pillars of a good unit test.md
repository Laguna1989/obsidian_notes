---
tags:
  - book-chapter
  - testing
---
> [!info] from [[Khorikov - Unit Testing - Principles, Practices and Patterns]]


- How to recognize a valuable unit test?
- Popular testing concepts

# Diving into the Four Pillars of a Good Unit Test

- Four attributes
	- Protection against regressions
		- How much code is executed during the test?
		- The complexity of that code
		- The code's domain significance
	- resistance to Refactoring
		- Refactoring does not change the functionality, so tests should not break by refactorings
		- Avoid such False Positives at all costs
			- The more a test is coupled to implementation details, the more false alarms are triggered
			- Decouple the test from the implementation. Tests should care about observable behavior, not about ways to get there
		- Aim at the end result instead of verifying implementation details
	- Fast feedback
	- Maintainability
		- How hard is it to understand the test?
		- How hard is it to run the test?
- Maximizing Test accuracy
	- Combination of "detect regressions" and "resist refactoring"
	- Avoid false Positive and false negatives
	- Either a statistical approach or signal to noise ratio
	- In short term a false negative is very bad but a false positive is no issue.
	- in long term false positives are detrimental to the trust in the tests

# In search of the Ideal Test

- Value estimate of a test is a product of the individual attributes (each in range 0-1)

## Extreme Example: End to End Tests

- End 2 End tests cover a lot of code and thus cover a lot of regressions
- Immune to false positives and refsctorings
- Main Drawback: Slow

## Extreme Example: Trivial Tests

- Covers a simple piece of code
- Fast feedback
- Low chance of false positive
- Drawback: don't find regressions

## Extreme Example: Brittle Tests

- Runs fast
- Good chance of finding regressions
- Drawback: not immune at all to refsctorings

## Ideal Test

- Mutually exclusive attributes
- Resistance to refactoring is never negotiable (mostly just a binary attribute)
- it boils down to a slider between "protection against regression" and "Fast Feedback"

> [!info] The CAP theorem (data storage)
> - Consistency
> - Availability
> - Partition Tolerance

# Exploring Test Automation Concepts

## The Test Pyramid

- Unit tests (catch errors early)
- Integration tests
- End to End Tests (only where you never want to see any bugs)
- "protection against regression" (end to end tests and "Fast Feedback"(unit tests)
- The mix of tests is individual to each team

# Black Box and White Box Testing

- **Black Box** - examines the SUT without knowing the internal structure. Tests What instead of How
- **White Box** - Testing inner workings of the SUT. Derived from the source code, not from requirements

> [!Summary]
> - Foundational attributes
>	- Protection against regressions
>	- Resistance to Refactoring
>	- Fast feedback
>	- Maintainability
>- A false positive is a false alarm and should be avoided
>- A tests value is the product of all attributes
>- Resistance to refactoring is non-negotiable
>- The test pyramid with unit tests, Integration tests and end to end tests
>- Black box and white box tests

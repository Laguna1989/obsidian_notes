---
tags:
  - book-chapter
  - testing
---
> [!info] from [[Khorikov - Unit Testing - Principles, Practices and Patterns]]
# The Definition of "Unit Test"

- A Unit test is an automated test that
	- Verifies a small piece of code (known as the "unit")
	- Does it quickly
	- Dos it in isolation

The isolation part leads to a separation between Classic and London TDD

> [!info] Classic and London TDD
>  Classic TDD
>  - Based on [[Kent  Beck - Test Driven Development]]
>
>
>  London TDD (mockist)
>  - Based on [[Growing Object-Oriented Software, Guided by tests]]

## The Isolation Issue: The London Take

- In order to test in isolation, all dependencies have to be replaced by Test Doubles
- This allows to focus on the class in isolation
- If the test fails, you know exactly which part failed
- Allows to split the object graph

## Example

> [!info] See also [[Three As of Unit Testing]]

> [!info] Method under test (MUT)
> The Method under test is one method in the SUT that is called by the test. Often synonymous with SUT, but MUT is just one function, while SUT is the whole class

### Classic Style

- Store - Customer - Inventory
- Classical test: Do not replace the collaborator, but use a production-ready instance of it
- The test verifies both Customer and Store class

### London Style

> [!info] Mock
> A mock is a special kind of Test Double that allows to examine interactions between the SUT and its collaborators.

- Set up Mocks instead of production ready instances
- Directly telling the mock instance how to react
- Assertion changes to verify expectations on the Mock

## The Isolation Issue: Classical Take

- Isolation requirement does not need to be the code: It can also be the individual tests

> [!info] Shared, private and out-of-process dependencies
> - Shared Dependency
> 	- Shared between test cases
> 	- Will lead to interdependent tests
> - Private Dependency
> 	- Just within one test case
> - Out-Of-Process Dependency
> 	- Affected by multiple test executables/production code run in parallel
> 	- E.g. a Database

The classic approach states that private dependencies can still be used in tests to keep isolation

> [!info] Volatile dependencies
> as introduced in [[Mark Seeman - Dependency Injection]]

Shared dependencies might be introduced to speed up test execution

# The Classical and the London Schools of Unit Testing

- Main difference is the isolation topic
- This leads to disagreement with
	- What is a "unit"?
	- How to handle dependencies?

## Handling Dependencies

- London TDD allows to keep immutable Dependencies or value objects
- A collaborator is a dependency that is either shared or mutable

# Contrasting Classical and London

- Most of the time, tests with mocks are more brittle
- Benefits of London TDD
	- Better Granularity
	- Easier for large dependency graphs
		- A large dependency graph is a design flaw in itself
	- If a test fails, you get immediate feedback which part failed
		- Often this is not an issue if tests are run frequently
- A unit can also be a "unit of behavior"
- Other differences
	- London style is outside-in TDD
	- Classical style is inside-out TDD

# Integration Tests in the Two Styles

- Based on the unit test requirements, an integration test is
	- A test that can not be run in isolation
	- A test that takes a long time to run
	- A test that verifies two or more behaviors
- End to End tests are a subset of Integration tests that include also out-of-process dependencies

> [!summary]
> - Definition of a unit test in classical style
> 	- Verifies a single unit of behavior
> 	- Does it quickly
> 	- Does it in isolation from other tests
> - The Isolation issue is what caused different styles (classical, London) of TDD to spawn
> - Integration test is a test that does not meet at least one of the definitions

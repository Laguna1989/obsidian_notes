---
tags:
  - book-chapter
  - testing
---

> [!info] from [[Khorikov - Unit Testing - Principles, Practices and Patterns]]

- Mocks are a controversial subject, mostly fueld by the London/Classical discussion
- There is a deep coneection between mocks and test fragility

# Differentating Mocks from Stubs

## The Types of Test Doubles

- "Test Double" is an overarching term describing all fake dependencies in tests
- Imagine a "Stunt Double" in movies
- Test double types
	- Mock Group (examine outgoing behavior)
		-  Spy (handwritten mocks)
		- Mock (created by a testing framework)
	- Stub Group (examine incoming behavior)
		- Dummy (simple hardcoded value)
		- Stub (can be configured to return different values)
		- Fake (more sophisticated than a stub)

## Mock (the Tool) Vs Mock (the Test Double)

The class from the mocking library (tool) is different from the actually created mock

## Don't Assert Interactions with Stubs

- Stubs only help to emulate incomging interactions (they should not be asserted)
- Tests should verify the end result, not the incoming data
- It does not matter how the SUT creates the end result as long as the result is correct

## Using Mocks and Stubs together

- If a test double is examining both incoming and outgoing behavior, it is always considered a mock

## Relation to Command Query Separation

> [!info] See also [[Command Query Separation]]

- Test doubles that substitute commands become mocks
- Test doubles that substitute queries become stubs

# Observable Behavior Vs Implementation Details

- Test Fragility/resistance to refactoring originates in [[Chapter 4 - The four Pillars of a good unit test]]
- The only way to avoid dependencies on implementation details is to use mocks

## Observable Behavior and Public API

- Not the same
- A method can never be in both public and private API
- A method can never be in both observable behavior and implementation detail

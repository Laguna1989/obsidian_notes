---
tags:
  - book-chapter
  - testing
---
> [!info] from [[Khorikov - Unit Testing - Principles, Practices and Patterns]]
# How to Structure a Unit Test

- [[Three As of Unit Testing]]
- [[Given When Then Pattern]]
- Where to start:
	- Start with Arrange
	- Alternatively one can also start with Assert and work you way backwards

## Avoid Duplicated Sections

- One may encounter tests with multiple arrange, act or assert sections
- This is an indication that testing is not done in isolation
- Also the test does test multiple units of behavior
- If this is the case, the test should be split into several tests to fix the problem
- It might be fine to have multiple act sections in an integration test to speed up the test

## Avoid If-Statements in Tests

- A test should be a simple sequence of steps without branching
- An if statement is an indication that too many things are verified at once
- There are no benefits to branching within a test
- In fact, they make the test harder to read and understand

## How Large Should Each Section Be?

- Arrange should be the largest section
	- common or even lengthy setup code should be extracted into helpers
- Act sections should ideally be a single line or a single statement
	- Might be an indicator of bad design. If two call belong together, they should be grouped via a respective API
	- -> This is called *Invariant Violation*
- Number of assertions:
	- Ideally there should be one assertion
	- More assertions can be valid if the unit of behavior has multiple outcomes
	- Too many assertions are an indicator of missing abstraction
- Teardown?
	- Most unit tests should not have a teardown section because they don't have out-of-process dependencies

## Differentiating the System under Test

- SUT can be a single method or (in classic TDD) many collaborators
- It has a single entry point
- Naming suggestion: To differentiate the SUT from dependencies, name it `sut`

## Dropping 3A Comments

- Separate different blocks by Arrange, Act, Assert comments
- Alternatively, separate them by empty lines

# Exploring the xUnit Testing Framework

- All testing frameworks work roughly identical
- Going into details about [xunit](https://xunit.net/)

# Reusing Test Fixtures between Tests

- Reusing code from arrange sections is a good way to shorten and simplify your tests
- Extract Setup functions into separate helper functions

> [!info] Test Fixture
> There are two common uses
> - A test fixture is an object the test runs against
> - An attribute that marks a class containing tests

## Reuse Dependencies (test fixture) via the Test Class Constructr

- Initializing and reusing dependencies between tests is an anti-pattern, as it creates high coupling
- Using the constructor reduces readability

## Better: Private Factory Functions

- Allows for reuse
- Avoids coupling between test cases
- Integration tests might still benefit from shared dependencies.

# Naming a Unit Test

- Use expressive names
- One option: `[Method]_[Scenario]_[ExpectedResult]` is one of the most common and least helpful naming schemes
	- makes you focus on implementation details
- Avoid cryptic names and repetition in test names

## Unit Test Naming Guidelines

- Don't follow a rigid naming policy. One cannot fit high level descriptions into narrow boxes
- Name tests as you would describe them to non programmers
- Separate names with underscores

> [!warning] naming
> The MUT or SUT name does not need to be part of the test name

- Avoid "should" or similar words in the test name

# Refactoring to Parametrized Tests

- One test is normally not enough to describe behavior
- Grouping tests together by parametrization is a good thing
- Group input and expected output in test data
- Grouping positive and negative tests is a good pattern

## Fluent Tests

- Value.should.be reads as plain English

> [!Summary]
> - All tests should follow the [[Three As of Unit Testing]]
> - The act section should just be one line
> - Name the SUT sut in the test
> - Reuse code by applying factory methods
> - Don't follow a rigid naming policy
> - Use Parametrized tests
> - Use fluent assertions


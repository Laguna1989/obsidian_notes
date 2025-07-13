
> [!info] Each unit test should have three parts
> - Arrange
> - Act
> - Assert

# Overview

- Also called 3A Pattern
- Provides a simple, uniform structure for all tests in the suite
- Makes it easy to read and understand any test
- Reduces Maintenance Cost

# Structure

- Arrange
	- Bring the system under test into the desired state
- Act
	- Call the MUT
	- Pass prepared dependencies (if any)
	- Capture output (if any)
- Assert
	- Verify the outcome (return value, changed global state, final state of the SUT, any method being called on collaborators, ...)

> [!info] See also [[Given When Then Pattern]]

# Links

- [The three A’s of Unit Testing - DEV Community](https://dev.to/coderjay06/the-three-a-s-of-unit-testing-b22)

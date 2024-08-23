---
tags:
  - conference
  - SoCraTes-2024
  - testing
---

[GitHub - mkutz/untangle-your-spaghetti-test-code](https://github.com/mkutz/untangle-your-spaghetti-test-code?tab=readme-ov-file)

# Tangles

[TANGLES.md](https://github.com/mkutz/untangle-your-spaghetti-test-code/blob/main/TANGLES.md)

![[IMG-2024-08-22-144114805.png]]

- Hidden Arrange
	- Issue: setup not visible `data.sql` is very hidden
	- Explicitly create unicorns instead of having a predefined list
- Too many assertions
	- Dump all assertions and combine them to ideally have a single assertion
- Test does not check for non-existence
- Test case names are inconsistent
- Happy test case does not need the expected outcome
- Use random valid values as test input as a way of expressing "I don't care which valid value I get"
- Use the [[Builder]] and/or [[Prototype]] design pattern also in test code
- Think about testing on the right level (unit, integration, ...)
- Think about using [[ApprovalTests]] or [[Property Based Testing]] when appropriate

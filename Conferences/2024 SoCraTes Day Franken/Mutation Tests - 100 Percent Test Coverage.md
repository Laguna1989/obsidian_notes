---
tags:
  - testing
  - SoCraTes-2024
---
# 100 % Test Coverage

- Start with [[FizzBuzz]] example in typescript
- Example that tests no production code
- Example that has no expectation

> [!danger] Code coverage only checks, which Production code **was called**. It does not check if the tests do meaningful things

# Mutation Tests

> [!quote] Goodhart's Law
> When a measure becomes a target, it ceases to be a good measure

## Who Tests the Test?

- Mutation testing introduces changes to your code, then runs your unit tests again against the changed code
- If no test fails, this is an issue

> [!hint] Mutation tests do not test the code, but test the quality of tests

## Frameworks

In .Net -> Stryker
- E.g. exchanges `<` -> `<=`
- replaces plus with minus
- replaces logical or bool literals
- Initializers

### For C++

[[mutate_cpp]]

## When to Do Mutation Testing

- Do not run in CI as mutation tests are slow.
- Better run in nightly or locally to check deviations

## Mutation Strategies

- mutate source code
- mutate byte code (e.g. in .Net)
- mutate schemata (mutant switching) mutations are added with a lot of if statements and selectively switches on/off those mutations

## Fine-Tuning

- Mutation Testing tests very long
- ▶ files to be tested (e.g. via globbing patterns)
- ▶ mutation levels (how smart are the mutations)
- Git integration (only check changes since last tag/commit)

> [!summary] Summary
> - Non-invasive: No code changes required
> - Great for discovering important corner cases
> - Requires a lot of resources
> - A nice tool next to [[TDD]], [[ApprovalTests]] und [[tools/testing/Property Based Testing]]
> - ⚠ Only useful when test coverage is high enough
> - ⚠ Best used on Unit tests (no dependencies, runs fast)
> - ⚠ Works very well when writing a new test+impl, as the mutation source is rather slow

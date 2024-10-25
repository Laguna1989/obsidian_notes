---
tags:
  - tool
  - git
---

> [!info] Performs bisection between good and bad commits to find the commit that caused an issue

# HowTo

## Setup

```bash
git bisect start
```

```bash
git bisect good [commit id or tag]
```

```bash
git bisect bad [commit id or tag]
```

This results in the following output

```
Bisecting: 6 revisions left to test after this (roughly 3 steps)
```

## Process

- Perform the test if the issue is still there and check if the output is good or bad
- type

```bash
git bisect good
```

or

```bash
git bisect bad
```

With each step, the number of commits to be checked is halved.

## End of Process

after all commits have been checked, a message is printed

```
[commit hash] is the first bad commit
```

This is the commit where to search for the issue.

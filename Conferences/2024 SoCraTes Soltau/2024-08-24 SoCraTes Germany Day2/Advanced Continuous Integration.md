---
tags:
  - conference
  - SoCraTes-2024
  - continuous-integration
---
# Practices for CI

- Make all changes small and incremental
- **Commit frequently**
	- Really small, incremental changes
	- This requires discipline and a specific sequence in which you work
	- Hide functionality
		- Could be done via feature flags
		- Alternatively if new functions are not used you can
- Decouple the Code Base
	- Hexagonal architecture
	- [[Dependency Injection]]
	- Hide Unfinished Functionality
- Automate the build
- Adopt Expand-Contract (Strangler Pattern)
	- Intentional duplication
	- Idea:
		- Duplicate code
		- Do your work
		- Replace the old functionality
- Run a local build
- **Have a fast build**
	- What is fast?
	- [[Kent Beck - Extreme Programming Explained]] says max 10 minutes
	- some devs say 30s
	- Have a *Commit Build* (fast), resulting in an artifact
	- The artifacts are pulled by an acceptance test that runs
	- Whenever an acceptance test fails, you need to write a Unit test to make sure the same issues never happens again.
	- Ideally an acceptance test takes 10 minutes
	- The pipeline only deploys if acceptance tests are failing
- Have a vast amount of automated builds
- Commit only on green
- Agree to never break the build (as a team)
- Do not push *a* broken build
- Do not push *to a* broken build
- Revert immediately when the build is broken
- Version control everything

# Feature Branches or Trunk Based Development

If you work on branches the lead time is the same, but the cycle time is higher

# When to Review with Minimal Commits?

- Do pair programming
- [[Thierry de Pauw - Non Blocking Continuous Code Reviews]] -> [Non Blocking Continuous Code Reviews, a case study - Thierry de Pauw - YouTube](https://www.youtube.com/watch?v=uzUPdQVdwp0)

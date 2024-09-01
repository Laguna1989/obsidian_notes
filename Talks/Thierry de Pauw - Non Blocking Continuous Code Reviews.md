---
tags:
  - Talk
created: 2024-08-25
---
- Purpose of code Reviews:
	- Teams should make a conscious decision
	- Mentoring, learning
	- Knowledge Sharing
	- Check readability and maintainability (code style)
	- Maintain consistent design
		- ⚠ spotting design problems in reviews is too late
- Counter Arguments
	- Four Eyes principles
		- Killer argument to slow down everything and drive down quality
		- Pair or Team programming are way better
		- There is actually negative correlation between process gates and quality
	- "Sense" of security
		- I don't trust my code
		- Dilution of responsibility
		- -> won't be fixed by any process
- What Code Reviews should not be?
	- Exercise of power
	- Display of Hierarchy
	- Conducted by those missing mentoring skills
	- Blaming or Harming
	- A miserable experience
	- A must
	- Gatekeeping (delays feedback and reduces quality)
- Non Blocking Code Reviews
	- Every commit is reviewed
	- There is a kanban board
	- Every ticket is a feature (unit of work)
	- a commit is the unit of integration
	- once a feature is finished, it is added to "to review" onthe kanban board
	- Before starting new work or every morning, the team was looking at the "review" column first
	- Nobody can not be done by the same person
- Stop the code review as the stopping factor if code is releasable
- -> Unreviewerd code could end in production
	- Code Reviews are there to improve code quality, not to stop bugs
- Unit tests, linting and exploratory tests ensured that code in production is free of bugs
- Code quality has no impact on product delivery or productivity
- High code quality allows to add new features faster, that's why you still need code reviews

# Transaction Costs

 The cost of sending a batch to the next stage

If a change takes 10 minutes to implement and 2 hours to be reviewed, code reviews are pretty costly

-> minimize the transaction cost, minimize the cost of code reviews

# Benefits

- Zero impact on total lead time
- Reduces time to market
- We never block the delivery
- Early and fast feedback
- Reduce WIP
- There is some wasted time for rework, but that was way less compared to waiting
	- rework was speed up by a good CI
- Higher Trust

# Tooling

- Atlassian Crucible (discontinued)
- Jetbrains UpSource (discontinued)
- Facebook fabricator (discontinued)
- Git Gerrit (horrible UI)
- Ex-Remit (available on github)
- ReviewBoard (similar to crucible)
- No tooling at all

# Drawbacks

- Difficult in regulated industries
- Again: Pair Programming is better

# Conclusion

- Pair Programming is better than reviews
- Non Blocking code reviews are better than normal reviews
	- There is no gating
	- There is no waiting time
- Little WIP
- Less Context Switching, Less Multitasking
- No Urgency to fix code Quality issues

---
tags:
  - book-chapter
  - devops
---
# Excerpt

Create the foundations of your deployment pipeline

- We must use production-like environments in every part of the value chain
- No manual work to get those production-like environments

Enable on demand creation of dev, test and production environments

- Ways of providing an environment
    - Copying a virtualized environment
    - Building an automated environment from scratch
    - Using Infrastructure as code
    - Using automated OS configuration tools
    - Assembling an environment from a set of virtual images
    - Spinning up an environment in the cloud
- Create a single repository of truth
    - All application code and dependencies
    - All scripts (e.g. for database schemas, …)
    - Environment creation tools
    - Test code
    - Everything for deployment
    - Use hashes to ensure you have the right files
- Make Infrastructure easier to rebuild than to repair
    - Create immutable infrastructure
    - Extend the DoD to run the software in production like environments
    - Same tools for monitoring and escalation are used, giving confidence in the processes
- Continuously build, test and integrate code and environments
    - Increase the frequency of integration, testing and environments from periodic to continuous
    - Keep code in a always-shippable state
    - Catch errors early.
    - Unit tests should complete within max 10minutes
    - Use TDD or Acceptance TDD (ATDD)
    - Automate as many manual tests as possible
    - Integrate Performance testing (long running memory consumption, or performance, empty database entries, …)
    - Integrate non-functional requirements into automated tests
- Create a virtual andon cord
    - Treat as Priority 0 show stoppers and work on the immediately
    - If an acceptance test fails, have people on call who deal with this immediately
- Use Trunk based development, Continuous Integration and Continuous Delivery
- Automate and enable low-risk releases
- Decouple Deployment and Releases
- Architect for low risk releases

# Text for the Book Club Week6

- How would dev and production environments look like when the software is a middleware library, when customers run it on many different systems?
- What about the time it takes for the tools that create/run an environment to spin up? How long would you accept to wait (one time or regularly)?
- Do you have some sort of CI Pipeline? Is your code in an “always shippable” state?
- What is your branching strategy? Do you work on “master” or “trunk” or do you have feature branches? How long do those branches live on average?
- How do you support older versions? How easy is it for you to get the code running from last week? Last year? 4 years ago? I could imagine that the CI requirements are quite different depending on whether you need to do long time support of older releases.
- What is covered by your tests? How do you take care of manual tests, performance tests and non functional requirements in your current project?
- Do you have an “andon cord” equivalent? How do you deal with build breaks or red nighty/master branch verifications?
- What is the frequency of your deployments? What is the average lifetime of your branches? Do you practice Trunk-Based-Development?

# Text for the Book Club Week7

- What is your deployment process? How automated is it?
- Who in your setup can deploy code to production?
- How often do you perform releases? When doing a release, do you use any special release strategy such as the green/blue deployment pattern?

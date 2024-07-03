---
tags:
  - book-chapter
---
# Agile Practices

- Processes to avoid Desaster Projects. But Processes cause the Desaster they try to avoid
    - Can even slow the Team to Miss Deadlines and Slip Budgets
    - Runaway-Process-Inflation
- The agile manifesto (2001)
    - Individuals and interactions over Processes and Tools
    - Working Software over comprehensive documentation
        - Producer No document until its need is immediate and signifikant
    - Customer collaboration over contract negotiation
    - Responding to Change over following a plan
- 12 Agile principles 
![[Agile Printicples]]

# Overview of Extreme Programming XP

- The practices of [[Kent Beck - Extreme Programming Explained]]
    - Customer Team member
    - User Stories
    - Short cycles
    - Acceptance Tests
    - Pair Programming
    - [[TDD|Test Driven Development]]
    - Collective ownership
    - Continuous Integration
        - Build and Test end to end, including all acceptance tests
    - Sustainable pace
        - No overtime except for Last week in a Release
    - Open workspace
    - Planning Game
    - Simple Design
        - Consider the simplest Thing that could possibly Work
        - You are Not going to need it (Database, multiple Users, multithreading, …)
        - Once and only once (don't repeat yourself)
    - Refactoring
        - best done frequently
    - Metaphors

# Planning

- Initial Exploration
- Spülung, Splitting and Velocity
- Release planning
- Iteration planning
- Task Planning
    - Measure of "perfect Programming hours"
    - How does the Number of Points increase If the Team grows?
- Iteration
    - Evaluate Look, feel and Performance

# Testing

- Tests First means that the Software is conveniently callable
- Tests First forces us to decouple the software
- Writing Test before Code improves our Designs
- Unit Test are White Box Tests, which verify the individual mechanisms of the system
- Acceptance tests are black Box Tests which verify that the customer requirements are met. They are written by the customer or someone close to the customer.

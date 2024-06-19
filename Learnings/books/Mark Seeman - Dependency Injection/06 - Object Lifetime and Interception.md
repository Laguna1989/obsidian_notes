---
tags:
  - book-chapter
---
# Questions

- How does the `IDisposable` idea translate to languages without garbage collection?
- Table 9.1 lists multiple cross cutting concerns. Do you have similar cross cutting concerns in you project and how did you solve them?
- In listing 9.7 (interception for security) it is suggested to throw an exception if the user has insufficient rights to perform a certain action. This might be a valid approach in c#, but in c++, exceptions should be exceptional. How would you handle the behavior there?

# Text Week 6

Hi everyone. This week we are going to read about Object Lifetime and Interception (page 236 - 301).

The book introduces Dependency lifetime and introduces singleton, transient and scoped lifestyles. This shows how to deal with dependency lifetime and how to avoid or fix bad lifestyle choices. In the Interception chapter we learn how to intercept calls between objects, get to know the [[Decorator]] design pattern and how to apply cross cutting concerns.

I would like to discuss the following topics with you

- Have you had to deal with bad lifestyle choices in you project and how did you solve/mitigate them?
- How does the `IDisposable` idea translate to languages without garbage collection?
- Table 9.1 lists multiple cross cutting concerns. Do you have similar cross cutting concerns in you project and how did you solve them?
- In listing 9.7 (interception for security) it is suggested to throw an exception if the user has insufficient rights to perform a certain action. This is a valid approach in c#, but in other languages, e.g. c++, exceptions should be exceptional. How would you handle the behavior there?

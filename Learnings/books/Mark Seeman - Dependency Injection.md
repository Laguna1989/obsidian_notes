---
tags:
  - book
created: 2021-10-01
links: "[[Books MOC]]"
---
# Dependency Injection

[[Scott Young - Ultralearning]] Plan
<table>
  <tr>
   <td>What Topic and scope?
   </td>
   <td>
<ul>

<li>Learn about Dependency Injection

<li>Facilitate BookClub at EB
</li>
</ul>
   </td>
  </tr>
  <tr>
   <td>Primary Resources?
   </td>
   <td>
<ul>

<li>Dependency Injection by Mark Seeman

<li>Exercises?

<li>YT Videos?

<li><del>Ask JoSchl about Bookclub tips</del>
</li>
</ul>
   </td>
  </tr>
  <tr>
   <td>What is the Benchmark?
   </td>
   <td>
<ul>

<li>Bookclub successful
<ul>

<li>Weekly questions/meetings/exercises
</li>
</ul>

<li><del>Book read ~500 pages</del>
</li>
</ul>
   </td>
  </tr>
  <tr>
   <td>Direct Practice Activities?
   </td>
   <td>Bookclub, questions, discussions, exercises
   </td>
  </tr>
  <tr>
   <td>Backup Materials and Drill exercises?
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Planned Time Schedule
   </td>
   <td>
<ul>

<li>50 pages per week

<li>One appetizer post/comment every week
</li>
</ul>
   </td>
  </tr>
  <tr>
   <td>Time Spent
   </td>
   <td>
   </td>
  </tr>
</table>

# Bookclub Schedule

<table>
  <tr>
   <td>week
   </td>
   <td>date
   </td>
   <td>pages
   </td>
   <td>count
   </td>
   <td>topic
   </td>
  </tr>
  <tr>
   <td>1
   </td>
   <td>10.1.
   </td>
   <td>1 - 34
   </td>
   <td>34
   </td>
   <td>Basics of Dependency Injection
   </td>
  </tr>
  <tr>
   <td>2
   </td>
   <td>17.1.
   </td>
   <td>34 - 81
   </td>
   <td>46
   </td>
   <td>Writing tightly & loosely coupled code
   </td>
  </tr>
  <tr>
   <td>3
   </td>
   <td>24.1.
   </td>
   <td>81 - 124
   </td>
   <td>44
   </td>
   <td>Dependency Injection patterns
   </td>
  </tr>
  <tr>
   <td>4
   </td>
   <td>31.1.
   </td>
   <td>124 - 163
   </td>
   <td>39
   </td>
   <td>Dependency Injection anti patterns
   </td>
  </tr>
  <tr>
   <td>5
   </td>
   <td>7.2.
   </td>
   <td>163 - 236
   </td>
   <td>77
   </td>
   <td>code smells + application composition
   </td>
  </tr>
  <tr>
   <td>6
   </td>
   <td>14.2.
   </td>
   <td>236 - 301
   </td>
   <td>64
   </td>
   <td>Object lifetime + Interception
   </td>
  </tr>
  <tr>
   <td>7
   </td>
   <td>21.2.
   </td>
   <td>301 - 357
   </td>
   <td>56
   </td>
   <td>Aspect oriented programming by design + tool based aop
   </td>
  </tr>
  <tr>
   <td>8
   </td>
   <td>28.2.
   </td>
   <td>357 - 393
   </td>
   <td>36
   </td>
   <td>DI Container intro
   </td>
  </tr>
  <tr>
   <td>9
   </td>
   <td>7.3.
   </td>
   <td>393 - 427
   </td>
   <td>34
   </td>
   <td>Autofac DI container
   </td>
  </tr>
  <tr>
   <td>10
   </td>
   <td>14.3.
   </td>
   <td>427 - 466
   </td>
   <td>39
   </td>
   <td>Simple injector DI container
   </td>
  </tr>
  <tr>
   <td>11
   </td>
   <td>21.3.
   </td>
   <td>466 - end
   </td>
   <td>40
   </td>
   <td>Microsoft extensions DI container
   </td>
  </tr>
</table>

# Discussion Questions

## Week 1 (Basics of Dependency Injection)

Questions

- What are myths that you have heard about when talking about DI?
- Page 11 mentions the [[Liskov Substitution Principle]] (LSP). Can you give an example from your current project where the LSP is used?
- Page 11 mentions the [[Single Responsibility Principle]] (SRP). Can you provide an example from your current project where this is violated? What lead to this issue?
- Page 14 mentions the [[Open Close Principle]] (OCP).
- The LSP, OCP and SRP are three of the SOLID Principles. What other principles are part of SOLID?
- Name one stable and one volatile dependency in your current project

Possible Exercises
- Extend the HelloWorld Example with a simple FileWriter (without late binding)
- Expectations towards the book

### Text Week 1:

Hello everyone and welcome to the first week of the bookclub. Great to have you. Let’s embark on our journey with the first chapter of “Dependency Injection”.

This week we are going to read Chapter 1: “The basics of Dependency Injection: What, why and how” (pages 1-34).

Before you start reading, I would like to ask you to share your expectations for the book and the book club. Do you already have some understanding of or even hands-on experience with dependency injection? Or is DI a topic which is completely new to you?

While and after reading this week's chapter it would be great to discuss with you:

- Are you familiar with any of the myths about DI mentioned in the book?
- The text mentions the [[SOLID Design Principles]]. Are you familiar with them and can you list them?
- The concept of volatile and stable dependencies is introduced. Think about any project you work(ed) on. How would the dependencies be classified and have any dependencies (especially the volatile ones) caused problems for you?

## Week 2 (Tightly and Loosely Coupled code)

Questions
- What are the issues in the tightly coupled example?
- How are those issues removed by loose coupling?
- The tightly coupled example starts with an inside-out approach from the database layer. How would you approach the task inside-out and avoid the issues?

Possible Exercises
- Follow the two examples in your IDE

### Text Week 2

Hello everyone. It is the second week of the bookclub. This week we are going to read chapter 2 and 3 “Writing tightly & loosely coupled code”, which corresponds to pages 34 to 80.

This week’s content is all about examples. I strongly recommend you to open your IDE when reading the book and follow the example projects while reading.

This week I would like to discuss with you:

- There are quite some issues with the tightly coupled code mentioned in the book. Could you find additional ones?
- Does it make sense to you how those issues are avoided by using loosely coupled code?
- The tightly coupled example starts with an inside-out approach and it is stated that using an outside-in approach gives quicker feedback. What would you do if you work on this problem with an inside-out approach to get reasonably fast feedback, too?

## Week 3 (Dependency Injection Patterns)

Questions

- In this Chapter some patterns were introduced: Composition Root, Constructor Injection, Method Injection and Property Injection. Have you used any of those Patterns?
- Were they helpful and if not, why?
- Can you share an example when you used a specific pattern?

### Text Week 3

Hi everyone. It is the third week of the book club. This week we are going to read chapter 4 “DI Patterns”, which corresponds to pages 83 to123.

After the examples from last week, common DI patterns are introduced, namely “Composition Root”, “Constructor Injection”, “Method Injection” and “Property Injection”.

This week I would like to discuss with you:

- Have you used any of the mentioned patterns already? Can you share an example?
- Why did you decide to go for that specific pattern?
- What problem did the respective pattern solve and was it helpful?

## Week 4 (Anti Patterns)

Questions:

- The anti patterns described in this section are: Control-Freak, Service Locator, Ambient Context and Constrained Construction
- Have you noticed any of the anti-patterns in your current or previous project? In which way are/were they harmful?
- Were you able to refactor or at least mitigate the effects of the anti-pattern?

### Text for Week4

Hello dear members of the book club. We are already in week 4 of the book club. This week we are going to read about DI Anti-Patterns (page 124-163).

The Anti-Patterns introduced in this week are Control-Freak, Service Locator, Ambient Context and Constrained Construction.

I would like to discuss with you:

- Have you noticed any of the anti-patterns in your current or previous project? In which way are/were they harmful?
- Were you able to refactor or at least mitigate the effects of the anti-pattern?

## Week 5 (Code Smells and Application-Design)

- The code smells introduced were Constructor-overinjection, Abstract Factory and Cyclic Dependencies
- Have you noticed any of the code smells in your current or previous project? Were they harmful or could you live with the code smell? Were you able to refactor or mitigate the effects of the code smells?
- There are examples given for application composition. Do you follow the example given in your current or previous project? What is the outcome and effect?
- One point not mentioned here is the design of middleware or library code. How would you proceed in this case? What smells might originate there?

### Text Week 5

Hi everyone. This week we are going to read about Code Smells and Application design (page 163 236).

The code smells introduced in the book are Constructor-overinjection, Abstract Factory and Cyclic Dependencies.

I would like to discuss with you:

- Have you noticed any of the code smells in your current or previous project? Were they harmful or could you live with the code smell? Were you able to refactor or mitigate the effects of the code smells?
- There are examples given for application composition. Do you follow the example given in your current or previous project? What is the outcome and effect?
- One point not explicitly mentioned by the book is the design of middleware or library code. How would you proceed in this case? What smells might originate there?

## Week 6 (Object Lifetime and Interception)

- How does the `IDisposable` idea translate to languages without garbage collection?
- Table 9.1 lists multiple cross cutting concerns. Do you have similar cross cutting concerns in you project and how did you solve them?
- In listing 9.7 (interception for security) it is suggested to throw an exception if the user has insufficient rights to perform a certain action. This might be a valid approach in c#, but in c++, exceptions should be exceptional. How would you handle the behavior there?

### Text Week 6

Hi everyone. This week we are going to read about Object Lifetime and Interception (page 236 - 301).

The book introduces Dependency lifetime and introduces singleton, transient and scoped lifestyles. This shows how to deal with dependency lifetime and how to avoid or fix bad lifestyle choices. In the Interception chapter we learn how to intercept calls between objects, get to know the [[Decorator]] design pattern and how to apply cross cutting concerns.

I would like to discuss the following topics with you

- Have you had to deal with bad lifestyle choices in you project and how did you solve/mitigate them?
- How does the IDisposable idea translate to languages without garbage collection?
- Table 9.1 lists multiple cross cutting concerns. Do you have similar cross cutting concerns in you project and how did you solve them?
- In listing 9.7 (interception for security) it is suggested to throw an exception if the user has insufficient rights to perform a certain action. This is a valid approach in c#, but in other languages, e.g. c++, exceptions should be exceptional. How would you handle the behavior there?

## Week 7 (Aspect Oriented Programming and Tool Based AOP)

Hi everyone, the book club is already entering the last third of its lifetime. This week we will read the chapters about aspect oriented programming (AOP) by design and tool based aspect oriented programming (pages 301 - 357).

The chapter starts with an recap of the solid principles and shows how the solid principles enable AOP and can be used to prevent code duplication. Furthermore the [[Command Query Separation]] is introduced and cross cutting concerns (from last week) are discussed.

When talking about tool based AOP, the advantages and disadvantages are discussed.

My question this week would be if you have used tool based AOP and if so in which language. I am not mainly developing in C# but this seems a very specific technique to me.

## Week 8 (DI Container Intro)

Hi everyone,

sorry for the vacation-induced late post this week.This week will mark the final chapter that we will read together. It introduces DI Containers (pages 359 - 392).

This chapter is all about DI Containers. You will learn when to use them, how to configure them and what the basic concepts of those containers are.

My question this week is if you have used DI Containers already in one of your projects and what your experience was.

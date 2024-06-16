---
tags:
  - book
created: 2021-08-01
links: "[[Books MOC]]"
---
# Collaborative Game Types for Programmers

## Randori

- Code projected on the wall
- around 4-10 programmers
- everyone gets a turn
- work in pairs
- Randori Rules:
    - Whoever is on the keyboard, decides what code goes in the codebase
    - If you have they keyboard and you don’t know what to type, ask for help.
    - If you are asked for help, kindly ask for the best of your abilities.
    - If you are not asked, but see room for improvement, wait for an appropriate moment to suggest things. (this might be the next time when the tests are green or until the retrospective)
- Pair switching strategies
    - timeboxing:
        - each pair has a 5-7 minutes timebox.
        - After that time the copilot becomes the driver and a new copilot is selected from the audience.
        - Rule of thumb: longer timeboxes for statically typed languages
    - Ping Pong
        - driver writes the first test
        - copilot writes the implementation
        - refactor together
        - original driver sits down in the audience and a new person steps up, initially beoming the copilot
        - original copilot becomes driver
    - NTests
        - The pair at the keyboard writes N tests and implementation (usually 1,2 or 3)
        - A new pair steps up

# Tools

- Test run logging: Log when tests were executed and how they turned out (red, green). Get insights
- Kata Catalogue
- Cyber Dojo
- Coder’s dojo client (enables test run logging)
- Constant Test Running
- Code Smell Analysis

# Using Production Code in the Dojo

- Don’t go down rabbit holes
- Do Small steps
- Still do agile

# Organizing a Coding Dojo

- Deliberate practice (practice things you can not do)
- Sit down after the dojo and do the kata again on your own

## What Happens at the Dojo?

- Introduce the Dojo
- Agree on the activities for today
- Code!
- Retrospective
    - Three questions: What did you learn? What surprised you? What did you not understand?

### Times:

- Dojo 2-3 hours
- Retreat: 1 day
	- optional socializing at the end

### Group Size:

- 3-15 people

### Room:

- big enough
- projector
- laptop
- seats for everyone, e.g. conference table

### Editor/IDE

- common ground
- if in separate pairs: everyone decides on his own.

### Programming Language:

- If [[TDD]] is the focus: Some language you are familiar with
- If you want to learn a language, pick a new one

### Work time of Free Time:

- Different people will show up

> [!quote] Martin Fowler
> Any fool can write code that a computer can understand. Great programmers can write code that everyone else can understand

Ask Questions

- “Would it make the code more readable, if …?”

Give Praise

Make Notes

Have a Parking-Lot Todo List for later discussion

Social Skills:
- Praise in public, criticize in private

### Retrospective:

- What are the best aspects of the design?
- In what ways did we do TDD particularly well?
- Did we learn something new?
- Did anything unexpected happen?
- What do we still need to practice more?
- What should we do differently in the future?
- What will you do differently tomorrow in your real job?

## Dojo Principles

- One can’t discuss a form without code. And there cannot be code without tests. The code is the design and code without tests does not exist.
- The Master can’t be a master of every form
- Come without your relics: Of course you know how and why to do it. The point is to do it right now and to explain it to others
- Learn again (easier when you are together with someone who is learning it for the first time)
- Slow down. Learning will force you to slow down anyway. You cannot learn something new and be faster at the same time.
- Throw yourself in a prepared Kata, if you find yourself threatened by boredom
- If it seems difficult to you, look for others to help you until it is no longer difficult
- Mastering a subject. If it seems easy to you, explain it to others.

## TDD Rules

- You are not allowed to write any production code unless it makes a failing test pass.
- You are not allowed to write more of a test that is failing. compilation failure is also failure
- You are not allowed to write more production code other than to make the test pass

### Principles for Automated Testing

- Readability
- Robustness
- Speed
- Updatability
- => Maintainability

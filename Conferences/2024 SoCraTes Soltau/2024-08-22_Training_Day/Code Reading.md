---
tags:
  - conference
  - SoCraTes-2024
---
# Intro

- We read code more than we write it
- What if we practice code reading explicitly?
- [Code Reading Club](https://codereading.club/)
- Book recommendation: [The Programmers Brain](https://www.amazon.de/Programmers-Brain-Every-Programmer-Cognition/dp/1617298670/ref=sr_1_1?crid=22FQ4GQLFU3T4&dib=eyJ2IjoiMSJ9.nfJd9y_cD9mBVVMIF7vmq89_DLVQnMyTvQwL9B7pDVAYeoD4EymPEWqh8ZUOfvjT8y8zHSSkuh4QogYD68oFMaIRhgqNrMIleaAVpS3cKlVDhJT3oq9NgCWORAwRe6vAFni7iZf547sk9hR4AzPAZH36rDkowEARPYCD9dbHCEnhxLzMprFpaYx9TvQL7wHgyx-6U1EQDV1K6ok81UQmSeuw99U_bqmdC4yf3r5Ppgc.-Zui7CgylqzPGPabby21BcWPAmnm9ioi8TrwfjWFb_E&dib_tag=se&keywords=the+programmers+brain&qid=1724313784&sprefix=the+programmers+%2Caps%2C128&sr=8-1)
- "read code to understand" vs "read code to judge"
- [website](https://maritvandijk.com/presentations/code-reading/)

# Exercise 1

Take one minute to read the code and write down the one thing that strikes most

- Code line length (look for *code density*)
- Lots of hard coded strings, regex
- Domain: cucumber
- Typo in comment
- Language seems to be java
- New things/unfamiliar:
	- package-info.java
	- overall code structure
- Missing Syntax highlighting
- Where is the entry point?
- What is the build system?

# Exercise 2

Mark variables, classes and functions and build a "dependecy graph" where they are used

Findings:
- It is hard to distinguish what a variable or a method call is
- Reuse of variable names is dangerous
- Some variables are only used once, but created way up up front
- Level of nestedness
	- two types of nesting (if and loop) are mixed
- Mixed use of camelCase and snake_case
- Two comment styles

# How We Read Code

- We do mostly not read code top to bottom
- Scanning code
- Whitespaces help to group functionality
- What kind of anchors do you use when reading code?
	- Comments
	- Whitespaces
	- Variable names or method names

# Exercise 3

Identify 5 central thematic concepts (domain or code)

- Language
- File
- Dialect
- HTML
- Translation
- Engine Template
- Edge Case Handling

Learnings:
- "anaphoric" constants: implicit variables
- Look for headers/includes/packages
- Look at the name of the source file
- Check for domain level
- Read Code Outside->In
- Context is important
- Concepts gives you a checklist for things to look up (is there a glossary?)

# Exercise 4

Look for the most important lines in the code?

How to decide which lines are the most important ones?
- The lines that actually do something
	- Look for *side effects* and *return values*
- Control flow
- Happy path
- The lines I do not yet understand

Learning:
- People first look at different lines

# Exercise 5

Summarize what the code does

- Loop over languages and for each language write a html file which contains the language name with some corner case handling

# Solution/Core Origin

- cucumber jvm
- natural language to bdd transpiler
- Generator for I18N

27.1.2023

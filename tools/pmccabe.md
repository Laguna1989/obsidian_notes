---
tags:
  - cpp
---
`pmccabe` is a tool for measuring #cyclomaticComplexity.

call with
```
pmccabe *.cpp | sort -nr | head -10
```

Understanding the output
```
 A line is written to standard output for each function found of the form:

  Modified McCabe Cyclomatic Complexity
  |   Traditional McCabe Cyclomatic Complexity
  |       |    # Statements in function
  |       |        |   First line of function
  |       |        |       |   # lines in function
  |       |        |       |       |  filename(definition line number):function
  |       |        |       |       |           |
  5       6       11      34      27      [gettoken.c]
```

- **first** and **last** number are important: cyclomatic complexity and lines of code


`cppcheck` is a #tool for static #cpp code analysis. [Website](https://cppcheck.sourceforge.io/)

# Usage

Execute with
```
cppcheck impl/ --enable=all 2> cpp_check_warnings.txt
```

Resulting file will contain quite some false positives (because of `all`). E.g. unused functions.

# Suppressions

```
cppcheck impl/ --enable=all --suppress=unusedFunction 2> cpp_check_warnings.txt
```


# Backlinks
- Available on the right side via backlinks
- Also available at the bottom of each document via `ctrl + p` -> `toggle backlinks in document`
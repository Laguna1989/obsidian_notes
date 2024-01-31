`cppcheck` is a #tool for static #cpp code analysis. [Website](https://cppcheck.sourceforge.io/)


Execute with
```
cppcheck impl/ --enable=all 2> err.txt
```

Resulting file will contain quite some false positives (because of `all`). E.g. unused functions.
---
tags:
  - tool
  - vim
---
# Load Vim without Config

```bash
vim --clean
```

# Load a Script File in Vim

```vim
:so <script_filepath>
```

# Read a File

```vim
:r input.txt|1d
```

`:r` read file,

`|` line by line

`1d` delete command once

# Replace

```vim
%s/x/*/g
```

replace all `x` by `*`

# Slient Mode

```vim
:silent!
```

does not ask for input, dost not print console outpupt

# Evaluate

Evaluate expressions

```vim
:silent %s/.*/\=eval(submatch(0))
```

evaluates the complete line

`submatch()` returns the nth match in a regex. As this regex matches the complete line, it returns everything

# Join Command

``` vim
J
```

join all selected lines, adding a whitespace

```vim
gJ
```

join without adding whitespace at the end of the line

# Visual Block Select All

```vim
V i p
```

# Normal Commands

```vim
:norm VipgJ
```

# Jump to End of line

```
$
```

# Jump to First line

```vim
gg
```

# Jump to Last line

```vim
G
```

# Execute

Needs a `<cr>` at the end of the string to work (simulates the "I press return")

```vim
exe ":norm vip:sort! n\<cr>"
```

# Macros

```vim
:let @m = ":norm vipgJ$x\<cr>"
```

Show all macros

```vim
:reg
```

execute the macro

```vim
:norm @m
```

execute the macro 999 times

```vim
:norm 999@m
```

Concatenate variables

```vim
:let @m = myVarA . myVarB . "<cr>"
```

# Variables

Read line into variable

```vim
let myVar = getline(".")
```

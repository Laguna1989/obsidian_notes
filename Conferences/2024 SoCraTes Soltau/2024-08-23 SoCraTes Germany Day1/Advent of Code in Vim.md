---
tags:
  - conference
  - SoCraTes-2024
  - vim
---

See [[Vim]]

# Example (2017 Day 2)

```
5 1 9 5
7 5 3
2 4 6 8
```

find min and max in each line and calculate the difference

## Idea

replace the end of each line with a double new line

```vim
" add extra blank lines between input lines
:%s/$/\r
```

```vim
" converting spaces to line breaks
:%s/\s\+/\r\g
```

Sort each line

```
" select one paragraph (vip) and sort
exe ":norm vip:sort! n\<cr>"
" hint we end up at the start of the paragraph
```

get only largest and smallest value

```vim
" only keep top and bottom line of paragraph (largest smallest)
:norm jV}kkd
```

j = down one lin
V = visual block mode
} = end of paragraph
kk= up two lines
d= delete line

subtract small from big

```vim
:exe ":norm kA-\<esc>J\<cr>"
```

evaluate

```vim
:s/.*/\=eval()submatch(0))
```

go to next line of unsolved paragraph

```vim
:norm jj
```

macro time

```
let @m = "foobar" . someVar
```

`.` concatenates strings

[advent-of-code/vim/2017/day-02/aoc-2017-02.commented.vim at main · yogan/advent-of-code · GitHub](https://github.com/yogan/advent-of-code/blob/main/vim/2017/day-02/aoc-2017-02.commented.vim)

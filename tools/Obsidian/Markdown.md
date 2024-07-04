---
tags:
  - obsidian
  - markdown
---
# References

- [Markdown Cheat Sheet](https://www.markdownguide.org/cheat-sheet/)

# Important Markdown Things

## Text Modifiers

### Bold

**Bold** Text

```markdown
**Bold** text
```

### Strikethrough

This is ~~strikethrough~~

```markdown
This is ~~strikethrough~~
```

### Highlight

I need to highlight ==those very important words==

```markdown
I need to highlight ==those very important words==
```

## Image Size

[[Image Size]]

## Block Quotes

> This is an awesome block quote which will can be started by typing `>` at the beginning of the line

[[Callouts]]

## Dividers

Dividers can be added via `***`in a single line, e.g.
***

Many other symbols can be used, e.g.
- - -
___
---

## Diagrams

[[Diagrams]]

## LaTex

Double dollar signs `$$` can be used to start LaTeX Block

$$
\Omega = \frac{\sigma}{\int_0^x y\;dy}
$$

## Links to Blocks

- Linking to blocks
	- [[Obsidian#LaTex]]
- Creating blocks via `^`
	- Can not contain underscores or spaces

^custom-block

## Comments

Markdown comments can be done via `%`

> [!example] Line comment
This is %%a line comment%% not visible in preview

> [!example] Block comment
> %%
> This is a block comment
> %%
> This is also not visible in preview

## Footnotes

Obsidian also supports footnotes via links [^1]

[^1]: My footnote

## Definition List / Terms

```
First Term
: This is the definition of the first term.

Second Term
: This is one definition of the second term.
: This is another definition of the second term.
```

Not supported by [[Obsidian]]

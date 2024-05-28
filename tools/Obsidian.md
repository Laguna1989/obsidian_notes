---
Progress: 30
tags:
  - tag
  - tool
links: "[[Tools]]"
---
#tool 
# Local graph
- shows only the connections going out from the currently opened tab
- can be linked in the sidebar
- open with `ctrl + p`-> `local graph`
# Images 
## Width
Use a pipe `|<width>` in the image square brackets to define the width (for consistency)
![|500](https://picsum.photos/536/354)
## Custom ratio
Use a pipe `|<width>x<height>`in the image square brackets. This will squash the image.

![|600x50](https://picsum.photos/536/354)
# Property view
- disable properties being visible in files via `settings` - `editor` - `properties in document`-> hidden
- enable property view in `settings`- `core plugins`

# Style
- Use general theme: `settings` -> `appearance` -> border
- Install `Style Settings`community plugin
- Pick a theme that fits me
- Adjust accordingly
## Custom card Layout
- `settings` -> `style settings` -> `dark mode` -> card -> custom card shadow
```
inset -2px -2px 40px 0px rgba(0, 0, 0,.2), inset 1px 1px 10px 0 rgba(255, 255, 255, .2) 
```

# Excalidaw
[Excalidraw](https://github.com/zsviczian/obsidian-excalidraw-plugin)

# Numerals
Plugin that allows to do math
```math
lemons = 5
price = 2.50€

full_price = lemons * price
```
# Markdown
## Block quotes
> This is an awesome block quote which will can be started by typing `>` at the beginning of the line

## Callouts
Some special sort of block quote which are formatted in a nice way

> [!Info]  This is an info
> Infos can contain other MD elements, like 
> - lists or
> - images

> [!info]+ Collapsible Callouts
> By adding a `+` or `-` directly after the title the callout is collapsible. 
> - `+`expanded by default
> - `-`collapsed by default

### Other callout types
> [!success]
> Alias `check`,  `done`

> [!question]
> Alias `help`, `faq`

> [!warning] This is a warning
> Be cautious about stuff 
> ---
> Alias `caution`, `attention`

> [!Failure]
> Alias: `fail`, `missing`

> [!danger]
> Alias `error`

> [!bug]
> 

> [!abstract]
> - useful for longer notes

> [!example] 
> Can also contain 
> ```
> block code
> ```

> [!cite]
> offer way better formatting and look than just normal block quote

## Dividers
Dividers can be added via `***`in a single line, e.g.

***

Many other symbols can be used, e.g. 
- - - 
___
---
## Diagrams

### Mermaid diagrams 
[[Mermaid Diagrams]]
### Plantuml
There is potentially support for plantuml via [this plugin](https://github.com/joethei/obsidian-plantuml)

## LaTex
Double dollar signs `$$` can be used to start LaTeX Block
$$
\Omega = \frac{\sigma}{\int_0^x y\;dy}
$$

## Links to blocks
- Linking to blocks
	- [[Obsidian#LaTex]]
- Creating blocks via `^`
	- Can not contain underscores or spaces

^custom-block

## Comments
Markdown commets can be done via `%`

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

# Hotkeys
## Find in files
`ctrl + shift + F`
## Show file explorer (custom)
`ctrl + shift + D`
## Open settings
`ctrl + ,`

## Open Graph
`ctrl + G`


# Tags
Tags can either be placed via inline tas, e.g. #tag.
They can also be placed in the properties view.


# Meta Bind 
- Allows input fields like this to connect to properties
```meta-bind
INPUT[progressBar(title(Progress), minValue(0), maxValue(100)):Progress]
```

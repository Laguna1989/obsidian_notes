---
Progress: 51
tags:
  - tag
  - tool
  - obsidian
links: "[[Tools]]"
date1: 2024-05-30
---
# Local Graph

- shows only the connections going out from the currently opened tab
- can be linked in the sidebar
- open with `ctrl + p`-> `local graph`

# Property view

- disable properties being visible in files via `settings` - `editor` - `properties in document`-> hidden
- enable property view in `settings`- `core plugins`

# Style

- Use general theme: `settings` -> `appearance` -> [Border](https://github.com/Akifyss/obsidian-border)
- Install `Style Settings`[community plugin](https://github.com/mgmeyers/obsidian-style-settings)
- Pick a theme that fits
- Adjust accordingly, e.g. for [sunset theme](https://github.com/Akifyss/obsidian-border/blob/main/presets/Sunset.json) , remove the `background-mod`noise layers

## Custom Card Layout

> [!danger] Problem: Card shadows only work well for light themes

> [!check] Fix:
> `settings` -> `style settings` -> `dark mode` -> card -> custom card shadow
>
> ```
> inset -2px -2px 40px 0px rgba(0, 0, 0,.2), inset 1px 1px 10px 0 rgba(255, 255, 255, .2) 
> ```

# Excalidaw

[Excalidraw](https://github.com/zsviczian/obsidian-excalidraw-plugin)

# Numerals

> [!danger] Can result in quite some startup time

Plugin that allows to do math

```math
lemons = 5
price = 2.50€

full_price = lemons * price
```

# Markdown

## Images

### Image Width

Use a pipe `|<width>` in the image square brackets to define the width (for consistency)
![|500](https://picsum.photos/536/354)

### Custom Ratio

Use a pipe `|<width>x<height>`in the image square brackets. This will squash the image.

![|600x50](https://picsum.photos/536/354)

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

### Mermaid Diagrams

[[Mermaid Diagrams]]

### Plantuml

There is potentially support for plantuml via [this plugin](https://github.com/joethei/obsidian-plantuml)

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

[[Hotkeys]]

# Tags

Tags can either be placed via inline tas, e.g. #tag.
They can also be placed in the properties view.

# Meta Bind

> [!danger] Can result in quite some loading time.

[Github page](https://github.com/mProjectsCode/obsidian-meta-bind-plugin)
[TTRPG explanation video](https://www.youtube.com/watch?v=iAYS0254a7I)

## Input Fields

Allows input fields like this to be connected to properties

```meta-bind
INPUT[progressBar(title(Progress), minValue(0), maxValue(100)):Progress]
```

`INPUT[date:date1]`
`INPUT[datePicker:date1]`

## Views

- Can be used in view mode : `VIEW[{date1}]`
- Can be used to cross-reference properties from different notes

# Backlinks

- Available on the right side via backlinks
- Also available at the bottom of each document via `ctrl + p` -> `toggle backlinks in document`

# Linter

There is an awesome [linter plugin](https://github.com/platers/obsidian-linter) that auto-formats notes.

# Non Linking Links

- `ctrl + p`-> `Copy Obsidian URL`
- create a link

```
[Link Text](Obsidian URL)
```

# CSS Folder

`Settings` -> `Appearance`->`CSS Snippets`

# Alternate Checkboxes

![[IMG-2024-06-14-175114344.png]]

# TODO

- Check out <https://github.com/gapmiss/croppie-for-obsidian> for cropping images inside obisidian

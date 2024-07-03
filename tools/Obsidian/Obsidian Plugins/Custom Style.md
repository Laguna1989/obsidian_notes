---
tags:
  - obsidian
  - plugin
---
# Custom Style

- Use general theme: `settings` -> `appearance` -> [Border](https://github.com/Akifyss/obsidian-border)
- Install `Style Settings`[community plugin](https://github.com/mgmeyers/obsidian-style-settings)
- Pick a theme that fits
- Adjust accordingly, e.g. for [sunset theme](https://github.com/Akifyss/obsidian-border/blob/main/presets/Sunset.json) , remove the `background-mod`noise layers

# Custom Cards

> [!danger] Problem: Card shadows only work well for light themes

> [!check] Fix:
> `settings` -> `style settings` -> `dark mode` -> card -> custom card shadow
>
> ```
> inset -2px -2px 40px 0px rgba(0, 0, 0,.2), inset 1px 1px 10px 0 rgba(255, 255, 255, .2) 
> ```

---
tags:
  - obsidian
---
# Initial State

Files and folders are sorted separately (first all folders, then all files)
![[IMG-2024-06-19-070933358.png]]

# Desired Outcome

Files and folders are both sorted consistently
![[IMG-2024-06-19-070904581.png]]

# How-To

1) Install [GitHub - custom file explorer sorting](https://github.com/SebastianMC/obsidian-custom-sort)
2) Create a `sortspec.md` file with the following preamble

```
---
sorting-spec: |
  target-folder: <<Folder To Sort>>
  < a-z
---
```

3) Enable custom sorting in the sidebar

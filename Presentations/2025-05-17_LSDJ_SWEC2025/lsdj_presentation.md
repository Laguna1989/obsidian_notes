---
marp: true
theme: uncover
class: invert
style: |
  :root {
    --color-background: #1a1a1a;
    --color-heading: #ffffff;
    --color-text: #e0e0e0;
    --color-link: #64b5f6;
  }
  section {
    background-color: var(--color-background);
    color: var(--color-text);
    font-family: 'Helvetica Neue', Arial, sans-serif;
  }
  h1, h2, h3, h4, h5, h6 {
    color: var(--color-heading);
  }
  a {
    color: var(--color-link);
  }
  code {
    background: rgba(255, 255, 255, 0.1);
    border-radius: 4px;
    padding: 0.2em 0.4em;
  }
  pre {
    background: #2d2d2d;
    border-radius: 8px;
    padding: 1em;
  }
title: Little Sound DJ (LSDJ) - Music Creation on Game Boy
author:
  name: Simon Weis
  email: simon.weis@posteo.de
  github: laguna1989
date: 2025-05-17
tags:
  - presentation
  - marp
  - lsdj
  - gameboy
  - music
---

<!-- 
Build with:
marp lsdj_presentation.md --pdf --allow-local-files
-->

# Little Sound DJ (LSDJ)
## Music Creation on Game Boy

2025-05-17 | SWEC 2025

**Simon Weis** 

---

# What is LSDJ?

- Music tracker software for the Nintendo Game Boy
- Created by Johan Kotlinski (aka [johan.kotlinski](https://www.littlesounddj.com/))
- Turns the Game Boy into a powerful music production tool

---

# Key Features

- 4-channel tracker interface
- Sample-based synthesis
- Pattern-based sequencing
- Real-time performance controls
- Save songs to cartridge

---

# LSDJ Interface

```
[PATTERN EDITOR]  [INSTRUMENT EDITOR]

  C-4 01 .. .. 80    WAVE
  ... .. .. .. ..     
  ... .. .. .. ..     ENV
  ... .. .. .. ..     LEN  
  ... .. .. .. ..     
```

---

# Workflow

1. Create instruments (WAV, SYN, KIT)
2. Sequence patterns (16 steps per pattern)
3. Chain patterns into songs
4. Use phrases for variations
5. Perform live with keyboard mode

---

# Why Game Boy?

- Limited hardware → creative constraints
- Unique 8-bit sound chip (LR35902)
- Portable music studio
- Nostalgic appeal
- Active chiptune community

---

# Getting Started

1. Get a Game Boy + Flash Cart
2. Download LSDJ ROM
3. Transfer to flash cart
4. Start making music!

---

# Resources

- [Official LSDJ Website](https://www.littlesounddj.com/)
- [LSDJ Wiki](https://littlesounddj.fandom.com/)
- [Kits (Samples)](https://github.com/psgcabal/lsdj-kits)
- [Community Forum](https://www.littlesounddj.com/forum/)

---

# Thank You!

- Questions?
- Let's make some chiptunes!
- @your_handle

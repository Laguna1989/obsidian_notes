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

## Chiptune on Game Boy

2025-05-18 | SWEC 2025

**Simon Weis**

---

![](gameboy_music.png)

---

# Why Game Boy?

- Limited hardware → creative constraints
- Unique 4-bit sound
- Portable music studio
- Nostalgic appeal
- Active chiptune community

---

![](chip_layout.png)

---

# Game Boy Audio System

![](apu_channels.png)

---

# Four Channels (monophonic)

- Pulse-based channel with sweep function
- Pulse-based channel without sweep
- Wave based channel
- Noise channel

---

# The APU

- Clocked by the master clock (runs faster on SGB1)
- 4 Bit Volume register and DAC
- Internally uses Durations instead of Frequencies

---

![](apu_flow.png)

---

```
Step   Length Ctr  Vol Env     Sweep
---------------------------------------
0      Clock       -           -
1      -           -           -
2      Clock       -           Clock
3      -           -           -
4      Clock       -           -
5      -           -           -
6      Clock       -           Clock
7      -           Clock       -
---------------------------------------
Rate   256 Hz      64 Hz       128 Hz
```

---

# LSDJ

![](lsdj.png)

---

# Demo

---

# Resources

- [Official LSDJ Website](https://www.littlesounddj.com/)
- [LSDJ Wiki](https://littlesounddj.fandom.com/)
- [Kits (Samples)](https://github.com/psgcabal/lsdj-kits)
- [Community Forum](https://www.littlesounddj.com/forum/)
- [gbdev.io](https://gbdev.io/pandocs/Audio.html)

---

# Thank You!
k
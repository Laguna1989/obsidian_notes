---
tags:
  - tool
  - hacking
  - network
  - command-line
---

> [!info] Gobuster
> `gobuster` is a tool used for directory and file brute-forcing, commonly used in web application penetration testing.

# Installation

``` bash
sudo apt install gobuster
```

# Wordlist

Can be obtained via

``` bash
git clone https://github.com/danielmiessler/SecLists.git
```

# Usage

```basn
gobuster -u http://<target_ip>/ -w SecLists/Discovery/Web-Content/directory-list-2.3-small.txt
```

or any other directory list

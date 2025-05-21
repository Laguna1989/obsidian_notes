---
tags:
  - tool
  - git
---

# Git Blame -L, Git Log -L

- `git blame -L 15,26:path/to/file.txt` will blame only this range of lines
- Works also for `git log -L ...`
- Does not need to be a line range, but can be a function name
	- `git log -L :<function_name>:path/to/file.txt`
	- will try to figure out heuristically what was changed

# Git Blame -w

- Ignore whitespaces

# Git Blame -C

- Ignore lines moved in the same file
- Can be appended up to three times
- `git blame -C -C -C path/to/file`
	- will ignore lines moved, creation of file

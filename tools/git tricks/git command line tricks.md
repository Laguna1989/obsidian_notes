---
tags:
  - tool
  - git
  - command-line
---

# Git Reflog

- will store comands (e.g. rebase, reset, ...)

# Git Diff --word-diff

- will not diff by lines, but by words: make it easy to spot any small change

# Git Config --gobal rerere.enabled

```bash
git config --global rerere.enabled
```

- REuse REcorded Resolution
- whenever you solve a merge conflict, me git remember that and reuse it to solve a similar merge conflict in the future

# Git Push --force-with-lease

```bash
git push --force-with-lease
```

- like force push, but works out only if the reference is correct.
- This will avoid deleting commits of other people

# Add a Base Version of a File, Ignore Future Changes

```bash
git update-index --skip-worktree .obsidian/workspace.json
```

- Works for local and upstream changes

# Show Remote Branches

```bash
git remote -vv
```

# Delete Local Commit

```bash
git reset --hard HEAD~1
```

# Change Commit Message of (multiple) Local Commits

> [!danger] Does not work if already pushed!

- If you want to change the message of the two last locals commits

```bash
git rebase -i HEAD~2
```

- In the editor, change `pick` to `reword`. Do not yet change the commit message
- After saving and closing the editor, a new editor will open, once for each commit to be changed
- Type the new committ messages here

---
tags:
  - tool
---
# Repo Size Badge

```![GitHub repo size](https://img.shields.io/github/repo-size/[USER/ORG]/[REPONAME])```
will e.g. look like this
![GitHub repo size](https://img.shields.io/github/repo-size/darkpalacestudio/filter_lib)

# Personal Access Tokens and CPM (cloning Private repos)

- It seems that one needs to use classic personal access tokens for https access.
- Perhaps the [Git Credentials Manager](https://github.com/git-ecosystem/git-credential-manager/blob/main/README.md) is another viable option? (for later)
- github website: Got to `Settings` -> `Developer Settings` -> `personal access tokens`
- create a token
- on the command line

```
git config --global url."https://[normal_github_username]:[access_token]@github.com".insteadOf "https://github.com"
```

- check that you can clone the private repo, without entering any credentials

``` 
git clone https://github.com/darkpalacestudio/dps_juce_setup.git dps_juce_test_clone
```

- verify that `~/.gitconfig` contains correct username and access token
- in `CMakeLists.txt`:

```
CPMAddPackage(  
  NAME dps_juce_setup  
  GITHUB_REPOSITORY darkpalacestudio/dps_juce_setup  
  GIT_TAG master  
  )
```

# Github Actions Ci Access Private Repos

- create a new ssh key locally:

```
ssh-keygen -t ed25519 -C "your_email@example.com"
```

- go to the github website and open the settings for the private repo (the private one you want to use somewhere else)
	- under "deploy keys" add the public key
- go to the github website and open the settings for the repo (the downstream project that wants to use the private repo)
	- under "secrets and variables" - "actions" add a new secret with the private key
- in github actions script add the following:

```
ssh-add - <<< '${{ secrets.[Name of the repository secret] }}'
```

# Github Actions Use Custom Xcode Version on Mac

Available versions can be checked on [this website](https://github.com/actions/runner-images/blob/main/images/macos/macos-14-Readme.md#xcode) (change url if you use a different macos version).

```yml
Mac:  
  runs-on: macos-latest  
  steps:  
    # Select fixed xcode version  
    - name: Select Xcode 15.4  
      run: sudo xcode-select -s /Applications/Xcode_15.4.app/Contents/Developer
      
    - name: Set up cmake  
      uses: jwlawson/actions-setup-cmake@v2.0  
      with:  
        cmake-version: '3.26.x'  
```

# Force Git to Use Ssh instead of Https

```
git config --global url."ssh://git@github.com".insteadOf "https://github.com"
```

# Git Stash --all

- `git stash` ignores ignored and untracked files, use `git stash --all` to include those.
- works also for `git clean --all`

# Git Blame -L, Git Log -L

- `git blame -L 15,26:path/to/file.txt` will blame only this range of lines
- Works also for `git log -L ...`
- Does not need to be a line range, but can be a function name
	- `git log -L :<function_name>:path/to/file.txt`
	- will try to figure out heuristically what was changed

# Git Blame -w

- ignore whitespaces

# Git Blame -C

- ignore lines moved in the same file
- Can be appended up to three times
- `git blame -C -C -C path/to/file`
	- will ignore lines moved, creation of file

# Git Reflog

- will store comands (e.g. rebase, reset, ...)

# Git Diff --word-diff

- will not diff by lines, but by words: make it easy to spot any small change

# Git Config --gobal rerere.enabled

- REuse REcorded Resolution
- whenever you solve a merge conflict, me git remember that and reuse it to solve a similar merge conflict in the future

# Git Push --force-with-lease

- like force push, but works out only if the reference is correct.
- This will avoid deleting commits of other people

# Add a Base Version of a File, Ignore Future Changes

```bash
git update-index --skip-worktree .obsidian/workspace.json
```

- Works for local and upstream changes

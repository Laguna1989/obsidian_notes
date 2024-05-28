## repo size badge
```![GitHub repo size](https://img.shields.io/github/repo-size/[USER/ORG]/[REPONAME])```
will e.g. look like this
![GitHub repo size](https://img.shields.io/github/repo-size/darkpalacestudio/filter_lib)

## Personal access tokens and CPM (cloning private repos)
- It seems that one needs to use classic personal access tokens for https access.
- Perhaps the [Git Credentials Manager](https://github.com/git-ecosystem/git-credential-manager/blob/main/README.md) is another viable option? (for later)
- github website: Got to `Settings` -> `Developer Settings` ->  `personal access tokens`
- create a token
- on the command line
```
git config --global url."https://[normal_github_username]:[access_token]@github.com".insteadOf "https://github.com"
```
- check that you can clone  the private repo, without entering any credentials
``` 
git clone https://github.com/darkpalacestudio/dps_juce_setup.git dps_juce_test_clone
```
- verify that `~/.gitconfig`  contains correct username and access token
- in `CMakeLists.txt`:
```
CPMAddPackage(  
  NAME dps_juce_setup  
  GITHUB_REPOSITORY darkpalacestudio/dps_juce_setup  
  GIT_TAG master  
  )
```

## github actions ci access private repos
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

## Force git to use ssh instead of https
```
git config --global url."ssh://git@github.com".insteadOf "https://github.com"
```

# git stash --all
- `git stash` ignores ignored and untracked files, use `git stash --all` to include those.
- works also for `git clean --all`
# git blame -L, git log -L
* `git blame -L 15,26:path/to/file.txt` will blame only this range of lines
* Works also for `git log -L ...` 
* Does not need to be a line range, but can be a function name 
	* `git log -L :<function_name>:path/to/file.txt`
	* will try to figure out heuristically what was changed

# git blame -w
* ignore whitespaces
# git blame -C
* ignore lines  moved in the same file
* Can be appended up to three times
* `git blame -C -C -C path/to/file`
	* will ignore lines moved, creation of file

# git reflog
- will store comands (e.g. rebase, reset, ...)

# git diff --word-diff
- will not diff by lines, but by words: make it easy to spot any small change

# git config --gobal rerere.enabled
- REuse REcorded Resolution
- whenever you solve a merge conflict, me git remember that and reuse it to solve a similar merge conflict in the future

# git push --force-with-lease
- like force push, but works out only if the reference is correct. 
- This will avoid deleting commits of other people

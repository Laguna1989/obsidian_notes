---
tags:
  - tool
  - git
  - github
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

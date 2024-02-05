
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


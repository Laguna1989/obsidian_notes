---
tags:
  - tool
  - git
  - github
  - github-actions
---
# Github Actions Ci Access Private Repos

- create a new ssh key locally:

```
ssh-keygen -t ed25519 -C "your_email@example.com"
```

- go to the github website and open the settings for the private repo (the private one you want to use somewhere else)
	- under "deploy keys" add the **public key**
- go to the github website and open the settings for the repo (the downstream project that wants to use the private repo)
	- under "secrets and variables" - "actions" add a new secret with the private key, e.g. as `MY_SSH_KEY`
- in github actions script add the following:

```
ssh-add - <<< '${{ secrets.[Name of the repository secret] }}'
```

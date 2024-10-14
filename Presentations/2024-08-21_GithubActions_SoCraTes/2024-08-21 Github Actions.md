---
tags:
  - presentation
  - conference
  - SoCraTes-2024
  - github-actions
  - github
---
# Github Actions

Simon Weis

SoCraTes Germany 2024

---

# Motivation

- Automate workflows
- Unified development/build environment
- Target different platforms
- Any language/framework/tool
- Get a fancy badge on your repo
- Very easy to get started

---

## Pricing

- Public repositories:
	- Free
- Private repositories:
	- Free monthly limit
	- Free on self-hosted runners

---

# Alternatives

- Gitlab CI
- Travis
- Teamcity
- Jenkins
- ...

---

# Workflow

- Create a `yml` file in

```
.github/workflows
```

- Tip: Get and Editor with `yml` formatting/highlighting

---

# Exampl Yaml

```yml
name: Run Tests

on:
	push:
	  branches: [ master ]
  pull_request:
	  branches: [ master ]
  workflow_dispatch:

jobs:
	...
```

---

# Jobs

```yml
UnitTests:
	runs-on: ubuntu-latest

	steps:
		- uses: actions/checkout@v4
		- name: Configure CMake
			run: cmake -B ${{github.workspace}}/build
		- name: Build
			working-directory: ${{github.workspace}}/build
			run: make
		- name: Test
			working-directory: ${{github.workspace}}/build
				run: ./tests
```

---

# In the Web UI

![[IMG-2024-08-22-083154055.png]]

---

# Community Power

Github Actions [Marketplace](https://github.com/marketplace?type=actions)
- Deployment to AWS, GoogleCloud, FTP, github pages, docker ...
- Cove Coverage and Code Analysis
- Linting, Security Checks, ...
- Integrates with JIRA
- Any `bash` or `bat` script
- Docker images

---

# Tip: See Installed Software

![[IMG-2024-08-22-083642189.png]]

---

# Tip: Setup Your Own Runner

![[IMG-2024-08-23-070612598.png]]

---

# Tip: Dependabot

- Automatically creates PRs for outdated dependencies
	- cargo, npm, docker, gradle, maven, pip, Terraform, yarn, ...

---

# Let's Try it out

## Hands-on Workshop

[github workshop repo](https://github.com/Laguna1989/CodeNummy_GithubActions)

or

Your own repo

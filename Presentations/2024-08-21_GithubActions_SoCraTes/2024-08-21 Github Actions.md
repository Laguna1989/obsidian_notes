# Github Actions

Simon Weis

SoCraTes Soltau 2024

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

- Travis
- Gitlab CI
- Teamcity
- Jenkins

---

# Workflow

- Create a yaml file in

```
.github/workflows
```

- Tip: Get and Editor wih yml formatting/highlighting

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

Github Actions Marketplace
- Deployment to AWS, GoogleCloud, FTP, github pages, docker ...
- Cove Coverage and Code Analysis
- Linting, Security Checks, ...
- Integrates with JIRA
- Automatic code reviews by ChatGPT
- Any `bash` or `bat` script
- Docker images

---

# Tip: See Installed Software

![[IMG-2024-08-22-083642189.png]]

---

# Tip: Setup Your Own Runner

---

# Tip: Dependabot

- Automatically creates PRs for outdated dependencies

---

# Summary

- Very easy to get started
- Powerful functionality

---

# Let's Try it out

Hands-on workshop

[github workshop repo](https://github.com/Laguna1989/CodeNummy_GithubActions)

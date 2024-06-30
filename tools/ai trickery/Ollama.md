---
tags:
  - tool
  - ai
  - ai/llml
links: "[[tools]]"
---

> [!note] See [[AI Assisted Programming]]

> [!note] Website: [Ollama](https://ollama.com/)

# Overview

Ollama is a way to run a large language model locally

# Setup Instructions

## Linux

```bash
#########################
#install
curl -fsSL https://ollama.com/install.sh | sh
# might need to enter root password

#########################
# start
ollama serve
# if ollama service is already running:
systemctl stop ollama

#########################
# run
ollama run llama3 
```

Instead of `llama3` you can use any of the models on the ollama website.

# Models

- `deepseek-coder v2` is good for programming related tasks
- `codellama` is also said to be good with code

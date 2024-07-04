---
tags:
  - testing
  - cpp
---
# References

- [GitHub - nlohmann/mutate\_cpp: C++ Mutation Test Environment](https://github.com/nlohmann/mutate_cpp)

# Overview

- Mutation testing Framework for cpp
- Comes with its own webservice that runs locally
- Very easy and well explained project setup

# Run

```bash
# cd to your local clone of mutate_cpp 
venv/bin/python run.py
```

Open [127.0.0.1:5000](http://127.0.0.1:5000/)

# In case Progress Gets Stuck

- Check log, most likely it is a patch that can not be applied
- Stop server
- Clean Source Directory

```bash
# cd to the source directory
git reset --hard
# optional (remove all .rej files)
```

- restart server with `run.py` command from above

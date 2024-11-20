---
tags:
  - tool
  - cpp
  - performance
  - linux
---

> [!info] Perf is a powerful performance analysis tool

# Installation on Linux

```bash
sudo apt-get install linux-tools-common
```

# Get Statistics

```bash
perf stat ./executable
```

Best executed on a performance test, e.g. with [[Google Benchmark]].
-> Interesting numbers are e.g. `branch-misses`

# Annotated Sourcecode via Perf

## Perf Record

```bash
sudo perf record -a ./executable
```

This results in a `perf.data` file

## Perf Report

```bash
sudo perf report perf.data
```

-> press `a` on any symbol

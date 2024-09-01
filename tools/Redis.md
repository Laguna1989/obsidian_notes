---
tags:
  - tool
  - network
---
# Overview

- `Redis` stands for *Re*mote *Di*ctionary *S*ervice
- Advanced No-SQL key-value data store
- Can be used as Database, cache or message broker
- Good for short-term data that needs fast retrieval
- Uses the machines RAM but can be backed up to the hard drive
- Runs as server-side software

# Command line Tool

- Installation

```bash
sudo apt install redis-tools
```

- Connect

```bash
redis-cli -h <target_ip>
```

## Once Connected

- Get statistics about the redis server

```redis
info
```

- Select a specific db

```redis
select 0
```

- List all keys in a db

```redis
keys *
```

- Get a specific key

```redis
get <key_name>
```

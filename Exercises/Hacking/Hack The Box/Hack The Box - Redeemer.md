---
tags:
  - hacking
---
# Topics

- redis

# Steps

- connect via vpn
- scan ports via [[nmap]]
- connect via [[Redis]]

```bash
redis-cli -h <target_ip>
```

- get redis statistics

```redis
info
```

- select db 0

```redis
select 0
```

- List all keys

```redis
keys *
```

- Get flag value

```redis
get flag
```

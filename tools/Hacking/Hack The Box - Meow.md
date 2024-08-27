---
tags:
  - hacking
---
# Themes

- Telnet
- Basic setup

# Steps

- ping the target

```bash
ping <target_ip>
``` 

- do a portscan

```bash
nmap -sV <target_ip>
```

- use telnet to connect

```bash
telnet <target_ip>
```

- Try out common usernames

```
root
admin
administrator
user
```

- once connected, use `ls` and cat to find the `flag`

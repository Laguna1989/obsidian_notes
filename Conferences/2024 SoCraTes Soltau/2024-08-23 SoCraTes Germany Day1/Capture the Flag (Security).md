---
tags:
  - conference
  - SoCraTes-2024
---

- [HackTheBox](https://www.hackthebox.com/) Website about learning about security
- john the ripper toolset
- md5 hashes can be looked up via google
- Never store stuff unsalted
- `sqlmap` stores a cache that can break results
	- `sqlmap --flush-session` removes that cache
- `sudo -l`
	- list allowed commands

```
[sudo] password for laguna: 
Matching Defaults entries for laguna on simondell:
    env_reset, mail_badpass, secure_path=/usr/local/sbin\:/usr/local/bin\:/usr/sbin\:/usr/bin\:/sbin\:/bin\:/snap/bin, use_pty

Runas and Command-specific defaults for laguna:
    Defaults!/usr/lib/*/libexec/kf5/kdesu_stub !use_pty

User laguna may run the following commands on simondell:
    (ALL : ALL) ALL

```

- Check shell history `history`
- Check which shell/bash we are in: `echo $0`
- `whoami` -> find out current user
- `ls -lha /` to get info about files and folders
- `nc -nvlp [port]`[netcat](https://en.wikipedia.org/wiki/Netcat)
- `ls /etc/sudoers.d`
- `echo [password] | sudo -l -S
- Create an interactive shell
	- `python3 -c 'import pty;pty.spawn("/bin/bash")'
	- Ctrl Z
- Useful website for bash commands [explainshell.com](https://www.explainshell.com)

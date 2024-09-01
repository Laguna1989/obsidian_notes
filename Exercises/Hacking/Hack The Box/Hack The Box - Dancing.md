---
tags:
  - hacking
---
# Topics

- smb
> [!note] see also [[SMB]]

# Steps

- connect via vpn
- `nmap` reveals

```bash
$ nmap -sV <target_ip>
Starting Nmap 7.80 ( https://nmap.org ) at 2024-08-27 14:52 CEST
Nmap scan report for <target_ip>
Host is up (0.025s latency).
Not shown: 997 closed ports
PORT    STATE SERVICE       VERSION
135/tcp open  msrpc         Microsoft Windows RPC
139/tcp open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp open  microsoft-ds?
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 8.35 seconds
```

- list content via `smb` (`-L` = list shares)

```bash
smbclient -L <target_ip>
```

- smb commands

```smb
help - list all commands
l - list content 
get - get (download)
cd - change directory
```

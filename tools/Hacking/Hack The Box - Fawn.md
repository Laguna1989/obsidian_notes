# Themes

- ftp

# Steps

- Download the ovpn file and connect to the vpn

```bash
openvpn starting_point_<name>.ovpn
```

- Ping the target

```bash
ping <target_ip>
```

- do a portscan

```bash
nmap -sV <target_ip>
```

- connect via ftp

```bash
ftp <target_ip>
```

- use the `anonymous` user as this does not require a password
- we will receive a response code `230` for successful login
- ftp type `help` to get a list of all commands
- ftp list the files and receive the flag file

```ftp
ls
get flag.txt
```

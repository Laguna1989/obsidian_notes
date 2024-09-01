---
tags:
  - tool
  - network
---
- SMB stands for Server Message Block
- SMB allows to access files or printers at a remote server
- Clients can read, create, remove and updates files on the server
- Clients can also communicate with any server program that is set up to receive SMB client requests
- smb enabled storage is called "share"
- normally login/password data is required, but misconfiguration allows guest or anonymous access
- smb runs as application layer software, relying on lower level communication protocols
![[IMG-2024-08-27-145632535.png]]
- smb often uses netbios over tcp/ip (that is why we see both ports open)

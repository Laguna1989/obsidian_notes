---
tags:
  - tool
  - apple
---
# Links

[Good tutorial](https://melatonin.dev/blog/how-to-code-sign-and-notarize-macos-audio-plugins-in-ci/)

# How to Get App-specific Password (needed for Notary tool)

- go to [appleid.apple.com](https://appleid.apple.com/)
![[IMG-2024-09-13-214923459.png]]
- Go to App-specific Passwords
- Create a password and immediately safe it (it will only be shown on creation)

# How to Find the Shortname Team ID

- Go to [developer.apple.com/account](https://developer.apple.com/account)
- Go to Membership Details
- Copy the Team ID

> [!info] This is needed for **notarytool**

> [!warning] Do not use this Shortname for **codesign**
>  The Full Team ID is needed for that

# How to Find the Full Team ID

- Execute in a terminal

```bash
security find-identity -v -p codesigning
```

There is a quoted string at the end of the line(s), which contains the full team id. Usually the shortname is part of the full team id

> [!info] This is needed for **codesign**

> [!warning] Do not use this for **notarytool**
> The shortmane is needed for that

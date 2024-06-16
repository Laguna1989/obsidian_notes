---
tags:
  - design-patterns
links: "[[Structural Design Patterns MOC]]"
---

> [!quote] Interface for accessing a particular resource
>

- The interface looks like the interface of the object you want to access
- Same interface but entirely different internal behavior
- A class that functions as an interface to a particular resource which may be remote, expensive to construct or may require logging or any other added functionality
- Best Example: Smart Pointers.
	- Same functionality as with a raw pointer, but with some extensions available and very different underlying behavior.

## Property Proxy

- In C# there are properties, which is a member with a getter and setter
- Take care of assignment and access and add special behavior
![Enter image alt description](IMG-2024-05-31-134031765.png)

## Virtual Proxy

- Example:
	- Image interface with single interface function draw() = 0
	- Bitmap is an Image
![Enter image alt description](IMG-2024-05-31-134031894.png)

- Drawback: We do not actually need to load the bitmap unless someone wants to draw it
- We can build a virtual Proxy (LazyBitmap) which follows the interface of the bitmap, but it is actually a lazy proxy which only loads the bitmap when draw is called

- In draw we check if the bitmap has been loaded and then actually load it once.
![Enter image alt description](IMG-2024-05-31-134032034.png)

## Communication Proxy

- We start with a “Pingable” Interface with single function `ping (std::string const& message) = 0`
- Then we have a Struct Ping, which inherits from Ping.
- A Function `tryit(Pingable& pp)`, which calls ping
- Lets create a RemotePong class that uses the same interface (ping) but connects to a REST service.
![Enter image alt description](IMG-2024-05-31-134032227.png)

- In main we only need to replace `Pong` with `RemotePong`
![Enter image alt description](IMG-2024-05-31-134032238.png)

## Proxy Vs [[Decorator]]

- They are really similar
- Proxy provides an identical interface, decorated provides an enhanced interface
- Decorator typically aggregates, Proxy can be a brand new object, not related to the original implementation at all
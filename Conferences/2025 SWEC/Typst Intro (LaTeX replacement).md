---
tags:
  - SWEC-2025
---

- Installation mit winget or apt
- Written in rust
- Tinymist Typst extension for vscode
- Uses basic markdown inspired syntax

# Set Rules

```typst
#set text (font: "Consolas")
Now this is in Consolas
```

# Show Rules

- Further Customization
- E.g. text replacement

```
#show "difficult": "easy"
```

Also with lambdas

```
#show heading : heading => [#set align(center)]
```

```
#show heading.where(level:3) : heading => [#set text(red)]
```

# Syntax

```
#let subject = [Typst]

This talk is about #subject.
```

Scopes

```
[ ] is used for content
#{ } is used for code
```

Arrays, dicts, loops

```
#let arr = (1,2,3)
#let dict = (first: "Hello", second: "World")
#for i in arr { [#i] }

#for (key, val) in dict [ #key: #val ]
```

Functions

```
#let add(a, b) = {a + b}

#add(2,3)

/*Variable number of arguments*/
#let separate_words(sep, ..wods) = {
	let w_array = words.pos()
	for word in w_array.intersperse(sep){ [#word] }
}
#let fruits = ("Apple", "Banana)
#separate_words("|", ..fruits)
```

# Layout

```
#h(15pt)
#v(10%)
#grid(
	columns: (1fr, 2fr, 1fr),
	column-gutter: 4pt,
	, ..rects
)
```

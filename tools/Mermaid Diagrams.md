Very useful diagrams, can be displayed directly in [[Obsidian]].

[Mermaid](http://mermaid.js.org/#/) seems to be a valid alternative to [[plantuml]].


# Examples
## Graph 
```mermaid
graph TD
Start ---> B
Start ---> |Alternative|Stop2
Start ---> B[\Text in the B Box/]
```

graph can be followed by `TD` (top-down) or `LR`(left right)
```mermaid
graph LR
Start ---> Stop
```
## Sequence Diagram
```mermaid
sequenceDiagram
    Alice->>+John: Hello John, how are you?
    Alice->>+John: John, can you hear me?
    John-->>-Alice: Hi Alice, I can hear you!
    John-->>-Alice: I feel great!
```


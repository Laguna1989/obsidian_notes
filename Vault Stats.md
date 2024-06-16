# Files in Repo by Size

```dataview  
TABLE round(file.size) as "File Size (b)"
SORT file.size desc
LIMIT 20
```

# Notes with Most Backlinks

```dataview
TABLE file.inlinks as Backlinks, length(file.inlinks) as Total
SORT length(file.inlinks) DESC
WHERE !contains(file.name, "MOC")
LIMIT 5
```

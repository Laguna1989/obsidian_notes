
# Conferences
```dataview
Table 
	(""+ created +"") AS Date
From #conference
SORT file.ctime DESC
```



```dataview
Table 
	(""+ created +"") AS Date
From #talk
SORT file.ctime DESC
```

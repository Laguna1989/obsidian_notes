---
tags:
  - rust
  - SWEC-2024
---

Aus afl++ entstanden
- #Rust library
- Korpus (testcase), target und objectives
- comile guided anleitung für fuzzer
- creates coverage und metriken
- Feedback loop der test cases anhand von objectives in fehler und warnings sortiert
- Mutators verändern input, evolutionärer ansatz UND zufällige werte
- Analyzer: treffe aussagen über inputs treffen
- Stages: baut pipeline auf
- Executor: kombiniert input, observer und porgamm (inkl hardware support)
- Ideal: programm direkt über memory parameter fuzzbar

# Beispiel Xpdf

- cve von 2019
- infinite recursion bug
- fix: recursion limit und fehler schmeissen
- feedback: coverage, runtime und stack size
- rust macht beim build alles.
	- **baut xpdf** mit bestimmter instrumentierung (spezifischer clang und gcc)
	- **starting sample** input: 2 pdfs ("hello world" und "example pdf")
		- -> corpus schreiben
		- in.-memory corpus contained die pdfs
	- **findings** on disc corpus contained findings
	- **observer** greift mittels shared memory auf fuzzingtarget
		- time observer (laufzeit)
		- edge observer (coverage)
	- **objectives** timeout UND neue code pfade
	- **monitor** printed wie viele targets
	- **forkserver** forked für jede execution und startet xpdf und füge datei als cmdl argument hinzu
	- timeout wert sinnvoll wählen ("wie lange läuft das tool?")
	- havoc mutator: sehr random, kommt von haus aus mit
- invalides pdf: als guter fall, weil das programm ja eigentlich läuft
- wie viele execs pro sekunde?
- schneller machen:
	- multicore
	- mehr sinnvoller input
	- kein fork&exec sondern direkt in memory
	- lto compiler

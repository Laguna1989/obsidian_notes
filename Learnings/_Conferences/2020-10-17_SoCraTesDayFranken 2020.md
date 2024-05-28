---
created: 2020-10-17
---
#conference
[[_Confrerences]]
# SoCraTesDay Franken 2020

## Timeline
![[Pasted image 20240527071925.png]]

## SoCraTes Day Franken Introduction



* Wer auch immer kommt, sind die richtigen Leute - Die Leute sind da, weil sie interessiert sind
* Was auch immer passiert, ist das richtige - Weil man selber Talks vorschlagen/halten/anfragen kann.
* Wenn es beginnt, ist der richtige Zeitpunkt - Kreativität folgt eigenen Regeln
* Wenn es vorbei ist, ist es vorbei - 45 min, muss nicht ausgeschöpft werden, kann länger dauern

### Gesetze
* Gesetz der zwei Füße - Jeder darf sich so bewegen, wie er will - Wechsel auch zwischen Session möglich
* Bumblebees and Butterflies: Schmetterlinge mischen überall ein bisschen mit, Hummeln bleiben die ganze Zeit bei einer Session.
* Sei bereit, Überraschungen zu erleben

Online Board [https://miro.com/app/board/o9J_kjxiJlY=/](https://miro.com/app/board/o9J_kjxiJlY=/)

## Konfiguration Management

* Früher wenig linux admins, sondern v.a. linux oder noch ältere systeme
* admins loggen sich manuell remote ein und ändern configs manuell
* next step: shell scripte, die sich selber einloggen, aber ebenfalls fehleranfällig
* Erstes gutes und weit verbreitetes Tool: Puppet
    * deklarative beschreibung des Zielzustands
    * Client muss auf zielrechner laufen
    * Server speichert Konfigurationen
* Chef ähnlich zu Puppet
* beide vor containern und cloud. Alte Rechenzentrumswelt
* Ab jetzt dynamische Infrastruktur
* 2010 Amazon startet cloud Anwendungen mit AWS mit proprietären Konfigurationsmanagement
* Jetzt Saltstack oder Ansible (super einfach) auch noch für statische Welt
* Heat, Terraform v.a. für dynamisches Umfeld
* terraform:
    * deklarativer Zustand
* Pets vs Cattle
    * Pets sind die alte generation, um die man sich individuell kümmert
    * Cattle ist eine anonyme Herde, wo Tiere beliebig dazu oder weg kommen.
* Tool: Packer
    * Baue mir automatisiert das Abbild einer VM und führe bestimme Anwendungen aus
    * Automatisierung des Image Builds
    * Kann für beliebige Targets kompilieren (docker, aws, google cloud, …)
* Vagrant: lokales testing ohne Cloud oder VM
    * provisionierung lokal - wie terraform für cloud, hier lokal
    * docker steuert container
    * vagrant steuert vms oder docker
##  tmux und terminals

* Motivation
    * Slides im terminal :O (“patat”)
    * TMux : Terminal Multiplexer, wie gnu screen
    * Window manager für terminals
    * Keep stuff running after logout
    * Skripting
* Begriffliches:
    * Terminal
        * Provides IO to a computer
        * Ursprung in den 60ern, TeleTYpeWriter Ausgabe
        * Visual Display Units (erste screens, “glass TTYs”)
        * Control Codes: ^M carriage return, ^J Line feed, ^G Bell
        * Escape Sequences like Ansi escape sequences
        * Unterschiedliche Hersteller, Chaos wegen proprietären Protokollen
        * Unix führt Abstraktionsschicht ein: termcap/terminfo 
            *  welche Escape sequences, welche Features? 
            *  $TERM
        * VT100 oder VT220 sehr stark verbreitet
    * Terminal Emulators
        * Terminal bietet nur IO
        * Terminal Emulator: Schicht zwischen Shell und Terminal
        * Terminal bietet keine Syntax Highlighting oder Tab Completion -> shell
        * Job Control ctrl Z, crtl C, fg, bg, jobs, ….
        * Posix Terminal In----terface: Input/Output
    * Terminal Impl / API
        * Unix system provide tty devices tty1, tty2, … controlled vio ioctl, system calls
        * Pseudoterminals PTYs (/devpts/*)
        * Windows bietet ConPTY API
        * Deutliche Verbesserung für Windows in den letzten Jahren
    * Linux Basics (most likely never required in real work)
        * stty command to get/set terminal capabilities, e.g. stty -a
    * Notable Terminal Emulators:
        * Linux: console, xterm, konsole, GNOME Terminal
        * macOS: Terminal, iTerm2, Terminator
        * Windows: Windows Terminal, mintty, PuTTY, ConEmu
        * TODO Check out Windows Terminal!!
        * Features: Unicode, Emojis, 256 Colors, look and feel
        * Keyboard Shortcuts
    * Command line shell
        * “command line shell”
        * Shell und terminal kann beliebig kombiniert werden
    * CLI
        * auch python hat ein CLI
        * verarbeitet parameter
        * edit/edit command lines
        * convenience features (tab completion, …)
    * TUI
        * nachmalen von windows in shells
        * z.B. vim, tmux
    * Console
        * nicht gut definierter term, sehr schwammig
        * Windows manager für anwendungen im terminal

## Podcasts

Lange Liste: [https://github.com/qotsa2002/podcasts](https://github.com/qotsa2002/podcasts)
* The ideal cast - Gene Kim - DevOps [https://itrevolution.com/the-idealcast-podcast/](https://itrevolution.com/the-idealcast-podcast/)
* Ready for review - IT themen  [https://ready-for-review.dev/](https://ready-for-review.dev/)
* Legacy code rocks -  [https://www.legacycode.rocks/podcast-1](https://www.legacycode.rocks/podcast-1)
* Malicious Life - Security [https://malicious.life/](https://malicious.life/)
* Software Crafts Podcast - Verschiedene Themen rund um software crafting [https://www.softwarecraftspodcast.com/](https://www.softwarecraftspodcast.com/)

## Conditional Untangling
* v.a. java spezifische Umformungen, z.B. Try&lt;T>, bind oder flatmap

## Corona Hacks
* Statt Termine mit 1h dauer - Dreiviertel Stunden Termine  weil wegzeiten wegfallen.
* Laptop am Abend abbauen
* Morgens/Abends um den Block laufen um Arbeitsweg zu simulieren
* Kameras einschalten - lange Diskussion
* Feste Zeiten für Kaffeepausen
* Mittagspause blocken
* Kaffeeklatsch Termine um Flurfunk zu simulieren
* Privatleben/Arbeitszeit
* Liste von Leuten die man lange nicht getroffen hat
* Tagebuch führen, was man alles erledigt hat
* Hybride Meetings (halb online, halb offline) funktioniert nicht
* “Kreativ” mit Arbeitszeit umgehen
* Vorteile:
    * Office Utilization
    * Einstellen von Leuten, die nicht in der Gegend wohnen
    * Umwelt
    * Alle Teilnehmer (20) sagen, sie sind im home office produktiver
* Nachteile:
    * Soziale Isolation
    * Falls sich homeoffice durchsetzt: Mehr Konkurrenz auf dem Arbeitsmarkt?
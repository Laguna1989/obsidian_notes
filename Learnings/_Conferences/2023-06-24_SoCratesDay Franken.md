---
created: 2023-06-24
---
#conference 
# SoCraTes Day Franken 2023
## Timeline
![[2023-06-23_SoCraTesDayFrankenTimeline.png]]


## 10:00 Testing without Mocks
* Beispiel: Flachwitze App
* Architektur:
    * Browser -> request handler -> JokeRepo -> DB -> Filesystem (seiteneffekt)
* Request handler soll getestet werden
* Mögliche Lösung: Mock für das JokeRepo
* Das erzeugt zwei Nachteile:
    * Mocks produzieren false positives (test die fehlschlagen, obwohl mein Code korrekt funktioniert) und false negatives (grüne tests obwohl Problem im Code vorhanden)
    * Zwei losgelöste implementierungen (Mock und tatsächliche Impl)
* Das Nullable Object Pattern
    * Code mit Seiteneffekten that has a createNull() factory method (creates impl with disabled external communication but behaves normally), parameterless instantiation
* Beispiel: JokeRepo.createNull().remove(id) // simuliert erfolgreiches löschen, ohne Seiteneffekte
    * Klingt wie Mock und Implin einem Objekt
    * Produktivcode enthält (unerwünschten) createNull() code
* CreateNull() funktion erlaubt configuration der Implementierung
* Zweites Pattern um Funktionen ohne return value zu testen
    * EventEmitter: Alle Objekte emittieren Events, wenn seiteneffekte auftreten würden
    * Fühlt sich an wie mock expectations die zufällig auch in production benutzt werden kann
* Isolated tests (alles durch mocks ersetzt) vs sociable tests (schnittstellen zu den dependencies werden mitgetestet)
* Eigentlich sind es keine Unit tests mehr
* Dependency Chains:
    * Lowlevel: Projekt Unanbhängige Komponenten (HttpClient, DynamoDbClient, …)
        * Macht nur genau so viel wie benötigt wird, um das Highlevel Objekt zum laufen zu bringen
    * HighLevel: Projekt abhängige Komponenten (JokeRepo, CartService, ..)
        * createNull() erstellt eine lowlevel null componente und speichert diese intern
    * Meistens sehr kurze Ketten (2-3 Komponenten)
* TLDR: 	
    * Nullable Object Gleiches Objekt in Impl und Tests
    * Objekt kann genau so konfiguriert werden wie benötigt (KISS!)
    * Seiteneffekte lösen Events aus, die zum testen oder in produktion benutzt werden können
    * Highlevel Objekte transformieren ihre Nullkonfiguration in das Format für die darunterliegende Ebene
* Violation von SRP?!?


## 11:00 Multiplayer Games are not that hard
* Selber gehalten
* [https://docs.google.com/presentation/d/1HbXXm_dDPE-tnEzEGMY3bUyvsS4OmO6oMmsES5W2QIE/edit?usp=sharing](https://docs.google.com/presentation/d/1HbXXm_dDPE-tnEzEGMY3bUyvsS4OmO6oMmsES5W2QIE/edit?usp=sharing) 


## 12:00 Mittagessen


## 12:45 Sport und Dehnen


## 13:00 DevOps
* Development und Operations in einem Team
* Keine Rolle, keine Org-Struktur, kein Tool sondern eine Kultur
* 3 Companies doing devops well
    * Amazon/AWS
    * Netflix
    * Airbnb
    * Starbucks (unerwartet, weil keine Software)
    * US customs border protection (Papierkrieg durch Automatisierung abgeschafft)
    * NASA
* Nicht nur Software liefern, sondern ein echtes Produkt, mit Kundenservice, mit Hardware Provisionierung, …
* Responsibilities
    * Develop
    * Deploy
    * Support
    * Protect
    * Automation
* CREAM -> Cash Rules Everything Around Me


## 14:00 Local LLM (large language models)
* Private gpt (nicht gut)
* Gpt4all (gute Übersicht)
* Braucht viel Spei


## 15:00 Prompt Injection Attacks vs Gandalf
* [https://gandalf.lakera.ai/](https://gandalf.lakera.ai/)   
* Owasp.org (für alle dinge die kaputt gehen können)


## 17:00 Refucktoring
* Make a simple fizzbuzz as bad as possible by applying refactoing
* [https://github.com/Hackerkegeln/refuctoring/tree/socrafran-2023](https://github.com/Hackerkegeln/refuctoring/tree/socrafran-2023) 
# 🎯 C Programming Playground - Pointer & Memory Training

Dieses Repository enthält eine strukturierte Sammlung von C-Übungen zum Erlernen von Pointern und Memory-Management.

## 📚 Roadmap

Die vollständige Roadmap findest du in [`roadmap.md`](./roadmap.md). Sie ist in 5 Stufen unterteilt:

-   **Stufe 0:** Warm-up (30-60 min Tasks)
-   **Stufe 1:** Pointer-Arithmetik (60-120 min)
-   **Stufe 2:** Einstieg malloc/free (90-120 min)
-   **Stufe 3:** Kleine Micro-Projekte (je 1-2h)
-   **Stufe 4:** Abschlussprojekt (2h)

## 📊 Fortschritt

### Stufe 0 — Warm-up

-   ✅ **0.1 Variable introspection** (`01_varintrospect/`)

    -   Programm erstellt, das int-Variablen anlegt, ausgibt, Adressen zeigt
    -   Pointer-Dereferenzierung und Wertänderung implementiert
    -   **Status:** Erfolgreich abgeschlossen

-   ✅ **0.2 Zwei Variablen tauschen (Swap)** (`02_switchvars/`)

    -   `swap(int* a, int* b)` Funktion implementiert
    -   Pointer als Funktionsargumente korrekt verwendet
    -   Tausch mit temporärer Variable durchgeführt
    -   **Status:** Erfolgreich abgeschlossen

-   ✅ **0.3 Pointer auf verschiedene Typen** (`03_pointertypes/`)

    -   int, float, char Variablen angelegt
    -   Wert, Adresse und sizeof für jeden Typ ausgegeben
    -   Memory-Layout und Stack-Organisation verstanden
    -   **Status:** Erfolgreich abgeschlossen

### Stufe 1 — Pointer-Arithmetik

-   ✅ **1.1 Mini-Array-Debugger** (`11_miniarraydebug/`)

    -   Array-Traversierung nur mit Pointern (`ptr++`)
    -   Pointer-Arithmetik und Pointer-Differenz verstanden
    -   While-Loop mit Pointer-Vergleich implementiert
    -   `#define` für Konstanten korrekt verwendet
    -   **Status:** Erfolgreich abgeschlossen

-   ✅ **1.2 Manuelle strlen-Funktion** (`12_manualstrlen/`)

    -   Implementierte `my_strlen` mit reiner Pointer-Iteration (kein Indexing)
    -   Länge über Pointer-Differenz ermittelt
    -   **Status:** Erfolgreich abgeschlossen

-   ⏳ **1.3 Pointer auf Pointer** - (`13_pointertopointer`)
    -   **Status:** Erfolgreich abgeschlossen

### Stufe 2 — malloc/free

-   ⏳ Noch nicht begonnen

### Stufe 3 — Micro-Projekte

-   ⏳ Noch nicht begonnen

### Stufe 4 — Abschlussprojekt

-   ⏳ Noch nicht begonnen

## 🔧 Kompilieren & Ausführen

Empfohlene Compile-Flags für Lernen:

```bash
gcc -Wall -Wextra <datei>.c -o <output>
./<output>
```

**Fish Shell Shortcut:**

```fish
cr <datei>.c  # kompiliert und führt aus
```

## 💡 Lernziele

-   Grundlegendes Verständnis von Pointern (`&`, `*`)
-   Pointer-Arithmetik und Array-Pointer-Äquivalenz
-   Dynamische Speicherverwaltung (`malloc`, `free`, `realloc`)
-   Memory-Layout und Debugging
-   Ownership-Konzepte in C

## 🧠 Wichtige Erkenntnisse

### Memory & Stack

-   **Stack wächst rückwärts:** Variablen werden in umgekehrter Reihenfolge ihrer Deklaration im Speicher abgelegt (von hohen zu niedrigen Adressen)
-   **Keine Garantie:** Die Reihenfolge lokaler Variablen ist implementation-defined - Compiler können optimieren und umordnen
-   **Adressen zeigen auf Bytes:** Jede Adresse referenziert genau 1 Byte im Speicher
-   **Keine Variable-Terminatoren:** Zwischen Variablen gibt es keine Markierungen - der Compiler weiß durch den Typ, wie viele Bytes zu lesen sind

### Strings in C

-   **String = Pointer:** Ein String ist nur die Adresse des ersten Zeichens (`char*`)
-   **Null-Terminator:** Strings enden mit `\0` (1 Byte mit Wert 0, NICHT zwei Bytes `/` und `0`)
-   **Keine String-Objekte:** C hat keinen String-Typ - nur char-Arrays mit `\0` am Ende
-   **printf sucht `\0`:** String-Funktionen lesen solange, bis sie auf das Null-Byte treffen

### Typen & Speicher

-   **sizeof gibt Bytes zurück:**
    -   `int` = 4 Bytes = 32 Bits → Wertebereich: 2^32 Werte
    -   `float` = 4 Bytes
    -   `char` = 1 Byte = 8 Bits → 2^8 = 256 Werte (0-255 oder -128 bis 127)
-   **char ist ein Integer:** `char` ist nur eine 8-Bit-Zahl, die oft für Buchstaben genutzt wird
-   **ASCII-Wert = gespeicherter Wert:** `'b'` und `98` sind identisch im Speicher

### printf & Format-Specifier

-   **printf ist ein Interpreter:** Parst Format-String und konvertiert Werte je nach Specifier
-   **Gleicher Wert, verschiedene Ausgaben:**
    -   `%c` → ASCII-Lookup → Zeichen
    -   `%d` → Dezimal-ToString
    -   `%x` → Hex-ToString
    -   `%p` → Pointer-Formatter
-   **Type Promotion:** `char` wird automatisch zu `int` promoted beim Funktionsaufruf

### Kompilierung & Linking

-   **`#include` kopiert KEINEN Code:** Nur Deklarationen (Function Signatures) werden eingefügt
-   **Object Files (`.o`):** Intermediate Compilation - Machine Code mit unaufgelösten Symbolen
-   **Dynamic Linking (Standard):** Executables sind klein, printf-Code kommt aus `libSystem.dylib` zur Laufzeit
-   **Static Linking:** Printf-Code wird ins Binary kopiert → größere Executables
-   **Stub & PLT:** Bei Dynamic Linking springt der Code über einen Stub zur echten Funktion
-   **Header Files:** Müssen MANUELL geschrieben werden - nicht automatisch generiert!

### Dateitypen

| Datei               | Beschreibung                            | Erstellt von   |
| ------------------- | --------------------------------------- | -------------- |
| `.c`                | Source Code (Implementation)            | Programmierer  |
| `.h`                | Header (API/Deklarationen)              | Programmierer  |
| `.o`                | Object File (kompiliert, nicht gelinkt) | `gcc -c`       |
| `.out` / executable | Fertiges Programm                       | `gcc` (Linker) |
| `.s`                | Assembly Code                           | `gcc -S`       |
| `.a`                | Static Library                          | `ar`           |
| `.so`/`.dylib`      | Shared Library                          | `gcc -shared`  |

### Debugging & Tools

-   **lldb:** LLVM Debugger für macOS (Apple Silicon)
-   **`Ctrl+C`:** SIGINT - unterbricht Programm
-   **`Ctrl+D`:** EOF - beendet interaktive Shells (lldb, fish, python)
-   **Assembly:** ARM64 auf Apple Silicon Macs
-   **Debug-Symbole:** `gcc -g` fügt Variablennamen für Debugger hinzu

## 📝 Notizen

-   Copilot für C-Dateien deaktiviert, um eigenständiges Lernen zu fördern
-   Jede Übung hat ihren eigenen Ordner mit selbsterklärendem Code
-   Fish Shell Funktion `cr` für schnelles Compile & Run

## References

-   [Type syntax in the language C: an object lesson in syntactic innovation](https://dl.acm.org/doi/pdf/10.1145/947626.947627)

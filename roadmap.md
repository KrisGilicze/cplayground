# 🧭 Roadmap: Tiny C Projects für Pointer & Memory

## Stufe 0 — Warm-up (30–60 min Tasks)

**Ziel:** Syntax lesen ohne Schmerzen, erste Pointer-Anfasspunkte.

### 0.1 Variable introspection

**Aufgabe:**  
Schreibe ein Programm, das:

- eine int-Variable anlegt
- ihren Wert ausgibt
- ihre Adresse (&x) ausgibt
- einen Pointer auf sie zeigt (`int* p = &x`)
- über den Pointer den Wert verändert

**Lernpunkt:**  
`&`, `*`, Dereferenzieren, Adressen.

### 0.2 Zwei Variablen tauschen (Swap)

**Aufgabe:**  
Schreibe eine `swap(int* a, int* b)` Funktion.  
Teste sie.

**Lernpunkt:**  
Pointer als Funktionsargumente verstehen.

### 0.3 Pointer auf verschiedene Typen

**Aufgabe:**  
Lege je einen int, float, char an und gib jeweils:

- Wert
- Adresse
- Größe (sizeof)

aus.

**Lernpunkt:**  
Pointer + sizeof + unterschiedliche Typgrößen.

## Stufe 1 — Pointer-Arithmetik (60–120 min)

### 1.1 Mini-Array-Debugger

**Aufgabe:**  
Lege ein statisches Array an:
```c
int nums[5] = {1,2,3,4,5};
```
Schreib eine Funktion, die:

- den Pointer `p = nums` nimmt
- nacheinander alle Elemente nur mit `p` und `p++` ausgibt

**Lernpunkt:**  
Array <-> Pointer Äquivalenz, Pointer-inkrementierung.

### 1.2 Manuelle strlen-Funktion

**Aufgabe:**  
Implementiere `size_t my_strlen(char* s)` ohne Array-Indexing, nur mit Pointer-Arithmetik.

**Lernpunkt:**  
Zeichenketten sind Pointer auf Null-terminierte Bereiche.

### 1.3 Pointer auf Pointer

**Aufgabe:**
```c
void to_uppercase(char** s_ptr);
```
Die Funktion soll den String, auf den `*s_ptr` zeigt, in GROSSBUCHSTABEN umwandeln.

**Lernpunkt:**  
`**` verstehen, Pointer in Funktionen verändern.

## Stufe 2 — Einstieg malloc/free (90–120 min)

Jetzt beginnen bewusste Allokationen und Freigaben.

### 2.1 Dynamisches Array

**Aufgabe:**  
Schreib eine Funktion:
```c
int* make_array(int n)
```
die mit malloc ein ganzzahliges Array erstellt und mit Werten füllt (z. B. 0..n-1).  
Später: `free()` nicht vergessen.

**Lernpunkt:**  
`malloc`, `sizeof`, `free`.

### 2.2 Realloc-Simulation (manuell)

**Aufgabe:**  
Ohne `realloc`:

- malloc für n ints
- neues Array mit 2*n Größe erzeugen
- Inhalte rüberkopieren (Pointer-basiert!)
- altes free
- neues Array zurückgeben

**Lernpunkt:**  
Copy-by-pointer, Ownership, Memory Flow.

### 2.3 dyn. String duplicator

**Aufgabe:**  
Schreibe `char* my_strdup(const char* original)`.  
Wie strdup, aber alles selbst.

**Lernpunkte:**  
Stringlänge bestimmen, Speicher allokieren, kopieren.

## Stufe 3 — Kleine Micro-Projekte (je 1–2 h)

Jetzt echte Mini-Tools, die C-Kernelmechanik spürbar machen.

### 3.1 Mini-Vector (wie std::vector light)

**Aufgabe:**  
Struktur Vector mit:

- `int* data`
- `int capacity`
- `int length`

Funktionen:

- `init_vector()`
- `push_back()`
- `free_vector()`

**Lernpunkte:**  
wachsende Buffers, Ownership, Realloc.

### 3.2 Eigener Memory-Pool (tiny allocator)

**Aufgabe:**

- Allokiere ein großes statisches Array `char pool[1024];`
- Bau eine Funktion `void* pool_alloc(int size)` die linear Speicher aus dem Pool „vergibt"
- Kein Free nötig

**Lernpunkte:**  
Memory-Layout, Pointer-Offsets, primitive Allocator-Logik.

### 3.3 Mini-CSV-Parser (nur ein Feld pro Zeile)

**Aufgabe:**

- Datei einlesen
- jede Zeile dynamisch duplizieren
- Pointerweise „," durch `\0` ersetzen
- Werte ausgeben

**Lernpunkte:**  
IO + Strings + malloc fusion.

## Stufe 4 — Kleines Abschlussprojekt (2 h)

### 4.1 Simplified malloc debugger

**Aufgabe:**

- Schreibe eine `debug_malloc(size)` Funktion, die intern protokolliert:
  - wo allokiert wurde
  - wie viel
- `debug_free()` löscht den Eintrag
- Am Programmende: alle nicht-freien Blöcke ausgeben (leak report!)

**Lernpunkte:**  
Listen, Speicherverwaltung, Debugging wie Valgrind light.

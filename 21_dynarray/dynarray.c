#include<stdio.h>
#include<stdlib.h>

// ### 2.1 Dynamisches Array

// **Aufgabe:**  
// Schreib eine Funktion:
// ```c
// int* make_array(int n)
// ```
// die mit malloc ein ganzzahliges Array erstellt und mit Werten füllt (z. B. 0..n-1).  
// Später: `free()` nicht vergessen.

// **Lernpunkt:**  
// `malloc`, `sizeof`, `free`.

int* make_array(size_t n) {
    int* buffer = malloc(n * sizeof *buffer);
    if (!buffer) {
        fprintf(stderr, "Error: Nicht genügend Speicher vorhanden!\n");
        return NULL;
    }
    for (size_t i = 0; i < n; i++) {
        buffer[i] = (int)i;
    }
    return buffer;
}

#define ARRAY_SIZE 8

int main()
{
	printf("Initializing buffer ...\n");
    int* a = make_array(ARRAY_SIZE);
    if (!a) return 1;
    for (size_t x = 0; x < ARRAY_SIZE; x++) {
        printf("%d ", a[x]);
    }
    printf("\nDone!\n");
    free(a);
	return 0;
}

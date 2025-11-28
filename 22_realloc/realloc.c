#include<stdio.h>
#include<stdlib.h>

// ### 2.2 Realloc-Simulation (manuell)

// **Aufgabe:**  
// Ohne `realloc`:

// - malloc für n ints
// - neues Array mit 2*n Größe erzeugen
// - Inhalte rüberkopieren (Pointer-basiert!)
// - altes free
// - neues Array zurückgeben

// **Lernpunkt:**  
// Copy-by-pointer, Ownership, Memory Flow.

#define ARRAY_SIZE 8

int* my_realloc(int * arr, size_t size) {
    int* newArray = malloc(2 * size * sizeof(int) );
    if (!newArray) return NULL;
    for (size_t i = 0; i < size; i++) {
        newArray[i] = arr[i];
    }
    free(arr);
    return newArray;
}

// Clean solution:
int *my_clean_realloc(int *arr, size_t size) {
    if (size == 0) {
        free(arr);
        return malloc(0); /* oder NULL, dokumentieren */
    }

    if (size > SIZE_MAX / 2) return NULL; /* overflow check */

    int *newArray = malloc(2 * size * sizeof *newArray);
    if (!newArray) return NULL; /* Caller keeps arr */

    /* pointer-basierte Kopie */
    int *src = arr;
    int *dst = newArray;
    int *end = arr + size;
    while (src < end) {
        *dst++ = *src++;
    }

    /* Initialisiere neu hinzugefügten Bereich für Vorhersagbarkeit */
    for (size_t i = size; i < 2 * size; ++i) newArray[i] = 0;
    /* alternativ: memset(newArray + size, 0, (2*size - size) * sizeof *newArray); */

    free(arr);
    return newArray;
}

int main() {
    int* buffer = malloc(ARRAY_SIZE * sizeof(int));
    if (!buffer) return 1;
    for (size_t x = 0; x < ARRAY_SIZE; x++) {
        buffer[x] = (int)x;
        printf("%d\n", buffer[x]);
    }
    int* buffer2 = my_realloc(buffer, ARRAY_SIZE);
    if (!buffer2) return 1;
    for (size_t y = 0; y < 2* ARRAY_SIZE; y++) {
        printf("new %d ", buffer2[y]);
    }
    free(buffer2);
    printf("\nDone!\n");
	return 0;
}

#include<stdio.h>

// ### 0.3 Pointer auf verschiedene Typen

// **Aufgabe:**  
// Lege je einen int, float, char an und gib jeweils:

// - Wert
// - Adresse
// - Größe (sizeof)

// aus.

// **Lernpunkt:**  
// Pointer + sizeof + unterschiedliche Typgrößen.

int main() {
    int mint = 3;
    float mfloat = 3.0;
    char mchar = 'a';
    printf("Int %d\n", mint);
    printf("Float %f\n", mfloat);
    printf("Char %c\n", mchar);


    printf("Address Int %p\n", &mint);
    printf("Address Float %p\n", &mfloat);
    printf("Address Char %p\n", &mchar);

    printf("Size of Int %lu\n", sizeof(mint));
    printf("Size of Float %lu\n", sizeof(mfloat));
    printf("Size of Char %lu\n", sizeof(mchar));

    return 0;
}
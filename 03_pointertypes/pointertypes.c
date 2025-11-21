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
    // int mint = 3;
    // float mfloat = 3.0;
    char mterm = '\0';
    char mchar3 = 'c';
    char mchar2 = 'b';
    char mchar = 'a';

    char* a = &mchar2;

    printf("Als char: %c\n", mchar2);
    printf("Als int:  %d\n", &mchar2);
    printf("Als hex:  0x%x\n", mchar2);
    printf("Adresse:  %p\n", &mchar2);
    printf("Wert an Adresse: %d\n", *(&mchar2));
    printf("Wert an Adresse: %d\n", a);
    // printf("Int %d\n", mint);
    // printf("Float %f\n", mfloat);
    // printf("Char %c\n", mchar);


    // printf("Address a %p\n", &mchar);
    // printf("Address b %p\n", &mchar2);
    // printf("Address c %p\n", &mchar3);
    // printf("Address term %p\n", &mterm);
    // printf("String test: %s\n", &mchar); // <--- sollte doch "abc" printen

    // printf("Size of Int %lu\n", sizeof(mint));
    // printf("Size of Float %lu\n", sizeof(mfloat));
    // printf("Size of Char %lu\n", sizeof(mchar));

    return 0;
}
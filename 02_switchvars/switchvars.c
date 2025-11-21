#include<stdio.h>

// ### 0.2 Zwei Variablen tauschen (Swap)

// **Aufgabe:**  
// Schreibe eine `swap(int* a, int* b)` Funktion.  
// Teste sie.

// **Lernpunkt:**  
// Pointer als Funktionsargumente verstehen.
void swap(int* a, int* b) {
    printf("Param 1: %d, param 2: %d\n", *a, *b);
    int x = *a;
    *a = *b;
    *b = x;
}

int main() {
    int x = 4;
    int y = 8;
    printf("Var X: %d, Var Y: %d\n", x, y);
    swap(&x,&y);
    printf("Var X: %d, Var Y: %d\n", x, y);

    return 0;
}
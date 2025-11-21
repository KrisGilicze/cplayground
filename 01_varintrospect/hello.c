#include<stdio.h>

// **Aufgabe: 0.1**  
// Schreibe ein Programm, das:

// - eine int-Variable anlegt
// - ihren Wert ausgibt
// - ihre Adresse (&x) ausgibt
// - einen Pointer auf sie zeigt (`int* p = &x`)
// - über den Pointer den Wert verändert

// **Lernpunkt:**  
// `&`, `*`, Dereferenzieren, Adressen.

int main() {
    int x = 17;
    
    int* p = &x;
	printf("my int x: %d\n", x);
    printf("int x address: %p\n", &x);

    *p = 16;
	printf("my int x: %d\n", x);
    printf("int x address: %p\n", &x);
    return 0;
}

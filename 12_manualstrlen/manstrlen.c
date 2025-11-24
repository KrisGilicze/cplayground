#include<stdio.h>
#include<string.h>

// ### 1.2 Manuelle strlen-Funktion

// **Aufgabe:**  
// Implementiere `size_t my_strlen(char* s)` ohne Array-Indexing, nur mit Pointer-Arithmetik.

// **Lernpunkt:**  
// Zeichenketten sind Pointer auf Null-terminierte Bereiche.


size_t my_strlen(char* str) {
    int counter = 0;
    while (1) {
        if (*str == '\0') {
            return counter;
        }
        if (counter == 100) {
            // safety net
            return counter;
        }
        counter++;
        str++;
    }
    return 5;
}

int main() {
    char* greeting = "Hello!";
    size_t sLen = strlen(greeting);
    size_t mLen = my_strlen(greeting);
	printf("%s\n", greeting);
	printf("Size of greeting: %zu\n", sLen);
	printf("greeting[0]: %c\n", *(greeting+6));
    printf("Bool: %d\n", 1 == 1);
	printf("Size of my_greet: %zu\n", mLen);
	return 0;
}

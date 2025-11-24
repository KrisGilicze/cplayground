#include<stdio.h>

// ### 1.3 Pointer auf Pointer

// **Aufgabe:**
// ```c
// void to_uppercase(char** s_ptr);
// ```
// Die Funktion soll den String, auf den `*s_ptr` zeigt, in GROSSBUCHSTABEN umwandeln.

void to_uppercase(char** s_ptr) {
    int offset = 32; // taken from ASCII table
    char* my_s = *s_ptr;
    printf("%s\n", my_s);
    while (*my_s != '\0') {
        // check if small letter
        if (*my_s >= 97 && *my_s<=122) {
            printf("%c\n", *my_s-offset);
            *my_s = (char)(*my_s-offset);
        } else {
            printf("%c\n", *my_s);

        }
        my_s++;
    }
}

int main() {
    // char* greeting = "HellO"; <-- !!! string literals are read-only
    char greeting[20] = "HellO";
    char* p_greeting = greeting;
    char** pp_greeting = &p_greeting;
	printf("%s\n", greeting);

    to_uppercase(pp_greeting);
	printf("%s\n", greeting);
	return 0;
}

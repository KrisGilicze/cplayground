#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ### 2.3 dyn. String duplicator

// **Aufgabe:**  
// Schreibe `char* my_strdup(const char* original)`.  
// Wie strdup, aber alles selbst.

// **Lernpunkte:**  
// Stringlänge bestimmen, Speicher allokieren, kopieren.

char* my_strdup(const char* original) {
    if (!original) return NULL;
    size_t size = 0;
    size_t i = 0;

    // get size of input string
    while (original[i] != '\0') {
        size++;
        i++;
    }
    char* buffer = malloc((size+1) * sizeof *buffer);

    // error check for mem alloc
    if (!buffer) {
        fprintf(stderr, "Error: nicht genügen Speicher\n");
        return NULL;
    }

    // copy string to buffer
    for (size_t j = 0; j<size; j++) {
        *(buffer + j) = *(original + j);
    }
    *(buffer + size) = '\0'; // null-terminate the copied string
    return buffer;

    // alternative solution with pointer arithmetic
    // while ((*d++ = *s++) != '\0')
}

int main() {
    char* greeting = "Hi there! How are you doing? Ready for real C Challenges?";
    char greeting2[] = "Maus56789";
	printf("%s\n", greeting);

    char* cpstr = my_strdup(greeting);
    if (!cpstr) return 1;
	printf("%s\n", cpstr);

    // Bonus: check if sizeof works as expected before decay
    printf("Size of copied string: %zu\n", strlen(greeting2));
    printf("Size of greeting2 string: %zu\n", sizeof(greeting2));

    // free allocated memory
    free(cpstr);

	return 0;
}

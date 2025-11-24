#include<stdio.h>

// ### 1.1 Mini-Array-Debugger

// **Aufgabe:**  
// Lege ein statisches Array an:
// ```c
// int nums[5] = {1,2,3,4,5};
// ```
// Schreib eine Funktion, die:

// - den Pointer `p = nums` nimmt
// - nacheinander alle Elemente nur mit `p` und `p++` ausgibt

// **Lernpunkt:**  
// Array <-> Pointer Äquivalenz, Pointer-inkrementierung.

#define SIZE 5

void printArray(int* ptr, int* numsArray, int sizeOfArray) {
    printf("sizeof in function: %lu\n", sizeof(numsArray));

    int* start = ptr;

    // for (int i = 0; i<sizeOfArray; i++) {
    //     printf("%d th element: %d\n", i, *ptr);
    //     ++ptr;
    // }

    while (ptr < start + sizeOfArray) {
        printf("%d th element: %d\n", ptr-start, *ptr);
        ++ptr;
    }
}

int main() {
    int nums[SIZE] = {4, 2, 3, 4, 5};
    int* p = nums;

    printArray(p, nums, SIZE);

	return 0;
}

#include<stdio.h>
#include<stdlib.h>

// ## Stufe 3 — Kleine Micro-Projekte (je 1–2 h)

// Jetzt echte Mini-Tools, die C-Kernelmechanik spürbar machen.

// ### 3.1 Mini-Vector (wie std::vector light)

// **Aufgabe:**  
// Struktur Vector mit:

// - `int* data`
// - `int capacity`
// - `int length`

// Funktionen:

// - `init_vector()`
// - `push_back()`
// - `free_vector()`

// **Lernpunkte:**  
// wachsende Buffers, Ownership, Realloc.

#define INITIAL_CAPACITY 10

struct Vector {
    int* data;
    size_t capacity;
    size_t length;
};

struct Vector init_vector () {
    size_t v_capacity = INITIAL_CAPACITY;
    int* v_data = malloc(v_capacity * sizeof(*v_data));
    if (v_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    struct Vector vec;

    vec.data = v_data;
    vec.capacity = v_capacity;
    vec.length = 0;
    
    return vec;
}

void push_back(struct Vector* vec, int element) {
    if (vec->capacity <= vec->length) {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(*(vec->data)));
        if (vec->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(1);
        }
    }
    (*vec).data[vec->length] = element;
    vec->length += 1;
}

void free_vector(struct Vector* vec) {
    free(vec->data);
    vec->data = NULL;
    vec->capacity = 0;
    vec->length = 0;
};


int main () {
    struct Vector my_vec = init_vector();
    push_back(&my_vec, 17);
    push_back(&my_vec, 38);
    push_back(&my_vec, 58);
    push_back(&my_vec, 18);
    push_back(&my_vec, 37);
    push_back(&my_vec, 34);
    push_back(&my_vec, 33);
    push_back(&my_vec, 32);
    push_back(&my_vec, 39);
    push_back(&my_vec, 34);
    push_back(&my_vec, 37);
    push_back(&my_vec, 30);
	printf("Vector: %d\n", my_vec.data[my_vec.length - 3]);
    free_vector(&my_vec);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo* sig; // Puntero al siguiente nodo
} Nodo;

void recorrido(Nodo* head);

int main() {
    Nodo N1 = {5, NULL};
    Nodo N2 = {4, NULL};
    Nodo* head;
    head = (Nodo*)malloc(sizeof(Nodo));
    if (head == NULL) {
        // OCURRIO UN ERROR
    }
    head->sig = &N1;

    Nodo* N3 = malloc(sizeof(Nodo));
    N3->sig = NULL;

    // Conectar el N1 con el N2
    N1.sig = &N2;
    // Conectar el N2 con el N3
    N2.sig = N3;

    N3->dato = 4;

    recorrido(head);

    free(N3);

    return 0;
}


void recorrido(Nodo* head) {
    Nodo* aux = head->sig;

    while(aux != NULL) {
        printf("Info: %d, Dir: %p\n", aux->dato, aux->sig);
        aux = aux->sig;
    }
    
    printf("Terminó el ciclo while");
}
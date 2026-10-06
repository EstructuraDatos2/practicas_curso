#include <stdio.h>
#include <stdlib.h>

// Definir la estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* ant;
    struct Nodo* sig;
} Nodo;

// PROTOTIPOS
Nodo* crearNodo(int dato);
void append(Nodo** head, Nodo** tail, int dato);
void recorrido(Nodo** head);

int main() {
    Nodo* head = NULL;
    Nodo* tail = NULL;

    append(&head, &tail, 10);
    append(&head, &tail, 40);
    append(&head, &tail, 30);
    append(&head, &tail, 50);
    append(&head, &tail, 20);

    return 0;
}

Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));

    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;

    return nuevoNodo;
}

/**
 *
 * @brief Función para insertar Nodos al final de la lista
 * @param head Referencia al primer elemento de la lista
 * @param tail Referencia al ultimo elemento de la lista
 *
 */
void append(Nodo** head, Nodo** tail, int dato) {
    // Creamos un nuevo nodo
    Nodo* nuevo = crearNodo(dato);

    // Verificamos si la lista esta vacia
    if (head == NULL && tail == NULL) {
        *head = nuevo;
        *tail = nuevo;
        return; 
    }

    // Si no es el primer elemento insertamos al final
    (*tail)->sig = nuevo;
    nuevo->ant = *tail;
    *tail = nuevo;
}

void recorrido(Nodo** head) {
    printf("Recorrido hacia delante:\n");
    Nodo* aux = *head;

    while(aux != NULL) {
        printf("%d -> ", aux->dato);
        aux = aux->sig;
    }
    
    printf("NULL\n");
}
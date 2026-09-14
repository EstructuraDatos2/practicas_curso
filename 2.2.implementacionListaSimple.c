#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* sig;
}Nodo;

Nodo* getLastElement(Nodo* head);
void printList(Nodo* head);
void append(int dato, Nodo** head);

int main() {
    // 0. Puntero al primer elemento
    Nodo* head = NULL;
    
    int dato;
    // 3. Leer el nuevo dato
    printf("Ingrese el nuevo dato en la lista: ");
    scanf("%d", &dato);

    append(dato, &head);
    append(20, &head);
    append(30, &head);
    append(40, &head);
    append(50, &head);

    printList(head);

    return 0;
}

void append(int dato, Nodo** head) {
    // 1. Crear un nuevo nodo
    Nodo* nuevo = NULL;
    // 2. Le asignamos memoria
    nuevo = (Nodo*) malloc(sizeof(Nodo)); // ! Aqui reservamos memoria pero falta algo importante

    if(nuevo == NULL) {
        printf("ERROR: No se pudo agregar el nodo");
        return;
    }

    nuevo->dato = dato;
    nuevo->sig = NULL;

    // Insertar en la lista
    if(*head == NULL) {
        // Si la lista esta vacia solo actualizamos head
        *head = nuevo;
    } else {
        // Si la lista no esta vacía
        // * Dame el ultimo elemento de la lista
        Nodo* lastElement = getLastElement(*head);
        lastElement->sig = nuevo;
    }
}

Nodo* getLastElement(Nodo* head) {
    Nodo* aux = head;

    while(aux->sig != NULL) {
        aux = aux->sig;
    }

    return aux;
}

void printList(Nodo* head) {
    Nodo* aux = head;

    while(aux != NULL) {
        printf("%d -> ", aux->dato);
        aux = aux->sig;
    }
    printf("NULL\n");
}
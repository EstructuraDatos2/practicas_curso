#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* sig;
    struct Nodo* ant;
} Nodo;

typedef struct Lista {
    int longitud;
    Nodo* head;
    Nodo* tail;
} Lista;

// PROTOTIPOS
void append(Lista* circular, int dato);
Nodo* crearNodo(int dato);
void recorrido(Lista circular);
void recorridoInverso(Lista circular);

int main() {
    Lista doblementeCircular = {0, NULL, NULL};
    
    append(&doblementeCircular, 10);
    append(&doblementeCircular, 20); 
    append(&doblementeCircular, 30);
    append(&doblementeCircular, 40);
    append(&doblementeCircular, 50);

    recorrido(doblementeCircular);
    recorridoInverso(doblementeCircular);

    return 0;
}

/**
 * @brief Función para insertar nodos al inicio de la lista
 * 
 * @param circular Referencia a la estructura de Lista
 * @param dato Dato numerico que será la información del nodo
 */
void append(Lista* circular, int dato) {
    // 0. Crear el nodo
    Nodo* nuevo = crearNodo(dato);

    // 1. Verificar si la lista esta vacia
    if (circular->head == NULL) {
        // Si esta vacia? Igualar head y tail al nuevo nodo
        circular->head = nuevo;
        circular->tail = nuevo;

        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
        // return;
    } else {
        // Si no está vacia?
        nuevo->ant = circular->tail;
        nuevo->sig = circular->head;
    
        circular->tail->sig = nuevo;
        circular->head->ant = nuevo;

        circular->tail = nuevo;
    }
    circular->longitud++;
}

Nodo* crearNodo(int dato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    
    if(nuevo == NULL) {
        printf("No se pudo crear correctamente el nodo para %d\n", 10);
        return NULL;
    }

    nuevo->dato = dato;
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    return nuevo;
}

void recorrido(Lista circular) {
    printf("Recorrido de INICIO a FIN\n");
    Nodo* aux = circular.head;

    do {
        printf("%d -> ", aux->dato);
        aux = aux->sig;
    } while (aux != circular.head);
    printf("NULL\n");
}

void recorridoInverso(Lista circular) {
    printf("Recorrido de FIN a INICIO\n");
    Nodo* aux = circular.tail;

    do {
        printf("%d -> ", aux->dato);
        aux = aux->ant;
    } while (aux != circular.tail);
    printf("NULL\n");
}

void recorridoCiclos(Lista circular, int numCiclos) {
    numCiclos = 3;
    // 10,20,30,40,50,10,20,30,40,50,10,20,30,40,50
}
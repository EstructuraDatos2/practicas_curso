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
void preappend(Nodo** head, Nodo** tail, int dato);
void recorrido(Nodo** head);
void recorridoInverso(Nodo** tail);
void recorridoIdaVuelta(Nodo** head, Nodo** tail);

int main() {
    Nodo* head = NULL;
    Nodo* tail = NULL;

    append(&head, &tail, 10);
    append(&head, &tail, 40);
    append(&head, &tail, 30);
    append(&head, &tail, 50);
    append(&head, &tail, 20);
    preappend(&head, &tail, 90);

    recorrido(&head);
    recorridoInverso(&tail);
    recorridoIdaVuelta(&head, &tail);

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
    if (*head == NULL && *tail == NULL) {
        *head = nuevo;
        *tail = nuevo;
        return; 
    }

    // Si no es el primer elemento insertamos al final
    (*tail)->sig = nuevo;
    nuevo->ant = *tail;
    *tail = nuevo;
}

void preappend(Nodo** head, Nodo** tail, int dato) {
    // Creamos un nuevo nodo
    Nodo* nuevo = crearNodo(dato);

    // Verificamos si la lista esta vacia
    if (*head == NULL && *tail == NULL) {
        *head = nuevo;
        *tail = nuevo;
        return; 
    }

    // Si no es el primer elemento insertamos al final
    (*head)->ant = nuevo;
    nuevo->sig = *head;
    *head = nuevo;
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

void recorridoInverso(Nodo** tail) {
    printf("Recorrido hacia atrás:\n");
    Nodo* aux = *tail;

    while(aux != NULL) {
        printf("%d -> ", aux->dato);
        aux = aux->ant;
    }
    
    printf("NULL\n");
}

void recorridoIdaVuelta(Nodo** head, Nodo** tail) {
    printf("Recorrido de ida y vuelta.\n");
    Nodo* aux = *head;
    int llegoAlFinal = 0;

    // Recorrido hacia delante
    while(aux != NULL) {
        printf("%d -> ", aux->dato);
        if (!llegoAlFinal) {
          aux = aux->sig; 
        } else {
          aux = aux->ant;
        }
        // aux = !llegoAlFinal ? aux->sig : aux->ant;
        
        if (aux->sig == NULL) {
            // Me doy la vuelta
            llegoAlFinal = 1;
        }
    }

    printf("NULL\n");
    // 90->10->40->30->50->20->50->30->40->10->90->NULL
}
#include <stdio.h>
#include <stdlib.h>

// Estructura de nodos para el arbol
typedef struct Nodo {
  int dato;
  struct Nodo *izq;
  struct Nodo *der;
  int esHoja;
} Nodo;

// PROTOTIPOS
Nodo* insertarNodo(Nodo* raiz, int dato);
Nodo* buscarNodo(Nodo* raiz, int nodoBuscado);

int main() {
    Nodo* raiz = NULL;

    raiz = insertarNodo(raiz, 20);
    raiz = insertarNodo(raiz, 5);
    raiz = insertarNodo(raiz, 10);
    raiz = insertarNodo(raiz, 15);
    raiz = insertarNodo(raiz, 35);
    raiz = insertarNodo(raiz, 50);
    raiz = insertarNodo(raiz, 8);

    Nodo* Nodo35 = buscarNodo(raiz, 35);
    Nodo* Nodo32 = buscarNodo(raiz, 32);
    Nodo* Nodo20 = buscarNodo(raiz, 20);

    return 0;
}

Nodo* insertarNodo(Nodo* raiz, int dato) {
    // PASO 1 Verificar si el arbol esta vacio
    if (raiz == NULL) {
        Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
        nuevoNodo->dato = dato;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        nuevoNodo->esHoja = 1;
        
        return nuevoNodo;
    }

    // PASO 2 Verificar si el nuevo valor es menor (Se inserta a la izquierda
    if (dato < raiz->dato) {
        raiz->izq = insertarNodo(raiz->izq, dato);
    }
    // PASO 3 Verificar si el nuevo valor es mayor (Se inserta a la derecha)
    else if(dato > raiz->dato) {
        raiz->der = insertarNodo(raiz->der, dato);
    }
    raiz->esHoja = 0;
      
    // PASO 4 Cuando se llega a una posición vacia se crea el nuevo nodo
    // PASO 5 Si el valor ya existe no se inserta un duplicado
    return raiz;
}

Nodo* buscarNodo(Nodo* raiz, int nodoBuscado) {
    // PASO 1 Verificar si el arbol esta vacio
    if (raiz == NULL) {
        printf("No se encontró el nodo buscado\n");
        return NULL;
    }

    // PASO 2 Si el nodo raiz es igual al buscado
    if (raiz->dato == nodoBuscado) {
        printf("Nodo encontrado: %d\n", nodoBuscado);
        return raiz;
    }

    // PASO 3 Si es menor continuamos al subarbol izquierdo
    if (nodoBuscado < raiz->dato) {
        return buscarNodo(raiz->izq, nodoBuscado);
    }
    // PASO 4 Si es menor continuamos al subarbol derecho
    else {
        return buscarNodo(raiz->der, nodoBuscado);
    }
}
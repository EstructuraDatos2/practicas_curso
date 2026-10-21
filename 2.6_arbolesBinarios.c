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

int main() {
    Nodo* raiz = NULL;

    raiz = insertarNodo(raiz, 20);
    raiz = insertarNodo(raiz, 5);
    raiz = insertarNodo(raiz, 10);
    raiz = insertarNodo(raiz, 15);
    raiz = insertarNodo(raiz, 35);
    raiz = insertarNodo(raiz, 50);

    return 0;
}

Nodo* insertarNodo(Nodo* raiz, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    nuevoNodo->esHoja = 1;

    // PASO 1 Verificar si el arbol esta vacio
    if (raiz == NULL) {
        return nuevoNodo;
    }
    
    // EL DATO ES UN DUPLICADO
    // if (raiz->dato == dato)

    // PASO 2 Verificar si el nuevo valor es menor (Se inserta a la izquierda
    if (dato < raiz->dato) {
        
    }
    // PASO 3 Verificar si el nuevo valor es mayor (Se inserta a la derecha)
    else {

    }
    // PASO 4 Cuando se llega a una posición vacia se crea el nuevo nodo

    // PASO 5 Si el valor ya existe no se inserta un duplicado
    return NULL;
}
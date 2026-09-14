#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Objeto {
    char nombre[20];
    int ordenEncontrado;
    struct Objeto *sig;
} Objeto;
int id = 0;

Objeto* crearObjeto(char nombre[]);
void append(Objeto* *head, char nombre[]);
void recorrido(Objeto* *head);

int main() {
    // Puntero a la cabeza de la lista enlazada
    Objeto* head = NULL;
    char nombre[20];
    while (1) {
        // Leemos por teclado el nombre del objeto
        printf("Encontraste un objeto!!!, escribe el nombre: \n");
        scanf("%s", nombre);
        if(strcmp(nombre, "0") == 0) break;
        append(&head, nombre);
    }

    // ENTREGAR CONTRIBUCIONES "VOLUNTARIAS"
    entregarContribuciones();

    return 0;
}


Objeto* crearObjeto(char nombre[]) {
    // Creamos el puntero al "Nodo" y reservamos memoria 
    Objeto* nuevoObjeto;
    nuevoObjeto = (Objeto*)malloc(sizeof(Objeto));

    // Asignamos los datos del objeto
    strcpy(nuevoObjeto->nombre, nombre);
    nuevoObjeto->ordenEncontrado = ++id;
    nuevoObjeto->sig = NULL;

    // Devolvemos la referencia al objeto creado
    return nuevoObjeto;
}

/**
 * @brief Función para insertar nodos al final de la lista
 * 
 * @param head Referencia al primer elemento de la lista
 * @return Objeto* Devuelve 
 */
void append(Objeto** head, char nombre[]) {
    // 1. Necesito verificar la lista (esta vacia? hay elementos? cual es el ultimo elemento?)
    if (*head == NULL) {
        *head = crearObjeto(nombre);
        return;
    }

    // 1.1 Buscamos el final de la lista
    Objeto* final = *head;
    while(final->sig != NULL) {
        final = final->sig;
    }

    // 2. Necesito crear el elemento con los datos dados por el usuario (usaremos la función que ya tenemos)
    Objeto* nuevoObjeto = crearObjeto(nombre);
    final->sig = nuevoObjeto;
    recorrido(head);
}


void recorrido(Objeto** head) {
    Objeto* aux = *head;

    while(aux != NULL) {
        printf("%s -> ", aux->nombre);
        aux = aux->sig;
    }
    printf("NULL\n");
    system("pause");
    system("cls");
}
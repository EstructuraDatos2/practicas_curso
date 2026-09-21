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
void append(Objeto** head, char nombre[]);
void recorrido(Objeto** head);
void entregarContribuciones(Objeto* head);
void eliminarObjeto(Objeto** head, int id);
void liberarLista(Objeto** head);

int main() {
    // Puntero a la cabeza de la lista enlazada
    Objeto* head = NULL;
    char nombre[50];

    // Ciclo infinito que lee el nombre de nuevos objetos
    while (1) {
        // Leemos por teclado el nombre del objeto
        printf("Encontraste un objeto!!!, escribe el nombre: \n");
        if(fgets(nombre, sizeof(nombre), stdin) == NULL) break;

        // fgets guarda el '\n' final; lo eliminamos
        nombre[strcspn(nombre, "\n")] = '\0';
        
        // El ciclo termina si el usuario escribre solo '0'
        if(strcmp(nombre, "0") == 0) break;
        
        append(&head, nombre);
    }

    // ENTREGAR CONTRIBUCIONES "VOLUNTARIAS"
    // - 1 Moneda
    append(&head, "Moneda");
    // - 2 Casco
    append(&head, "Casco");
    // - 3 Llave    ###
    append(&head, "Llave");
    // - 4 Arco
    append(&head, "Arco");
    // - 5 Lanza
    append(&head, "Lanza");
    // - 6 Copa     ###
    append(&head, "Copa");
    // - 7 Varita
    append(&head, "Varita");
    // - 8 Laptop
    append(&head, "Laptop");
    // - 9 Brújula  ###
    append(&head, "Brujula");
    // - 10 Gorro mágico
    system("cls");
    append(&head, "Gorro Magico");
    entregarContribuciones(head);

    liberarLista(&head);

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
    printf("Lista enlazada completa:\n");
    Objeto* aux = *head;

    while(aux != NULL) {
        printf("%s -> ", aux->nombre);
        aux = aux->sig;
    }
    printf("NULL\n");
    // system("pause");
    // system("cls");
}

void entregarContribuciones(Objeto* head) {
    printf("\nObjetos que amablemente voy a entregar al SAT: \n");
    Objeto* aux = head;
    int contador = 1;
    while(aux != NULL) {
        if (contador % 3 == 0) {
            printf("%d.- ", contador);
            printf("%s\n", aux->nombre);
            // ELIMINAR OBJETO DE LA LISTA
            eliminarObjeto(&head, id);
        }

        aux = aux->sig;
        contador++;
    }
}

void eliminarObjeto(Objeto** head, int id) {
    // Asumimos que los id son únicos y no se repiten
    Objeto* ant = *head;
    Objeto* aux = ant->sig;

    if(ant->ordenEncontrado == id) {
        // CASO 1: Eliminacion del primer elemento de la lista
        *head = aux;
        free(ant);
    } else {
        // CASO 2: Eliminacion al medio o final
        do {
            if (aux->ordenEncontrado == id) {
                ant->sig = aux->sig;
            } else {
                ant = aux;
                aux = aux->sig;
            }
        } while(aux->ordenEncontrado != id);
        free(aux);
    }
}

void liberarLista(Objeto** head) {
    Objeto *act = *head;
    Objeto *aux = NULL;

    // Liberamos la referencia de la cabeza
    *head = NULL;

    while(act != NULL) {
        aux = act->sig;
        free(act);
        act = aux;
    }
}
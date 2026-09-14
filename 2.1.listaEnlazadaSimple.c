#include <stdio.h>
#include <stdlib.h>

typedef struct Enemigo{
    int id;
    int x;
    int y;
    int vida;
    struct Enemigo *siguiente;
} Enemigo;

void recorrido(Enemigo *head);

int main() {
    Enemigo *cabeza = NULL;
    Enemigo *enemigo1 = NULL;
    Enemigo *enemigo2 = NULL;
    Enemigo *enemigo3 = NULL;


    // Escribe el código necesario para completar:
    // 1. Reservar memoria para los 3 enemigos
    enemigo1 = malloc(sizeof(Enemigo));
    enemigo2 = malloc(sizeof(Enemigo));
    enemigo3 = malloc(sizeof(Enemigo));
    // 2. Asignales un id aleatorio
    enemigo1->id = 1;
    enemigo2->id = 2;
    enemigo3->id = 3;
    // 3. Hacer que cabeza apunte a enemigo1
    cabeza = enemigo1;
    // 4. Conecta enemigo1 con enemigo2
    enemigo1->siguiente = enemigo2;
    // 5. Conecta enemigo2 con enemigo3
    enemigo2->siguiente = enemigo3;
    // 6. Hacer que enemigo3 apunte a NULL
    enemigo3->siguiente = NULL;
    
    recorrido(cabeza);

    return 0;
}

void recorrido(Enemigo* head) {
    Enemigo* aux = head;

    while(aux != NULL) {
        printf("ID: %d, SIG: %p\n", aux->id, aux->siguiente);
        aux = aux->siguiente;
    }
}
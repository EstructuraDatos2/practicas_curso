#include <stdio.h>

int main() {
    int* puntero;
    int variable = 20;
    puntero = &variable; // Con '&' accedo a la dirección de memoria

    printf("Valor del puntero: %p\n", puntero);
    printf("Dirección de memoria del puntero: %p\n", &puntero);
    *puntero = 10;

    printf("%d\n", variable);

    typedef struct{
        double y;
        int x;
    } Punto;

    Punto caso1 = {5, 3.3};

    printf("Valor en X: %d\n", caso1.x);
    printf("Valor en Y: %f\n", caso1.y);

    Punto* apuntador = &caso1;
    
    printf("Valor en X: %d\n", apuntador->x);
    printf("Valor en Y: %f\n", (*apuntador).y);

    int* punt;
    printf("%d\n", *punt);

    return 0;
}
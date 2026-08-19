#include <stdio.h>

int main() {
    int* puntero;
    int variable = 20;
    puntero = &variable; // Con '&' accedo a la dirección de memoria

    printf("Valor del puntero: %p\n", puntero);
    printf("Dirección de memoria del puntero: %p\n", &puntero);
    *puntero = 10;

    printf("%d\n", variable);
    return 0;
}
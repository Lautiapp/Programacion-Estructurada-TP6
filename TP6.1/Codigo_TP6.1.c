#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int vector[50];
    int i;
    int suma = 0;
    int producto = 1;

    for (i = 0; i < 50; i++) {
        printf("\nIngrese un elemento del vector: ");
        scanf("%d", &vector[i]);
        suma += vector[i];
        producto *= vector[i];
    }

    for (i = 49; i >= 0; i--) {
        printf("El elemento numero %d del vector es: %d\n", i + 1, vector[i]);
    }

    printf("La suma de todos los elementos del vector es: %d\n", suma);
    printf("El producto de todos los elementos del vector es: %d\n", producto);
    
    printf("Los componentes de indice par son: \n");

    for (i=0; i < 50; i++){
        if (i % 2 == 0) {
            printf("%d\n", vector[i]);
        }
    }

    printf("Los componentes de indice impar son: \n");

    for (i=0; i < 50; i++){
        if (i % 2 != 0) {
            printf("%d\n", vector[i]);
        }
    }

    
    return 0;
}
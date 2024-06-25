#include <stdio.h> 
#include <stdlib.h>

#define MAX_NOMBRE 20

int main(int argc, char *argv[]) {
    
    char* nombre_empleado[50];
    float sueldo_empleado[50];
    int i, categoria, antiguedad;
    int cant_cat1 = 0;
    int cant_cat2 = 0;
    int cant_cat3 = 0;
    float total_sueldos = 0.0;
    float total_sueldos_cat1 = 0.0;
    float total_sueldos_cat2 = 0.0;
    float total_sueldos_cat3 = 0.0;
    int sueldo_maximo = 0;

    for (i = 0; i < 50; i++){
        nombre_empleado[i] = (char *)malloc(MAX_NOMBRE * sizeof(char));
        
        printf("\nIngrese el nombre del empleado: ");
        scanf("%s", nombre_empleado[i]);
        
        while (getchar() != '\n');
        
        do {
            printf("\nIngrese la categoria del empleado (1 - 2 - 3): ");
            scanf("%d", &categoria);
            if (categoria < 1 || categoria > 3){
                printf("La categoria ingresada no existe. Intente nuevamente\n\n");
            }
        } while (categoria < 1 || categoria > 3);

        do {
            printf("\nIngrese la antiguedad en años del empleado: ");
            scanf("%d", &antiguedad);
            if (antiguedad < 0 || antiguedad > 50) {
                printf("La antigueadad no puede ser menor a cero o mayor a 50. Intente nuevamente\n\n");
            }
        } while (antiguedad < 0 || antiguedad > 50);


        sueldo_empleado[i] = antiguedad * 100.0;

        switch (categoria) {
        case 1:
            cant_cat1++;
            sueldo_empleado[i] += 1500.0;
            total_sueldos_cat1 += sueldo_empleado[i];
            break;
        case 2:
            cant_cat2++;
            sueldo_empleado[i] += 2000.0;
            total_sueldos_cat2 += sueldo_empleado[i];
            break;
        case 3:
            cant_cat3++;
            sueldo_empleado[i] += 2500.0;
            total_sueldos_cat3 += sueldo_empleado[i];
            break;
        }

        total_sueldos += sueldo_empleado[i];


        if (i == 0 || sueldo_empleado[i] > sueldo_empleado[sueldo_maximo]) {
            sueldo_maximo = i;
        }
        
        while (getchar() != '\n');

    }

    printf("\nHay %d empleados de Categoria 1\nHay %d empleados de Categoria 2\nHay %d empleados de Categoria 3\n", cant_cat1, cant_cat2, cant_cat3);

    printf("El total de sueldos de la Categoria 1 es: $%.1f\nEl total de sueldos de la Categoria 2 es: $%.1f\nEl total de sueldos de la Categoria 3 es: $%.1f\n", total_sueldos_cat1, total_sueldos_cat2, total_sueldos_cat3);

    float promedio_sueldos = total_sueldos / 50.0;

    printf("El sueldo promedio general es de: $%.2f\n", promedio_sueldos);

    printf("El sueldo maximo es de: $%.1f y le pertenece a %s\n", sueldo_empleado[sueldo_maximo], nombre_empleado[sueldo_maximo]);
    

    float porcentaje_sueldo_cat1 = (total_sueldos_cat1 * 100) / total_sueldos;
    float porcentaje_sueldo_cat2 = (total_sueldos_cat2 * 100) / total_sueldos;
    float porcentaje_sueldo_cat3 = (total_sueldos_cat3 * 100) / total_sueldos;

    printf("El total de sueldos de la Categoria 1 representa el %.2f%% del total\nEl total de sueldos de la Categoria 2 representa el %.2f%% del total\nEl total de sueldos de la Categoria 1 representa el %.2f%% del total\n", porcentaje_sueldo_cat1, porcentaje_sueldo_cat2, porcentaje_sueldo_cat3);
    
    for (i = 0; i < 50; i++) {
        free(nombre_empleado[i]);
    }

    return 0;
}
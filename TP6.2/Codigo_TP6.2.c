#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int sueldos[10];
    int edades[10];
    int i;
    float total_sueldos = 0.0;
    float total_sueldos_gap = 0.0;
    int total_empleados_gap = 0;
    float total_edades = 0.0;
    int condicion1 = 0;
    int condicion2 = 0;

    for (i = 0; i < 10; i++){
        do {
            printf("\n\nIngrese el sueldo del empleado: ");
            scanf("%d", &sueldos[i]);
            if(sueldos[i] <= 0){
                printf("El sueldo no puede ser negativo o igual a cero. Intente nuevamente\n");
            }
        } while (sueldos[i] <= 0);

        do {
            printf("\nIngrese la edad del empleado: ");
            scanf("%d", &edades[i]);
            if(edades[i] < 18 || edades[i] > 100) {
                printf("La edad no puede ser menor a 18 o mayor a 100. Intente nuevamente\n");
            }
        } while (edades[i] < 18 || edades[i] > 100);
        

        total_sueldos += sueldos[i];

        if(edades[i] > 23 && edades[i] < 40){
            total_sueldos_gap += sueldos[i];
            total_empleados_gap++;
        }

        total_edades += edades[i];

        if (edades[i] > 30 && sueldos[i] < 1000){
            condicion1++;
        }
    }

    float sueldo_promedio = total_sueldos / 10.0;

    printf("El promedio de los sueldos es: $%.2f\n", sueldo_promedio);

    float sueldo_promedio_gap = total_sueldos_gap / total_empleados_gap;

    printf("El sueldo promedio de los empleados que tienen entre 23 y 40 años es: $%.2f\n", sueldo_promedio_gap);

    float promedio_edades = total_edades / 10.0;

    printf("El promedio de edad es: %.1f\n", promedio_edades);

    printf("La cantidad de empleados mayores a 30 años y con un sueldo menor a $1000 es: %d\n", condicion1);

    for (i = 0; i < 10; i++){
        if (edades[i] < promedio_edades){
            condicion2++;
        }
    }

    printf("La cantidad de empleados con edades menores al promedio es: %d", condicion2);

    
    return 0;
}
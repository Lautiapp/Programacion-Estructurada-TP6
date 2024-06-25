#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int cantidad_atendida_mozo[6] = {0};
    float facturado_mozo[6] = {0};
    int cantidad_facturas_mesa[12] = {0};
    float monto_facturado_mesa[12] = {0};
    int factura;
    int cantidad_personas;
    int mozo;
    float monto;
    int mesa;
    int cantidad_facturas = 0;
    float caja_diaria = 0.0;
    int i;
    float porcentual;
    int maximo_atendido = 0;
    int mozo_maximo_atendido;
    int facturas_superaron = 0;
    int maximo_facturas = 0;
    int mesa_maximo = 0;

    do{
        do{
            printf("\nIngrese el numero de factura: ");
            scanf("%d", &factura);
            if (factura < 0) {
                printf("El numero de factura no puede ser menor a cero. Intente nuevamente\n");
            }
        } while (factura < 0);

        if (factura != 0) {
            do{
                printf("\nIngrese el numero de mozo (0-5): ");
                scanf("%d", &mozo);
                if(mozo < 0 || mozo > 5){
                    printf("El numero ingresado no es valido. Intente nuevamente\n");
                }
            } while (mozo < 0 || mozo > 5);

            do{
                printf("\nIngrese el numero de mesa (0-11): ");
                scanf("%d", &mesa);
                if(mesa < 0 || mesa > 11){
                    printf("El numero ingresado no es valido. Intente nuevamente\n");
                }
            } while (mesa < 0 || mesa > 11);

            do{
                printf("\nIngrese la cantidad de personas que comieron: ");
                scanf("%d", &cantidad_personas);
                if(cantidad_personas < 1 || cantidad_personas > 30) {
                    printf("La cantidad de personas no puede ser menor a 1 o mayor a 30. Intente nuevamente\n");
                }
            } while(cantidad_personas < 1 || cantidad_personas > 30);

            do{
                printf("\nIngrese el monto de la cuenta: ");
                scanf("%f", &monto);
                if(monto <= 0){
                    printf("El monto no puede ser menor o igual a cero. Intente nuevamente\n");
                }
            } while (monto < 0);

            cantidad_atendida_mozo[mozo] += cantidad_personas;
            cantidad_facturas++;
            caja_diaria += monto;
            monto_facturado_mesa[mesa] += monto;
            facturado_mozo[mozo] += monto;
            cantidad_facturas_mesa[mesa]++;

            if(monto > 45){
                facturas_superaron++;
            }


        }

    } while (factura != 0);

    if (cantidad_facturas > 0) {
        for(i = 0; i < 6; i++) {
            printf("\nLa cantidad de personas atendidas por el mozo numero %d fue de %d\n", i, cantidad_atendida_mozo[i]);
        }
        
        printf("Se realizaron %d facturas\n", cantidad_facturas);

        printf("La caja diaria es de $%.2f", caja_diaria);

        for(i = 0; i < 12; i++){
            printf("El monto facturado por la mesa %d en total es de $%.2f\n", i, monto_facturado_mesa[i]);
        }

        for(i = 0; i < 6; i++) {
            porcentual = (facturado_mozo[i] * 100) / caja_diaria;
            printf("El porcentaje facturado por el mozo numero %d respecto del total es del %.2f%%\n", i, porcentual);
        }

        for(i = 0; i < 6; i++){
            porcentual = facturado_mozo[i] * 0.05;
            printf("Al mozo numero %d le corresponde $%.2f\n", i, porcentual);
        }

        for(i = 0; i < 6; i++){
            if(cantidad_atendida_mozo[i] > maximo_atendido) {
                mozo_maximo_atendido = i;
                maximo_atendido = cantidad_atendida_mozo[i];
            }
        }

        printf("El mozo que mas personas atendio fue el numero %d con %d en total\n", mozo_maximo_atendido, maximo_atendido);

        printf("%d facturas superaron superaron los $45\n", facturas_superaron);

        for(i = 0; i < 12; i ++){
            if(cantidad_facturas_mesa[i] > maximo_facturas) {
                mesa_maximo = i;
                maximo_facturas = cantidad_facturas_mesa[i];
            }
        }
        
        printf("La mesa a la que se le facturo mas veces fue la numero %d, con un total de %d veces\n", mesa_maximo, maximo_facturas);
    }
    else{
        printf("No se cobraron mesas");
    }
    
    return 0;
}
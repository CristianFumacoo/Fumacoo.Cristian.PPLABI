#include <stdio.h>
#include <stdlib.h>
#include "algo.h"
#include "menu.h"

#define AUTOS 10
#define MARCAS 5
#define COLORES 5
#define SERVICIOS 4
#define TRABAJOS 5

int main()
{
    int opc;
    char respuesta = 's';

    int idTrabajo = 1;
    eTrabajo trabajos[TRABAJOS];

    int idMarca = 1000;
    eMarca marca[MARCAS];

    int idColor = 5000;
    eColor color[COLORES];

    int idServicio = 20000;
    eServicio servicio[SERVICIOS];

    int idAuto = 50000;
    eAuto autos[AUTOS];

    harcodeo(marca,color,servicio,autos,trabajos);

    do
    {
        opc = menu();

        switch(opc)
        {
        case 1:
            if(altaAuto(autos,marca,color,AUTOS,MARCAS,COLORES,idAuto))
            {
                printf("El auto se ingreso correctamente.\n");
                idAuto++;
            }
            else
            {
                printf("Hubo un error.\n");
            }
            system("pause");
            break;
        case 2:
            if(modificarAuto(autos,marca,color,AUTOS,COLORES,MARCAS))
            {
                printf("Se modifico correctamente.\n");
            }
            else
            {
                printf("Hubo un error.\n");
            }
            system("pause");
            break;
        case 3:
            if(borrarAuto(autos,marca,color,AUTOS,COLORES,MARCAS))
            {
                printf("Se borro correctamente.\n");
            }
            else
            {
                printf("Hubo un error.\n");
            }
            system("pause");
            break;
        case 4:
            mostrarAutos(autos,marca,color,AUTOS,MARCAS,COLORES);
            system("pause");
            break;
        case 5:
            mostrarColores(color,COLORES);
            system("pause");
            break;
        case 6:
            mostrarMarcas(marca,MARCAS);
            system("pause");
            break;
        case 7:
            mostrarServicios(servicio,SERVICIOS);
            system("pause");
            break;
        case 8:
            altaTrabajo(trabajos,autos,marca,color,servicio,AUTOS,SERVICIOS,MARCAS,COLORES,TRABAJOS,idTrabajo);
            break;
        case 9:
            mostrarTrabajos(trabajos,servicio,TRABAJOS,SERVICIOS);
            system("pause");
            break;
        case 10:
            respuesta = 'n';
            break;
        default:
            printf("Opcion incorrecta.\n");
            system("pause");
            break;
        }
    }
    while(respuesta == 's');
}

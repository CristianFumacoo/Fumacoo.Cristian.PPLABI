#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "algo.h"

void harcodeo(eMarca marcas[],eColor colores[],eServicio servicios[], eAuto autos[],eTrabajo trabajos[])
{
    char marcasH[5][20] = {"Renault", "Fiat", "Ford", "Chevrolet", "Peugeot"};
    int idMarcas[5] = {1,2,3,4,5};
    char coloresH[5][20] = {"Negro", "Blanco", "Gris", "Rojo", "Azul"};
    int idColores[5] = {1,2,3,4,5};
    char servicio[4][20] = {"Lavado","Pulido","Encerado","Completo"};
    int precioServis[4] = {250,300,400,600};
    int idServis[4] = {1,2,3,4};

    int llenoMarcas[5] = {0,0,0,0,0};
    int llenoColores[5] = {0,0,0,0,0};
    int llenoServis[4] = {0,0,0,0};


    for(int i = 0; i < 5; i++)
    {
        strcpy(marcas[i].descripcion,marcasH[i]);
        marcas[i].id = idMarcas[i];
        marcas[i].isEmpty = llenoMarcas[i];

        strcpy(colores[i].nombreColor,coloresH[i]);
        colores[i].id = idColores[i];
        colores[i].isEmpty = llenoColores;

        trabajos[i].isEmpty = 1;
    }

    for(int i = 0; i < 4; i++)
    {
        strcpy(servicios[i].descripcion,servicio[i]);
        servicios[i].precio = precioServis[i];
        servicios[i].id = idServis[i];
        servicios[i].isEmpty = llenoServis[i];
    }

    for(int i = 0; i < 10; i++)
    {
        autos[i].isEmpty = 1;
    }
}

int altaAuto(eAuto autito[],eMarca marcas[],eColor colores[],int tam,int tamColor, int tamMarca,int id)
{
    int retorno = 0;

    for(int i = 0; i<tam; i++)
    {
        if(autito[i].isEmpty == 1)
        {
            printf("ID: %d\n",id);
            autito[i].id = id;

            printf("Ingrese patente: ");
            fflush(stdin);
            scanf("%s",&autito[i].patente);

            mostrarMarcas(marcas,tamMarca);
            printf("Ingrese el ID de la marca de su auto: ");
            scanf("%d",&autito[i].idMarca);

            while(autito[i].idMarca > 5 || autito[i].idMarca < 1)
            {
                printf("Error. Ingrese el ID de la marca de su auto: ");
                scanf("%d",&autito[i].idMarca);
            }

            mostrarColores(colores,tamColor);
            printf("Ingrese el ID del color de su auto: ");
            scanf("%d",&autito[i].idColor);

            while(autito[i].idColor > 5 || autito[i].idColor < 1)
            {
                printf("Error. Ingrese el ID del color de su auto: ");
                scanf("%d",&autito[i].idColor);
            }

            printf("Ingrese el modelo de su auto: ");
            scanf("%d",&autito[i].modelo);


            autito[i].isEmpty = 0;
            retorno = 1;

            break;
        }
    }

    return retorno;
}

int altaTrabajo(eTrabajo trabajos[],eAuto autito[],eMarca marca[],eColor color[],eServicio servicio[], int tamAuto, int tamServicio,int tamMarca,int tamColor,int tamTrabajos,int id)
{
    int retorno = 0;
    int idAutoSelec;
    int idServicioSelec;
    int auxId;

    for(int i = 0; i < tamTrabajos; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            mostrarAutos(autito,marca,color,tamAuto,tamMarca,tamColor);
            printf("Ingrese la patente del auto al que desea brindar un servicio: ");
            scanf("%d",&auxId);

            idAutoSelec = buscarAuto(autito, tamAuto, auxId);

            if(idAutoSelec != -1)
            {
                strcpy(trabajos[i].patente,autito[idAutoSelec].patente);

                mostrarServicios(servicio,tamServicio);
                printf("¿Que servicio le quiere hacer?\n");
                scanf("%d",&trabajos[i].idServicio);
                while(trabajos[i].idServicio > 4 || trabajos[i].idServicio < 1)
                {
                    printf("Error. Ingrese el ID del servicio a hacer: ");
                    scanf("%d",&trabajos[i].idServicio);
                }
                printf("Eligio bien\n");


                trabajos[i].id = id;
                trabajos[i].isEmpty = 0;
                retorno = 1;
                break;
            }
        }
    }

    printf("Llego aca.");
    return retorno;
}


int modificarAuto(eAuto autito[],eMarca marcas[],eColor colores[],int tam,int tamColor, int tamMarca)
{
    int retorno = 0;
    int auxId;
    char respuesta;
    int idAModificar;
    int opc;

    mostrarAutos(autito,marcas,colores,tam,tamColor,tamMarca);

    printf("Ingrese el ID del auto que desea modificar: ");
    scanf("%d",&auxId);

    idAModificar = buscarAuto(autito, tam, auxId);

    if(idAModificar != -1)
    {
        printf("¿Seguro que quiere Modificar a?\n");
        mostrarAuto(autito[idAModificar],marcas[idAModificar],colores[idAModificar]);
        printf("Ingrese 'S' para Modificar o 'N' para cancelar: ");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta == 's')
        {
            switch(menuModificar())
            {
            case 1:
                mostrarColores(colores,tamColor);
                printf("\nIngrese el id de su nuevo color.\n");
                scanf("%d",&autito[idAModificar].idColor);

                while(autito[idAModificar].idColor > 4 || autito[idAModificar].idColor < 1)
                {
                    printf("Error. Ingrese el ID del nuevo color: ");
                    scanf("%d",&autito[idAModificar].idColor);
                }
                retorno = 1;
                break;
            case 2:
                printf("Ingrese su nuevo modelo: ");
                scanf("%d",&autito[idAModificar].modelo);
                break;
                retorno = 1;
            }
        }
    }

    return retorno;
}

int borrarAuto(eAuto autito[],eMarca marcas[],eColor colores[],int tam,int tamColor, int tamMarca)
{
    int retorno = 0;
    int auxId;
    char respuesta;
    int idAModificar;
    int opc;

    mostrarAutos(autito,marcas,colores,tam,tamColor,tamMarca);

    printf("Ingrese el ID del auto que desea Borrar: ");
    scanf("%d",&auxId);

    idAModificar = buscarAuto(autito, tam, auxId);

    if(idAModificar != -1)
    {
        printf("¿Seguro que quiere Borrar a?\n");
        mostrarAuto(autito[idAModificar],marcas[idAModificar],colores[idAModificar]);
        printf("Ingrese 'S' para Borrar o 'N' para cancelar: ");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta == 's')
        {
            autito[idAModificar].isEmpty = 1;
            retorno = 1;
        }
    }

    return retorno;
}

















/*************************** COMIENZO DE LOS MOSTRAR************************************/
void mostrarAuto(eAuto autito,eMarca marcas,eColor color)
{
    if(autito.isEmpty != 1)
    {
        printf("%d%15s%15s%15s%15d\n",autito.id,autito.patente,color.nombreColor,marcas.descripcion,autito.modelo);
    }
}

void mostrarAutos(eAuto autito[],eMarca marcas[],eColor color[],int cant,int cantMarcas,int cantColores)
{
    printf("%s%20s%15s%15s%15s\n\n","ID","PATENTE","COLOR","MARCA","MODELO");

    int idColor;
    int idMarca;

    for(int i = 0; i<cant; i++)
    {
        idColor = buscarColor(color,cantColores,autito[i].idColor);
        idMarca = buscarMarca(marcas,cantMarcas,autito[i].idMarca);

        mostrarAuto(autito[i],marcas[idMarca],color[idColor]);
    }
}


void mostrarMarca(eMarca marca)
{
    if(marca.isEmpty != 1)
    {
        printf("%d%15s\n",marca.id,marca.descripcion);
    }
}

void mostrarMarcas(eMarca marca[],int cant)
{
    printf("%s%15s\n\n","ID","NOMBRE");

    for(int i = 0; i<cant; i++)
    {
        mostrarMarca(marca[i]);
    }
}

void mostrarColor(eColor color)
{
    if(color.isEmpty != 1)
    {
        printf("%d%15s\n",color.id,color.nombreColor);
    }
}

void mostrarColores(eColor color[],int cant)
{
    printf("%s%15s\n\n","ID","COLOR");

    for(int i = 0; i<cant; i++)
    {
        mostrarColor(color[i]);
    }
}
void mostrarServicio(eServicio servicio)
{
    if(servicio.isEmpty != 1)
    {
        printf("%d%15s%15d\n",servicio.id,servicio.descripcion,servicio.precio);
    }
}

void mostrarServicios(eServicio servicios[],int cant)
{
    printf("%s%15s%15s\n\n","ID","TRABAJO","PRECIO");

    for(int i = 0; i<cant; i++)
    {
        mostrarServicio(servicios[i]);
    }
}

void mostrarTrabajo(eTrabajo trabajo,eServicio servicio)
{
    if(trabajo.isEmpty != 1)
    {
        printf("%d%15s%15s\n",trabajo.id,trabajo.patente,servicio.descripcion);
    }
}
void mostrarTrabajos(eTrabajo trabajo[],eServicio servicio[],int cant,int cantServis)
{
    int idServis;
    printf("%s%15s%15s\n\n","ID","PATENTE","SERVICIO");

    for(int i = 0; i<cant; i++)
    {
        idServis = buscarServis(servicio,cantServis,trabajo[i].idServicio);
        mostrarTrabajo(trabajo[i],servicio[idServis]);
    }
}



/*************************** FIN DE LOS MOSTRAR************************************/


/*************************** COMIENZO DE LOS BUSCAR************************************/
int buscarColor(eColor color[],int cant,int idColor)
{
    int retorno = -1;

    for(int i = 0; i < cant; i++)
    {
        if(color[i].id == idColor)
        {
            retorno = i;
        }
    }

    return retorno;
}

int buscarMarca(eMarca marca[],int cant,int idMarca)
{
    int retorno = -1;

    for(int i = 0; i < cant; i++)
    {
        if(marca[i].id == idMarca)
        {
            retorno = i;
        }
    }

    return retorno;
}

int buscarAuto(eAuto autito[],int tam,int id)
{
    int retorno = -1;

    for(int i=0; i<tam; i++)
    {
        if(autito[i].isEmpty != 1)
        {
            if(autito[i].id == id)
            {
                retorno = i;
            }
        }
    }

    return retorno;
}

int buscarServis(eServicio servicio[],int tam,int id)
{
    int retorno = -1;

    for(int i=0; i<tam; i++)
    {
        if(servicio[i].isEmpty != 1)
        {
            if(servicio[i].id == id)
            {
                retorno = i;
            }
        }
    }

    return retorno;
}
/*************************** FIN DE LOS BUSCAR************************************/

















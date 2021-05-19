#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opc;

    system("cls");
    printf("1.Ingresar auto.\n");
    printf("2.Modificar auto.\n");
    printf("3.Borrar auto.\n");
    printf("4.Mostrar Autos.\n");
    printf("5.Mostrar Colores.\n");
    printf("6.Mostrar Marcas.\n");
    printf("7.Mostrar Servicios.\n");
    printf("8.Alta Trabajo.\n");
    printf("9.Mostrar Trabajo.\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&opc);

    return opc;
}

int menuModificar()
{
    int opc;

    system("cls");
    printf("\n¿Que desea modificar?\n");
    printf("1.Color\n");
    printf("2.Modelo\n");
    scanf("%d",&opc);

    return opc;
}







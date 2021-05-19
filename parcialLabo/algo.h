typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int isEmpty;
    char descripcion[20];
}eMarca;

typedef struct
{
    int id;
    int isEmpty;
    char nombreColor[20];
}eColor;

typedef struct
{
    int id;
    int isEmpty;
    char patente[7];
    int idColor;
    int idMarca;
    int modelo;
}eAuto;

typedef struct
{
    int id;
    int isEmpty;
    char descripcion[25];
    char servicio[20];
    int precio;
}eServicio;

typedef struct
{
    int id;
    char patente[7];
    int idServicio;
    int isEmpty;
    eFecha fecha;
}eTrabajo;

void harcodeo(eMarca[],eColor[],eServicio[],eAuto[],eTrabajo[]);

int altaAuto(eAuto[],eMarca[],eColor[],int,int,int,int);
int altaTrabajo(eTrabajo[],eAuto[],eMarca[],eColor[],eServicio[],int,int,int,int,int,int);

int modificarAuto(eAuto[],eMarca[],eColor[],int,int,int);

int borrarAuto(eAuto[],eMarca[],eColor[],int,int,int);

void mostrarAuto(eAuto,eMarca,eColor);
void mostrarAutos(eAuto[],eMarca[],eColor[],int,int,int);

void mostrarMarca(eMarca);
void mostrarMarcas(eMarca[],int);

void mostrarColor(eColor);
void mostrarColores(eColor[],int);

void mostrarServicio(eServicio);
void mostrarServicios(eServicio[], int);

void mostrarTrabajo(eTrabajo,eServicio);
void mostrarTrabajos(eTrabajo[],eServicio[],int,int);

int buscarColor(eColor[],int,int);
int buscarMarca(eMarca[],int,int);
int buscarAuto(eAuto[],int,int);
int buscarServis(eServicio[],int,int);











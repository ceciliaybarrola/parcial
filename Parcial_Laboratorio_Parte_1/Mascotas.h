#define LIBRE 0
#define OCUPADO 1
#include <string.h>
#include "Inputs.h"
typedef struct
{
    int idMascota;
    int idCliente;
    char nombre[100];
    int tipo;
    int raza;
    int edad;
    float peso;
    char sexo;
    int estado;
}eMascota;

typedef struct{
int tipo;
char descripcionTipo[100];
}eTipoMascota;

typedef struct{

int idTipo;
int idRaza;
char nombreRaza[50];
char pais[50];

}eRaza;

void inicializarMascota(eMascota mascota[],int tam);
void HardcodeoMascotas(eMascota mascotas[]);
int BuscarLibreMascota(eMascota mascota[],int tam);
int BuscarMascotaPorId(eMascota mascotas[], int tam, int id);
int EliminarMascota(eMascota mascotas[], int tam);
void OrdenarMascotasPorTipo(eMascota mascotas[], int tam);
void PromedioDeEdadMascotas(eMascota mascotas[], int tam);
void PromedioDeEdadMascotasPorTipo (eMascota mascotas[], int tamMascotas, eTipoMascota tipo[], int tamTipo);

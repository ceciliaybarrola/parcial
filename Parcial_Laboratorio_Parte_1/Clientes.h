#define LIBRE 0
#define OCUPADO 1
#include <string.h>
#include "Inputs.h"

typedef struct{
    int idCliente;
    char nombre[100];
    char apellido[100];
    char localidad[100];
    long int telefono;
    int edad;
    char sexo;
    int estado;
}eClientes;

void HardcodeoClientes(eClientes clientes[]);
void inicializarClientes(eClientes clientes[], int tam);
int BuscarLibreClientes(eClientes clientes[],int tam);
int AltaClientes(eClientes clientes[], int tam, int counter);
int ModificarCliente(eClientes clientes[], int tam);
int BuscarClientePorId(eClientes clientes[], int tam, int id);
void MostrarListadoClientes(eClientes clientes[], int tam);
void PromedioVaronesMujeres(eClientes clientes[], int tam);
int ContadorClientes(eClientes clientes[], int tam);
int ContadorPorSexo(eClientes clientes[], int tam, char sexo);
float calcularPorcentaje(int cantidad, int cantidadTotal);
int acumuladorEdadPorSexo(eClientes clientes[], int tam, char sexo);

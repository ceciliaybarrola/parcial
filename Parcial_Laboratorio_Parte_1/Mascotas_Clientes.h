#include "Mascotas.h"
#include "Clientes.h"
typedef struct{
 int idCliente;
 int contadorMascotas;
 int estado;
}eClientesMascotas;



void mostrarMascota(eTipoMascota listadoTipo[], int tamTipo, eMascota mascota[],int tamMascota, eClientes cliente[], int tamCliente, eRaza raza[], int tamRaza);
void mostrarClienteConMascota(eMascota mascota[],int tamMascota, eClientes cliente[], int tamCliente);
int AltaMascota(eMascota mascotas[], int tamMascota, eClientes clientes[],int tamClientes, int contador, eRaza raza[], int tamRaza);
int BorradoClienteEnCascada(eMascota mascotas[], int tamMascota, eClientes clientes[],int tamClientes);
void ListarClientesConMasDeUnaMascota(eMascota mascotas[], int tamMascotas, eClientes clientes[], int tamClientes);
void InicializarEstructuraClienteMascotas(eClientesMascotas auxClientesMascotas[], eClientes clientes[], int tamClientes);
void ContabilizarMascotasPorCliente(eClientesMascotas auxClientesMascotas[],eMascota mascotas[], int tamMascotas, eClientes clientes[], int tamClientes);
void MostrarClientesConMasDeUnaMascota(eClientesMascotas auxClientesMascotas[], eClientes clientes[], int tamClientes );
void MostrarMascotasConMasDeTresAnios(eClientes cliente[], int tamCliente, eMascota mascota[], int tamMascota);
void MostrarMascotaSegunTipo(eTipoMascota listadoTipo[], int tamTipo, eClientes cliente[], int tamCliente, eMascota mascota[], int tamMascota);
void OrdenarClientesPorCantidadDeMascotas(eClientes clientes[], int tamClientes, eMascota mascotas[], int tamMascotas);
void OrdenarClientesPorCantidadDeMascotas_Nombre(eClientes clientes[], int tamClientes, eMascota mascotas[], int tamMascotas);
void MostrarListadoClientes_CantidadMascotas(eClientesMascotas auxClientesMascotas[],eClientes clientes[], int tam);
int ModificarMascota(eMascota mascotas[], int tam, eClientes clientes[], int tamClientes);
void MostrarDueniosConMascotasDelMismoSexo(eMascota mascotas[], int tam, eClientes clientes[], int tamClientes);

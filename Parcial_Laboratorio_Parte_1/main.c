#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "Mascotas_Clientes.h"
#define TAM_CLIENTES 10
#define TAM_MASCOTAS 20
#define TAM_TIPO_MASCOTAS 3

int main()
{
   eClientes clientes[TAM_CLIENTES];
   eMascota mascotas[TAM_MASCOTAS];
   eTipoMascota tipoMascota[3]={{1,"gato"}, {2,"perro"}, {3,"raro"} };
   eRaza raza[6]= {{1,10, "persa", "egipto"},{1,11,"siames","arabia"},{2,12,"labrador", "italiano"},{2,13 ,"rottweiler", "aleman"},{3,14, "reptil", "Brasilero"},{3,15, "Anfibio","indio"}};
   int opcion;
   int ret;
   int contMascota=0;
   int contCliente=0;
   inicializarMascota(mascotas,TAM_MASCOTAS);
   inicializarClientes(clientes, TAM_CLIENTES);


   HardcodeoMascotas(mascotas);
   HardcodeoClientes(clientes);


   do{
    opcion=UserMenue();

    switch (opcion){
    case 1:
        MostrarListadoClientes(clientes, TAM_CLIENTES);
        break;
     case 2:
        printf("*********************************************MUESTRO MASCOTAS************************************************\n");

        mostrarMascota(tipoMascota, TAM_TIPO_MASCOTAS, mascotas,TAM_MASCOTAS, clientes, TAM_CLIENTES, raza, 6);
        break;
     case 3:

        printf("*********************************MUESTRO CLIENTES CON SUS MASCOTAS***********************************\n");
        mostrarClienteConMascota(mascotas,TAM_MASCOTAS, clientes, TAM_CLIENTES);
        break;
      case 4:
          ret=AltaMascota(mascotas,TAM_MASCOTAS, clientes, TAM_CLIENTES, contMascota, raza, 6);
          switch(ret)
          {
            case 1:
                printf("Alta Realizada\n");
                contMascota++;
                break;
            case 0:
                printf("No hay espacio disponible\n");
                break;
          }
        break;
      case 5:
          mostrarMascota(tipoMascota, TAM_TIPO_MASCOTAS, mascotas,TAM_MASCOTAS, clientes, TAM_CLIENTES, raza, 6);
          ret=EliminarMascota(mascotas, TAM_MASCOTAS);
            switch(ret)
            {
                case 1:
                    printf("Baja realizada\n");
                    break;
                case 0:
                    printf("No se encontro id\n");
                    break;
                case -1:
                    printf("Accion cancelada\n");
                    break;
            }
        break;
      case 6:
          mostrarMascota(tipoMascota, TAM_TIPO_MASCOTAS, mascotas,TAM_MASCOTAS, clientes, TAM_CLIENTES, raza, 6);
          ret=ModificarMascota(mascotas, TAM_MASCOTAS);
            switch(ret)
            {
                case 1:
                    printf("Modificacion realizada\n");
                    break;
                case 0:
                    printf("No se encontro id\n");
                    break;
                case -1:
                    printf("Accion cancelada\n");
                    break;
            }
        break;
      case 7:
          ret=AltaClientes(clientes, TAM_CLIENTES,contCliente);
          switch(ret)
          {
            case 1:
                printf("Alta Realizada\n");
                contCliente++;
                break;
            case 0:
                printf("No hay espacio disponible\n");
                break;
          }
        break;
      case 8:
          ret=BorradoClienteEnCascada(mascotas,TAM_MASCOTAS, clientes, TAM_CLIENTES);
            switch(ret)
            {
                case 1:
                    printf("Baja realizada\n");
                    break;
                case 0:
                    printf("No se encontro id\n");
                    break;
                case -1:
                    printf("Accion cancelada\n");
                    break;
            }
        break;
      case 9:
          OrdenarMascotasPorTipo(mascotas,TAM_MASCOTAS);
          mostrarMascota(tipoMascota, TAM_TIPO_MASCOTAS, mascotas,TAM_MASCOTAS, clientes, TAM_CLIENTES, raza, 6);
        break;
      case 10:
          ret=ModificarCliente(clientes, TAM_CLIENTES);
            switch(ret)
            {
                case 1:
                    printf("Modificacion realizada\n");
                    break;
                case 0:
                    printf("No se encontro id\n");
                    break;
                case -1:
                    printf("Accion cancelada\n");
                    break;
            }
        break;
      case 11:
        ListarClientesConMasDeUnaMascota(mascotas, TAM_MASCOTAS, clientes, TAM_CLIENTES);
        break;
      case 12:
        MostrarMascotasConMasDeTresAnios(clientes,TAM_CLIENTES,mascotas,TAM_MASCOTAS);
        break;
      case 13:
        MostrarMascotaSegunTipo(tipoMascota, TAM_TIPO_MASCOTAS,  clientes, TAM_CLIENTES, mascotas, TAM_MASCOTAS);
        break;
      case 14:
        OrdenarClientesPorCantidadDeMascotas(clientes,TAM_CLIENTES,mascotas,TAM_MASCOTAS);
        break;
      case 15:
        OrdenarClientesPorCantidadDeMascotas_Nombre(clientes,TAM_CLIENTES,mascotas,TAM_MASCOTAS);
        break;
      case 16:
        PromedioDeEdadMascotas(mascotas, TAM_MASCOTAS);
        break;
      case 17:
        PromedioDeEdadMascotasPorTipo ( mascotas,  TAM_MASCOTAS,  tipoMascota, TAM_TIPO_MASCOTAS);
        break;
      case 18:
        PromedioVaronesMujeres(clientes, TAM_CLIENTES);
        break;
    }
    system ("pause");
    system("cls");
   }while(opcion!=19);

    return 0;
}

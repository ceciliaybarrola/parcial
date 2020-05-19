#include "Clientes.h"


void HardcodeoClientes(eClientes clientes[])
{
    int idCliente[5]={3000,3001,3002,3003,3004};
    char nombre[5][100]={"Mujer","senior","chica","chico","otroSenior"};
    char apellido[5][100]={"Suarez","Awada","Martinez","Meca","Wilson"};
    char localidad[5][100]={"Alsina","Lanus","Avellaneda","Palermo","Gerli"};
    long int telefono[5]={1533334444,1525255252,1599990000,1578945612,1500009999};
    int edad[5]={35,40, 20, 21, 56};
    char sexo[5]={'f','m','f','m','m'};
    int i;
    for(i=0;i<5;i++)
    {
        clientes[i].idCliente=idCliente[i];
        strcpy(clientes[i].nombre, nombre[i]);
        strcpy(clientes[i].apellido, apellido[i]);
        strcpy(clientes[i].localidad, localidad[i]);
        clientes[i].telefono=telefono[i];
        clientes[i].edad=edad[i];
        clientes[i].sexo=sexo[i];
        clientes[i].estado=OCUPADO;

    }
}
int BuscarClientePorId(eClientes clientes[], int tam, int id)
{
    int i;
    int index=-1;

    for (i=0; i<tam; i++)
    {
        if (clientes[i].estado==OCUPADO && id==clientes[i].idCliente)

            {
                index=i;
            }
    }
    return index;
}
void MostrarListadoClientes(eClientes clientes[], int tam)
{

    int i;
    printf("******ID***************NOMBRE*************APELLIDO************LOCALIDAD*****EDAD*****SEXO*************TELEFONO\n");
    for(i=0;i<tam;i++)
    {
        if(clientes[i].estado==OCUPADO)
        {

            printf("%8d %20s %20s %20s %8d %8c %20ld\n",clientes[i].idCliente,
                                                    clientes[i].nombre,
                                                    clientes[i].apellido,
                                                    clientes[i].localidad,
                                                    clientes[i].edad,
                                                    clientes[i].sexo,
                                                    clientes[i].telefono);
        }
    }
    printf("**************************************************************************************************************\n");

}
void inicializarClientes(eClientes clientes[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        clientes[i].estado=LIBRE;
    }
}
int BuscarLibreClientes(eClientes clientes[],int tam)
{
  int i;
  int index = -1;

  for(i=0; i<tam; i++)
  {
      if(clientes[i].estado==LIBRE)
      {
          index =  i;
          break;
      }
  }
  return index;
}

int AltaClientes(eClientes clientes[], int tam, int counter)
{
    int i;
    int ret=1;

    i=BuscarLibreClientes(clientes, tam);

    if(i==-1){
        ret=0;
    }else{
        clientes[i].idCliente=GetId(3005, counter);
        getString(clientes[i].nombre, "Ingrese nombre: ", "ERROR! Ingrese nombre: ");
        getString(clientes[i].apellido, "Ingrese apellido: ", "ERROR! Ingrese apellido: ");
        getString(clientes[i].localidad, "Ingrese localidad: ", "ERROR! Ingrese localidad: ");
        clientes[i].edad=GetInt("Ingrese edad: ", "ERROR! Reingrese edad: ", 0, 120);
        clientes[i].sexo=getChar("Ingrese sexo 'f' o 'm': ","No es una opcion disponible, reingrese 'f' o 'm': ", 'f','m');
        clientes[i].telefono=GetLongInt("Ingrese celular o telefono de linea: ","ERROR! reingrese celular o telefono de linea: ", 20000000, 1599999999 );
        clientes[i].estado=OCUPADO;
    }
    return ret;
}
int ModificarCliente(eClientes clientes[], int tam)
{
    int id;
    int i;
    int ret=1;
    int opcion;
    char confirmacion[100];

    char nombre[100];
    char apellido[100];
    char localidad[100];
    long int telefono;
    int edad;
    char sexo;

    MostrarListadoClientes(clientes, tam);
    id=GetUnsignedInt("Ingrese el id del cliente a modificar: ", "No es un valor disponible. Ingrese el id del cliente a modificar: ");

    i=BuscarClientePorId(clientes, tam, id);

    if(i==-1){
        ret=0;
    }else{
        strcpy(nombre, clientes[i].nombre);
        strcpy(apellido, clientes[i].apellido);
        strcpy(localidad, clientes[i].localidad);
        telefono=clientes[i].telefono;
        edad=clientes[i].edad;
        sexo=clientes[i].sexo;

        do{
          printf("MENU DE MODIFICACIONES\n1.Nombre\n2.Apellido\n3.Localidad\n4.Telefono\n5.Sexo\n6.EXIT\n ");
          opcion=GetInt("Ingrese una opcion: ","ERROR! Ingrese una opcion valida: ",1 , 6);

          switch(opcion)
          {
            case 1:
                getString(nombre, "Ingrese nuevo nombre del cliente: ", "ERROR! Ingrese nuevo nombre del cliente: ");
                break;
            case 2:
                getString(apellido, "Ingrese nuevo apellido: ","ERROR! Ingrese nuevo apellido: ");
                break;
            case 3:
                getString(localidad, "Ingrese nueva localidad: ","ERROR! Ingrese nuevo localidad: ");
                break;
            case 4:
                telefono=GetLongInt("Ingrese celular o telefono de linea: ","ERROR! Reingrese celular o telefono de linea", 20000000, 1599999999 );
                break;
            case 5:
                sexo=getChar("Ingrese nuevo sexo 'f' o 'm': ","No es una opcion disponible, reingrese 'f' o 'm': ", 'f','m' );
                break;
            case 6:
                edad=GetInt("Ingrse nueva edad: ","ERROR! Reingrese nueva edad: ", 0, 120);
                break;
            case 7:
                getString(confirmacion,"Desea realmente modificar los datos? ","ERROR! Desea realmente modificar los datos? ");
                if(stricmp(confirmacion,"si")==0)
                {
                    strcpy(clientes[i].nombre, nombre);
                    strcpy(clientes[i].apellido, apellido);
                    strcpy(clientes[i].localidad, localidad);
                    clientes[i].telefono=telefono;
                    clientes[i].edad=edad;
                    clientes[i].sexo=sexo;
                }else{
                    ret=-1;
                }
                break;
          }
          system ("pause");
          system("cls");

        }while(opcion!=7);
    }
    return ret;

}
void PromedioVaronesMujeres(eClientes clientes[], int tam)
{
    int contadorClientes;
    int contadorMujeres;
    int contadorHombres;
    float porcentaje;
    float promedioSobreTotalHombres;
    float promedioSobreTotalMujeres;
    float promedioEntreHombres_Mujeres;


    contadorClientes=ContadorClientes(clientes, tam);
    contadorMujeres=ContadorPorSexo(clientes, tam, 'f');
    contadorHombres=ContadorPorSexo(clientes, tam, 'm');

    porcentaje=calcularPorcentaje(contadorMujeres, contadorClientes);
    printf("El porcentaje de las clientes mujeres es %%%.2f \n", porcentaje);

    porcentaje=calcularPorcentaje(contadorHombres, contadorClientes);
    //printf("y el de clientes hombres es %%%.2f.\n",porcentaje);

    /***********************************************/

    promedioSobreTotalHombres=(float)contadorClientes/contadorHombres;
    promedioSobreTotalMujeres=(float)contadorClientes/contadorMujeres;

    printf("El promedio de hombre sobre el total es %.2f y el de mujeres es %.2f.\n", promedioSobreTotalHombres,promedioSobreTotalMujeres);

    /**************************************************/
    promedioEntreHombres_Mujeres= (float)contadorHombres/contadorMujeres;

    printf("El promedio que tengo entre varones y mujeres de mis clientes es de %.2f por mujer. \n", promedioEntreHombres_Mujeres);

    /*****************************************************/






}
float calcularPorcentaje(int cantidad, int cantidadTotal)
{

    return ((float)cantidad/ cantidadTotal) * 100;

}
int ContadorClientes(eClientes clientes[], int tam)
{
    int contadorClientes=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(clientes[i].estado==OCUPADO)
        {
            contadorClientes++;
        }
    }
    return contadorClientes;

}
int ContadorPorSexo(eClientes clientes[], int tam, char sexo)
{
    int contadorPorSexo=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(clientes[i].estado==OCUPADO && clientes[i].sexo== sexo)
        {
            contadorPorSexo++;
        }
    }
    return contadorPorSexo;
}
int acumuladorEdadPorSexo(eClientes clientes[], int tam, char sexo)
{
    int AcumuladorEdad=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(clientes[i].estado==OCUPADO && clientes[i].sexo== sexo)
        {
            AcumuladorEdad+= clientes[i].edad;
        }
    }
    return AcumuladorEdad;
}


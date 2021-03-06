#include "Mascotas.h"

void HardcodeoMascotas(eMascota mascotas[])
{
    int idMascota[11]={1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
    int idCliente[11]={3000,3000,3001,3001,3001,3002,3002,3003,3004,3004,3004};
    char nombre[11][20]={"pelusa","michi","firulas","cartucho","siena","ladri","igui","mora","mocoso","gatito","belen"};
    int tipo[11]={1,1,2,2,1,2,3,2,1,1,2};
    int raza[11]={10,10,12,12,13,13,14,13,10,11,14};
    int edad[11]={1,15,13,12,7,2,6,8,16,3,8};
    float peso[11]={16.2,15.4,3.2,9.2,10,10,15,13,15.3,20,29};
    char sexo[11]={'f','f','m','m','m','m','f','m','m','m','m'};

    int i;
    for(i=0;i<11;i++)
    {
        mascotas[i].idMascota=idMascota[i];
        mascotas[i].idCliente=idCliente[i];
        strcpy(mascotas[i].nombre, nombre[i]);
        mascotas[i].tipo=tipo[i];
        mascotas[i].raza= raza[i];
        mascotas[i].edad=edad[i];
        mascotas[i].peso=peso[i];
        mascotas[i].sexo=sexo[i];
        mascotas[i].estado=OCUPADO;
    }
}
void inicializarMascota(eMascota mascota[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        mascota[i].estado=LIBRE;
    }
}
int BuscarLibreMascota(eMascota mascota[],int tam)
{
  int i;
  int index = -1;

  for(i=0; i<tam; i++)
  {
      if(mascota[i].estado==LIBRE)
      {
          index =  i;
          break;
      }
  }
  return index;

}
int BuscarMascotaPorId(eMascota mascotas[], int tam, int id)
{

    int i;
    int index=-1;

    for (i=0; i<tam; i++)
    {
        if (mascotas[i].estado==OCUPADO && id==mascotas[i].idMascota)

            {
                index=i;
            }
    }
    return index;


}

int EliminarMascota(eMascota mascotas[], int tam)
{
    int i;
    char confirmation[20];
    int ret=1;
    int id;

    id=GetUnsignedInt("Ingrese id: ","No es un valor disponible, reingrse id: ");
    i=BuscarMascotaPorId(mascotas, tam, id);

    if (i==-1){
        ret=-1;
    }
    else
    {
        getString(confirmation,"�Realmente desea dar de baja esta mascota?: ","ERROR! �Realmente desea dar de baja esta mascota?: ");

        if(stricmp(confirmation, "si")==0){

            mascotas[i].estado = LIBRE;
        }
        else{
            ret=0;
        }
    }
    return ret;
}
void OrdenarMascotasPorTipo(eMascota mascotas[], int tam)
{
    eMascota auxiliar;
    int i;
    int j;


    for(i=0; i<tam-1; i++)
    {
        if(mascotas[i].estado!=OCUPADO){
            continue;
        }
        for(j=i+1; j<tam; j++)
        {
            if(mascotas[i].estado!=OCUPADO){
                continue;
            }
            if(mascotas[i].tipo > mascotas[j].tipo)
            {
                auxiliar=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=auxiliar;
            }
        }
    }

}
void PromedioDeEdadMascotas(eMascota mascotas[], int tam)
{
    int i;
    int acumuladorEdad=0;
    int contadorMascotas=0;
    float promedio;

    for(i=0;i<tam; i++)
    {
        if(mascotas[i].estado==OCUPADO)
        {
            contadorMascotas++;
            acumuladorEdad= acumuladorEdad + mascotas[i].edad;
        }
    }
    promedio=(float)acumuladorEdad/contadorMascotas;
    printf("El promedio de edad de las mascotas es: %.2f.\n", promedio);
}
void PromedioDeEdadMascotasPorTipo (eMascota mascotas[], int tamMascotas, eTipoMascota tipo[], int tamTipo)
{
    int acumuladorEdad;
    int contadorMascotas;
    float promedio;
    int i;
    int j;

    for(i=0; i<tamTipo; i++)
    {
        contadorMascotas=0;
        acumuladorEdad=0;
        for(j=0; j<tamMascotas; j++)
        {
            if(mascotas[j].estado==OCUPADO && mascotas[j].tipo == tipo[i].tipo)
            {
                contadorMascotas++;
                acumuladorEdad+=mascotas[j].edad;
            }
        }
        promedio=(float)acumuladorEdad/contadorMascotas;
        printf("El promedio de edad de las mascotas tipo %s es: %.2f.\n", tipo[i].descripcionTipo, promedio);
    }
}

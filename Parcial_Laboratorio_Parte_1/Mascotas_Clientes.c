#include "Mascotas_Clientes.h"


void mostrarMascota(eTipoMascota listadoTipo[], int tamTipo, eMascota mascota[],int tamMascota, eClientes cliente[], int tamCliente, eRaza raza[], int tamRaza)
{
    int i;
    int j;
    int x;
    int z;
    printf("*** MASCOTA ********** TIPO ****** RAZA *** EDAD *** PESO * SEXO * ID ******** DUENIO\n");
    for(i=0; i<tamMascota; i++)
    {
        if(mascota[i].estado==OCUPADO)
        {

            for(j=0;j<tamCliente;j++)
            {
                if(cliente[j].idCliente==mascota[i].idCliente)
                {
                    for(x=0; x<tamTipo; x++)
                    {
                        if(mascota[i].tipo == listadoTipo[x].tipo)
                        {
                            for(z=0;z<tamRaza; z++)
                            {

                                  if(mascota[i].raza==raza[z].idRaza)
                                  {
                                    printf(" %10s %8d:%6s %14d %8d %8.2f %5c %5d %14s %20s %10s", mascota[i].nombre,
                                                                                        mascota[i].tipo,
                                                                                        listadoTipo[x].descripcionTipo,
                                                                                        mascota[i].raza,mascota[i].edad,
                                                                                        mascota[i].peso,mascota[i].sexo,
                                                                                        mascota[i].idMascota, cliente[j].nombre,
                                                                                        raza[z].pais, raza[z].nombreRaza);

                                  }





                            }

                        }
                    }
                }
            }
            printf("\n");
        }
    }
     printf("************************************************************************************************************\n");
}
void mostrarClienteConMascota(eMascota mascota[],int tamMascota, eClientes cliente[], int tamCliente)
{
    int i;
    int j;

    printf("***************NOMBRE*************APELLIDO************LOCALIDAD*****EDAD*****SEXO************TELEFONO\n");
    for(i=0;i<tamCliente;i++)
    {
        if(cliente[i].estado==OCUPADO)
        {
            printf("%20s %20s %20s %8d %8c %20ld\n",cliente[i].nombre,cliente[i].apellido, cliente[i].localidad,cliente[i].edad, cliente[i].sexo,cliente[i].telefono);
            for(j=0; j<tamMascota; j++)
            {
                if(mascota[j].idCliente==cliente[i].idCliente)
                {
                    printf("%20s \n", mascota[j].nombre);
                }
            }
            printf("\n");
        }
    }
    printf("*****************************************************************************************************\n");
}
int AltaMascota(eMascota mascotas[], int tamMascota, eClientes clientes[],int tamClientes, int contador, eRaza raza[], int tamRaza)
{
    int index;
    int ret=1;
    int id;
    int retId;
    int auxRaza;
    int flag=0;
    int j;
    index=BuscarLibreMascota(mascotas, tamMascota);

    if (index==-1)
    {
        ret=0;
    }
    else{

        mascotas[index].idMascota=GetId(1011,contador);
        MostrarListadoClientes(clientes, tamClientes);
        do{
            id=GetUnsignedInt("Ingrese id duenio: ","ERROR! Reingrese id del duenio: ");
            retId=BuscarClientePorId(clientes, tamClientes, id);
            if(retId==-1)
            {
                printf("No se encontro el id del duenio, reingrese por favor \n");
            }else{
                mascotas[index].idCliente=id;
            }

        }while(retId==-1);

        getString(mascotas[index].nombre, "Ingrese nombre de la mascota: ", "ERROR! Reingrese nombre de la mascota: ");
        mascotas[index].tipo=GetInt("Ingrese tipo:\n1.gato\n2.perro\n3.raro\n","error reingrese",1,3);



        for(j=0; j<tamRaza; j++)
        {
            if (raza[j].idTipo == mascotas[index].tipo)
            {
                printf("%d. %s.  %s\n", raza[j].idRaza, raza[j].nombreRaza, raza[j].pais);
            }
        }

        do{
                auxRaza=GetUnsignedInt("Ingrese ID raza: ","ERROR! no es un valor disponible, reingrese: ");
                for(j=0; j<tamRaza;j++)
                {
                    if((raza[j].idTipo == mascotas[index].tipo) && (raza[j].idRaza == auxRaza))
                    {
                        mascotas[index].raza=auxRaza;
                        flag=1;
                    }
                }

        }while(flag==0);


        mascotas[index].edad=GetInt("Ingrese edad: ","ERROR! Reingrese edad: ", 0, 200);
        mascotas[index].peso=GetFloat("Ingrese peso: ", "ERROR! Reingrse peso: ", 0.0, 200.0);
        mascotas[index].sexo=getChar("Ingrese sexo 'f' o 'm': ","No es una opcion disponible, reingrese ", 'f','m' );
        mascotas[index].estado=OCUPADO;
    }
    return ret;
}
int BorradoClienteEnCascada(eMascota mascotas[], int tamMascota, eClientes clientes[],int tamClientes)
{
    int id;
    int i;
    int index;
    int ret=1;
    char confirmacion[100];

    MostrarListadoClientes(clientes, tamClientes);
    id=GetUnsignedInt("ingrese Id a eliminar: ","No es un valor disponible, reingrese por favor: ");
    index=BuscarClientePorId(clientes, tamClientes, id);

    if(index==-1)
    {
        ret=0;

    }else{
        getString(confirmacion,"¿Realmente desea dar de baja este cliente?","ERROR! ¿Realmente desea dar de baja este cliente?");

        if(stricmp(confirmacion, "si")==0){

            for(i=0; i<tamMascota; i++)
            {
                if(mascotas[i].estado==OCUPADO && mascotas[i].idCliente == clientes[index].idCliente)
                {
                    mascotas[i].estado=LIBRE;
                }
            }
            clientes[index].estado = LIBRE;
        }else{
            ret=-1;
        }
    }
    return ret;
}
void ListarClientesConMasDeUnaMascota(eMascota mascotas[], int tamMascotas, eClientes clientes[], int tamClientes)
{
    eClientesMascotas auxClientesMascotas[tamClientes];
    //inicializar array paralelo
    InicializarEstructuraClienteMascotas(auxClientesMascotas, clientes, tamClientes);
    //contabilizar mascotas por clientes
    ContabilizarMascotasPorCliente(auxClientesMascotas, mascotas, tamMascotas, clientes, tamClientes);
    //mostrar clientes con mas de una mascota
    printf("******ID***************NOMBRE*************APELLIDO************LOCALIDAD*****EDAD*****SEXO*************TELEFONO\n");
    MostrarClientesConMasDeUnaMascota(auxClientesMascotas, clientes, tamClientes);
    printf("**************************************************************************************************************\n");
}

void InicializarEstructuraClienteMascotas(eClientesMascotas auxClientesMascotas[], eClientes clientes[], int tamClientes)
{
    int i;

    for(i=0; i<tamClientes; i++)
    {
        auxClientesMascotas[i].idCliente=clientes[i].idCliente;
        auxClientesMascotas[i].contadorMascotas=0;
        auxClientesMascotas[i].estado=clientes[i].estado;
    }
}

void ContabilizarMascotasPorCliente(eClientesMascotas auxClientesMascotas[],eMascota mascotas[], int tamMascotas, eClientes clientes[], int tamClientes)
{
    int i;
    int j;

    for(i=0; i<tamClientes; i++)
    {
        for(j=0; j<tamMascotas; j++)
        {
            if(auxClientesMascotas[i].estado==OCUPADO && auxClientesMascotas[i].idCliente==mascotas[j].idCliente)
            {
                auxClientesMascotas[i].contadorMascotas++;
            }
        }
    }
}
 void MostrarClientesConMasDeUnaMascota(eClientesMascotas auxClientesMascotas[], eClientes clientes[], int tamClientes )
 {
    int i;

    for(i=0; i<tamClientes; i++)
    {
        if(auxClientesMascotas[i].estado==OCUPADO && auxClientesMascotas[i].contadorMascotas > 1)
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
 }

void MostrarMascotasConMasDeTresAnios(eClientes cliente[], int tamCliente, eMascota mascota[], int tamMascota)
{
    int i;
    int j;
    printf("************* MASCOTA **** TIPO ************** RAZA *** EDAD *** PESO * SEXO * ID ************* DUENIO\n");
    for(i=0; i<tamMascota; i++)
    {
        if(mascota[i].estado==OCUPADO && mascota[i].edad > 3)
        {
            for(j=0;j<tamCliente;j++)
            {
                if(cliente[j].idCliente==mascota[i].idCliente)
                {
                    printf(" %20s %8d %20d %8d %8.2f %5c %5d %20s\n", mascota[i].nombre,mascota[i].tipo, mascota[i].raza,mascota[i].edad,mascota[i].peso,mascota[i].sexo,mascota[i].idMascota, cliente[j].nombre);

                }
            }
        }
    }
    printf("*****************************************************************************************************\n");
}

void MostrarMascotaSegunTipo(eTipoMascota listadoTipo[], int tamTipo, eClientes cliente[], int tamCliente, eMascota mascota[], int tamMascota)
{
    int opcion;
    int i;
    int j;
    int x;

    opcion=GetInt("Ingrese le tipo por el cual quiere listar:\n 1.Gato\n 2.Perro\n 3.Raro\nIngrese la opcion: ","ERROR! Reingrese opcion: ", 1, 3);

    for (i=0; i<tamTipo; i++)
    {
        if(opcion== listadoTipo[i].tipo)
        {
            break;
        }
    }

    printf("Tipo elegido: %s\n", listadoTipo[i].descripcionTipo);

    printf("************* MASCOTA ********** TIPO ************** RAZA *** EDAD *** PESO * SEXO * ID ************** DUENIO\n");
    for(j=0; j<tamMascota; j++)
    {
       if(mascota[j].tipo == listadoTipo[i].tipo)
       {
            for(x=0; x<tamCliente; x++)
            {
                if(cliente[x].idCliente==mascota[j].idCliente)
                {
                    printf(" %20s %8d:%6s %20d %8d %8.2f %5c %5d %20s\n",  mascota[j].nombre,
                                                                           mascota[j].tipo,
                                                                           listadoTipo[i].descripcionTipo,
                                                                           mascota[j].raza,
                                                                           mascota[j].edad,
                                                                           mascota[j].peso,
                                                                           mascota[j].sexo,
                                                                           mascota[j].idMascota,
                                                                           cliente[x].nombre);

                }
            }
       }
    }
}
void OrdenarClientesPorCantidadDeMascotas(eClientes clientes[], int tamClientes, eMascota mascotas[], int tamMascotas)
{
    eClientesMascotas auxClientesMascotas[tamClientes];
    eClientesMascotas auxOrdClientesMascotas;
    eClientes auxCliente;
    int i;
    int j;
    //inicializar array paralelo
    InicializarEstructuraClienteMascotas(auxClientesMascotas, clientes, tamClientes);
    //contabilizar mascotas por clientes
    ContabilizarMascotasPorCliente(auxClientesMascotas, mascotas, tamMascotas, clientes, tamClientes);

    for(i=0; i<tamClientes-1; i++)
    {
        for(j=i+1; j<tamClientes; j++)
        {
            if(auxClientesMascotas[i].contadorMascotas > auxClientesMascotas[j].contadorMascotas)
            {
                auxCliente=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=auxCliente;

                auxOrdClientesMascotas= auxClientesMascotas[i];
                auxClientesMascotas[i]=auxClientesMascotas[j];
                auxClientesMascotas[j]=auxOrdClientesMascotas;

            }
        }
    }
    MostrarListadoClientes_CantidadMascotas(auxClientesMascotas,clientes, tamClientes);
}
void OrdenarClientesPorCantidadDeMascotas_Nombre(eClientes clientes[], int tamClientes, eMascota mascotas[], int tamMascotas)
{
    eClientesMascotas auxClientesMascotas[tamClientes];
    eClientesMascotas auxOrdClientesMascotas;

    eClientes auxCliente;
    int i;
    int j;

    //inicializar array paralelo
    InicializarEstructuraClienteMascotas(auxClientesMascotas, clientes, tamClientes);
    //contabilizar mascotas por clientes
    ContabilizarMascotasPorCliente(auxClientesMascotas, mascotas, tamMascotas, clientes, tamClientes);

    for(i=0; i<tamClientes-1; i++)
    {
        if(clientes[i].estado!=OCUPADO)
        {
            continue;
        }
        for(j=i+1; j<tamClientes; j++)
        {
             if(clientes[j].estado!=OCUPADO)
            {
                continue;
            }

            if(auxClientesMascotas[i].contadorMascotas > auxClientesMascotas[j].contadorMascotas || (auxClientesMascotas[i].contadorMascotas == auxClientesMascotas[j].contadorMascotas  && stricmp(clientes[i].nombre, clientes[j].nombre)>0))
            {
                auxCliente=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=auxCliente;

                auxOrdClientesMascotas= auxClientesMascotas[i];
                auxClientesMascotas[i]=auxClientesMascotas[j];
                auxClientesMascotas[j]=auxOrdClientesMascotas;
            }
        }
    }
    MostrarListadoClientes_CantidadMascotas(auxClientesMascotas,clientes, tamClientes);
}

void MostrarListadoClientes_CantidadMascotas(eClientesMascotas auxClientesMascotas[],eClientes clientes[], int tam)
{
    int i;
    printf("******ID***************NOMBRE*************APELLIDO************LOCALIDAD*****EDAD*****SEXO*************TELEFONO***CANTIDAD\n");
    for(i=0;i<tam;i++)
    {
        if(clientes[i].estado==OCUPADO)
        {

            printf("%8d %20s %20s %20s %8d %8c %20ld %10d\n",clientes[i].idCliente,
                                                         clientes[i].nombre,
                                                         clientes[i].apellido,
                                                         clientes[i].localidad,
                                                         clientes[i].edad,
                                                         clientes[i].sexo,
                                                         clientes[i].telefono,
                                                         auxClientesMascotas[i].contadorMascotas);
        }
    }
     printf("*****************************************************************************************************************CANTIDAD\n");

}
int ModificarMascota(eMascota mascotas[], int tam, eClientes clientes[], int tamClientes)
{
    int id;
    int i;
    int ret=1;
    int opcion;
    char confirmacion[100];

    char nombre[100];
    int tipo;
    int raza;
    int edad;
    float peso;
    char sexo;
    int idCliente;
    int retId;


    id=GetUnsignedInt("ingrese Id a modificar: ","No es un valor disponnible, reingrese por favor: ");

    i=BuscarMascotaPorId(mascotas, tam, id);

    if(i==-1)
    {
        ret=0;

    }else{
        strcpy(nombre, mascotas[i].nombre);
        tipo=mascotas[i].tipo;
        raza= mascotas[i].raza;
        edad=mascotas[i].edad;
        peso=mascotas[i].peso;
        sexo=mascotas[i].sexo;
        idCliente=mascotas[i].idCliente;

        do{
          printf("MENU DE MODIFICACIONES\n1.Nombre\n2.Tipo\n3.Raza\n4.Edad\n5.Peso\n6.Sexo\n7.duenio\n8.EXIT\n ");
          opcion=GetInt("Ingrese una opcion: ","ERROR! Ingrese una opcion valida: ",1 , 7);

          switch(opcion)
          {
            case 1:
                getString(nombre, "Ingrese nuevo nombre de la mascota: ", "ERROR! Ingrese nuevo nombre de la mascota: ");
                break;
            case 2:
                tipo=GetInt("TIPOS DE MASCOTAS\n1.gato\n2.perro\n3.raro\nIngrese nuevo tipo: ","ERROR! Reingrese el tipo: ",1,3);
                break;
            case 3:
                raza=GetInt("Ingrese nueva raza de la mascota: ","ERROR! Ingrese nueva raza de la mascota: ",10, 15);
                break;
            case 4:
                edad=GetInt("Ingrese nueva edad: ","ERROR! Reingrese la edad: ", 0, 200);
                break;
            case 5:
                peso=GetFloat("Ingrese nuevo peso: ", "ERROR! Reingrese el nuevo peso: ", 0.0, 200.0);
                break;
            case 6:
                sexo=getChar("Ingrese nuevo sexo 'f' o 'm': ","No es una opcion disponible, reingrese nuevo sexo 'f' o 'm': ", 'f','m' );
                break;
            case 7:
                MostrarListadoClientes(clientes, tamClientes);
                 do{
                        idCliente=GetUnsignedInt("Ingrese id duenio: ","ERROR! Reingrese id del duenio: ");
                        retId=BuscarClientePorId(clientes, tamClientes, idCliente);
                        if(retId==-1)
                        {
                            printf("No se encontro el id del duenio, reingrese por favor \n");
                        }else{
                            mascotas[i].idCliente=idCliente;
                        }

                    }while(retId==-1);
                break;
            case 8:
                getString(confirmacion,"Desea realmente modificar los datos? ","ERROR! Desea realmente modificar los datos? ");
                if(stricmp(confirmacion,"si")==0)
                {
                    strcpy(mascotas[i].nombre, nombre);
                    mascotas[i].tipo=tipo;
                    mascotas[i].raza= raza;
                    mascotas[i].edad=edad;
                    mascotas[i].peso=peso;
                    mascotas[i].sexo=sexo;
                    mascotas[i].idCliente=idCliente;

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
void MostrarDueniosConMascotasDelMismoSexo(eMascota mascotas[], int tam, eClientes clientes[], int tamClientes)
{
    int i;
    int j;
    int contador;
    int contadorF;
    int contadorM;
    for(i=0;i<tamClientes;i++)
    {
        if(clientes[i].estado==OCUPADO)
        {
            contador=0;
            contadorM=0;
            contadorF=0;


            for(j=0; j<tam; j++)
            {
                if(mascotas[j].idCliente==clientes[i].idCliente)
                {
                    contador++;
                    if(mascotas[j].sexo=='f')
                    {
                        contadorF++;
                    }
                    else
                    {
                        contadorM++;
                    }
                }

            }
            if(contador== contadorF || contador== contadorM)
            {
                printf("%20s %20s %20s %8d %8c %20ld\n",clientes[i].nombre,clientes[i].apellido, clientes[i].localidad,clientes[i].edad, clientes[i].sexo,clientes[i].telefono);

            }
        }
    }






}






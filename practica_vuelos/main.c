#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Vuelos.h"
#include "Pilotos.h"
int main()
{
    LinkedList* listaVuelos=ll_newLinkedList();
    LinkedList* listaPilotos=ll_newLinkedList();
    int opcion;
    char confirmation[100];
    int ret;

   // pilotos_hardcodear(listaPilotos);
    //controller_Ybarrola_loadPilotstoText(listaPilotos);
    controller_Ybarrola_loadPilotsfromText(listaPilotos);
    //controller_Ybarrola_listPilotos(listaPilotos);

    do{
        opcion=UserMenue();
        system("cls");
        switch(opcion)
        {
            case 1:
                ret=controller_Ybarrola_loadFromText(listaVuelos,listaPilotos);
                FunctionReturnMessages(ret, " ", " ", "ERROR! No existe el archivo", "Se cargaron los vuelos de forma efectiva");
                break;
            case 2:
                ret=controller_Ybarrola_listFlights(listaVuelos,listaPilotos);
                FunctionReturnMessages(ret, " ", " ", "ERROR!", "Se listaron los vuelos de forma efectiva");
                break;
            case 3:
                ret=controller_Ybarrola_countTotalPassengers(listaVuelos);
                FunctionReturnMessages(ret, " ", " ", "ERROR!", "Se contaron los pasajeros de forma efectiva");
                break;
            case 4:
                ret=controller_Ybarrola_countPassengersToIreland(listaVuelos);
                FunctionReturnMessages(ret, " ", " ", "ERROR!", "Se contaron los pasajeros hacia Irlanda de forma efectiva");
                break;
            case 5:
                ret=controller_Ybarrola_filterShortFlights(listaVuelos,listaPilotos);
                FunctionReturnMessages(ret, " ", " ", "ERROR!", "Se cargaron los vuelos cortos en el archivo de forma efectiva");
                break;
            case 6:
                ret=controller_Ybarrola_ListFligthsToPortugal(listaVuelos,listaPilotos);
                FunctionReturnMessages(ret, " ", " ", "ERROR!", "Se listaron los vuelos a Portugal de forma efectiva");
                break;
            case 7:
                ret=controller_Ybarrola_ListFligthsWithoutLifeson(listaVuelos,listaPilotos);
                FunctionReturnMessages(ret, " ", " ", "ERROR!", "Se cargaron los vuelos sin Alex Lifeson de forma efectiva");
                break;
            case 8:
                ret=controller_Ybarrola_ListFilteredFligths(listaVuelos,listaPilotos);
                FunctionReturnMessages(ret, " ", " ", "ERROR!", "Se cargaron los vuelos de forma efectiva");

                break;
            case 9:
                getString(confirmation,"Está seguro que desea salir?");
                if(strcmpi(confirmation, "si")==0)
                {opcion=10;}
                break;
           /* case 9:
                controller_Ybarrola_listPilotos(listaPilotos);
                break;  */


        }
    system("pause");
    system("cls");
    }while(opcion!=10);


    return 0;
}

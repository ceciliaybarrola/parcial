#include "Inputs.h"

int UserMenue(void)
{
    int option;

    printf("|ALTAS, BAJAS Y MODIFICACIONES DE CLIENTES|\n");
    printf("Menu de opciones:\n");
    printf("1. Listado de clientes\n");
    printf("2. listado de Mascotas\n");
    printf("3. listado de clientes con mascotas\n");
    printf("4. alta mascota\n");
    printf("5. baja mascota\n");
    printf("6. modificar mascota\n");
    printf("7. alta duenio\n");
    printf("8. Borrado de dueño en cascada\n");
    printf("9. ordenar las mascotas por tipo\n");
    printf("10. Modificacion duenio\n");
    printf("11. Listar clientes con mas de una mascota\n");
    printf("12. Listar las mascotas con mas de tres años, con respectivos dueños\n");
    printf("13. Listar las mascotas por un tipo en particular\n");
    printf("14. Ordenar a los duenios por cantidades de mascotas y mostarlos \n");
    printf("15. Ordenar a los duenios por cantidades de mascotas y por orden alfabetico de los nombres y mostarlos \n");
    printf("16. El promedio de edad entre las mascotas \n");
    printf("17. El promedio de edad entre las mascotas, por tipo \n");
    printf("18. El promedio que tengo entre varones y mujeres de mis clientes\n");
    printf("19. Salir\n");

    option=GetInt("Ingrese una opcion: ","No es una opción valida, reingrese la opción: ",1,20);

    return option;
}

float GetFloat(char message[], char errorMessage[], float min, float max)
{
    float floatNumber;
    char stringNum[200];
    //pido datos
    printf("%s", message);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';

    floatNumber=atof(stringNum);

    while(IsAnfloatNumber(stringNum)!=1|| floatNumber<min || floatNumber>max)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';

        floatNumber=atof(stringNum);
    }
    return floatNumber;
}
int IsAnfloatNumber(char charArray[])//no funciona
{
    int i=0;
    int ret=1;
    int dotsCounter=0;

    if(charArray[0]=='\0'||charArray[0]=='.'){
        ret=0;
    }
    else{
        if(charArray[0]=='-'){
         i=1;
        }
    }
    for( ;charArray[i]!='\0' ;i++)
    {
         if(charArray[i]<'0'||charArray[i]>'9')
        {
            if(charArray[i]!= '.'||dotsCounter!=0)
            {
               ret=0;
               break;
            }
            else{
                dotsCounter++;
            }
        }
    }
    return ret;
}

void getString(char charArray[], char message[], char errorMessage[])
{
    printf("%s", message);
    fflush(stdin);
    //__fpurge(stdin);
    fgets(charArray, 51, stdin);
    charArray[strlen(charArray)-1] = '\0';

    while(IsAnAlphabetString(charArray)==1)
    {

        printf("%s", errorMessage);
        fflush(stdin);
        //__fpurge(stdin);
        fgets(charArray, 51, stdin);
        charArray[strlen(charArray)-1] = '\0';
    }
}
int IsAnAlphabetString(char charArray[])
{
    int i;
    int flag=0;

    for(i=0; charArray[i]!='\0'; i++)
    {
        if((charArray[i]<'a' || charArray[i]>'z') && (charArray[i]<'A' || charArray[i]>'Z'))
        {
            flag=1;
            break;
        }
    }
    return flag;
}


int GetId(int constant, int counter)
{

    return constant+counter;
}
char getChar(char message[], char errorMessage[], char min, char max)
{
    char character;

    printf("%s", message);
    fflush(stdin);
    scanf(" %c", &character);

    while (character!= min && character!= max){
        printf("%s", errorMessage);
        fflush(stdin);
        scanf(" %c", &character);
    }

    return character;
}
int GetInt(char message[], char errorMessage[], int min, int max)
{
    int num;
    char stringNum[200];
    //pido datos
    printf("%s", message);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';
    //convierto a stringNum a un numero int
    num=atoi(stringNum);
    //si la funcion IsAnumber es distinto a 1 omito las siguentescondiciones porque no es un numero
    //si pasa la primer condicion es porque es un numero y el la variable 'num' tiene un valor numerico valido
    //valida si esta en el rango y de no ser asi entra en el while para repetir el proceso
    while(IsAnIntNumber(stringNum)!=1|| num<min || num>max)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';

        num=atoi(stringNum);
    }
    return num;

}
long int GetLongInt(char message[], char errorMessage[], long int min, long int max)
{
    long int num;
    char stringNum[200];

    printf("%s", message);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';
    num=atol(stringNum);

    while(IsAnIntNumber(stringNum)!=1|| num<min || num>max)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';

        num=atol(stringNum);
    }
    return num;

}
int IsAnIntNumber(char charArray[])
{
    int i=0;
    int retorno=1;

     if(charArray[0]=='-'){
        i=1;
    }
    for( ; charArray[i]!='\0' ;i++)
    {
        if(charArray[i]<'0'||charArray[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int GetUnsignedInt(char message[], char errorMessage[])
{
    int num;
    char stringNum[200];
    //pido datos
    printf("%s", message);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';

    //si la funcion IsAnumber es distinto a 1 omito no es un numero

    while(IsAnUnsignedIntNumber(stringNum)!=1)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';
    }
     //convierto a stringNum a un numero int
     num=atoi(stringNum);

    return num;
}
int IsAnUnsignedIntNumber(char charArray[])
{
    int i;
    int ret=1;

    if(charArray[0]=='\0')
    {
        ret=0;
    }
    for(i=0 ; charArray[i]!='\0' ;i++)
    {
        if(charArray[i]<'0'||charArray[i]>'9')
        {
            ret=0;
            break;
        }
    }

    return ret;
}

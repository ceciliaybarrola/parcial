#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int UserMenue(void);

int GetId(int constant, int counter);
int GetInt(char message[], char errorMessage[], int min, int max);
int IsAnIntNumber(char charArray[]);
float GetFloat(char message[], char errorMessage[], float min, float max);
int IsAnfloatNumber(char charArray[]);
char getChar(char message[], char errorMessage[], char min, char max);
void getString(char charArray[], char message[], char errorMessage[]);
int IsAnAlphabetString(char charArray[]);
int IsAnUnsignedIntNumber(char charArray[]);
int GetUnsignedInt(char message[], char errorMessage[]);
long int GetLongInt(char message[], char errorMessage[], long int min, long int max);

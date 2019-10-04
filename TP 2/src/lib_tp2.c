/*
 * lib_tp2.c
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "lib_tp2.h"

int getStr(char charStr[], int length, char *pMensaje)
{

char buffer[length];
printf("%s", pMensaje);
__fpurge(stdin);
fgets(buffer, length,stdin);
strncpy(charStr,buffer,length);

	return 0;
}
int getFloat(float *pResultado,char *pMensaje,char *pMensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%f",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}
int getInt(	int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}


int loadNewEmployee(char name[], char lastName[],int length,float *salary, int *sector,
		char *pMsgName, char *pMsgLastName, char *pMsgSalary, char *pMsgErrorSalary,
		float minSalary, float maxSalary, int maxtrySalary,char *pMsgSector,
		char *pMsgErrorSector, int minSector, int maxSector, int maxtrySector)
{
	int retorno =-1;
	getStr(name,length,pMsgName);
	getStr(lastName,length,pMsgLastName);
	getFloat(salary, pMsgSalary, pMsgErrorSalary, minSalary, maxSalary, maxtrySalary);
	getInt(sector, pMsgSector, pMsgErrorSector, minSector, maxSector, maxtrySector);


	return retorno;
}

int mainMenu(int *option)
{
int buffer;

printf("\n 1.- Alta de empleado.");
printf("\n 2.- Modificar empleado.");
printf("\n 3.- Borrar empleado.");
printf("\n 4.- Imprimir Informe.");
printf("\n 5.- Salir.");
getInt(&buffer,"\ningrese la opcion deseada", "\nopcion incorrecta",1,5,3);
*option=buffer;
	return 0;
}
int modificarMenu(int *option)
{
int buffer;
printf("\n 1.- Cambiar Nombre.");
printf("\n 2.- Cambiar apellido.");
printf("\n 3.- Cambiar Salario.");
printf("\n 4.- Cambiar sector.");


getInt(&buffer,"\ningrese la opcion deseada", "\nopcion incorrecta",1,4,3);

*option = buffer;
return 0;
}

int isValidAlphabetic(char *name)
{
int retorno =0;
int i;
int length=strlen(name)-1;

if(name!=NULL && length>0)
{
	for(i=0;i<length;i++)
	{
		if((name[i]>='A' && name[i]<='Z') || (name[i]>='a' && name[i]<='z'))
		{
			retorno=0;
			continue;
		}else{
			printf("Error. Ingreso algun caracter no alfabetico.\n");
			retorno = -1;
			break;
		}
	}
}
	return retorno;
}

int isValidFloat(char *number)
{
	{
	int retorno =0;
	int i;
	int length=strlen(number)-1;

	if(number!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if((number[i]>='0' && number[i]<='9') || (number[i]=='.'))
			{
				retorno=0;
				continue;
			}
			else
			{
				printf("Error. Ingreso algun caracter no numerico.\n");
				retorno = -1;
				break;
			}
		}
	}
		return retorno;
	}
}
int getVFloatStr(char *stringRecibido)
{
	int retorno = 0;
	int length = strlen(stringRecibido);
	int i;
	for(i=0;i<length;i++)
	{
		if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
		{
			retorno =-1;
			break;
		}
	}
	return retorno;
}
int GetCheckedFloat(char *input, float min, float max,int length, float *output)
{
	int retorno =-1;
	char bufferStr[length];
	float bufferFloat;

	strncpy(bufferStr,input,length);

	if(strlen(bufferStr)>0 && bufferStr!=NULL)
	{
	bufferFloat=atof(bufferStr);
	}
	if(bufferFloat<max && bufferFloat>min)
	{
		*output=bufferFloat;
		retorno=0;
	}else
	{
	printf("el numero debe estar entre %.2f y %.2f.", min, max);
		retorno=-1;
	}

	return retorno;
}







/*
 * utn_lib.c
 *
 *  Created on: 31 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn_lib.h"


int getInt(int *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = -1;
	int buffer;
	do {
		printf("%s", pMensaje);
		__fpurge(stdin);

		if (scanf("%d", &buffer) == 1 && buffer >= minimo && buffer <= maximo) {
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s", pMensajeError);
		reintentos--;
	} while (reintentos >= 0);
	return retorno;
}
int isValidNumeric(char *number) {
	{
		int retorno = 0;
		int i;
		int length = strlen(number) - 1;
		if (number != NULL && length > 0) {
			for (i = 0; i < length; i++) {
				if (number[i] >= '0' && number[i] <= '9') {
					retorno = 0;
				} else {
					printf("Error. Ingreso algun caracter no numerico.\n");
					retorno = -1;
					break;
				}
			}
		}
		return retorno;
	}
}
int isValidAlphabetic(char *rcvdStr) {
	int retorno = 0;
	int i;
	int length = strlen(rcvdStr) - 1;

	if (rcvdStr != NULL && length > 0) {
		for (i = 0; i < length; i++) {
			if ((rcvdStr[i] >= 'A' && rcvdStr[i] <= 'Z')
					|| (rcvdStr[i] >= 'a' && rcvdStr[i] <= 'z')
					|| (rcvdStr[i] == ' ')) {
				retorno = 0;

			} else {
				printf("Error. Ingreso algun caracter no alfabetico.\n");
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}
int mainMenu(int *option) {
	int buffer;

	printf("\n 1.- Cargar los datos de empleados desde data.csv(texto)");
	printf("\n 2.- Cargar los datos de empleados desde data.csv(bin)");
	printf("\n 3.- Alta de Empleado");
	printf("\n 4.- Modificar Empleado");
	printf("\n 5.- Baja Empleado");
	printf("\n 6.- Listar Empleados");
	printf("\n 7.- Ordenar Empleados alfabeticamente");
	printf("\n 8.- Guardar los datos de empleados en data.csv(texto)");
	printf("\n 9.- Guardar los datos de empleados en data.csv(bin)");
	printf("\n 10.-Clonar lista de empleados.");
	printf("\n 11.-Eliminar un empleado de la lista(por indice) e Imprimirlo");
	printf("\n 12.-Eliminar lista clonada");
	printf("\n 13.-Compara la lista y su clon");
	printf("\n 14.-Crear una sublista");

	getInt(&buffer, "\ningrese la opcion deseada", "\nopcion incorrecta", 1, 14,
			3);
	*option = buffer;
	return 0;
}
int getStr(char charStr[], int length, char *pMensaje) {
	char buffer[length];
	printf("%s", pMensaje);
	__fpurge(stdin);
	fgets(buffer, length, stdin);
	strncpy(charStr, buffer, length);
	return 0;
}
int modificarEmpleadoMenu(int *option)
{
	int retorno = -1;
	int buffer;
	printf("\nQue desea hacer con este empleado?");
	printf("\n1.-Modificar Nombre.");
	printf("\n2.-Modificar Horas Trabajadas.");
	printf("\n3.-Modificar Sueldo.");
	printf("\n4.-Salir.");
	getInt(&buffer, "\nIngrese la opcion deseada.", "\nOpcion incorrecta.", 1, 4,3);

	*option = buffer;
	return retorno;
}
int getChar(char *letra, char *pMensaje) {
	char buffer;
	printf("%s", pMensaje);
	__fpurge(stdin);
	buffer = getchar();

	*letra = buffer;

	return 0;
}

/*
 * utn_lib.h
 *
 *  Created on: 31 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_LIB_H_
#define UTN_LIB_H_



#endif /* UTN_LIB_H_ */
int getInt(int *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos);
int isValidNumeric(char *number);
int isValidAlphabetic(char *rcvdStr);
int mainMenu(int *option);
int getStr(char charStr[], int length, char *pMensaje);
int modificarEmpleadoMenu(int *option);
int getChar(char *letra, char *pMensaje);

/*
 ============================================================================
 Name        : TP1.c
 Author      : Ignacio Martin CAnay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"




int main(void) {

int A;
int B;
int Suma;
int Resta;
int Division;
int Multiplicacion;
int factorialA;
int factorialB;

getNumber(&A);
getNumber(&B);

printf("\nNumero ingresado: %d", A);
printf("\nNumero ingresado: %d", B);

sumTwoNumbers(&A, &B, &Suma);
printf("\nEl resultado de la suma de %d + %d es: %d", A, B, Suma);

substractTwoNumbers(&A, &B, &Resta);

printf("\nEl resultado de la resta de %d - %d es: %d", A, B, Resta);

if(quotienTwoNumbers(&A, &B, &Division)==-1)
	{
	printf("\n No se puede dividir por 0");

	}//Division = NULL;  que resultado tendria que ponerle aca al resultado de la division
else
	{
	printf("\nEl resultado de la Division de %d y %d es: %d", A, B, Division);
	}

multiplicationTwoNumbers(&A, &B,&Multiplicacion);
printf("\nElresultado de la multiplicacion de %d y %d es: %d", A, B, Multiplicacion);

factorial(&A,&factorialA);
factorial(&B,&factorialB);
printf("\nEl factorial de %d es: %d. Y el factorial de %d es: %d", A, factorialA, B, factorialB);


return 0;
}







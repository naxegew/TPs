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

int A=0;
int B=0;
int Suma;
int Resta;
float Division;
int Multiplicacion;
int factorialA;
int factorialB;
int opInput;
int flagVal1=0;
int flagVal2=0;
int flagCalc=0;


printf("\n --Menu de Opciones--"
		"\n 1.-Ingresar el Primer Valor."
		"\n 2.-Ingresar el segundo Valor."
		"\n 3.-Realizar todas las operaciones."
		"\n 4.-Imprimir los resultados."
		"\n 5.-Salir\n");

do
{
getNumber(&opInput, "\nQue desea hacer (ingrese 1 a 5)?");


	switch(opInput)
	{
	case 1:
		getNumber(&A, "Ingrese el primer valor: ");
		flagVal1=1;
		break;
	case 2:

		getNumber(&B, "Ingrese el segundo valor: ");
		flagVal2=1;



		break;
	case 3:
		if(flagVal2==1 && flagVal1==1){
		sumTwoNumbers(&A, &B, &Suma);
		substractTwoNumbers(&A, &B, &Resta);
		quotienTwoNumbers(A, B, &Division);
		multiplicationTwoNumbers(&A,&B,&Multiplicacion);
		factorial(A,&factorialA);
		factorial(B,&factorialB);
		printf("calculos realizados");
		flagCalc=1;
		}
		else if(flagVal2==0 && flagVal1==0)
		{
		printf("falta ingresar los dos valores para caulcular (opcion 1 y 2 del menu)");
		}
		else if(flagVal2==0 && flagVal1==1)
		{
			printf("falta ingresar el segundo valor para hacer los calculos (opcion 2 del menu)");
		}
		else if(flagVal1==0)
		{
			printf("falta ingresar el primer valor para hacer los calculos(opcion 1 del menu)");
		}

		break;
	case 4:
		if(flagCalc==1){
			printf("\nPrimer Numero ingresado: %d", A);
			printf("\nSegundo Numero ingresado: %d", B);
			printf("\nEl resultado de la suma de %d + %d es: %d", A, B, Suma);
			printf("\nEl resultado de la resta de %d - %d es: %d", A, B, Resta);
			if(quotienTwoNumbers(A, B, &Division)==-1)
				{
				printf("\n No se puede dividir por 0");

				}
			else
				{
				printf("\nEl resultado de la Division de %d y %d es: %.2f", A, B, Division);
				}
				printf("\nElresultado de la multiplicacion de %d y %d es: %d", A, B, Multiplicacion);
				printf("\nEl factorial de %d es: %d. Y el factorial de %d es: %d", A, factorialA, B, factorialB);
		}else{
		printf("primero debe hacer los calculos (opcion 3 del menu)");
		}
		break;
	case 5:
		printf("saliendo");

		return 0;
		break;
	default:
		printf("Opcion incorrecta");
		break;
	}
}while(opInput!=5);

}







/*
 * tp1.c
 *
 *  Created on: 1 sept. 2019
 *      Author: igna
 */

#include <stdio.h>
#include <stdlib.h>

int getNumber (int *inputNumber)
{
	int number;
	printf("ingrese un numero: ");
	scanf("%d", &number);
	*inputNumber = number;
			return 0;
}

int sumTwoNumbers(int *number1, int *number2, int *result)
{
int aNumber1 = *number1;
int aNumber2 = *number2;
int aResult;
aResult = aNumber1 + aNumber2;
*result = aResult;
return 0;
}

int substractTwoNumbers(int *number1, int *number2, int *result)
{
int aNumber1 = *number1;
int aNumber2 = *number2;
int aResult;
aResult = aNumber1 - aNumber2;
*result = aResult;
return 0;
}

int quotienTwoNumbers(int *number1, int *number2, int *result)
{
int aNumber1 = *number1;
int aNumber2 = *number2;
int aResult;
int retorno = -1;
	if(aNumber1 !=0 && aNumber2 !=0)
	{
	aResult = aNumber1 / aNumber2;
	*result=aResult;
	return 0;
	}
return retorno;
}

int multiplicationTwoNumbers(int *number1, int *number2, int *result)
{
int aNumber1 = *number1;
int aNumber2 = *number2;
int aResult;

aResult = aNumber1 * aNumber2;

*result=aResult;
return 0;
}
int factorial(int *number, int *result)
{
int aNumber = *number;
int	aResult=1;
int i;

for(i=1;i<=aNumber;i++)
{
aResult *= i;
}
*result =aResult;
return 0;
}


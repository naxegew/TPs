/*
 * tp1.c
 *
 *  Created on: 1 sept. 2019
 *      Author: igna
 */

#include <stdio.h>
#include <stdlib.h>

int getNumber (int *inputNumber,char *pMensaje)
{
	int number;
	printf(pMensaje);
	scanf("%d", &number);
	*inputNumber = number;
			return 0;
}

int sumTwoNumbers(int *number1, int *number2, int *result)
{
int aNumber1 = *number1;
int aNumber2 = *number2;
int aResult=0;
aResult = aNumber1 + aNumber2;
*result = aResult;
return 0;
}

int substractTwoNumbers(int *number1, int *number2, int *result)
{
int aNumber1 = *number1;
int aNumber2 = *number2;
int aResult=0;
aResult = aNumber1 - aNumber2;
*result = aResult;
return 0;
}

int quotienTwoNumbers(int number1, int number2, float *result)
{


float aResult=0;
int retorno = -1;

	if(number1 != 0 && number2 != 0)
	{
	aResult = (float)number1 / number2;
	*result=aResult;
	return 0;
	}
return retorno;
}

int multiplicationTwoNumbers(int number1, int number2, int *result)
{

int aResult=0;
aResult = number1 * number2;

*result=aResult;
return 0;
}
int factorial(int number, int *result)
{

int	aResult=1;
int i;

for(i=1;i<=number;i++)
{
aResult = aResult * i;
}
*result =aResult;
return 0;
}


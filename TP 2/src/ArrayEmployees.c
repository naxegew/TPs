/*
 * ArrayEmployees.c
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"

/*Esta funcion marca todas las posiciones del array, que recibe como parametro, como vacia al asignarle a el campo isEmpty el valor 0.
 * la funcion devuelve -1, si el array es nulo o si esta vacio. Y devuelve 0 si puede cambiar el campo isEmpty a 0 de todos los elementos del array.
 * */
int initEmployees(Employee list[],int length)
{
	int retorno =-1;
	int i;
	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			list[i].isEmpty =0;
		}
		retorno =0;
	}

	return retorno;
}
 /*Esta funcion, recibe como parametros:
  * El Array de tipo Empleados donde va a guardar los datos (id, nombre, apellido -y el largo maximo de la cadena de caracteres de estos ultimos dos-, salario y sector) y el largo maximo de ese array
  * devuelve -1 si no puede Agregar al Array los datos, ya sea por que es un Array nullo o por que el largo maximo es 0.
  * */
int addEmployees(Employee list[], int length,int id, char name[], char lastName[],int strLength, float *salary, int *sector)
{
int retorno =-1;
int i;
if(list!= NULL && length>0)
   {
	for(i=0;i<length;i++)
	{
		if(list[i].isEmpty==1)
		{
			printf("\nla posicion %d esta siendo utilizada", list[i].id);
		}
		if(list[i].isEmpty==0){
			strncpy(list[i].name,name,strLength);
			strncpy(list[i].lastName,lastName,strLength);
			list[i].salary=*salary;
			list[i].sector=*sector;
			list[i].isEmpty=1;
			list[i].id=i+1;
			break;
		}
	}
}
return retorno;
}
/*La funcion findEmployeeByID,Busca un empleado en un array, segun el id del mismo.
 *  Recibe como parametros un array de tipo Employee y el largo maximo. Ademas recibe dos punteros, uno con el id a buscar y otro con la posicion en la que este id se encuentra dentro del array.
 * Devuelve -1 si el array es nulo o si no tiene ningun elemento ingresado
 * Devuelve 0 si puede ubicar el id dentro del array, y guarda en el puntero position, la posicion en la que se encuentra el id dentro del array
 */
int findEmployeeById(Employee list[],int length,int *pId,int *position)
{
int retorno =-1;
int i;
int id=*pId;
if(list!=NULL && length>0)
{
	for(i=0;i<length;i++) //recorre el array hasta que i = a
	{
		if(list[i].isEmpty==0)
		{
			continue; //si la posicion i de la lista esta vacia (isEmpty==0), sigue con al siguiente
		}
		else if(list[i].id==id)//si la posicion de la lista i, el id es = al id buscado.
		{
			retorno=0;
			*position=i; //devuelve en id la posicion en el array
		}
	}
}


	return retorno;
}

/*La funcion printEmployeByID imprime un unico empleado de entre un array de tipo empleados según el id del mimso.
 *Recibe como parametros, el Array de tipo employee, el largo maximo del array, y el id a buscar.
 *Devuelve -1 si el array es nulo o si no hay ningun elemento ingresado.
 *Devuelve 0 si encuentra un id en el array que coincida con el ingresado y lo imprime por consola.
 */
int printEmployeById(Employee list[],int length, int *id)
{
	int retorno =-1;
	int i;
	int buffer = *id;

	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].id==buffer)
			{
				printf("\n****************************************");

				printf("\n Id Empleado: %d", list[i].id);
				printf("\n nombre Empleado: %s", list[i].name);
				printf("\n Apellido Empleado: %s", list[i].lastName);
				printf("\n salario Empleado: %.2f", list[i].salary);
				printf("\n sector Empleado: %d\n", list[i].sector);
				printf("\n****************************************\n");

				retorno=0;

				break;
			}
		}
	}


	return retorno;
}
/*la funcion printEmployees imprime un array entero, del tipo employee.
 * Recibe como parametros un Array de tipo employee y el largo maximo del array
 * Devuelve -1 si el array es nulo o si no tiene ningun elemento ingresado
 * Devuelve 0 si puede imprimir el array
 */
int printEmployees(Employee list[], int length)
{
int i, retorno =-1;
	if(list!=NULL && length>0)
	{
		printf("\nid\t nombre y apellido \t salario\t sector");
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==1)
			{
				printf("\n****************************************\n");
				printf("%2d \t %s %s \t%.2f \t%d", list[i].id, list[i].name, list[i].lastName,list[i].salary, list[i].sector);
				printf("\n****************************************\n");
			}
		}
		retorno=0;
	}

	return retorno;
}
/*La funcion sortEmployeesByLastName sirve para ordenar los empleados. Primero los ordena segun el apellido, y si son iguales, los ordena segun el sector. Puede ser ordenado de Mayor a Menor o Visceversa.
 * Recibe como parametros un Array de tipo Employee, el largo maximo del array, el largo maximo de la cadena de caracteres del apellido y una opcion (1 o 0) para definir si se ordena de Mayor a Menor o visceversa.
 * Devuelve -1 si el array es nulo o si no tiene ingresado ningun elemento. o 0 si puede imprimir los elementos del array.
 *
 */
int sortEmployeesByLastName(Employee list[], int length,int strLength, int option)
{
int i,j;
int flagCambio=-1;
int retorno=-1;

Employee buffer;

	if(list!=NULL && length>0)
	{
		switch(option)
		{
		case 0:
			while(flagCambio==-1)
			{
			flagCambio=0;
				for(i=length;i>0;i--)
				{
					for(j=length;j>0;j--)
					{
						if(list[j].isEmpty!=0)
						{
							if(strcmp(list[j].lastName,list[j-1].lastName)==0)
							{
								if(list[j].sector<list[j-1].sector)
								{
									buffer = list[j];
									list[j] = list[j-1];
									list[j-1]=buffer;
									flagCambio=-1;
								}
							}
							else if(strcmp(list[j].lastName,list[j-1].lastName)<0)
							{
								buffer = list[j];
								list[j] = list[j-1];
								list[j-1]=buffer;
								flagCambio=-1;
							}
						}
					}
				}
			return retorno;
			}
			break;
		case 1:
			while(flagCambio==-1)
			{
				flagCambio=0;
				for(i=0;i<length;i++)
				{
					for(j=0;j<length;j++)
					{
						if(list[j].isEmpty!=0)
						{
							if(strcmp(list[j].lastName,list[j+1].lastName)==0)
							{
								if(list[j].sector>=list[j+1].sector)
								{
									continue;
								}
								else if(list[j].sector<list[j+1].sector)
								{

									buffer = list[j];
									list[j] = list[j+1];
									list[j+1]=buffer;
									flagCambio=-1;
								}
							}
						else if(strcmp(list[j].lastName,list[j+1].lastName)>0)
							{
								continue;
							}
							else if(strcmp(list[j].lastName,list[j+1].lastName)<0)
							{
								buffer = list[j];
								list[j] = list[j+1];
								list[j+1]=buffer;
								flagCambio=-1;
							}
						}
					}
				}
			}

			retorno=0;
			break;


		default:
			printf("solo se puede ordenar de mayor a menor o vicebersa");
			retorno=-1;
		break;
		}
	}
	return retorno;
}

/*La funcion totalSalary sirve para calcular la suma total del salario de todos los empleados.
 * Recibe como parametros un array de tipo Employee, el largo maximo y un puntero para guardar la suma total de los salarios.
 * devuelve -1 si el array es nulo o si no tiene cargado elementos, o 0 si puede calcular exitosamente la suma total de salarios
 */
int totalSalary(Employee list[],int length,float *pTotalSalary)
{
	int i;
	float acumSalary=0;
	int retorno =-1;

	if(list!=NULL && length>0)
		{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==1)
			{
			acumSalary = acumSalary + list[i].salary;
			retorno=0;
			}
		}
		}

	*pTotalSalary=acumSalary;
return retorno;
}
/*la funcion employeeCounter cuenta la cantidad total de empleados activos dentro de un Array de empleados
 * Recibe un array de tipo empelados, el largo maximo del array y un puntero donde guarda la suma total de los empleados.
 * devuelve -1 si el array es nulo o si no tiene cargado elementos, o 0 si puede contarlos exitosamente
 */
int employeeCounter(Employee list[], int length, int *pCountEmployee)
{
int i, contEmployee=0,retorno =-1;
	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==1)
			{
				contEmployee++;
				retorno=0;
			}
		}
	}
	*pCountEmployee=contEmployee;
	return retorno;
}
/*La funcion employeesAverageSalary sirve para calcular el salario promedio de todos los empleados.
 * Recibe como parametros un array de tipo Employee, el largo maximo del array, un puntero de tipo flotante con la suma total de los salarios,
 * un entero con la suma total de empleados y un puntero de tipo float donde guarda el promedio de salarios.
 * devuelve -1 si el array es nulo o si no tiene cargado elementos, o 0 si puede realizar el calculo con exito.
 */
int employeesAverageSalary(Employee list[], int lenght, float *pTotalSalary, int *pCountEmployees, float *pAverSalary)
{
int retorno=-1;
int countEmployees=*pCountEmployees;
float buffer;
float totalSalary=*pTotalSalary;

	if(pTotalSalary==0 || countEmployees ==0)
	{
		printf("no se puede dividir por 0");
		return retorno;
	}
	buffer = totalSalary/countEmployees;
	*pAverSalary=buffer;
	retorno=0;
	return retorno;
}

int cargarValores(Employee lista[])
{

	strncpy(lista[0].name,"pepe",51);
	strncpy(lista[0].lastName,"argento",51);
	lista[0].sector = 2;
	lista[0].salary = 15000;
	lista[0].isEmpty=1;
	lista[0].id=1;

	strncpy(lista[1].name,"moni",51);
	strncpy(lista[1].lastName,"argento",51);
	lista[1].sector = 4;
	lista[1].salary = 25000;
	lista[1].isEmpty=1;
	lista[1].id=2;

	strncpy(lista[2].name,"coki",51);
	strncpy(lista[2].lastName,"argento",51);
	lista[2].sector = 3;
	lista[2].salary = 15000;
	lista[2].isEmpty=1;
	lista[2].id=3;

	strncpy(lista[3].name,"pepe",51);
	strncpy(lista[3].lastName,"gonzalez",51);
	lista[3].sector = 2;
	lista[3].salary = 40000;
	lista[3].isEmpty=1;
	lista[3].id=4;

	strncpy(lista[4].name,"ignacio",51);
	strncpy(lista[4].lastName,"canay",51);
	lista[4].sector = 2;
	lista[4].salary = 15000;
	lista[4].isEmpty=1;
	lista[4].id=5;

return 0;
}


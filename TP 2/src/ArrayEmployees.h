/*
 * ArrayEmployees.h
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */




#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

int initEmployees(Employee list[],int length);
int addEmployees(Employee list[], int length,int id, char name[], char lastName[],int strLength, float *salary, int *sector);
int findEmployeeById(Employee list[],int length,int *pId,int *position);
int printEmployeById(Employee list[],int length, int *id);
int printEmployees(Employee list[], int length);
int sortEmployeesByLastName(Employee list[], int length,int strLength, int option);
int totalSalary(Employee list[],int length,float *pTotalSalary);
int employeeCounter(Employee list[], int length, int *pCountEmployee);
int employeesAverageSalary(Employee list[],int lenght,float *pTotalSalary,int *pCountEmployees, float *pAverSalary);

int cargarValores(Employee lista[]);
#endif /* ARRAYEMPLOYEES_H_ */

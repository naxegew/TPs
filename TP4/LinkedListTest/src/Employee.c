#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn_lib.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new() {
	Employee *employee;
	employee = (Employee*) malloc(sizeof(Employee));
	if (employee == NULL) {
		printf("no hay memoria");
	}

	return employee;
}
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *employee;
	int axId, axHsTrabajadas, axSueldo;

	employee = (Employee*) malloc(sizeof(Employee));
	if (employee == NULL) {
		printf("no hay memoria");
	}
	axId = atoi(idStr);
	employee_setId(employee, axId);

	//aca van los sets

	employee_setNombre(employee, nombreStr);
	if (atoi(horasTrabajadasStr) != 0) {
		axHsTrabajadas = atoi(horasTrabajadasStr);
	}
	employee_setHorasTrabajadas(employee, axHsTrabajadas);

	if (atoi(sueldoStr) != 0) {
		axSueldo = atoi(sueldoStr);
	}
	employee_setSueldo(employee, axSueldo);

	return employee;
}

int employee_setId(Employee *this, int id) {
	int retorno = -1;

	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int employee_setNombre(Employee *this, char *nombre) {
	int retorno = -1;

	if (nombre != NULL && strlen(nombre) > 0) {
		if (isValidAlphabetic(nombre) == 0) {
			strncpy(this->nombre, nombre, strlen(nombre));
			retorno = 0;
		}
	}

	return retorno;

}
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno = -1;

	if (this != NULL && horasTrabajadas > 0) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}
int employee_setSueldo(Employee *this, int sueldo) {
	int retorno = -1;

	if (this != NULL && sueldo > 0) {
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}
int getEmployeeParamName(char* name)
{
	int retorno = -1;
	char axName[128];

	getStr(axName,128,"ingrese el nombre del empleado");

	strncpy(name,axName,128);

	return retorno;
}
int getEmployeeParamWorkedHs(int *workedHs)
{
	int retorno = -1;
	int axWkdHs;

	(getInt(&axWkdHs, "Ingrese la cantidad de horas de trabajo", "Error en el ingreso de datos vuelva a intentar",1,200,3));

	*workedHs = axWkdHs;
	return retorno;
}
int getEmployeeParamSueldo(int *sueldo)
{
	int retorno = -1;
	int axSueldo;

	(getInt(&axSueldo, "Ingrese el sueldo", "Error en el ingreso de datos vuelva a intentar",1,300000,3));

	*sueldo=axSueldo;
			return retorno;
}
int getEmployeeParamId(LinkedList* pArrayListEmployee,int *id)
{
int retorno = -1;
int axId=0;

axId = ll_len(pArrayListEmployee)+1;

*id=axId;

return retorno;
}

Employee* employee_newParametrosConsole(int *id, char *nombre,
		int *horasTrabajadas, int *sueldo) {
	Employee *employee;
	int axId =*id,axHsTrabajadas=*horasTrabajadas, axSueldo=*sueldo;

	employee = (Employee*) malloc(sizeof(Employee));
	if (employee == NULL) {
		printf("no hay memoria");
	}

	employee_setId(employee, axId);

	employee_setNombre(employee, nombre);

	employee_setHorasTrabajadas(employee, axHsTrabajadas);

	employee_setSueldo(employee, axSueldo);

	return employee;
}
Employee* employee_findById(LinkedList* pArrayListEmployee)
{
	Employee* retorno = NULL;
	Employee* pEmployee;
	int i,id;
	int len;
	len=ll_len(pArrayListEmployee);
	printf("\nel largo de la lista es: %d", len);

	getInt(&id,"\nIngrese el Id a Buscar","\nerror ingreso un numero de id invalido",0,len+1,3);

	for(i=0;i<len;i++)
	{
		pEmployee=ll_get(pArrayListEmployee, i);
		if(pEmployee->id == id)
		{

			retorno = pEmployee;
		}
	}

	return retorno;
}

int employee_print(Employee *this)
{
	int retorno =-1;
	printf("\n| id  |\t Nombre \t|Hs trabajadas| sueldo ");
	printf("\n|%4d| %s\t |%d hs \t| $ %d |", this->id,this->nombre,this->horasTrabajadas, this->sueldo);


	return retorno;

}
int employee_criterio(void* var1,void* var2)
{

Employee* employee1 = (Employee*)var1;
Employee* employee2 = (Employee*)var2;
int r,retorno=0;
printf("\nnombre 1 %s nombre 2 %s",employee1->nombre,employee2->nombre);
r = strcmp(employee1->nombre,employee2->nombre);
if(r<0)
{
	retorno =-1;
}else
{
	retorno =1;
}
//printf("retorno es: %d *-------",retorno);
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int buffer,retorno=-1;
	if (this != NULL && id > 0)
	{
		buffer=this->id;
		*id=buffer;
		retorno =0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

	int buffer,retorno=-1;
	if (this != NULL && horasTrabajadas > 0)
	{
		buffer=this->horasTrabajadas;
		*horasTrabajadas=buffer;
		retorno =0;
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int buffer,retorno=-1;
	if (this != NULL && sueldo > 0)
	{
		buffer=this->sueldo;
		*sueldo=buffer;
		retorno =0;
	}
	return retorno;

}
int employee_getNombre(Employee* this,char* nombre)
{

	int retorno = -1;
	char buffer[128];

	if (this != NULL && nombre > 0)
	{
		strncpy(buffer,this->nombre,128);
		strncpy(nombre,buffer,128);
		retorno =0;
	}
	return retorno;
}
int employee_delete(Employee* this)
{
	int retorno =-1;
		free(this);
		return retorno;
}
int employeeList_init(LinkedList* pArrayListEmployee)
{

	return ll_clear(pArrayListEmployee);
}


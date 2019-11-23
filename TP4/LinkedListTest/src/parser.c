#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int r;
	char id[5], horasTrabajadas[4], sueldo[7], header[200];
	char nombre[128];
	Employee * newEmployee;

	fscanf(pFile, "%[^\n]\n", header);
			printf("%s\n", header);
			do
			{
			r=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas, sueldo);
			if(r==4)
			{
				printf("%s %s %s %s \n",id, nombre, horasTrabajadas, sueldo);
				//aca newemployee
				newEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				//aca uso el add del inked list para agregar el empleado
				ll_add(pArrayListEmployee,newEmployee);

			}

		}while(!feof(pFile));


    return 1;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int leyo=0;
	int i,id,sueldo,hsTrabajadas;
	char nombre[128];
	Employee* employee;


	do
	{

		employee=employee_new();
	leyo=+fread(employee,sizeof(Employee),1,pFile);
	if(leyo!=0)
	{
		ll_add(pArrayListEmployee,employee);
	}

	}while(!feof(pFile));


	for(i=0;i<=pArrayListEmployee->size;i++)
	{
		employee =ll_get(pArrayListEmployee,i);
		employee_getId(employee,&id);
		employee_getSueldo(employee,&sueldo);
		employee_getHorasTrabajadas(employee,&hsTrabajadas);
		employee_getNombre(employee,nombre);

		printf("\n|%d|%s|%d hs|$ %d |",id,nombre,hsTrabajadas,sueldo);

	}

	return 1;
}

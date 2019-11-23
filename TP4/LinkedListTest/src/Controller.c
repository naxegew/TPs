#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn_lib.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

	FILE* pFile;


	pFile = fopen(path,"r");

		if(pFile==NULL)
		{
			printf("El archivo no existe");
			 exit(EXIT_FAILURE);
		}
		ll_clear(pArrayListEmployee);
		parser_EmployeeFromText(pFile,pArrayListEmployee);


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;


	pFile = fopen("data.bin","rb");
	employeeList_init(pArrayListEmployee);
	parser_EmployeeFromBinary(pFile,pArrayListEmployee);
	fclose(pFile);


    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	char name[128];
	int workedHs,sueldo,id;
	Employee* employee;

	getEmployeeParamName(name);
	getEmployeeParamWorkedHs(&workedHs);
	getEmployeeParamSueldo(&sueldo);
	getEmployeeParamId(pArrayListEmployee,&id);
	printf("\n%d | %d  | %s  | %d ", id, workedHs,name, sueldo);
	employee=employee_newParametrosConsole(&id,name,&workedHs,&sueldo);
	ll_add(pArrayListEmployee,employee);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* employee;
	int option;
	int buffer;
	char axName[128];
	employee=employee_findById(pArrayListEmployee);
	 employee_print(employee);
	 modificarEmpleadoMenu(&option);
	 switch(option)
	 {
	 case 1:
		 getStr(axName,128,"ingrese el nombre");
		 employee_setNombre(employee,axName);


		 break;
	 case 2:
		 getInt(&buffer,"Ingrese las horas trabajadas" ,"Error vuelva a intentar",0,
		 		200,3);
		 employee_setHorasTrabajadas(employee,buffer);

	 		 break;
	 case 3:
		 getInt(&buffer,"Ingrese el nuevo sueldo" ,"Error vuelva a intentar",0,
				 		300000,3);
		 employee_setSueldo(employee,buffer);
	 		 break;
	 case 4:
		 return 1;
	 		 break;
	 default:
	 		 break;

	 }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* employee;
	Employee* axEmployee;
	int len,i;
	char SoN;
	employee=employee_findById(pArrayListEmployee);

	len=ll_len(pArrayListEmployee);
	do{
	getChar(&SoN,"\ndesea borrar a este empleado? (s o n): ");
	}while(SoN!='s' && SoN!='n');

	if(SoN=='s')
	{
		for(i=0;i<len;i++)
		{
			axEmployee = ll_get(pArrayListEmployee,i);

			if(axEmployee == employee)
			{
				ll_remove(pArrayListEmployee,i);
				printf("\nEl empleado fue removido con exito.");
				return 0;
			}
		}
	}


    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i,id,sueldo,hsTrabajadas;
	char nombre[128];
	Employee* employee;

printf("\nid|nombre|hsTrab|sueldo|");
	for(i=0;i<pArrayListEmployee->size;i++)
	{

		employee =ll_get(pArrayListEmployee,i);
		employee_getId(employee,&id);
		employee_getSueldo(employee,&sueldo);
		employee_getHorasTrabajadas(employee,&hsTrabajadas);
		employee_getNombre(employee,nombre);

		printf("\n|%d|%s\t|%d hs\t|$ %d\t |",id,nombre,hsTrabajadas,sueldo);

	}

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int sort;

	sort = ll_sort(pArrayListEmployee,employee_criterio,1);
	printf("%d sort",sort);
	controller_ListEmployee(pArrayListEmployee);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int len = ll_len(pArrayListEmployee);
	int i,id,hsTrabajadas,sueldo;
	char nombre[128];
	Employee* employee;


	pFile = fopen(path,"w");

		if(pFile==NULL)
		{
			printf("El archivo no existe");
			 exit(EXIT_FAILURE);
		}
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		for(i=0;i<len;i++)
		{

			employee =ll_get(pArrayListEmployee,i);
			employee_getId(employee,&id);
			employee_getSueldo(employee,&sueldo);
			employee_getHorasTrabajadas(employee,&hsTrabajadas);
			employee_getNombre(employee,nombre);
			fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,hsTrabajadas,sueldo);
		}

		fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;

		int i,cantidadEscrita,id,sueldo,hsTrabajadas;
		char nombre[128];
		Employee employeeAuxiliar;
		Employee* employee;


		pFile = fopen(path,"wb");

			if(pFile==NULL)
			{
				printf("El archivo no existe");
				 exit(EXIT_FAILURE);
			}

			for(i=0;i< pArrayListEmployee->size ;i++)
			{
				employee =ll_get(pArrayListEmployee,i);
				employee_getId(employee,&id);
				employee_getSueldo(employee,&sueldo);
				employee_getHorasTrabajadas(employee,&hsTrabajadas);
				employee_getNombre(employee,nombre);


					employeeAuxiliar.id=id;
					employeeAuxiliar.sueldo=sueldo;
					employeeAuxiliar.horasTrabajadas=hsTrabajadas;
					strncpy(employeeAuxiliar.nombre,nombre,128);

				printf("\nse escribio %d, veces",i);

			cantidadEscrita=fwrite(&employeeAuxiliar,sizeof(Employee),1,pFile);
				if(cantidadEscrita<1)
				{
				printf("error al escribir el archivo .bin");
				}
			}

			fclose(pFile);

    return 1;
}

int controller_cloneEmployeeList(LinkedList* pArrayListEmployee, LinkedList* clonePArrayListEmployee)
{
	int retorno =-1;


	clonePArrayListEmployee = ll_clone(pArrayListEmployee);
	if(clonePArrayListEmployee != NULL)
	{
		printf("lista clonada: ");
		controller_ListEmployee(clonePArrayListEmployee);
		retorno =0;
	}

	return retorno;
}
int controller_compare(LinkedList* pArrayListEmployee,LinkedList* clonePArrayListEmployee)
{
	int retorno = -1,r;
	r= ll_containsAll(pArrayListEmployee,clonePArrayListEmployee);

	 if(r==1)
	 {
		 printf("las listas son iguales");

	 }else if(r==0)
	 {
		 printf("las listas difieren en algun elemento");
	 }else if(r ==-1)
	 {
		 printf("la verificacion fallo o no se encontro elemento");
	 }


	 return retorno;

}
int controller_pop(LinkedList* pArrayListEmployee)
{
	int retorno = -1, index;
	int id,sueldo,hsTrabajadas;
	char nombre[128];
	Employee* employee;
	getInt(&index,"ingrese el indice del empleado a remover","indice incorrecto, intente de nuevo",0,
	ll_len(pArrayListEmployee),3);
	employee = ll_pop(pArrayListEmployee,index);
	employee_getId(employee,&id);
	employee_getSueldo(employee,&sueldo);
	employee_getHorasTrabajadas(employee,&hsTrabajadas);
	employee_getNombre(employee,nombre);

	printf("\n|%d|%s|%d hs|$ %d |",id,nombre,hsTrabajadas,sueldo);

	return retorno;
}
int controller_delete(LinkedList* pArrayListEmployee)
{
	int retorno =-1;

	retorno = ll_deleteLinkedList(pArrayListEmployee);
	if(retorno == 0)
	{
		printf("se elimino una lista que contenia elementos");
	}else if(retorno ==1)
	{
		printf("la lista esta vacia");
	}else if(retorno == -1)
	{
		printf("no se encontro la lista para borrar");
	}

	return retorno;
}
int controller_sublist(LinkedList* pArrayListEmployee,LinkedList* pArraySublistEmployee)
{
	int retorno =-1;
	int from,to;


	getInt(&from,"ingrese el indice del comienzo de la lista","Error vuelva a intentar",0,ll_len(pArrayListEmployee),3);
	getInt(&to,"ingrese el indice del final de la lista","Error vuelva a intentar",from,ll_len(pArrayListEmployee),3);

	pArraySublistEmployee= ll_subList(pArrayListEmployee,from,to);

	controller_ListEmployee(pArraySublistEmployee);

	return retorno;
}



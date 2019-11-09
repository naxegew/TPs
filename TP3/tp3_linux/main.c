#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_lib.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


/*
int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};
*/
/*
 * int main()
{

	LinkedList* pArrayListEmployee;
	//Employee* employee;
	//int id=30;


	controller_loadFromText("data.csv",pArrayListEmployee);


	//printf("%d %d %d",course,lets,find);

	return 0;

}
*/


int main()
{
    int option;

    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
    	mainMenu(&option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("data.bin",listaEmpleados);

            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);

            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	// ordenar
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	//guardar en data2.csv
            	controller_saveAsText("da.csv",listaEmpleados);
            	break;
            case 9:
            	//guardar en data.bin
            	controller_saveAsBinary("data.bin",listaEmpleados);
            	break;
            case 10:
            	break;
            default:
            	break;
        }
    }while(option != 10);
    return 0;
}


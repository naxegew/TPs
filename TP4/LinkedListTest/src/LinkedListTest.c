/*
 ============================================================================
 Name        : LinkedListTest.c
 Author      : Ignacio Martin Canay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_lib.h"

int main()
{
    int option;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* clonListaEmpleados = ll_newLinkedList();
    LinkedList* subListaEmpleados = ll_newLinkedList();

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
            	controller_saveAsText("data.csv",listaEmpleados);
            	break;
            case 9:
            	//guardar en data.bin
            	controller_saveAsBinary("data.bin",listaEmpleados);
            	break;
            case 10: //ll_clone
            	controller_cloneEmployeeList(listaEmpleados,clonListaEmpleados);
            	break;
            case 11: // llpop
            	controller_pop(listaEmpleados);
                       	break;
            case 12: //ll_delete
            	 controller_delete(clonListaEmpleados);
                       	break;
            case 13: //ll_containst off
            	controller_compare(clonListaEmpleados,listaEmpleados);
                       	break;
            case 14: // ll sublist
            	controller_sublist(listaEmpleados,subListaEmpleados);
                       	break;
            default:
            	break;
        }
    }while(option != 15);
    return 0;
}

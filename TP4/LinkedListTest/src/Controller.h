int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_cloneEmployeeList(LinkedList* pArrayListEmployee, LinkedList* clonePArrayListEmployee);
int controller_compare(LinkedList* pArrayListEmployee,LinkedList* clonePArrayListEmployee);
int controller_pop(LinkedList* pArrayListEmployee);
int controller_delete(LinkedList* pArrayListEmployee);
int controller_sublist(LinkedList* pArrayListEmployee,LinkedList* pArraySublistEmployee);



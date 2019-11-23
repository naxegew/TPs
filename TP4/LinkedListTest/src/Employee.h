#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*mines*-*-*-*-*--*-*-*-*-*-*
int getEmployeeParamName(char* name);
int getEmployeeParamWorkedHs(int *workedHs);
int getEmployeeParamSueldo(int *sueldo);
int getEmployeeParamId(LinkedList* pArrayListEmployee,int *id);
Employee* employee_newParametrosConsole(int *id, char *nombre,
		int *horasTrabajadas, int *sueldo);
Employee* employee_findById(LinkedList* pArrayListEmployee);
int employee_print(Employee* this);
int employee_criterio(void* var1,void* var2);
int employeeList_init(LinkedList* pArrayListEmployee);


#endif // employee_H_INCLUDED

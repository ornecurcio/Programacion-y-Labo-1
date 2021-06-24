#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int dia;
	char horario[128];
    int sala;
    int cantidad;
    float facturacion;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* diaStr,char* horarioStr,char* salaStr, char* cantidadStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setDia(Employee* this,int dia);
int employee_getDia(Employee* this,int* dia);

int employee_setHorario(Employee* this,char* horario);
int employee_getHorario(Employee* this,char* horario);

int employee_setSala(Employee* this,int sala);
int employee_getSala(Employee* this,int* sala);

int employee_setCantidad(Employee* this,int cantidad);
int employee_getCantidad(Employee* this,int* cantidad);

int employee_setFacturacion(Employee* this,float facturacion);
int employee_getFacturacion(Employee* this,float* facturacion);

void employee_print(Employee* this);

//int employee_sortId(void* thisOne, void* thisTwo);
//int employee_sortSueldo(void* thisOne, void* thisTwo);
//int employee_sortHoras(void* thisOne, void* thisTwo);
int employee_sortNombre(void* thisOne, void* thisTwo);
//
void employee_putIn(void* this);
//void employee_putDis(void* this);
int employee_putSala(void* this, int sala);
#endif // employee_H_INCLUDED

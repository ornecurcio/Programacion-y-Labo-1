#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "UTN.h"

void employee_delete(Employee* this)
{
	free(this);
}
Employee* employee_new()
{
	Employee* pAux=NULL;
	pAux=(Employee*)malloc(sizeof(Employee));
	if(pAux!=NULL)
	{
		pAux->id=0;
		strcpy(pAux->nombre,"");
		pAux->dia=0;
		strcpy(pAux->horario,"");
		pAux->sala=0;
		pAux->cantidad=0;
		pAux->facturacion=0;
	}
	return pAux;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* diaStr,char* horarioStr,char* salaStr, char* cantidadStr)
{
	Employee* pAuxEmpleado = employee_new();
	if(pAuxEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horarioStr!=NULL && diaStr!=NULL && salaStr!=NULL && cantidadStr!=NULL)
	{
		if((employee_setId(pAuxEmpleado,atoi(idStr))!=0) ||
		(employee_setNombre(pAuxEmpleado,nombreStr)!=0) ||
		(employee_setHorario(pAuxEmpleado,horarioStr)!=0) ||
		(employee_setDia(pAuxEmpleado,atoi(diaStr))!=0) ||
		(employee_setCantidad(pAuxEmpleado,atoi(cantidadStr))!=0) ||
		(employee_setSala(pAuxEmpleado,atoi(salaStr))!=0))
		{
			free(pAuxEmpleado);
			pAuxEmpleado=NULL;
		}
	}
	return pAuxEmpleado;
}
int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=0;
 	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}
int employee_setDia(Employee* this,int dia)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->dia=dia;
		retorno=0;
	}
	return retorno;
}
int employee_getDia(Employee* this,int* dia)
{
	int retorno=-1;
	if(this!=NULL && dia!=NULL)
	{
		*dia=this->dia;
		retorno=0;
	}
	return retorno;
}
int employee_setHorario(Employee* this,char* horario)
{
	int retorno=-1;
	if(this!=NULL && horario!=NULL)
	{
		strcpy(this->horario,horario);
		retorno=0;
	}
	return retorno;
}
int employee_getHorario(Employee* this,char* horario)
{
	int retorno=-1;
	if(this!=NULL && horario!=NULL)
	{
		strcpy(horario,this->horario);
		retorno=0;
	}
	return retorno;
}
int employee_setSala(Employee* this,int sala)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->sala=sala;
		retorno=0;
	}
	return retorno;
}
int employee_getSala(Employee* this,int* sala)
{
	int retorno=-1;
	if(this!=NULL && sala!=NULL)
	{
		*sala=this->sala;
		retorno=0;
	}
	return retorno;
}
int employee_setCantidad(Employee* this,int cantidad)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->cantidad=cantidad;
		retorno=0;
	}
	return retorno;
}
int employee_getCantidad(Employee* this,int* cantidad)
{
	int retorno=-1;
	if(this!=NULL && cantidad!=NULL)
	{
		*cantidad=this->cantidad;
		retorno=0;
	}
	return retorno;
}
int employee_setFacturacion(Employee* this,float facturacion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->facturacion=facturacion;
		retorno=0;
	}
	return retorno;
}
int employee_getFacturacion(Employee* this,float* facturacion)
{
	int retorno=-1;
	if(this!=NULL && facturacion!=NULL)
	{
		*facturacion=this->facturacion;
		retorno=0;
	}
	return retorno;
}

void employee_print(Employee* this)
{
	int auxId, auxDia, auxSala, auxCantidad;
	float auxFacturacion;
	char auxNombre[128], auxHora[128], auxDayStr[128];
	if(employee_getId(this, &auxId)==0 && employee_getNombre(this, auxNombre)==0 &&
	   employee_getHorario(this, auxHora)==0 && employee_getDia(this, &auxDia)==0 &&
	   employee_getSala(this, &auxSala)==0 && employee_getCantidad(this, &auxCantidad)==0 &&
	   employee_getFacturacion(this, &auxFacturacion)==0 && utn_putDay(auxDia, auxDayStr)==0)
	{
		printf("Id: %d - Nombre: %s - Dia: %s - Horario: %s\n",auxId, auxNombre,auxDayStr,auxHora);
		//printf("Id: %d - Nombre: %s - Dia: %d - Horario: %s - Sala: %d - Cantidad: %d - Facturacion: %.2f\n",auxId, auxNombre,auxDia,auxHora, auxSala, auxCantidad, auxFacturacion);
	}
	//printf("Id: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n",(*(this)).id, (*(this)).nombre,(*(this)).horasTrabajadas, (*(this)).sueldo);
}
//int employee_sortId(void* thisOne, void* thisTwo)
//{
//	int retorno=0;
//	int auxId1, auxId2;
//
//	if(thisOne!=NULL && thisTwo!=NULL)
//	{
//		if(employee_getId((Employee*)thisOne, &auxId1)==0 && employee_getId((Employee*)thisTwo, &auxId2)==0)
//		{
//			if(auxId1 > auxId2)
//			{
//				retorno=1;
//			}
//			if( auxId1 < auxId2 )
//			{
//				retorno=-1;
//			}
//		}
//	}
//	return retorno;
//}
//int employee_sortSueldo(void* thisOne, void* thisTwo)
//{
//	int retorno=0;
//	int auxSueldo1, auxSueldo2;
//
//	if(thisOne!=NULL && thisTwo!=NULL)
//	{
//		if(employee_getSueldo((Employee*)thisOne, &auxSueldo1)==0 && employee_getSueldo((Employee*)thisTwo, &auxSueldo2)==0)
//		{
//			if(auxSueldo1 > auxSueldo2)
//			{
//				retorno=1;
//			}
//			if(auxSueldo1 < auxSueldo2)
//			{
//				retorno=-1;
//			}
//		}
//	}
//	return retorno;
//}
//int employee_sortHoras(void* thisOne, void* thisTwo)
//{
//	int retorno=0;
//
//	int auxHoras1, auxHoras2;
//	if(thisOne!=NULL && thisTwo!=NULL)
//	{
//		if(employee_getHorasTrabajadas((Employee*)thisOne, &auxHoras1)==0 && employee_getHorasTrabajadas((Employee*)thisTwo, &auxHoras2)==0)
//		{	if(auxHoras1 > auxHoras2)
//			{
//				retorno=1;
//			}
//			if(auxHoras1 < auxHoras2)
//			{
//				retorno=-1;
//			}
//		}
//	}
//	return retorno;
//}
//int employee_sortNombre(void* thisOne, void* thisTwo)
//{
//	int retorno=0;
//	char auxNombre1[128],auxNombre2[128];
//	if(thisOne!=NULL && thisTwo!=NULL)
//	{
//		if(employee_getNombre((Employee*)thisOne, auxNombre1)==0 && employee_getNombre((Employee*)thisTwo, auxNombre2)==0)
//		{
//			if(strcmp(auxNombre1,auxNombre2)>0)
//			{
//				retorno=1;
//			}
//			if(strcmp(auxNombre1,auxNombre2)<0)
//			{
//				retorno=-1;
//			}
//		}
//	}
//	return retorno;
//}
void employee_putIn(void* this)
{
	int auxDia;
	float auxFacturacion;
	int auxCantidad;
	if(employee_getDia((Employee*)this, &auxDia)==0)
	{
		if(auxDia==1 || auxDia==2 || auxDia==3)
		{
			employee_getCantidad(this, &auxCantidad);
			auxFacturacion=(float)auxCantidad*240;
			employee_setFacturacion(this, auxFacturacion);
		}
		else
		{
			employee_getCantidad(this, &auxCantidad);
			auxFacturacion=(float)auxCantidad*340;
			employee_setFacturacion(this, auxFacturacion);
		}
	}
	if(employee_getCantidad((Employee*)this, &auxCantidad)==0 && auxCantidad>=3)
	{
		auxFacturacion=auxFacturacion-(10*auxFacturacion/100);
		employee_setFacturacion(this, auxFacturacion);
	}
}
//void employee_putDis(void* this)
//{
//	int auxSueldo;
//	if(employee_getSueldo((Employee*)this, &auxSueldo)==0 && auxSueldo>50000)
//	{
//		auxSueldo=auxSueldo-(10*auxSueldo/100);
//		employee_setSueldo(this, auxSueldo);
//	}
//}

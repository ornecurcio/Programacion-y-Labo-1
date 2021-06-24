#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN.h"
int menu(void)
{
		int option;
	    int flag=0;
	    char* path=NULL;
	    int flag2=0;
	    path=(char*)calloc(20,sizeof(char));
	    LinkedList* listaEmpleados = ll_newLinkedList();
	    printf("------------ /BIENVENIDO/ -------------\n");
	    do{
	    	if(utn_getNumero(&option,"-------- Seleccione una opcion --------\n"
	    			"1. Cargar Archivo\n"
	    			"2. Imprimir Ventas\n"
	    			"3. Generar Archivo de montos\n4. Informes\n5. Salir\n",
	    					"------- Error ingrese ------ \n"
					"1. Cargar Archivo\n"
				    "2. Imprimir Ventas\n"
				    "3. Generar Archivo de montos\n4. Informes\n5. Salir\n", 1, 11, 2)==0){
				switch(option)
				{
					case 1:
						if(flag==0)
						{
							utn_getNumero(&flag, "Desea abrir: \n1. Data.csv \n2. Otro", "Error, opcion incorrecta", 1, 2, 1);
							switch(flag)
							{
							case 1:
								controller_loadFromText("Data.csv",listaEmpleados);
								controller_putInDisEmployee(listaEmpleados);
								break;
							case 2:
								if(utn_getArchivo(path)==0)
								{
									controller_loadFromText(path,listaEmpleados);
									controller_putInDisEmployee(listaEmpleados);
								}
								break;
							}
						}
						else
						{
							printf("El archivo ya fue cargado");
						}
						break;
//					case 2:
//						if(flag==0)
//						{
//							utn_getNumero(&flag, "Desea abrir: \n1. data.bin \n2.Chequeo.bin", "Error, opcion incorrecta", 1, 2, 1);
//							switch(flag)
//							{
//							case 1:
//								controller_loadFromBinary("data.bin",listaEmpleados);
//								break;
//							case 2:
//								controller_loadFromBinary("Chequeo.bin",listaEmpleados);
//								break;
//							}
//						}
//						else
//						{
//							printf("El archivo ya fue cargado\n");
//						}
//
//						break;
//					case 3:
//						controller_addEmployee(listaEmpleados);
//						break;
//					case 4:
//						controller_editEmployee(listaEmpleados);
//						break;
//					case 5:
//						controller_removeEmployee(listaEmpleados);
//						break;
					case 2:
						if(flag!=0)
						{
							controller_ListEmployee(listaEmpleados);
						}
						else
						{
							printf("Primero debe cargar un archivo\n");
						}
						break;
//					case 7:
//						controller_sortEmployee(listaEmpleados);
//						printf("Desea imprimir lista ordenada. ");
//						if(utn_getCaracterSN()==0)
//						{
//							controller_ListEmployee(listaEmpleados);
//						}
//						break;
					case 3:
						if(flag!=0)
						{
							utn_getNumero(&flag2, "Desea guardar en: \n1. Data.csv \n2. Nuevo archivo", "Error, opcion incorrecta", 1, 2, 1);
							switch(flag2)
							{
							case 1:
								controller_saveAsText("Data.csv",listaEmpleados);
								break;
							case 3:
								if(utn_getArchivo(path)==0)
								{
									controller_saveAsText(path,listaEmpleados);
								}
								else
								{
									flag2=0;
								}
								break;
							}
						}
						break;
					case 4:
						controller_informes(listaEmpleados);
						break;
//					case 9:
//						utn_getNumero(&flag2, "Desea guardar en: \n1. data.bin \n2. Chequeo.bin \n3. Nuevo archivo", "Error, opcion incorrecta", 1, 3, 1);
//						switch(flag2)
//						{
//						case 1:
//							controller_saveAsBinary("data.bin",listaEmpleados);
//							break;
//						case 2:
//							controller_saveAsBinary("Chequeo.bin",listaEmpleados);
//							break;
//						case 3:
//							if((utn_getArchivo(path, "Ingrese nombre de archivo","Error, no es valido caracter especial, no olvide el .bin", 2, 30))==0)
//							{
//								controller_saveAsBinary(path,listaEmpleados);
//							}
//							else
//							{
//								flag2=0;
//							}
//							break;
//						}
//						break;
//					case 10:
//						controller_putInDisEmployee(listaEmpleados);
//						printf("Desea imprimir nueva lista?. ");
//						if(utn_getCaracterSN()==0)
//						{
//							controller_ListEmployee(listaEmpleados);
//						}
//						break;
//					case 11:
//						if(ll_isEmpty(listaEmpleados)==0 && flag2==0)
//						{
//							printf("Se encuentra una lista con datos en ejecucion, desea salir sin guardar? ");
//							if(utn_getCaracterSN()==0)
//							{
//								controller_deleteLinkedList(listaEmpleados);
//							}
//						}
//						else
//						{
//							controller_deleteLinkedList(listaEmpleados);
//						}
//						break;
				}
	    	}
	    }while(option!=5);
	return 0;
}



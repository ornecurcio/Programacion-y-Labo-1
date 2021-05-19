#include <stdio.h>
#include <stdlib.h>
#include "Recaudacion.h"

int informes_RecaudacionMasAlta(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, eTipo aTipo[], int cantidadTipo, float importe)
{
	int retorno=-1;
	int i, j;
	char descripcion[30];
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0 && aTipo!=NULL && cantidadTipo>0)
	{
		printf("CONTRIBUYENTE----------RECAUDACION----------PRECIO");
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].isEmpty==0 && aAuxiliar[i].importe==importe)
			{
				for(j=0; j<cantidadContribuyente; j++)
				{
					if(aAuxiliar[i].idContribuyente==aContribuyente[j].idContribuyente)
					{
						getDescripcionRecaudacion(aTipo, cantidadTipo, aAuxiliar[i].tipo, descripcion);
						printf("\n%-d %-s \t %-s \t %-d \t %-s \t %-.2f",aContribuyente[j].idContribuyente,
								aContribuyente[j].apellido,aContribuyente[j].name, aAuxiliar[i].idRecaudacion,descripcion, importe);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}

/*
 ============================================================================
 Name        : Ornela Curcio
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Pedir el sueldo al usuario. Sumarle un 10% e informarle cuál
 será su sueldo con aumento
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int mayor;
	int array[5]={0, 1, 5, 6, 7};

	for(int i=5; i>0; i--)
	{
		if(array[i]>mayor)
		{
			mayor=array[i];
		}
	}
	printf("%d", mayor);
	return 0;
}

/*
 * fecha.c
 *
 *  Created on: 11 may. 2022
 *      Author: Gian Franzoso
 */


#include "fecha.h"

int main_Menu(){
	printf("\n Seleccione | 1-  ALTA DE AVION  | 2- MODIFICAR AVION   | 3- BAJA AVION ");
	printf("\n Seleccione | 4- LISTAR AVIONES  | 5- LISTAR AEROLINEAS | 6- LISTAR TIPOS ");
	printf("\n Seleccione | 7- LISTAR DESTINOS | 8- ALTA VUELO        | 9- LISTAR VUELOS "
			"			  | 10- SALIR \n");

		int option;

		printf("\n Opcion 1 ALTA DE AVION \n");
		printf("\n Opcion 2 MODIFICAR AVION: \n");
		printf("\n Opcion 3 BAJA AVION: \n");
		printf("\n Opcion 4 LISTAR AVIONES: \n");
		printf("\n Opcion 5 LISTAR AEROLINEAS \n");
		printf("\n Opcion 6 LISTAR TIPOS \n");
		printf("\n Opcion 7 LISTAR DESTINOS \n");
		printf("\n Opcion 8 ALTA VUELO: \n");
		printf("\n Opcion 9 LISTAR VUELOS \n");
		printf("\n Opcion 10 SALIR \n");
		scanf("%d", &option);

		return option;
}

int validarFecha(fecha fechas[], int top, int index) {
	int retorno = -1;
	int i;
	fecha auxFecha[top];


		for (i = 0; i < top; i++) {
			if (fechas[index].dia == auxFecha[i].dia && fechas[index].mes == auxFecha[i].mes && fechas[index].anio == auxFecha[i].anio) {
				retorno = 0;
				break;
			}


	}

	return retorno;

}


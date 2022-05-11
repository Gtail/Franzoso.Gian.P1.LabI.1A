/*
 ============================================================================
 Name        : Parcial.c
 Author      : Gian Franzoso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "fecha.h"
#include "Viajes.h"
#include "Aviones.h"

int main(void) {
	setbuf(stdout, NULL);
	int option;
	int idAvion=0;
	Avion list[TOP];
	Aerolinea aerolineas[TAMA];
	Tipo tipos[TAMT];
	Destino destinos[TAMD];
/*	fecha fechas[TAMF];
	Vuelo vuelos[TAMV];*/
	initAviones(list, TOP);
	HardcodeAerolinea(aerolineas, TAMA);
	HardcodeDestinos(destinos, TAMD);
	HardcodeTipo(tipos, TAMT);

	do {

		option = main_Menu();
		switch (option) {
		case 1:

			printf("\n Usted ha elegido la opcion N�1: Alta de Empleado \n");
			if (altaAvion(list, TOP, &idAvion, aerolineas, TAMA, tipos, TAMT) == 0) {
				printf("Todo ok \n");
				//flag=1;
			}
			break;
		case 2:
			/*if(flag!=1){
			 printf("\n No hay empleados disponibles \n ");
			 }else{
			 }*/
			printf("\n Usted ha elegido la opcion N�2: Modificacion de Empleado \n");
			modifyAvion(list, tipos, aerolineas, TOP, TAMT, TAMA);
			break;
		case 3:
			/*if(flag==0){
			 printf("\n No hay empleados disponibles \n ");
			 }else{

			 }*/
			printf("\n Usted ha elegido la opcion N�3: Eliminar Empleado \n");
			if(removeAvion(list, TOP, idAvion, tipos, aerolineas, TAMT, TAMA)==0){
				printf("Baja realizada\n");
			}
			break;
		case 4:
			/*	if(flag==0){
			 printf("\n No hay empleados disponibles \n ");
			 }else{*/
			printf("\n Usted ha elegido la opcion N�4: Listado de Pasajeros Alfabeticamente Apellido y Sector \n");

			break;
		case 5:
			printf(
					"\n Usted ha elegido la opcion N�5: Listado de Pasajeros Alfabeticamente Apellido y Sector \n");



			break;
		case 6:
			printf(
					"\n Usted ha elegido la opcion N�6: Total y Promedio de los Pasajes. Cuantos lo superan \n");

			break;
		case 7:
			printf(
					"\n Usted ha elegido la opcion N�7: Informar Listado de pasajeros por Codigo de Vuelo Activos \n");

			break;
		case 8:
			printf("\n Menu Principal \n");
			break;

			break;
		case 9:

			break;
		case 10:
			printf("\n Salir \n");
			break;
		}
	} while (option != 10);

	return 0;
}

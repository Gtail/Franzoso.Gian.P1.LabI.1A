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

/*
 * #define TAMF 5
#define TAMA 5
#define TAMT 4
#define TAMV 5
#define TAMD 4
#define TOP 5
 *
 */

int main(void) {
	setbuf(stdout, NULL);
	int option;
	int idAvion=0;
	int idVuelo=19999;
	Avion list[TOP];
	Aerolinea aerolineas[TAMA];
	Tipo tipos[TAMT];
	Destino destinos[TAMD];
	Vuelo vuelos[TAMV];
	Piloto pilotos[TAMP];
/*	fecha fechas[TAMF];
	Vuelo vuelos[TAMV];*/
	initAviones(list, TOP);
	HardcodeAerolinea(aerolineas, TAMA);
	HardcodeDestinos(destinos, TAMD);
	HardcodeTipo(tipos, TAMT);
	inicializarVuelos(vuelos, TAMV);
	HardcodePilotos(pilotos, TAMP);

	do {

		option = main_Menu();
		switch (option) {
		case 1:

			printf("\n Usted ha elegido la opcion Nº1: Alta de Avion \n");
			if (altaAvion(list, TOP, &idAvion, aerolineas, TAMA, tipos, TAMT, pilotos, TAMP) == 0) {
				printf("Todo ok \n");
				//flag=1;
			}
			break;
		case 2:
			/*if(flag!=1){
			 printf("\n No hay empleados disponibles \n ");
			 }else{
			 }*/
			printf("\n Usted ha elegido la opcion Nº2: Modificacion de Avion \n");
			modifyAvion(list, tipos, aerolineas,pilotos, TOP, TAMT, TAMA, TAMP);
			break;
		case 3:
			/*if(flag==0){
			 printf("\n No hay empleados disponibles \n ");
			 }else{

			 }*/
			printf("\n Usted ha elegido la opcion Nº3: Baja de Avion \n");
			if(removeAvion(list, TOP, idAvion, tipos, aerolineas, pilotos, TAMT, TAMA, TAMP)==0){
				printf("Baja realizada\n");
			}
			break;
		case 4:
			/*	if(flag==0){
			 printf("\n No hay empleados disponibles \n ");
			 }else{*/
			printf("\n Usted ha elegido la opcion Nº4: Listado de Aviones ordenados por aerolínea y capacidad. \n");
			sortAviones(list, tipos, aerolineas, pilotos, TOP, TOP, TAMT, TAMA, TAMP);
			break;
		case 5:
			printf(
					"\n Usted ha elegido la opcion Nº5: Listado de AEROLINEAS \n");

			listarAerolineas(list, aerolineas, TOP, TAMA);

			break;
		case 6:
			printf(
					"\n Usted ha elegido la opcion Nº6: Listar TIPOS \n");
			listarTipos(list, tipos, TAMT, TOP);
			break;
		case 7:
			printf(
					"\n Usted ha elegido la opcion Nº7: LISTAR DESTINOS \n");
			listarDestinos(destinos, TAMD);
			break;
		case 8:
			printf("\n Usted ha elegido la opcion Nº8: ALTA DE VUELOS \n");

			altaDeVuelo(list, TOP, vuelos, TAMV, tipos, TAMT, aerolineas, TAMA, destinos, TAMD, pilotos, TAMP, &idVuelo);
			break;
		case 9:
			printf("\n Usted ha elegido la opcion Nº9: LISTAR VUELOS \n");
			listarVuelos(list, TOP, vuelos, TAMV, tipos, TAMT, aerolineas, TAMA, destinos, TAMD);
			break;
		case 10:
			mostrarAvionesPorAerolinea(list, TOP, aerolineas, TAMA, tipos, TAMT, pilotos, TAMP);
			break;
		case 11:
			mostrarAvionesPorTipo(list, TAMA, aerolineas, TAMA, tipos, TAMT, pilotos, TAMP);
			break;
		case 12:
			mostrarAviones_PorAerolineas(list, TOP, aerolineas, TAMA, tipos, TAMT, pilotos, TAMP);
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			break;
		case 17:
			break;
		case 18:
			break;
		case 19:
			break;
		case 20:
			printf("\n Salir \n");
			break;

		}
	} while (option != 10);

	return 0;
}

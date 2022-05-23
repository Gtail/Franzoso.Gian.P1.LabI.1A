/*
 * Aerolineas.c
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */

#include "Aerolineas.h"


void HardcodeAerolinea(Aerolinea aerolineas[], int top) {
	int i;


	int typeAerolinea[] = { 1000, 1001, 1002, 1003, 1004 };
	char descripcion[][51] = { "Lan ", "Iberia ", "Norwegian" ,"American", "Austral"};
	//Lan, Iberia, Norwegian, American, Austral
	for (i = 0; i < top; i++) {
		aerolineas[i].idAerolinea = typeAerolinea[i];
		strcpy(aerolineas[i].descripcion, descripcion[i]);

	}
}

int validarAerolinea(Aerolinea aerolineas[], int top, int* idAerolinea) {
	int retorno = -1;
	int i;

	if (aerolineas != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (*idAerolinea == aerolineas[i].idAerolinea) {
				retorno = 0;
				break;
			}
		}

	}

	return retorno;

}

int getAerolinea_byId(char aerolinea[], int idAerolinea, Aerolinea aerolineas[], int top) {

	int retorno = -1;
	int i;

	if (aerolineas != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (idAerolinea == aerolineas[i].idAerolinea) {
				strcpy(aerolinea, aerolineas[i].descripcion);
			}
		}
		retorno = 1;
	}

	return retorno;
}



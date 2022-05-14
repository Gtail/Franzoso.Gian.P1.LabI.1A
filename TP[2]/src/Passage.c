/*
 * Passengers.c
 *
 *  Created on: 21 abr. 2022
 *      Author: Gian
 */
#include "Passage.h"


void HardcodePassage(ePassage passage[], int top) {
	int i;


	int typePassenger[] = { 1, 2, 3 };
	char typeClass[][51] = { "Primera Clase ", "Clase ejecutiva ", "Clase Turistica" };

	for (i = 0; i < top; i++) {
		passage[i].typePassenger = typePassenger[i];
		strcpy(passage[i].class, typeClass[i]);
		printf("%s", passage[i].class);
	}
}

void HardcodeStatus(ePassage passage[], int tams) {
	int i;


	int typeStatus[] = { 0, 1 };
	char status[][51] = { "Inactivo ", "Activo "};

	for (i = 0; i < tams; i++) {
		passage[i].statusFlight = typeStatus[i];
		strcpy(passage[i].status, status[i]);
	}
}

int getClass_byId(char class[], int idSector, ePassage passage[], int top) {

	int retorno = -1;
	int i;

	if (passage != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (idSector == passage[i].typePassenger) {
				strcpy(class, passage[i].class);
			}
		}
		retorno = 1;
	}

	return retorno;
}

int getStatus_byId(char status[], int stFlight, ePassage passage[], int tams) {

	int retorno = -1;
	int i;

	if (passage != NULL && tams > 0) {

		for (i = 0; i < tams; i++) {


			if (stFlight == passage[i].statusFlight) {

				strcpy(status, passage[i].status);
			}
		}
		retorno = 1;
	}

	return retorno;
}




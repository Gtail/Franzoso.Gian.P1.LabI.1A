/*
 * Pilotos.c
 *
 *  Created on: 23 may. 2022
 *      Author: Gian
 */

#include "Pilotos.h"



void HardcodePilotos(Piloto pilotos[], int top) {
	int i;


	int idPilot[] = { 1, 2, 3 };
	char name[][70] = { "Max Verstappen", "Esteban Tuero ", "Danica Patrick" };
	char sex[]={'m', 'm', 'f' };
	for (i = 0; i < top; i++) {
		pilotos[i].idPiloto = idPilot[i];
		strcpy(pilotos[i].nombre, name[i]);
		pilotos[i].sexo = sex[i];
	}
}

int validarPiloto(Piloto pilotos[], int top, int* idPiloto) {
	int retorno = -1;
	int i;

	if (pilotos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (*idPiloto == pilotos[i].idPiloto) {
				retorno = 0;
				break;
			}
		}

	}

	return retorno;

}

int getPiloto_ById(char tipo[],  int* idPiloto, Piloto pilotos[], int top) {

	int retorno = -1;
	int i;

	if (pilotos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (*idPiloto == pilotos[i].idPiloto) {
				strcpy(tipo, pilotos[i].nombre);
			}
		}
		retorno = 1;
	}

	return retorno;
}

/*
 * Viajes.c
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */

#include "Viajes.h"




void HardcodeDestinos(Destino destinos[], int top) {
	int i;

	int typeDestino[] = { 20000, 20001, 20002, 20003 };
	char descripcion[][51] = { "Calafate ", "Calafate ", "Madrid", "Amsterdam" };
	float precio[] = { 22250, 103000, 84400, 95600 };

	for (i = 0; i < top; i++) {
		destinos[i].idDestino = typeDestino[i];
		strcpy(destinos[i].descripcion, descripcion[i]);
		destinos[i].precio = precio[i];

	}
}

int validarViaje(Destino destinos[], int top, int idDestino) {
	int retorno = -1;
	int i;

	if (destinos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (idDestino == destinos[i].idDestino) {
				retorno = 0;
				break;
			}
		}

	}

	return retorno;

}


/*
 * Pilotos.h
 *
 *  Created on: 23 may. 2022
 *      Author: Gian
 */


#include "Aviones.h"
#ifndef PILOTOS_H_
#define PILOTOS_H_

struct{
	int idPiloto; // Validar 1- Max Verstappen 2- Esteban Tuero 3- Danica Patrick
	char nombre[70];
	char sexo;
}typedef Piloto;



int validarPiloto(Piloto pilotos[], int top, int* idPiloto);
void HardcodePilotos(Piloto pilotos[], int top);
int getPiloto_ById(char tipo[], int* idPiloto, Piloto pilotos[], int top);
#endif /* PILOTOS_H_ */

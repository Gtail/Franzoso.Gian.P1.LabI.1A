/*
 * fecha.h
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */

#ifndef FECHA_H_
#define FECHA_H_

#include "Aerolineas.h"
#include "inputUtn.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#define TAMF 5
#define TAMA 5
#define TAMT 4
#define TAMV 5
#define TAMD 4
#define TOP 10
#define TAMP 3
struct{
	int dia;
	int mes;
	int anio;
}typedef fecha;

int validarFecha(fecha fechas[], int top, int index);
int main_Menu();


#endif /* FECHA_H_ */

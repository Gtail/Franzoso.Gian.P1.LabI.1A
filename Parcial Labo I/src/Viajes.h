/*
 * Viajes.h
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */
#ifndef VIAJES_H_
#define VIAJES_H_
#include "Aerolineas.h"
#include "Aviones.h"
#include "fecha.h"
/*
 * Destino:
• id(comienza en 20000)
• descripción (máximo 25 caracteres)
• precio
Vuelo:
• id (autoincremental)
• idAvion (debe existir) Validar
• idDestino (debe existir) Validar
• fecha (Validar día, mes y año)
 */

struct{
	int idDestino; //arranca en 20000
	char descripcion[25]; //Calafate: $22250, Calafate: $103000, Madrid: $84400, Amsterdam: $95600)
	float precio;
}typedef Destino;

struct{
	int idVuelo; //autoincremental
	int idAvion; //validar Existencia
	int idDestino; //Validar existencia
	fecha fecha; //validar dia mes y año
}typedef Vuelo;




int validarViaje(Destino destinos[], int top, int idDestino);
void HardcodeDestinos(Destino destinos[], int top);


#endif /* VIAJES_H_ */

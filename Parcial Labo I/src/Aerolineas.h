/*
 * Aerolineas.h
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */

#include "fecha.h"
#ifndef AEROLINEAS_H_
#define AEROLINEAS_H_


/*



 */

struct{
	int idAerolinea;//arranca en 1000
	char descripcion[20]; //Lan, Iberia, Norwegian, American, Austral
}typedef Aerolinea;




int validarAerolinea(Aerolinea aerolineas[], int top, int* idAerolinea);
void HardcodeAerolinea(Aerolinea aerolineas[], int top);
int getAerolinea_byId(char aerolinea[], int idAerolinea, Aerolinea aerolineas[], int top);





#endif /* AEROLINEAS_H_ */

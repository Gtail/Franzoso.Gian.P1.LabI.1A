/*
 * Passengers.h
 *
 *  Created on: 21 abr. 2022
 *      Author: Gian
 */

#include "ArrayPassenger.h"
#ifndef PASSAGE_H_
#define PASSAGE_H_


struct{
	int id;
	int typePassenger;
	char class[51];
	char flycode[10]; //FK
	int statusFlight;
	char status[51];
}typedef ePassage;

/*
 *
 *para type passanger:
1 Primera clase.
2 Clase ejecutiva o business.
4 Clase turista o económica.
 */

int getClass_byId(char class[], int idSector, ePassage passage[], int top);
int getStatus_byId(char status[], int stFlight, ePassage passage[], int top);
void HardcodePassage(ePassage passage[], int top);
void HardcodeStatus(ePassage passage[], int tams);



#endif /* PASSAGE_H_ */

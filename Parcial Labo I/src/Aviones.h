/*
 * Aviones.h
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */

#include "Viajes.h"
#ifndef AVIONES_H_
#define AVIONES_H_
#define FULL 0
#define EMPTY 1


struct{
	int idTipo; //arranca en 5000
	char descripcion[20]; //Jet, Helice, Planeador, Carga
}typedef Tipo;

struct{
	int idAvion;
	int idAerolinea; //Validar
	int idTipo; //Validar
	int capacidad; //cant pasajeros entre 10 y 300;
	int isEmpty;
}typedef Avion;


void HardcodeTipo(Tipo tipos[], int top);
int initAviones(Avion list[], int len);
int altaAvion(Avion list[], int tamAvion, int* idAvion, Aerolinea aerolineas[], int tamAero, Tipo tipos[], int tamT );
int findEmptyAvion(Avion list[], int len, int *index);
int getTipo_ById(char tipo[], int idTipo, Tipo tipos[], int top);
int modifyAvion(Avion list[], Tipo tipos[], Aerolinea aerolineas[], int top, int tamt, int tama);
int getTipo_ById(char tipo[], int idTipo, Tipo tipos[], int top);
void printAviones(Avion lista[], Tipo tipos[], Aerolinea aerolineas[], int top, int tamt, int tama);
void show_OneAvion(Avion oneAvion, Tipo tipos[], Aerolinea aerolineas[],int top, int tamt, int tama);
int findAvionById(Avion* list, int len,int id, int* index);
int validarTipo(Tipo tipos[], int top, int* idTipo);
int removeAvion(Avion *list, int top, int id, Tipo tipos[], Aerolinea aerolineas[], int tamt, int tama);

#endif /* AVIONES_H_ */

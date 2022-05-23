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
#include "Pilotos.h"





struct{
	int idTipo; //arranca en 5000
	char descripcion[20]; //Jet, Helice, Planeador, Carga
}typedef Tipo;

struct{
	int idPiloto; // Validar 1- Max Verstappen 2- Esteban Tuero 3- Gilles Villenueve
	int idAvion; //autoincremental
	int idAerolinea; //Validar
	int idTipo; //Validar
	int capacidad; //cant pasajeros entre 10 y 300;
	int isEmpty;
}typedef Avion;


void HardcodeTipo(Tipo tipos[], int top);
int initAviones(Avion list[], int len);
int altaAvion(Avion list[], int tamAvion, int* idAvion, Aerolinea aerolineas[], int tamAero, Tipo tipos[], int tamT, Piloto pilotos[], int tamP );
int findEmptyAvion(Avion list[], int len, int *index);

int modifyAvion(Avion list[], Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int top, int tamt, int tama, int tamP);
int getTipo_ById(char tipo[], int* idTipo, Tipo tipos[], int top);
void printAviones(Avion lista[], Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int top, int tamt, int tama, int tamP);
void show_OneAvion(Avion oneAvion, Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int top, int tamt, int tama, int tamP);
int findAvionById(Avion* list, int len,int id, int* index);
int validarTipo(Tipo tipos[], int top, int* idTipo);

int sortAviones(Avion *list, Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[],int len, int top, int tamt, int tama, int tamP);
void show_Aerolineas(Avion oneAvion, Aerolinea aerolineas[], int tama);
void listarAerolineas(Avion oneAvion[], Aerolinea aerolineas[],int top,  int tama);
int removeAvion(Avion *list, int top, int id, Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int tamt, int tama, int tamP);

void listarTipos(Avion oneAvion[], Tipo tipos[], int tamt, int top);
void show_Tipos(Avion oneAvion, Tipo tipos[], int tamt);

int mostrarAvionesPorAerolinea(Avion aviones[], int tamAv, Aerolinea aerolineas[], int tamA, Tipo tipos[], int tamT, Piloto* pilotos, int tamP);
int mostrarAvionesPorTipo(Avion aviones[], int tamAv, Aerolinea aerolineas[], int tamA, Tipo tipos[], int tamT, Piloto pilotos[], int tamP);

int mostrarAviones_PorAerolineas(Avion aviones[], int tamAv, Aerolinea aerolineas[], int tamA, Tipo tipos[], int tamT, Piloto* pilotos, int tamP);
void show_OneAerolinea(Avion oneAvion, Tipo tipos[], Aerolinea aerolineas[], Piloto pilotos[], int top, int tamt, int tama, int tamP);

#endif /* AVIONES_H_ */

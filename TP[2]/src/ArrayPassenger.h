/*
 * ArrayPassenger.h
 *
 *  Created on: 21 abr. 2022
 *      Author: Gian
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include "Passage.h"
#include "inputUtn.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>


#define EMPTY 1
#define FULL 0
#define ACTIVO 1
#define INACTIVO 0

struct{
	int id;
	char name[51];
	char lastName[51];
	char flycode[10]; //PK
	float price;
	int typePassenger;
	int isEmpty;
	int statusFlight;
}typedef Passenger;


int subMenu();
int subMenu2();
int subMenu_Modify();
int findEmptyPassenger(Passenger list[], int len, int *index);
int addPassenger(Passenger list[], int len, int* id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
int initPassengers(Passenger list[], int len);
void show_OneEmployee(Passenger onePassenger, ePassage passages[], int top, int tams);
void printPassengers(Passenger lista[],int len, ePassage passages[], int top, int tams);
int hardcodePassengers(Passenger list[], int index, int* id, char name[51], char lastName[51],char flycode[10],  float precio, int typePassenger, int status);
int findPassengerById(Passenger* list, int len,int id, int* index);
int modifyPassenger(Passenger list[], int tam, ePassage passages[], int top,int tams);
int removePassenger(Passenger *list, int len, int id, ePassage passages[], int top, int tams);
int sortEmployees(Passenger *list, int len, int order);

void informes(Passenger list[], int len);
float calculate_Prices(Passenger list[], int len);
float calculate_AveragePassengers(Passenger list[], int len);
int calculate_ExceedPassengers(Passenger list[], int len);
int calculate_Passengers(Passenger list[], int len);
void print_ActivePassengers(Passenger lista[],int len, ePassage passages[], int top, int tams);
int sortPassengers_ByCode(Passenger *list, ePassage passages[], int len, int top, int tams, int order);

#endif /* ARRAYPASSENGER_H_ */

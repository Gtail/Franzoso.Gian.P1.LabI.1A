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

int validarViaje(Destino destinos[], int top, int* idDestino) {
	int retorno = -1;
	int i;

	if (destinos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (*idDestino == destinos[i].idDestino) {
				retorno = 0;
				break;
			}
		}

	}

	return retorno;

}

int listarDestinos(Destino destinos[], int tam){
int todoOk = 0;

    if(destinos != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Destinos  ***\n");
        printf("  Id    Descripcion    Precio\n");
        printf("--------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s  %5.2f\n", destinos[i].idDestino, destinos[i].descripcion, destinos[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}


int altaDeVuelo(Avion* aviones, int tamAv, Vuelo* vuelos, int tamV, Tipo* tipos, int tamT, Aerolinea* aerolineas, int tamA,  Destino* destinos, int tamD, Piloto* pilotos, int tamP, int* idVuelo){
	int retorno=-1;
	int index=-1;
	int indexA;
	Vuelo auxVuelo;

	if(aviones!=NULL && vuelos!=NULL && tipos!=NULL && aerolineas!=NULL && destinos !=NULL && tamA>0 && tamV>0 && tamT>0 && tamA>0 && tamD>0 && idVuelo!=NULL){
		buscarVueloLibre(vuelos, tamV, &index);
		if(index!=-1){
			auxVuelo.idVuelo=*idVuelo;
			(*idVuelo)++;
			printAviones(aviones, tipos, aerolineas, pilotos, tamAv, tamT, tamA, tamP);
			auxVuelo.idAvion=getValidInt("Ingrese un id de Avion \n", "Error, Ingrese SOLO numeros \n", 0, tamAv);
			while(findAvionById(aviones, tamAv, auxVuelo.idAvion, &indexA)!=0){
				printAviones(aviones, tipos, aerolineas, pilotos, tamAv, tamT, tamA, tamP);
				auxVuelo.idAvion=getValidInt("Ingrese un id de Avion \n", "Error, Ingrese SOLO numeros \n", 0, tamAv);
		}
				listarDestinos(destinos, tamD);
				auxVuelo.idDestino=getValidInt("Ingrese un id de Destino 20000 - 20003 \n", "Error, Ingrese SOLO numeros 20000 - 20003 \n", 20000, 20003);
				while(validarViaje(destinos, tamD, &auxVuelo.idDestino)!=0){
				auxVuelo.idDestino=getValidInt("Ingrese un id de Destino 20000 - 20003 \n", "Error, Ingrese SOLO numeros 20000 - 20003 \n", 20000, 20003);
				}
				printf("INGRESE LA FECHA \n");
			 printf("-------------..----------");
			 auxVuelo.fecha.dia=getValidInt("Ingrese el dia \n", "Error, ingrese SOLO numeros \n", 1, 31);
			 auxVuelo.fecha.mes=getValidInt("Ingrese el Mes \n", "Error, ingrese SOLO numeros \n",  1, 12);
			 auxVuelo.fecha.anio=getValidInt("Ingres el año \n", "Error, ingrese SOLO numeros \n",  2020, 2030);

			 vuelos[index]=auxVuelo;
			 retorno=0;
		}
	}

	return retorno;
}

int listarVuelos(Avion* aviones, int tamAv, Vuelo* vuelos, int tamV, Tipo* tipos, int tamT, Aerolinea* aerolineas, int tamA, Destino* destinos, int tamD)
{
	int retorno=-1;
	int i;
	if(aviones!=NULL && vuelos!=NULL && tipos!=NULL && aerolineas!=NULL && destinos !=NULL && tamA>0 && tamV>0 && tamT>0 && tamA>0 && tamD>0)
	{
        system("cls");
        printf("          *** Listado de Vuelos ***\n\n");
        printf("  IdVuelo        Avion      Destino     Fecha\n");
        printf("--------------------------------------------------------------------------------\n");

        for(i=0;i<tamV;i++){
        	if(vuelos[i].isEmpty==0){
        		showVuelo(vuelos[i], tamV, destinos, aviones, tamAv, tipos, tamT);
        	}else{
        		printf("No hay Vuelos para mostrar  \n");
        	}
        }


	}


	return retorno;
}

int getDestino_ById(char tipo[], int idDestino, Destino destinos[], int top) {

	int retorno = -1;
	int i;

	if (destinos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (idDestino == destinos[i].idDestino) {
				strcpy(tipo, destinos[i].descripcion);
			}
		}
		retorno = 0;
	}

	return retorno;
}

void showVuelo(Vuelo vuelos, int tamV, Destino* destinos, Avion aviones[], int tamAv, Tipo tipos[], int tamT)
{
	char auxDestino[25];
	int tipo;
	char auxTipo[25];
	getDestino_ById(auxDestino, vuelos.idDestino, destinos, tamV);
	if(getTipo_ByIdAvion(&tipo, vuelos.idAvion, aviones, tamAv)!=-1){
		getTipo_ById(auxTipo, &tipo, tipos, tamT);
	}
    system("cls");
    printf("          *** Listado de Vuelos ***\n\n");
    printf("  IdVuelo        Avion      Destino     Fecha\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("  %d             %s          %s         %02d/%02d/%02d\n", vuelos.idVuelo, auxTipo, auxDestino, vuelos.fecha.dia, vuelos.fecha.mes, vuelos.fecha.anio);

}

int getTipo_ByIdAvion(int* tipo, int idAvion, Avion aviones[], int top)
{

	int retorno = -1;
	int i;

	if (aviones != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (idAvion == aviones[i].idAvion) {
				*tipo=aviones[i].idTipo;
				break;
			}
		}
		retorno = 0;
	}

	return retorno;
}


int inicializarVuelos(Vuelo *vuelos, int tamV)
{
	int i;
	int retorno = -1;

	if (vuelos != NULL && tamV > 0) {
		for (i = 0; i < tamV; i++) {
			vuelos[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}


int buscarVueloLibre(Vuelo* vuelos, int tamV, int* index)
{
int i;
int retorno=-1;

if(vuelos!=NULL && tamV>0){
	for(i=0;i<tamV;i++){
		if(vuelos[i].isEmpty==1){
			*index=i;
			break;
		}
	}
	retorno=0;
}

return retorno;
}


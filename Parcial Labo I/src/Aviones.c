/*
 * Aviones.c
 *
 *  Created on: 11 may. 2022
 *      Author: Gian
 */


#include "Aviones.h"

int subMenu_Modify(){
	printf("----------------------------MENU MODIFICAR------------------------------");
	printf("\n Seleccione | 1- Modificar TIPO | 2- Modificar CAPACIDAD | 3- Salir \n");
		int option;

		printf("\n Opcion 1 Modificar TIPO \n");
		printf("\n Opcion 2 Modificar CAPACIDAD \n");
		printf("\n Opcion 3 Salir \n");

		scanf("%d", &option);

		return option;
}

void HardcodeTipo(Tipo tipos[], int top) {
	int i;


	int typeAvion[] = { 5000, 5001, 5002, 5003 };
	char descripcion[][51] = { "Jet ", "Helice ", "Planeador" ,"Carga"};

	for (i = 0; i < top; i++) {
		tipos[i].idTipo = typeAvion[i];
		strcpy(tipos[i].descripcion, descripcion[i]);

	}
}

int validarTipo(Tipo tipos[], int top, int* idTipo) {
	int retorno = -1;
	int i;

	if (tipos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (*idTipo == tipos[i].idTipo) {
				retorno = 0;
				break;
			}
		}

	}

	return retorno;

}

int initAviones(Avion list[], int len) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}

	return retorno;
}



int altaAvion(Avion list[], int tamAvion, int* idAvion, Aerolinea aerolineas[], int tamAero, Tipo tipos[], int tamT ){
	int idAerolinea;
	int idTipo;
	int capacidad;
	int index=-1;
	int retorno=-1;
printf("Entre \n");
	if(list!=NULL && tamAvion>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0){
		printf("Pase lo primero \n");
		findEmptyAvion(list, tamAvion, &index);

		if(index!=-1){
			printf("Pase el index %d \n",index);
			/*fecha.dia=getValidInt("Ingrese el dia 1 - 31 \n", "Error Ingrese SOLO 1 - 31 \n", 1, 31);
			fecha.mes=getValidInt("Ingrese el mes 1 - 12 \n", "Error Ingrese SOLO 1 - 12 \n", 1	, 12);
			fecha.anio=getValidInt("Ingrese el mes 1999 - 2022 \n", "Error Ingrese SOLO 1999 - 2022 \n", 1999, 2022);*/
			idAerolinea=getValidInt("Ingrese la Aerolinea 1000 Lan - 1001 Iberia - 1002 Norwegian - 1003 American - 1004 Austral \n", "Error Ingrese SOLO numeros de 1000 - 1004 \n", 1000	, 1004);

			if(validarAerolinea(aerolineas, tamAero, &idAerolinea)==0){
				list[index].idAerolinea=idAerolinea;
				printf("el id %d de Tipo NO existe \n	", idAerolinea);
			}else{
				printf("el id %d de Aerolinea NO existe \n	", idAerolinea);
			}

			idTipo=getValidInt("Ingrese el tipo de Avion 5000 Jet - 5001 Helice - 5002 Planeador - 5003 Carga \n", "ERROR. Ingrese SOLO numeros del 5000 al 5003\n", 5000, 5003);

			if(validarTipo(tipos, tamT, &idTipo)==0){
				list[index].idTipo=idTipo;
				printf("%d", list[index].idTipo);
			}else{
				printf("el id %d de Tipo NO existe \n	", idTipo);
			}

			capacidad=getValidInt("Ingrese la Capacidad del Avion 10 - 300 \n", "Error Ingrese SOLO numeros de 10 a 300 \n", 10, 300);
			if(capacidad>9 && capacidad<301){
				list[index].capacidad=capacidad;
				printf("%d capacidad \n", capacidad);
			}else{
				printf("La capacidad %d es INVALIDA \n", capacidad);
			}

			list[index].idAvion=*idAvion;
			(*idAvion)++;
			list[index].isEmpty=FULL;

		}
	}

	return retorno;
}

int findEmptyAvion(Avion list[], int len, int *index) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == EMPTY) {
				*index = i;
				retorno=0;
				break;
			}
		}

	}

	return retorno;
}




int modifyAvion(Avion list[], Tipo tipos[], Aerolinea aerolineas[], int top, int tamt, int tama) {
	int retorno = -1;
	int index;
	int id = -1;
	int opcion;
	Avion auxAvion;
	printAviones(list, tipos, aerolineas, top, tamt, tama);
	id = getValidInt("Ingrese el ID de Avion a Modificar \n",
			"Error, Ingrese un ID valido", 0, 5);
	if (findAvionById(list, top, id, &index) != -1) {
		printf("El id %d existe\n", id);
	} else {
		printf("El id %d es inexistente \n", id);
	}
	if (index != -1) {
		do {
			opcion = subMenu_Modify();
			switch (opcion) {
			case 1:
				auxAvion.idTipo =
						getValidInt("Ingrese el tipo de Avion 5000 Jet - 5001 Helice - 5002 Planeador - 5003 Carga \n",
						            "ERROR. Ingrese SOLO numeros del 5000 al 5003\n",
								    5000, 5003);

				if (validarTipo(tipos, tamt, &auxAvion.idTipo) == 0) {
					auxAvion.idTipo = list[index].idTipo;
				} else {
					printf("el id %d de Tipo NO existe \n	", auxAvion.idTipo);
				}
				break;
			case 2:
				auxAvion.capacidad =
						getValidInt("Ingrese la Capacidad del Avion 10 - 300 \n",
						"Error Ingrese SOLO numeros de 10 a 300 \n", 10, 300);
				if (auxAvion.capacidad > 9 && auxAvion.capacidad < 301) {
					auxAvion.capacidad = list[index].capacidad;
				} else {
					printf("La capacidad %d es INVALIDA \n",
							auxAvion.capacidad);
				}
				break;
			case 3:
				printf("Menu principal \n");
				break;
			}
		} while (opcion != 3);

	}

	return retorno;
}




int getTipo_ById(char tipo[], int idTipo, Tipo tipos[], int top) {

	int retorno = -1;
	int i;

	if (tipos != NULL && top > 0) {
		for (i = 0; i < top; i++) {
			if (idTipo == tipos[i].idTipo) {
				strcpy(tipo, tipos[i].descripcion);
			}
		}
		retorno = 1;
	}

	return retorno;
}

void printAviones(Avion lista[], Tipo tipos[], Aerolinea aerolineas[], int top, int tamt, int tama)
{

    if(lista !=NULL && top>0)
    {
        for (int i=0; i<top; i++)
        {
            if(lista[i].isEmpty == FULL)
            {

                show_OneAvion(lista[i], tipos, aerolineas, top, tamt, tama);


            }
        }
    }
    else
    {
        printf("\n No hay empleados que listar\n");
    }
}

void show_OneAvion(Avion oneAvion, Tipo tipos[], Aerolinea aerolineas[],int top, int tamt, int tama) {
	char auxAerolinea[25];
	char auxTipos[20];

	getAerolinea_byId(auxAerolinea, oneAvion.idAerolinea, aerolineas, tama);
	getTipo_ById(auxTipos, oneAvion.idTipo, tipos, tamt);

		printf(
				"\n |ID AVION |ID TIPO   | TIPO DE AVION  | AEROLINEA | CAPACIDAD       ");
		printf(
				"\n |%d  |%d  |%s  |%s | %d  \n",		oneAvion.idAvion,
											            oneAvion.idTipo,
											            auxTipos,
                                                        auxAerolinea,
														oneAvion.capacidad);

}


int findAvionById(Avion* list, int len,int id, int* index)
{
	int retorno=-1;
	int i;

	if(list!=NULL && len>0){
		for(i=0;i<len;i++){
			if(list[i].idAvion==id){
			*index=i;
			retorno=0;
			}
		}
	}
	return retorno;
}

int removeAvion(Avion *list, int top, int id, Tipo tipos[], Aerolinea aerolineas[], int tamt, int tama) {
	int retorno = -1;
	int index;

	if (list != NULL && tipos != NULL && aerolineas !=NULL && tamt > 0 && top > 0 && tama > 0) {
		printAviones(list, tipos, aerolineas, top, tamt, tama);
		id = getValidInt("Ingrese el ID del Avion a eliminar \n", "ERROR, ingrese SOLO numeros", 0, top);
		if (findAvionById(list, top, id, &index) != -1) {
			printf("El id %d existe \n", id);
		} else {
			printf("El id %d no existe \n", id);
		}
		if (index != -1) {
			list[index].isEmpty = EMPTY;
			retorno=0;
		}
	}

	return retorno;
}










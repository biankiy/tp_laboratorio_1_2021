/*
 * input.h
 *
 *  Created on: 12 oct. 2021
 *      Author: patricio
 */

#ifndef INPUT_H_
#define INPUT_H_


int utn_pedirNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
int utn_pedirfloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_pedirChar(char* mensaje, char* mensajeError, char* pResultado,int reintentos);
int utn_pedirNombre(char* pResultado, int longitud, char* mensaje,char* mensajeError, int reintentos);
int utn_pedirAlfaNumerico(char* pResultado, int longitud, char* mensaje, char* mensajeError);

int utn_getCuit(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
void getString(char cadena[],char mensaje[],int tam);

#endif /* INPUT_H_ */

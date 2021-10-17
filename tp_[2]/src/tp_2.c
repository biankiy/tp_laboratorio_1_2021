/*
 ============================================================================
 Name        : tp_2.c
 Author      : Bianca Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "input.h"
#include "empleado.h"
#define TAM 1000
#define MAX 10
#define TAMHARD 50
#define TAMSEC 6

#define LIBRE 0
#define OCUPADO 1


int main(void) {

	int opcion;
	//int flag = 0;
	int indice;
	int idAuto = 105;//---AUTO INCREMENTAL ID
	int auxID;
	int ordenElegido;

	float salarioTotal = 0;
	float salarioPromedio = 0;
	char respuesta = 's';

	Employee listaEmpleados[TAM];

	Sector sectores[TAMSEC] =
	    {
	        {1, "Recursos Humanos"},
	        {2, "Administracion"},
	        {3, "Sistemas"},
	        {4, "Comunicacion"},
	        {5, "Contable"},
	        {6, "Informes"},
	    };

	if(initEmployees(listaEmpleados, TAM) == 0){
		printf("La lista se inicializo Corecctamente\n");
	}else{
		printf("Ocurrio un error al Inicializar la lista\n");
	}

	HardcodearEmpleados(listaEmpleados, TAMHARD);
	idAuto+= TAMHARD;

	do{
		cartel();
		utn_pedirNumero(&opcion, "Ingrese una opcion ", "opcion Invalida", 1, 5);


		switch(opcion){
		case 1:

			cargarEmpleado(listaEmpleados, TAM, &idAuto);


		break;
		case 2:
			mostrarListaEmpleados(listaEmpleados, TAM, sectores, TAMSEC);

				if(utn_pedirNumero(&auxID,"\nIngrese ID del Empleado que desea modificar: \n","\nID invalido",0,1000) == 0)
				{
					indice = buscarIDempleado(listaEmpleados, TAM, auxID);

					if(	indice >= 0 && modificarEmpleado(listaEmpleados, TAM, indice)== 0)
					{
						printf("\nModificacion exitosa\n");


						break;
					}
					else
					{
						printf("No se pudo realizar la Modificacion\n");
					}
				}
				break;
		case 3:
			mostrarListaEmpleados(listaEmpleados, TAM, sectores, TAMSEC);

			if(utn_pedirNumero(&auxID,"\nIngrese ID del Empreado a Eliminar \n","\nID invalido",0,1000) == 0){

				indice = buscarIDempleado(listaEmpleados, TAM, auxID);

				if(indice >= 0 && bajaEmpleado(listaEmpleados, TAM, sectores, indice)== 0){
					printf("\nBaja realizada con exito\n");
				}
			}
			break;
		case 4:
				menuInfo();
				utn_pedirNumero(&ordenElegido, "Ingrese una opcion", "Error,opcion incorrecta", 1, 5);
				if (ordenElegido == 1){ // Descenddientee
					ordenarPorNombre(listaEmpleados,TAM,ordenElegido);
					mostrarListaEmpleados(listaEmpleados, TAM, sectores, TAMSEC);
				}
				else if (ordenElegido == 2){ // Ascendenteee
					ordenarPorNombre(listaEmpleados,TAM,ordenElegido);
					mostrarListaEmpleados(listaEmpleados, TAM, sectores, TAMSEC);
				}
				else if (ordenElegido == 3){
					salarioPromedioTotal(&salarioTotal, &salarioPromedio,listaEmpleados,TAM);
				}
				else if (ordenElegido == 4){
					if (&salarioPromedio >=0){
						saberSuledoMasAlto(&salarioPromedio, listaEmpleados,TAM ,sectores, TAMSEC);
					}
					else{
						printf("\nNecesitas calcular el salario promedio primero.\n");
					}
				}

				break;
		 case 5:
			 respuesta = 'n';

		}

	}while(respuesta == 's');

	return EXIT_SUCCESS;
}

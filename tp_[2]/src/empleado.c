/*
 * empleado.c
 *
 *  Created on: 16 oct. 2021
 *      Author: patricio
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



void HardcodearEmpleados(Employee listaEmpleado[],int tamEmpleados){


	int idsEmpleados[]={95,96,97,98,99,100,101,102,103,104};
	char nombres[][25]={"Karen","Leandro","Bianca","Julian","Lucila","Karen","Jessy","Cotton","Julian","Victor"};
	char apellidos[][25]={"Pizza","Panceta","Frutilla","Chocolate","Vodka","Conejo","Albondiga","Caramelo","Zapato","Manzana"};
	float salario[]={10 , 20 , 5 , 4 , 20, 3 , 11 , 8 , 9, 1};
	int sector[]={3,5,3,1,3,2,4,6,1,4};
	int estado[]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};


    for(int i=0; i<tamEmpleados; i++)
    {
    	listaEmpleado[i].id= idsEmpleados[i];
    	strcpy(listaEmpleado[i].name,nombres[i]);
    	strcpy(listaEmpleado[i].lastName, apellidos[i]);
    	listaEmpleado[i].salary = salario[i];
    	listaEmpleado[i].idsector= sector[i];
    	listaEmpleado[i].isEmpty = estado[i];

    }
}
void cartel(){

	   printf("\n\n1-Alta\n");
	   printf("2-Modificacion:\n");
	   printf("3-Baja\n");
	   printf("4-Informes :\n");
	   printf("5-Salir \n\n");
}
int initEmployees(Employee* list, int len){

	int retorno = -1;

	if(list != NULL && len > 0){
		for(int i=0; i<len; i++){
			list[i].isEmpty = LIBRE; //LIBRE
		}
		retorno  = 0;
	}

	return retorno;
}
int obtenerIndiceVacio(Employee* listaClientes, int cantidadClientes){

    int retorno = -1;

    if(listaClientes != NULL && cantidadClientes > 0){
        for(int i=0; i<cantidadClientes; i++){
            if(listaClientes[i].isEmpty == LIBRE){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int cargarNameSector(char* descripcion, int idSec, Sector sectores[], int len)
{
    int todoOk = 0;

    for(int i=0; i<len; i++)
    {
        if(sectores[i].id == idSec)
        {
            strcpy(descripcion, sectores[i].name);
            todoOk = 1;
        }
    }
    return todoOk;
}

int cargarEmpleado(Employee* list, int tamEmpleados, int* id){

	int retorno = -1;

	Employee auxEmployee;

	int nuevoID;
	nuevoID = *id;

	if((list!=NULL && tamEmpleados>0)){
		utn_pedirNombre(auxEmployee.name, 51, "Ingrese su nombre ", "Error , ingrese nuevamente \n", 5);
		utn_pedirNombre(auxEmployee.lastName, 51, "Ingrese su Apellido: ", "Error , ingrese nuevamente \n", 5);
		utn_pedirfloat(&auxEmployee.salary, "Ingrese su salario: ", "Error , ingrese nuevamente \n.\n", 0, LONG_MAX, 5);
		utn_pedirNumero(&auxEmployee.idsector, "Ingrese su sector [1-6]: ", "Error , ingrese nuevamente \n", 1, 6);

		if(addEmployee(list, tamEmpleados, nuevoID, auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.idsector) == -1){
			printf("\n  - ERROR  -.\n");
		}
		else {
			retorno = 1;
			*id = *id + 1;
		}
	}
	return retorno;
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){

	int retorno = -1;
	int indice;
	Employee auxiliar;

	if(list != NULL && len > 0 ){
		indice = obtenerIndiceVacio(list, len); // buscar libre
			if (indice < 0){
				printf("\nLa lista de empleados esta llena.");
			}
			else{
			auxiliar.id = id;
			strcpy(auxiliar.name, name);
			strcpy(auxiliar.lastName, lastName);
			auxiliar.salary = salary;
			auxiliar.idsector = sector;
			auxiliar.isEmpty = OCUPADO;
			retorno = 0;
			list[indice]=auxiliar;
		}
	}
	return retorno;
}


int mostrarUnEmpleado(Employee* unEmpleado,Sector* sectores,int lenSector){
	int retorno = -1;
	char nombreSector[20];

	cargarNameSector(nombreSector, unEmpleado->idsector, sectores, lenSector);

	if(unEmpleado != NULL && unEmpleado->isEmpty == OCUPADO )
	{
		retorno = 0;
		//cargarNameSector(nombreSector, unEmpleado->idsector, sectores, tamSec);
    	printf("| %*d | %*s | %*s | %*.2f |     %*d    | %*s  |  \n" ,-3,unEmpleado->id,
															-MAX,unEmpleado->name,
															-MAX,unEmpleado->lastName,
															-MAX,unEmpleado->salary,
															-MAX,unEmpleado->idsector,
															-MAX,nombreSector);
	}
	return retorno;
}

int mostrarListaEmpleados(Employee* listaEmpleados, int tam,Sector* sectores, int tamsec)
{
	int respuesta = -1;

	if(listaEmpleados != NULL && tam > 0)
	{
		respuesta = 0;
		printf("| ID  | NOMBRE     | APELLIDO   | SALARIO    |  ID SECTOR  |   SECTOR     | \n");
		for(int i=0; i<tam; i++)
		{
			//mostrarUnEmpleado(&listaEmpleados[i]);
			mostrarUnEmpleado(&listaEmpleados[i],sectores,tamsec);

		}
		respuesta=0;
	}
	return respuesta;
}
int buscarIDempleado(Employee listaEmpleados[], int tam, int idBuscado)
{
    int retorno =-1;

    if(listaEmpleados != NULL && tam>0 && idBuscado >= 0)
    {
        retorno = 0;
        for(int i=0; i<tam; i++)
        {
            if(listaEmpleados[i].id == idBuscado)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int bajaEmpleado(Employee* listaEmpleados, int tam ,Sector* sectores ,int indice){

	int retorno = -1;


	if(listaEmpleados != NULL && tam > 0 && indice < tam && indice >= 0 && listaEmpleados[indice].isEmpty == OCUPADO){

		listaEmpleados[indice].isEmpty = LIBRE;
		retorno = 0;
	}
	return retorno;
}
int modificarEmpleado(Employee* listaEmpleados, int cantidadEmpleados,int indice)
{
    int retorno = -1;
    Employee auxEmplado;
    int opcion;

    if(listaEmpleados != NULL && cantidadEmpleados > 0 && indice >= 0 && indice < cantidadEmpleados && listaEmpleados[indice].isEmpty == OCUPADO)
    {

        printf("---- MENU MODIFICACION ---- \n");
        printf("1- Modificar Nombre \n");
        printf("2- Modificar Apellido \n");
        printf("3- Modificar Salario \n");
        printf("4- Modificar Sector \n");

        utn_pedirNumero(&opcion,"ingrese una opcion: ", "opcion incorrecta",1,4);

        switch(opcion){
            case 1:
                if(utn_pedirNombre(auxEmplado.name, 50, "\nIngrese su Nombre: ", "Error,ingrese nuevamente", 3) == 0){
                    retorno = 0;
                    strcpy(listaEmpleados[indice].name , auxEmplado.name);
                }
            break;

            case 2:
            	if(utn_pedirNombre(auxEmplado.lastName, 50, "\nIngrese su Apellido: ", "Error,ingrese nuevamente", 3) == 0){
					retorno = 0;
					strcpy(listaEmpleados[indice].lastName , auxEmplado.lastName);
				}
            break;

            case 3:
            	if(utn_pedirfloat(&auxEmplado.salary, "\nIngrese su salario: ", "error", 0, LONG_MAX, 3) == 0){
            		retorno = 0;
            		listaEmpleados[indice].salary = auxEmplado.salary;
            	}
            break;

            case 4:
				if(utn_pedirNumero(&auxEmplado.idsector, "\nIngrese su sector 1-6: ", "ERROR-sector incorrecto", 1, 6)== 0){
					retorno = 0;
					listaEmpleados[indice].idsector = auxEmplado.idsector;
				}
			break;
        }

    }

    return retorno;
}
void menuInfo()
{
    printf("------------INFORMES----------------*\n\n");
    printf("1--Listado de los empleados ordenados por orden Descendentes\n");
    printf("2--Listado de los empleados ordenados por orden Ascendente\n");
    printf("3--Total y promedio de los salarios,\n");
    printf("4--Empleados con salario mayor que el promedio \n");
    printf("5--Salir--\n");
}


int ordenarPorNombre(Employee* list, int len, int orden){

    Employee employee;
    int ordenElegido = orden;
    int retorno = -1;

     if(ordenElegido == 1){
        for(int i=0; i<len-1; i++){ //ASCENDENTE
            for(int j=i+1; j<len; j++){
                if(strcmp(list[i].lastName,list[j].lastName)>0){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
                else if(strcmp(list[i].lastName, list[j].lastName) == 0 &&
                	list[i].idsector>list[j].idsector){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
        retorno = 0;
    }

    if(ordenElegido == 2){
        for(int i=0; i<len-1; i++){ //descendente
            for(int j=i+1; j<len; j++) {
                if(strcmp(list[i].lastName,list[j].lastName)<0){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 &&
                	list[i].idsector<list[j].idsector){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
        retorno = 1;
    }



    return retorno;
}
void salarioPromedioTotal(float* salarioTotal, float* promedioSalario,Employee list[],int len){

	    float totalSalarioEmpleado = 0;
		int totalEmpleados = 0;
		float promedioSalarioEmpleado = 0;

		for(int i = 0; i < len; i++){
			if (list[i].isEmpty == OCUPADO){
				totalSalarioEmpleado += list[i].salary;
				totalEmpleados++;

				}
			}
		*salarioTotal = totalSalarioEmpleado;

		if (totalEmpleados!=0){
			promedioSalarioEmpleado = (float)totalSalarioEmpleado/totalEmpleados;
			*promedioSalario = promedioSalarioEmpleado;
		}
		printf("\nEL Salario Total es: $ %.3f\n",totalSalarioEmpleado);
		printf("El salario Promedio es $ %.2f\n",promedioSalarioEmpleado);
}
void saberSuledoMasAlto(float* promedioSalario, Employee list[],int len ,Sector* sectores, int lenSector){

	int cantidadEmpMaxSueldo = 0;
	float salarioTotal = 0;
	salarioPromedioTotal(&salarioTotal, promedioSalario, list, len);
	printf("--------------EMPLEADOS QUE SUPERAN EL PROMEDIO-----------\n");

	for(int i = 0; i < len; i++){
		if((list[i].salary > *promedioSalario) && list[i].isEmpty == OCUPADO )
		{
			cantidadEmpMaxSueldo++;
			mostrarUnEmpleado(&list[i], sectores, lenSector);
		}

	}
	printf("la cantidad de empleados que superan el salario promedio %d \n", cantidadEmpMaxSueldo);
}

/*
 * empleado.h
 *
 *  Created on: 16 oct. 2021
 *      Author: patricio
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct
{
    int id;
    char name[51];
}Sector;

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int idsector;
	int isEmpty;
}Employee;


void HardcodearEmpleados(Employee listaEmpleado[],int tamEmpleados);

/**
 * @brief Muestra el menu principal
 */
void cartel();

/**
 * @brief Inicializa el campo isEmpy del vector de empleados en 1
 * @param Estructura eEmployee: lista de empleados
 * @return 0 si pudo inicializar con exito, y -1 si no.
 */
int initEmployees(Employee* listaClientes, int len);

/**
 * @brief Busca un lugar vacio (isEmpty = 1) en el vector de empleados
 * @param Lista de empleados
 * @param Tamanio de la lista.
 * @return 1 si pudo encontrar lugar vacio con exito, y -1 si no.
 */
int obtenerIndiceVacio(Employee* listaClientes, int cantidadClientes);
/**
 * @brief Aniade empleados al vector de empleados.
 * @param Lista de empleados
 * @param Tamanio de la lista
 * @param Id del empleado
 * @return 0 si pudo cargar al empleado con exito, y -1 si no.
 */
int cargarEmpleado(Employee* list, int listLen, int* id);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int altaCliente(Employee* listaEmpleados, int tam, Sector* sec, int tamSec,int* id);
/**
 * @brief Muestra un empleado.
 * @param Empleado auxiliar
 * @param Vector de sectores
 * @param tamanio del vector.
 * @return retorna 0, si salio  bien o -1 si salio mal,
 */
int mostrarUnEmpleado(Employee* unEmpleado,Sector* sectores,int lenSector);
/**
 * @brief Muestra todos los empleados en sistema.
 * @param Lista de empleados
 * @param Tamanio del vector de empleados
 * @param Vector de sectores
 * @param Tamanio del vector de sectores.
 * @return retorna 0, si salio  bien o -1 si salio mal,
 */
int mostrarListaEmpleados(Employee* listaEmpleados, int tam,Sector* sectores, int tamsec);

/**
 * @brief Encuentra un empleado en la lista con un id.
 * @param Lista de empleados
 * @param Largo de la lista
 * @param Id del empleado a buscar.
 * @return El indice del empleado si lo encuentra, sino -1.
 */
int buscarIDempleado(Employee listaEmpleados[], int tam, int idBuscado);

/**
 * @brief Da de baja a un empleado del sistema.
 * @param Lista de empleados
 * @param Tamanio de la lista
 * @param estructura de sectores
 * @param Tamanio del vector de sectores.
 * @param indice de la posicion del array
 * @return 0 si pudo eliminar con exito, y -1 si no.
 */
int bajaEmpleado(Employee* listaEmpleados, int tam ,Sector* sectores ,int indice);
/**
 * @brief Modifica un campo especifico a elegir de un empleado
 * @param Lista de empleados
 * @param Tamanio del vector de empleados
 * @param indice donde se encuentra empleado *
 * @return 0 si pudo modificar con exito, y -1 si no.
 */
int modificarEmpleado(Employee* listaEmpleados,int cantidadEmpleados, int indice);
/***
 * @brief carga los nombres de los sectores
 * @param descripcion
 * @param idSec
 * @param sectores
 * @param len tamanio de sectores
 * @return 0 si pudo modificar con exito, y -1 si no.
 */
int cargarNameSector(char*descripcion, int idSec, Sector sectores[], int len);
/**
 * @brief Muestra el menu de informes
 */
void menuInfo();
/**
 * @brief Agrupa los empleados por sector del 1 al 6 y los ordena por apellido de manera ascendente o descendente.
 * @param Lista de empleados
 * @param Tamanio del vector de empleados
 * @param Orden (1 para ascendente y 0 para descendente)
 * @return 0 si pudo ordenar con exito, y -1 si no.
 */
int ordenarPorNombre(Employee* list, int len, int orden);
/***
 * @brief Hace el total y el promedio de los salarios de los empleados
 * @param  pasa por parametro salarioTotal
 * @param  pasa por parametro el promedioSalario
 * @param list de meplados
 */
void salarioPromedioTotal(float* salarioTotal, float* promedioSalario,Employee list[],int len);
void saberSuledoMasAlto(float* promedioSalario, Employee list[],int len ,Sector* sectores, int lenSector);
#endif /* EMPLEADO_H_ */

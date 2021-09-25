
#ifndef CALCULOS_H_
#define CALCULOS_H_

/***
 * brief Muestra el menu y reemplaza el numero ingresado en el menu
 * @param num1 es el primer numero ingresado
 * @param num2 es el segundo numero ingresado
 * @param flag1 pertenece a num1
 * @param flag2 pertenece a num2
 * return no retorna nada
 */
void MostrarMenu(float num1, float num2,int flag1, int flag2);

/***
 * brief
 * return no retorna nada
 */
void MenuOpciones();

/***
 * brief permite el ingreso de un numero flotante
 * @return un numero flotante
 */
float IngresarNumero();

//-------------------- Calculos----------------------
/**
* brief recibe dos numeros enteros A y B , retorna la suma.
* param el primero numero para realizar la suma es entero.
* param el segundo numero utilizado para la suma es entero.
* return retorna el resultado de la suma entre A y B .
*/
float SumarNumeros(float num1, float num2);
/**
* brief:recibe dos numeros enteros A y B , retorna la resta.
* param el primero numero para realizar la resta es entero.
* param el segundo numero utilizado para la resta es entero.
* return: retorna el resultado de la resta .
*/
float RestarNumeros(float num1, float num2);
/**
* brief: recibe dos numeros enteros A y B , retorna la multiplicacion.
* param: el primero numero para realizar la multiplicacion es entero.
* param: el segundo numero utilizado para la multiplicacion es entero.
* return retorna el resultado de la multiplicacion.
*/

float MultiplicarNumeros(float num1, float num2);
/**
* brief : recibe dos numeros flotantes A y B , retorna la division.
* param : el numero dividiendo.
* param : el numero divisor.
* return :retorna el resultado de la division.
*/


float DividirNumeros(float num1, float num2);
/**
* brief :recibe un numero flotante y le realiza su factorial.
* param :el numero a realizarle el factorial.
* return :retorna el resultado del factorial.
*/
long long int Factorial(float numero);
//---------------------------------------------------------------------

void calcularOperaciones(float num1, float num2);
void mostrarDatos(float num1, float num2);

#endif /* CALCULOS_H_ */

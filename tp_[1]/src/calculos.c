
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

void MostrarMenu(float num1, float num2,int flag1, int flag2){

	printf("-------------------------------------------\n");
	printf("-------------- CALCULADORA -----------------\n");
	printf("-------------------------------------------\n");
	if(flag1 == 0){
		printf("1- Ingresar 1er operando (A = x)\n");
	}else{
		printf("1- Ingresar 1er operando (A = %.2f)\n" ,num1);
	}

	if(flag2 == 0){
		printf("2- Ingresar 2do operando (B = Y)\n");
	}else{
		printf("2- Ingresar 2do operando (B = %.2f)\n" ,num2);
	}

	printf("3- Calcular todas la operaciones\n");
	printf("4- Informar Resultados\n");
	printf("5- Salir\n\n");
}
void MenuOpciones(){

	float num1;
	float num2;
	int opcion;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;

		do{
			MostrarMenu(num1, num2, flag1, flag2);
			printf("Ingrese una opcion: ");
			scanf("%d", &opcion);

			switch(opcion){
				case 1:
					num1 = IngresarNumero();
					flag1 = 1;
					break;
				case 2:
					if(flag1 == 0){
						printf("\n Error ,Primero tiene que ingresar operando 1 \n");
					}else{
						num2 = IngresarNumero();
						flag2 = 1;
					}
					break;
				case 3:
					if(flag1 == 1 && flag2 == 1){
						calcularOperaciones(num1, num2);
						flag3 = 1;
					}else{
						printf("\n Debes ingresar los operandos antes de calcular \n");
					}
					break;
				case 4:
					if(flag3 ==0){
						printf("\n No puede mostrar los datos si no calculo las operaciones \n");
					}else{
						mostrarDatos(num1, num2);
					}
					break;
				case 5:
					printf("Salir");
					break;
			}
		}while(opcion != 5);
}
float IngresarNumero(){

	float numero;
	printf("Ingrese un numero: ");
	scanf("%f", &numero);

	return numero;
}
float SumarNumeros(float num1, float num2){

	float suma;

		suma= num1 + num2;
		    return suma;
}
float RestarNumeros(float num1, float num2){

	float resta;

		resta= num1 - num2;
		    return resta;
}
float MultiplicarNumeros(float num1, float num2){

	float multiplicar;

		multiplicar= num1 * num2;
		    return multiplicar;
}
float DividirNumeros(float num1, float num2){

	float dividir;

			dividir= (float)num1 / num2;

		    return dividir;
}
long long int Factorial(float numero){

	long long int fact;

        if(numero >= 0 )
        {
            if (numero == 1 || numero==0)
            {
                fact=1;
            }
            else
            {
                fact= numero*Factorial(numero-1);
            }
        }
        return fact;
}

void calcularOperaciones(float num1, float num2){

	printf("\n\n a) Calcular la suma (%.2f + %.2f)\n", num1, num2);
	printf(" b) Calcular la resta (%.2f - %.2f) \n", num1, num2);


	if(num2 == 0){
		printf(" c) Error no se puede dividir por 0\n");
	}else{
		printf(" c) Calcular la division (%.2f / %.2f)\n", num1, num2);
	}

	printf(" d) Calcular la multiplicacion (%.2f * %.2f)\n", num1, num2);
	printf(" e) Calcular el factorial (%.2f!) y (%.2f!)\n", num1, num2);

}
void mostrarDatos(float num1, float num2){

	printf("\n\nEl resultado de %.2f + %.2f es %.2f \n", num1, num2, SumarNumeros(num1, num2));
	printf("El resultado de %.2f - %.2f es %.2f \n", num1, num2, RestarNumeros(num1, num2));
	printf("El resultado de %.2f * %.2f es %.2f \n", num1, num2, MultiplicarNumeros(num1, num2));
	if(num2 == 0){
			printf("Error no se puede dividir por 0\n");
		}else{
			printf("El resultado de %.2f / %.2f es %.2f \n", num1, num2, DividirNumeros(num1, num2) );
		}
	if(num1 < 0 && num2 > 0){
		printf("Error no se puede calcular el factorial de un numero negativo  / El factorial de %.2f es: %lld \n", num2, Factorial(num2));
	}else if(num1 > 0 && num2 < 0){
		printf("El factorial de %.2f es: %lld / Error no se puede calcular el factorial de un numero negativo \n", num1, Factorial(num1));
	}else{
		printf("El factorial de %.2f es: %lld y El factorial de %.2f es: %lld \n", num1, Factorial(num1), num2, Factorial(num2));
	}

}

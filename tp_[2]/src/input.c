#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>


static int getInt(int* pResultado);
static int esNumerica(char* cadena, int limite);
static int pedirString(char* cadena, int longitud);
static int esLetra(char* caracter);
static int esDescripcion(char* cadena, int longitud);
static int getDescripcion(char* pResultado, int longitud);
static int esNombre(char*cadena,int longitud);
static int getNombre(char*pResultado,int longitud);
static int getCuit(char* pResultado, int longitud);


/***
 * @brief Obtiene un numero Entero
 * @param pResultado Puntero al espacio de momeria donde se dejara el resultado de la funcion
 * @return retorna 0[EXITO] si se obtiene un numero entero y -1[ERROR]
 */
static int getInt(int* pResultado){

	int retorno = - 1;
	char bufferString[50];

	if(pResultado != NULL){
		  __fpurge(stdin);
		if(pedirString(bufferString, sizeof(bufferString)) == 0){
			if(esNumerica(bufferString, sizeof(bufferString))){
				retorno = 0;
				*pResultado = atoi(bufferString);
			}
		}
	}
	return retorno;
}
/***
 * @brief verifica si la cadena ingresada es numerica
 * @param cadena Cadena de caracteres a ser analizada
 * @return retorna 0[EXITO] si se obtiene un numero entero y -1[ERROR]
 */
static int esNumerica(char* cadena, int limite){
	int retorno = 1;//VERDADERO

	for(int i=0; i<limite && cadena[i] != '\0'; i++){
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0'){
			retorno = 0;
			break;
		}
	}
	return retorno;
}
/***
 * \brief Lee de stedin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 		  un maximo de 'longitud  -1' caracteres.
 * @param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
 * @param longitud Define el tamano de la cadena
 * @return retorna o [EXITO] si se obtine una cadena  o retenorna -1 [ERROR]
 */
static int pedirString(char* cadena, int longitud){

    int retorno = -1;
    char bufferString[4096];// esta va a cambiar.

    if(cadena != NULL && longitud > 0){
        __fpurge(stdin);
        if(fgets(bufferString, sizeof(bufferString),stdin) != NULL){

            if(bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] == '\n'){

                bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] = '\0';
            }
            if(strnlen(bufferString, sizeof(bufferString)) <= longitud){
                strncpy(cadena,bufferString,longitud);
                retorno = 0;
            }
        }
    }

    return retorno;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/***
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @return
 */


int utn_pedirNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo){

	int retorno = -1;
	int numero;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo){

		__fpurge(stdin);
		printf("%s", mensaje);

		if(getInt(&numero) == 0 && numero >= minimo && numero <= maximo ){
			*pResultado = numero;
			retorno = 0;
		}else{
			printf("%s", mensajeError);
		}
	}
	return retorno;
}
/***
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @return
 */
int utn_pedirfloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
	int retorno = -1;
	float bufferFloat;
	int i;

	for(i=0; i<=reintentos; i++){
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
			printf("%s", mensaje);
			__fpurge(stdin);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}else{
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}
/**@brief esLetra(): Verifica si la variable es una letra.
 * @param char* caracter: Variable a verificar.
 * @return (1) OK / (0) Error
 */
static int esLetra(char* caracter)
{
	int respuesta = 1;
	if((*caracter < 'a' || *caracter > 'z') &&
			(*caracter < 'A' || *caracter > 'Z'))
	{
		respuesta = 0;
	}
	return respuesta;
}
/**@brief utn_getChar(): Solicita un caracter char al usuario.
 * @param char* mensaje: Es el mensaje a ser mostrado al usuario.
 * @param char* mensajeError: Es el mensaje de error a ser mostrado al usuario.
 * @param char* pResultado: Puntero al espacio de memoria donde se dejara el valor obtenido.
 * @param int reintentos: Cantidad de oportunidades para ingresar el dato.
 * @param int maximo: Valor maximo admitido.
 * @param int minimo: Valor minimo admitido.
 * @return (-1) Error / (0) Ok
 */
int utn_pedirChar(char* mensaje, char* mensajeError, char* pResultado,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int resultadoScanf;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos > 0)
	{
		do
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			resultadoScanf = scanf("%c" , &bufferChar);
			if(resultadoScanf == 1 && esLetra(&bufferChar) == 1)
			{
				retorno = 0;
				*pResultado = bufferChar;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}


//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
/***
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * @param cadena Cadena de caracteres a ser analizada
 * @return retorna o [EXITO] si se obtine una cadena  o retenorna -1 [ERROR]
 */
static int esDescripcion(char* cadena, int longitud){

    int retorno = -1;

    if(cadena != NULL && longitud > 0){
        for(int i=0; cadena[i] != '\0' && i < longitud ; i++){

            if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
                retorno = 0;
            break;

        }
    }

    return retorno;
}
/***
 * \brief obtine un string valido como descripcion
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @return retorna o [EXITO] si se obtine una cadena  o retenorna -1 [ERROR]
 */
static int getDescripcion(char* pResultado, int longitud){

    int retorno = -1;
    char descripcion[4096];

    if(pResultado != NULL){
        if( pedirString(descripcion, sizeof(descripcion)) == 0 &&
        esDescripcion(descripcion,sizeof(descripcion)) &&
        strnlen(descripcion,sizeof(descripcion)) < longitud){

            strncpy(pResultado,descripcion,longitud);
            retorno = 0;
        }
    }

    return retorno;

}
static int esNombre(char*cadena,int longitud)
{
	int retorno=-1;
	int i=0;
	if(cadena != NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i < longitud;i++)
		{
			if((cadena[i]<'A'||cadena[i]>'Z')&& (cadena[i]<'a'||cadena[i]>'z'))
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
static int getNombre(char*pResultado,int longitud)
{
	int retorno=-1;
	char buffer[1000];
	if(pResultado !=NULL)
	{
		if(pedirString(buffer,sizeof(buffer))==0 &&
			esNombre(buffer,sizeof(buffer))&&
			strnlen(buffer,sizeof(buffer)<longitud))
			{
			strncpy(pResultado,buffer,longitud);
			retorno=0;
			}
	}
	return retorno;
}
int utn_pedirNombre(char* pResultado, int longitud, char* mensaje,char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = -1;
	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getNombre(bufferString,sizeof(bufferString))== 0 && strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
	    	printf("%s",mensajeError);
	}
	return retorno;
}
/***
 * \brief Solicita una descripcion al usuario, luego de verificar devuelve el resultado
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud Es la longitud del array resultado
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de error a ser mostrado
 * @return retorna o [EXITO] si se obtine una cadena  o retenorna -1 [ERROR]
 */
int utn_pedirAlfaNumerico(char* pResultado, int longitud, char* mensaje, char* mensajeError){

    char descripcion[4096];
    int retorno = -1;

    printf("%s", mensaje);
    if(getDescripcion(descripcion,sizeof(descripcion)) == 0 && strnlen(descripcion,sizeof(descripcion))){
        strncpy(pResultado, descripcion,longitud);
        retorno = 0;
       // break;
    }else{
         printf("%s",mensajeError);
    }


    return retorno;
}

/**
 * \brief Obtiene un string valido como CUIT
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getCuit(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[12];

    if(pResultado != NULL)
    {
    	if(	pedirString(buffer,sizeof(buffer))==0 &&
    		esNumerica(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))== 11 )//total
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
//=======================================================================================


/**
 * \brief Solicita un CUIT al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el CUIT y -1 si no
 *
 */
int utn_getCuit(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[12];
	int retorno = -1;
	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getCuit(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) == 11 )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
void getString(char cadena[],char mensaje[],int tam)
{
    char auxiliar[tam];

    printf("%s", mensaje);
    //fflush(stdin);
   // __fpurge(stdin);
   scanf("%s", auxiliar);
    //gets()
   // fgets(cadena,tam,stdin);
    strcpy(cadena, auxiliar);
}

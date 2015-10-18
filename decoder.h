#ifndef _DECODER_H_
#define	_DECODER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/** \file decoder.h
 *  \brief Archivo que contiene las estructuras ins-t y instruction_t, ademas se encuentran definidas las funciones para realizar las intrucciones del documento de texto
*/
/** \struct ins_t;
 *  \brief  Estructura que almacena las instrucciones del archivo de texto
 */

typedef struct
{
	char** array;   /*!< Arreglo que se utiliza con el fin de guardas las instrucciones del documento de texto en una memoria dinamica*/
}ins_t;

/** \struct instruction_t;
 *  \brief  Estructura que almacena cada instrucciones en sus diferentes partes
 */

typedef struct
{
	char mnemonic[10];  /*!< Guarda el mnemonico de la instruccion*/
	char op1_type;      /*!< Guarda el caracter del primer parametro de la instruccion*/
	char op2_type;      /*!< Guarda el caracter del segundo parametro de la intruccion*/
	char op3_type;      /*!< Guarda el caracter del tecer parametro de la intruccion*/
	uint32_t op1_value; /*!< Guarda el numero del primer parametro de la instruccion*/
    uint32_t op2_value; /*!< Guarda el numero del segundo parametro de la instruccion*/
	uint32_t op3_value; /*!< Guarda el numero del tercer parametro de la instruccion*/
	uint8_t  registers_list[16];
}instruction_t;


/** \fn void decodeInstruction(instruction_t instruction,uint32_t *registro,flags_t *bandera);
    \brief Decodifica la instrucción y la ejecuta.
    \param instruction instrucción a decodificar y ejecutar.
*/
void decodeInstruction(instruction_t instruction,int *Banderas,uint32_t *registro,uint8_t *SRAM,uint16_t *mnemonico_hex);

/** \fn instruction_t getInstruction(char* instStr)
    \brief Obtiene la instrucción separada por partes.
    \param instrStr cadena que contiene la instrucción.
	\return instruction_t la instrucción separada por partes.
*/
instruction_t getInstruction(char* instStr);

/** \fn int readFile(char** instructions)
    \brief Lee instrucciones de un archivo.
    \param filename Nombre del archivo.
    \param instructions estructura con arreglo con las instrucciones leidas.
	\return Entero indicando la cantidad de líneas.
*/
int readFile(char* filename, ins_t* instructions);

/** \fn int countLines(FILE fp)
    \brief Cuenta la cantidad de líneas de un archivo.
    \param fp Puntero al archivo.
	\return Entero con la cantidad de líneas del archivo.
*/
int countLines(FILE* fp);

#endif /*_DECODER_H_*/


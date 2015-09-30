#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** \file SRAM.h
 *  \brief Archivo que contiene las definiciones de las funciones SRAM
*/

/**
* \brief Funcion encargada de poner datos en SRAM
* \param *registro Arreglo de los registros de los cuales se tomaran solo los que se almacenaran
* \param *R Arreglo que me indicara que registros debo almacenar
* \param *SRAM Memoria
* \return No hay retorno de la funcion
*/
void PUSH(uint32_t *registro,uint8_t *R,uint8_t *SRAM);

void POP(uint32_t *registro,uint8_t *R,uint8_t *SRAM);

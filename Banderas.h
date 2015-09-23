#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** \file banderas.h
 *  \brief Archivo que contiene las definiciones de las funciones para la activacion de las bandera
*/

/**
* \brief Funcion donde se llevara a cabo la activacion de las banderas N Z C S
* \param Rd Resultado
* \param Rn Primer dato de la operacion realizada
* \param Rm Segundo dato de la operacion realizada
* \param Banderas Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm,int *Banderas);

/**
* \brief Funcion donde se llevara a cabo la activacion de las banderas N Z C
* \param Rd Resultado
* \param Rn Primer dato de la operacion realizada
* \param Rm Segundo dato de la operacion realizada
* \param Banderas Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void BANDERAS_1(uint32_t Rd,uint32_t Rn,uint32_t Rm,int *Banderas);

/**
* \brief Funcion donde se llevara a cabo la activacion de las banderas N Z
* \param Rd Resultado
* \param Rn Primer dato de la operacion realizada
* \param Rm Segundo dato de la operacion realizada
* \param Banderas Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void BANDERAS_2(uint32_t Rd,int *Banderas);

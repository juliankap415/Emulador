#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** \file Instrucciones_desplazamiento.h
 *  \brief Archivo que contiene las definiciones de las funciones de desplazamiento
*/

/**
* \brief Funcion suma
* \param *Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion logica AND, bit a bit
* \param *Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Primer dato a realizar la operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void ANDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion logica X-OR, bit a bit
* \param *Rd Dato donde se almacenara el resultado
* \param Rn Primer registro a relizar operacion
* \param Rm Primer registro a relizar operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void EORS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion realiza una copia de un registro en otro
* \param *Rd Dato donde se realizara la copia
* \param Rn Dato al que se le realizara una copia
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void MOVS(uint32_t *Rd,uint32_t Rn,int *flags);

/**
* \brief Funcion logica OR, bit a bit
* \param *Rd Dato donde se almacenara el resultado
* \param Rn Primer registro a relizar operacion
* \param Rm Primer registro a relizar operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void ORRS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion resta
* \param *Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void SUBS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion suma,pero solo modifica las banderas
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void CMNS(uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion resta, pero solo modifica las banderas
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void CMPS(uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion multiplica, guarda 32 bits menos significativos
* \param *Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void MULS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion suma con acarreo
* \param *Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void ADCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion resta con acarreo
* \param *Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void SBCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion logica AND, bit a bit pero solo modifica las banderas
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void TST(uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion que no realiza ninguna operacion
* \return No hay retorno de la funcion
*/
void NOP();



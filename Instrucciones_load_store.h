#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/** \file Instruciones_load_store.h
 *  \brief Archivo que contiene las definiciones de las funciones correpondiente a
*/

/**
* \brief Funcion de carga que asigna 4 espacio de la memoria
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a utilizar para especficar direccion
* \param Rm Rn Dato a utilizar para especficar direccion
* \param *SRAM Memoria
* \return No hay retorno de la funcion
*/
void LDR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/**
* \brief Funcion de carga que asigna 1 espacio de la memoria con extension de cero
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a utilizar para especficar direccion
* \param Rm Rn Dato a utilizar para especficar direccion
* \param *SRAM Memoria
* \return No hay retorno de la funcion
*/
void LDRB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/**
* \brief Funcion de carga que asigna 2 espacio de la memoria con extension de cero
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a utilizar para especficar direccion
* \param Rm Rn Dato a utilizar para especficar direccion
* \param *SRAM Memoria
* \return No hay retorno de la funcion
*/
void LDRH(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/**
* \brief Funcion de carga que asigna 1 espacio de la memoria con extension de signo
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a utilizar para especficar direccion
* \param Rm Rn Dato a utilizar para especficar direccion
* \param *SRAM Memoria
* \return No hay retorno de la funcion
*/
void LDRSB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/**
* \brief Funcion de carga que asigna 2 espacio de la memoria con extension de signo
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a utilizar para especficar direccion
* \param Rm Rn Dato a utilizar para especficar direccion
* \param *SRAM Memoria
* \return No hay retorno de la funcion
*/
void LDRSH(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/**
* \brief Funcion de almacenamiento que guarda 4 espacios de la memoria
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a utilizar para especficar direccion
* \param Rm Rn Dato a utilizar para especficar direccion
* \param *SRAM Memoria
* \return No hay retorno de la funcion
*/
void STR(uint32_t Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/**
* \brief Funcion de almacenamiento que guarda 1 espacio de la memoria
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a utilizar para especficar direccion
* \param Rm Rn Dato a utilizar para especficar direccion
* \param *SRAM Memoria
* \return No hay retorno de la funcion
*/
void STRB(uint32_t Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

/**
* \brief Funcion de almacenamiento que guarda 2 espacios de la memoria
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a utilizar para especficar direccion
* \param Rm Rn Dato a utilizar para especficar direccion
* \param *SRAM Memoria
* \return No hay retorno de la funcion
*/
void STRH(uint32_t Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM);

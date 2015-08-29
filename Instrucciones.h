#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/**
* \brief Funcion suma
* \param Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \return entero sin signo de 32 bits
*/
uint32_t ADDS(uint32_t Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion realiza operación lógica AND bit a bit
* \param Rn Primer dato a realizar la operacion
* \param Rm Primer dato a realizar la operacion
* \return entero sin signo de 32 bits
*/
uint32_t AND(uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion realiza operación lógica X-OR bit a bit
* \param Rn Primer registro a relizar operacion
* \param Rm Primer registro a relizar operacion
* \return entero sin signo de 32 bits
*/
uint32_t EOR(uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion realiza una copia
* \param Rn Dato al que se le realizara una copia
* \return entero sin signo de 32 bits
*/
uint32_t MOV(uint32_t Rn);

/**
* \brief Funcion realiza operación logica OR bit a bit
* \param Rn Primer registro a relizar operacion
* \param Rm Primer registro a relizar operacion
* \return entero sin signo de 32 bits
*/
uint32_t ORR(uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion resta
* \param Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operación
* \param Rm Segundo dato a realizar la operación
* \return entero sin signo de 32 bits
*/
uint32_t SUBS(uint32_t Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Funcion realiza la activacion de las banderas
* \param Rd Dato principal a verificar la activacion de banderas
* \param Rn Primer dato de la operacion
* \param Rm Segundo dato de la operacion
* \param Banderas Arreglo donde se almacenara las banderas
* \return No retorna
*/
void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm,int* Banderas);


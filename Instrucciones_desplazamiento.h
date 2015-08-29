#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/**
* \brief Desplazamiento logico a la izquierda
* \param Rd Donde se almacenara el resultado
* \param Rn Dato que se modificara
* \param Rm Numero de desplazamientos
* \return entero sin signo de 32 bits
*/
uint32_t LSL(uint32_t Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Desplazamiento logico a la derecha
* \param Rd Donde se almacenara el resultado
* \param Rn Dato que se modificara
* \param Rm Numero de desplazamientos
* \return entero sin signo de 32 bits
*/
uint32_t LSR(uint32_t Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Rotacion a la derecha
* \param Rd Dato que se modificara
* \param Rm Numero de desplazamientos
* \return entero sin signo de 32 bits
*/
uint32_t ROR(uint32_t Rd,uint32_t Rm);

/**
* \brief Desplazamiento aritmetico a la derecha
* \param Rd Donde se almacenara el resultado
* \param Rn Dato que se desplazara pero conservara su signo
* \param Rm Numero de desplazamientos
* \return entero sin signo de 32 bits
*/
uint32_t ASR(uint32_t Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Operacion logica AND entre un dato y el complemento del otro dato
* \param Rd Primer operador de la operacion AND
* \param Rn Segundo operador de la operacion AND, al cual se le hara el complemento
* \return entero sin signo de 32 bits
*/
uint32_t BIC(uint32_t Rd,uint32_t Rm);

/**
* \brief Guardar el complemento de un dato
* \param Rm Dato al que se le hara el complemento
* \return entero sin signo de 32 bits
*/
uint32_t MVN(uint32_t Rm);

/**
* \brief Complemento a dos
* \param Rm Dato al que se le hara el complemento a dos
* \return entero sin signo de 32 bits
*/
uint32_t RSB(uint32_t Rm);

/**
* \brief Cambiar el orden de los bytes
* \param Rd Donde se almacenara el resultado
* \param Rm Datos que se modificara en bytes
* \return entero sin signo de 32 bits
*/
uint32_t REV(uint32_t Rd,uint32_t Rm);

uint32_t REV16(uint32_t Rd,uint32_t Rm);

uint32_t REVSH(uint32_t Rd,uint32_t Rm);

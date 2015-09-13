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
void LSL(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Desplazamiento logico a la derecha
* \param Rd Donde se almacenara el resultado
* \param Rn Dato que se modificara
* \param Rm Numero de desplazamientos
* \return entero sin signo de 32 bits
*/
void LSR(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Rotacion a la derecha
* \param Rd Dato que se modificara
* \param Rm Numero de desplazamientos
* \return entero sin signo de 32 bits
*/
void ROR(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Desplazamiento aritmetico a la derecha
* \param Rd Donde se almacenara el resultado
* \param Rn Dato que se desplazara pero conservara su signo
* \param Rm Numero de desplazamientos
* \return entero sin signo de 32 bits
*/
void ASR(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Operacion logica AND entre un dato y el complemento del otro dato
* \param Rd Primer operador de la operacion AND
* \param Rn Segundo operador de la operacion AND, al cual se le hara el complemento
* \return entero sin signo de 32 bits
*/
void BIC(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Guardar el complemento de un dato
* \param Rm Dato al que se le hara el complemento
* \return entero sin signo de 32 bits
*/
void MVN(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Complemento a dos
* \param Rm Dato al que se le hara el complemento a dos
* \return entero sin signo de 32 bits
*/
void RSB(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Cambiar el orden de los bytes
* \param Rd Donde se almacenara el resultado
* \param Rm Datos que se modificara en bytes
* \return entero sin signo de 32 bits
*/
void REV(uint32_t *Rdn,uint32_t Rm,int *flags);

void REV16(uint32_t *Rdn,uint32_t Rm,int *flags);

void REVSH(uint32_t Rd,uint32_t Rm,int *flags);

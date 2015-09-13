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
void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion realiza operación lógica AND bit a bit
* \param Rn Primer dato a realizar la operacion
* \param Rm Primer dato a realizar la operacion
* \return entero sin signo de 32 bits
*/
void AND(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion realiza operación lógica X-OR bit a bit
* \param Rn Primer registro a relizar operacion
* \param Rm Primer registro a relizar operacion
* \return entero sin signo de 32 bits
*/
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion realiza una copia
* \param Rn Dato al que se le realizara una copia
* \return entero sin signo de 32 bits
*/
void MOV(uint32_t *Rd,uint32_t Rn);

/**
* \brief Funcion realiza operación logica OR bit a bit
* \param Rn Primer registro a relizar operacion
* \param Rm Primer registro a relizar operacion
* \return entero sin signo de 32 bits
*/
void ORR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion resta
* \param Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operación
* \param Rm Segundo dato a realizar la operación
* \return entero sin signo de 32 bits
*/
void SUBS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

void CMN(uint32_t Rn,uint32_t Rm,int *flags);

void CMP(uint32_t Rn,uint32_t Rm,int *flags);

void MUL(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

void TST(uint32_t Rn,uint32_t Rm,int *flags);

void NOP();

void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm,int *Banderas);

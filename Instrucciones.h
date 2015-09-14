#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
* \brief Funcion suma
* \param Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param flags Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion logica AND, bit a bit
* \param Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Primer dato a realizar la operacion
* \param flags Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void AND(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion logica X-OR, bit a bit
* \param Rd Dato donde se almacenara el resultado
* \param Rn Primer registro a relizar operacion
* \param Rm Primer registro a relizar operacion
* \param flags Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion realiza una copia de un registro en otro
* \param Rd Dato donde se realizara la copia
* \param Rn Dato al que se le realizara una copia
* \return No retorna
*/
void MOV(uint32_t *Rd,uint32_t Rn);

/**
* \brief Funcion logica OR, bit a bit
* \param Rd Dato donde se almacenara el resultado
* \param Rn Primer registro a relizar operacion
* \param Rm Primer registro a relizar operacion
* \param flags Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void ORR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion resta
* \param Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param flags Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void SUBS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion suma,pero solo modifica las banderas
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param flags Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void CMN(uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion resta, pero solo modifica las banderas
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param flags Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void CMP(uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion multiplica, guarda 32 bits menos significativos
* \param Rd Dato donde se almacenara el resultado
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param flags Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void MUL(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion logica AND, bit a bit pero solo modifica las banderas
* \param Rn Primer dato a realizar la operacion
* \param Rm Segundo dato a realizar la operacion
* \param flags Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void TST(uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Funcion que no realiza ninguna operacion
* \return No retorna
*/
void NOP();

/**
* \brief Funcion donde se llevara a cabo la activacion de las banderas
* \param Rd Resultado
* \param Rn Primer dato de la operacion realizada
* \param Rm Segundo dato de la operacion realizada
* \param Banderas Arreglo donde se almacenaran las banderas
* \return No retorna
*/
void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm,int *Banderas);

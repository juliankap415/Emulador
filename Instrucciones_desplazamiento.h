#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
* \brief Desplazamiento logico a la izquierda
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a desplazar
* \param Rm Numero de desplazamientos
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void LSLS(uint32_t *Rdn,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Desplazamiento logico a la izquierda
* \param *Rdn Dato donde se almacenara el resultado
* \param Rn Dato a desplazar
* \param Rm Numero de desplazamientos
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void LSRS(uint32_t *Rdn,uint32_t Rn,uint32_t Rm,int *flags);

/**
* \brief Rotacion a la derecha
* \param *Rdn Dato que se rotara
* \param Rm Orden de la rotacion
* \return No hay retorno de la funcion
*/
void ROR(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Desplazamiento aritmetico a la derecha
* \param *Rdn Dato que se desplazara
* \param Rm Numero de desplazamientos
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void ASR(uint32_t *Rdn,uint32_t Rm,uint32_t Rn,int *flags);

/**
* \brief Operacion logica AND entre un dato y el complemento del otro dato
* \param *Rdn Primer operador de la operacion AND
* \param Rm Segundo operador de la operacion AND, al cual se le hara el complemento
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void BIC(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Guardar el complemento de un dato
* \param Rdn Donde se almacenara el dato
* \param Rm Dato al que se le hara el complemento
* \param flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void MVN(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Complemento a dos de un dato
* \param Rdn Donde se almacenara el dato
* \param Rm Dato al que se le hara el complemento a dos
* \param flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void RSB(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Cambiar el orden de los bytes
* \param Rdn Donde se almacenara el resultado
* \param Rm Dato que se le cambiara el orden de los bytes
* \param flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void REV(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Cambiar el orden de los bytes en cada halfword de 16bits
* \param Rdn Donde se almacenara el resultado
* \param Rm Dato que se le cambiara el orden de los bytes
* \param flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void REV16(uint32_t *Rdn,uint32_t Rm,int *flags);

/**
* \brief Cambiar el orden de los bytes del halfword bajo
* \param *Rdn Donde se almacenara el resultado
* \param Rm Dato que se le cambiara el orden de los bytes
* \param *flags Arreglo donde se almacenaran las banderas
* \return No hay retorno de la funcion
*/
void REVSH(uint32_t *Rdn,uint32_t Rm,int *flags);

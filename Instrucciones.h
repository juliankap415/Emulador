#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/**
* \brief Función realiza suma entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación suma
*/
uint32_t ADDS(uint32_t Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Función realiza operación lógica AND entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación AND
*/
uint32_t AND(uint32_t Rn,uint32_t Rm);

/**
* \brief Función realiza operación lógica X-OR entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación X-OR
*/
uint32_t EOR(uint32_t Rn,uint32_t Rm);

/**
* \brief Realiza una copia del registro 2 a registro 1
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Copia de registro
*/
uint32_t MOV(uint32_t Rn);

/**
* \brief Función realiza operación lógica OR entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación OR
*/
uint32_t ORR(uint32_t Rn,uint32_t Rm);

/**
* \brief Función realiza resta entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operación
* \param Registro2 Primer registro a relizar operación
* \return Operación resta
*/
uint32_t SUBS(uint32_t Rd,uint32_t Rn,uint32_t Rm);

void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm, uint32_t* Banderas);


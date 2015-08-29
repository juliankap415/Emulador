#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/**
* \brief Funci�n realiza suma entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operaci�n
* \param Registro2 Primer registro a relizar operaci�n
* \return Operaci�n suma
*/
uint32_t ADDS(uint32_t Rd,uint32_t Rn,uint32_t Rm);

/**
* \brief Funci�n realiza operaci�n l�gica AND entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operaci�n
* \param Registro2 Primer registro a relizar operaci�n
* \return Operaci�n AND
*/
uint32_t AND(uint32_t Rn,uint32_t Rm);

/**
* \brief Funci�n realiza operaci�n l�gica X-OR entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operaci�n
* \param Registro2 Primer registro a relizar operaci�n
* \return Operaci�n X-OR
*/
uint32_t EOR(uint32_t Rn,uint32_t Rm);

/**
* \brief Realiza una copia del registro 2 a registro 1
* \param Registro1 Primer registro a relizar operaci�n
* \param Registro2 Primer registro a relizar operaci�n
* \return Copia de registro
*/
uint32_t MOV(uint32_t Rn);

/**
* \brief Funci�n realiza operaci�n l�gica OR entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operaci�n
* \param Registro2 Primer registro a relizar operaci�n
* \return Operaci�n OR
*/
uint32_t ORR(uint32_t Rn,uint32_t Rm);

/**
* \brief Funci�n realiza resta entre  registro 1 y registro 2
* \param Registro1 Primer registro a relizar operaci�n
* \param Registro2 Primer registro a relizar operaci�n
* \return Operaci�n resta
*/
uint32_t SUBS(uint32_t Rd,uint32_t Rn,uint32_t Rm);

void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm, uint32_t* Banderas);


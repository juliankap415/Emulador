#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
* \brief Funcion de salto, si los datos son iguales
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BEQ(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si los datos no son iguales
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BNE(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si un dato es mayor o igual a otro (sin signo)
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BCS(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si un dato es menor a otro (sin signo)
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BCC(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si el dato es negativo
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BMI(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si el dato es positivo
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BPL(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si hay sobreflujo
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BVS(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si no hay sobreflujo
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BVC(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si un dato es mayor que el otro (sin signo)
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BHI(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si un dato es mayor o igual a otro (sin signo)
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BLS(uint32_t *registro,int Salto,int *Banderas);
/**
* \brief Funcion de salto, si un dato es mayor o igual a otro (con signo)
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BGE(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si un dato es menor a otro (con signo)
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BLT(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si un dato es mayor a otro (con signo)
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BGT(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, si un dato es menor o igual a otro (con signo)
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \param Banderas Quien se analizara para ver si se realiza el salto
* \return No retorna
*/
void BLE(uint32_t *registro,int Salto,int *Banderas);

/**
* \brief Funcion de salto, sin condicion
* \param PC Intrucciones a la que se le hara el salto correspondiente
* \param Saltos correspondientes a realizar
* \return No retorna
*/
void B(uint32_t *registro,int Salto);

void BL(uint32_t *registro,int salto);

void BX(uint32_t *registro);

void BLX(uint32_t *registro,uint32_t Registro);


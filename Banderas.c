#include "Banderas.h"

/**\file banderas.c
*\brief Contiene las funciones para la correcta activacion de las banderas N,Z,C,V
*/

void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm,int *Banderas)    //banderas para funciones aritmeticas
{
    uint32_t referencia=2147483648UL;                               //valor (2^32/2)-1

    //Bandera de negativo
    if (Rd>>31==1)           //Si Rd supera a la referencia entonces Rd es negativo
        *(Banderas+0)=1;        //se activa la bandera N

    else
        *(Banderas+0)=0;

    //Bandera de cero
    if (Rd==0)
        *(Banderas+1)=1;        //se activa la bandera Z

    else
        *(Banderas+1)=0;

    //Bandera de acarreo
    if (((Rn>=referencia)&&(Rm<referencia)&&(Rd<referencia))||((Rm>=referencia)&&(Rn<referencia)&&(Rd<referencia))||((Rn>=referencia)&&(Rm>=referencia)))
        *(Banderas+2)=1;        //se activa la bandera C

    else
        *(Banderas+2)=0;

    //Bandera de sobre flujo
    if(((Rn>=referencia)&&(Rm>=referencia)&&(Rd<referencia))||((Rn<referencia)&&(Rm<referencia)&&(Rd>=referencia)))
        *(Banderas+3)=1;                    //se activa la bandera V

	else
		*(Banderas+3)=0;
}

void BANDERAS_1(uint32_t Rd,uint32_t Rn,uint32_t Rm,int *Banderas)    //banderas para funciones aritmeticas que no modifican sobreflujo
{
    uint32_t referencia=2147483648UL;                               //valor (2^32/2)-1

    //Bandera de negativo
    if (Rd>>31==1)           //Si Rd supera a la referencia entonces Rd es negativo
        *(Banderas+0)=1;        //se activa la bandera N

    else
        *(Banderas+0)=0;

    //Bandera de cero
    if (Rd==0)
        *(Banderas+1)=1;        //se activa la bandera Z

    else
        *(Banderas+1)=0;

    //Bandera de acarreo
    if (((Rn>=referencia)&&(Rm<referencia)&&(Rd<referencia))||((Rm>=referencia)&&(Rn<referencia)&&(Rd<referencia))||((Rn>=referencia)&&(Rm>=referencia)))
        *(Banderas+2)=1;        //se activa la bandera C

    else
        *(Banderas+2)=0;

}

void BANDERAS_2(uint32_t Rd,int *Banderas)    //banderas para funciones de desplazamiento
{
    //Bandera de negativo
    if (Rd>>31==1)           //Si Rd supera a la referencia entonces Rd es negativo
        *(Banderas+0)=1;        //se activa la bandera N

    else
        *(Banderas+0)=0;

    //Bandera de cero
    if (Rd==0)
        *(Banderas+1)=1;        //se activa la bandera Z

    else
        *(Banderas+1)=0;
}


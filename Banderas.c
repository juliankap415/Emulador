#include "Banderas.h"

/**\file banderas.c
*\brief Contiene las funciones para la correcta activacion de las banderas N,Z,C,V
*/

void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm,int *Banderas)    //banderas para funciones aritmeticas
{
    uint32_t referencia=2147483647;                                 //valor (2^32/2)-1
    uint32_t aux1,aux2,aux3;                                        //aux1 guarda el bit mas significativo de Rn
                                                                    //aux2 guarda el bit mas significativo de Rm
                                                                    //aux3 guarda el bit mas significativo de Rd
    //Bandera de negativo
    if (Rd>>31==1)           //Si Rd supera a la referencia entonces Rd es negativo
    {
        *(Banderas+0)=1;        //se activa la bandera N
    }

    else
    {
        *(Banderas+0)=0;
    }

    //Bandera de cero
    if (Rd==0)
    {
        *(Banderas+1)=1;        //se activa la bandera Z
    }

    else
    {
        *(Banderas+1)=0;
    }

    //Bandera de acarreo
    if (Rd>(referencia))
    {
        *(Banderas+2)=1;        //se activa la bandera C
    }

    else
    {
        *(Banderas+2)=0;
    }

    //Bandera de sobre flujo
    aux1=Rn>>31;
    aux2=Rm>>31;
    aux3=Rd>>31;

    if((aux1==aux2)&&(aux3!=aux1))
		{
			*(Banderas+3)=1;                    //se activa la bandera V
		}

	else
	{
		*(Banderas+3)=0;
	}
}

void BANDERAS_DES(uint32_t Rd,int *Banderas)    //banderas para funciones de desplazamiento
{
    uint32_t referencia=2147483647;

    //Bandera de negativo
    if (Rd>referencia)
    {
        *(Banderas+0)=1;            //se activa la bandera N
    }

    else
    {
        *(Banderas+0)=0;
    }

    //Bandera de cero
    if (Rd==0)
    {
        *(Banderas+1)=1;            //se activa la bandera Z
    }

    else
    {
        *(Banderas+1)=0;
    }

    //Bandera de acarreo
    *(Banderas+2)=0;                //para estas funciones, no se activa la bandera C ni V

    //Bandera de sobre flujo
    *(Banderas+3)=0;
}


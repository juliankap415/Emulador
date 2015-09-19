#include "Banderas.h"

/**\file banderas.c
*\brief libreria encargada de activar o desactivar las banderas
*/

void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm,int *Banderas)    //banderas para funciones aritmeticas
{
    uint32_t referencia=2147483647;

    //Bandera de negativo
    if (Rd>referencia)
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
    if((Rn&(referencia)) == (Rm&referencia))
	{
		if((Rn&referencia) != (Rd&referencia))
		{
			*(Banderas+3)=1;                    //se activa la bandera V
		}
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


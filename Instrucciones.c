#include "Instrucciones.h"

void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn+Rm;
    BANDERAS(Rd,Rn,Rm,flags);
}

void AND(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn&Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void EOR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn^Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void MOV(uint32_t *Rd,uint32_t Rn)
{
    *Rd=Rn;
}

void ORR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn|Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void SUBS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn-Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void CMN(uint32_t Rn,uint32_t Rm,int *flags)
{
    BANDERAS(Rn+Rm,0,0,flags);
}

void CMP(uint32_t Rn,uint32_t Rm,int *flags)
{
    BANDERAS(Rn-Rm,0,0,flags);
}

void MUL(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn*Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void TST(uint32_t Rn,uint32_t Rm,int *flags)
{
    BANDERAS(Rn&Rm,0,0,flags);
}

void NOP()
{

}

void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm,int *Banderas)
{
    uint32_t referencia=2147483647;

    //Bandera de negativo
    if (Rd>referencia)
    {
        *(Banderas+0)=1;
    }

    else
    {
        *(Banderas+0)=0;
    }

    //Bandera de cero
    if (Rd==0)
    {
        *(Banderas+1)=1;
    }

    else
    {
        *(Banderas+1)=0;
    }

    //Bandera de acarreo
    if (Rd>(referencia))
    {
        *(Banderas+2)=1;
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
			*(Banderas+3)=1; // bandera de sobreflujo igual a 1
		}
	}
	else
	{
		*(Banderas+3)=0;
	}
}



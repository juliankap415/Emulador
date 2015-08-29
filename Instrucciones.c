#include "Instrucciones.h"


uint32_t ADDS(uint32_t Rd,uint32_t Rn,uint32_t Rm)
{
    Rd=Rn+Rm;

    return Rd;
}

uint32_t AND(uint32_t Rn,uint32_t Rm)
{
    return Rn&Rm;
}

uint32_t EOR(uint32_t Rn,uint32_t Rm)
{
    return Rn^Rm;
}

uint32_t MOV(uint32_t Rn)
{
    return Rn;
}

uint32_t ORR(uint32_t Rn,uint32_t Rm)
{
    return Rn|Rm;
}

uint32_t SUBS(uint32_t Rd,uint32_t Rn,uint32_t Rm)
{
    Rd=Rn-Rm;

    return Rd;;
}

void BANDERAS(uint32_t Rd,uint32_t Rn,uint32_t Rm,uint32_t* Banderas)
{
    uint32_t referencia=(2^32)/2;//2147483648

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
    if (Rd>((referencia*2)-1))
    {
        *(Banderas+2)=1;
    }

    else
    {
        *(Banderas+2)=0;
    }

    //Bandera de sobre flujo
    *(Banderas+1);

}

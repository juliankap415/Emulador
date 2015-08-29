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


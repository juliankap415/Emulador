#include "Instrucciones.h"
#include "Banderas.h"

/**\file Instrucciones.c
*\brief libreria encargada de realizar las funciones aritmeticas
*/

void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn+Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void ANDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn&Rm;
    BANDERAS_1(*Rd,Rn,Rm,flags);
}

void EORS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn^Rm;
    BANDERAS_1(*Rd,Rn,Rm,flags);
}

void MOVS(uint32_t *Rd,uint32_t Rn,int *flags)
{
    *Rd=Rn;
    BANDERAS_2(*Rd,flags);
}

void ORRS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn|Rm;
    BANDERAS_1(*Rd,Rn,Rm,flags);
}

void SUBS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn+(~Rm+1);
    BANDERAS(*Rd,Rn,~Rm+1,flags);
}

void CMNS(uint32_t Rn,uint32_t Rm,int *flags)
{
    BANDERAS(Rn+Rm,Rn,Rm,flags);
}

void CMPS(uint32_t Rn,uint32_t Rm,int *flags)
{
    BANDERAS(Rn+(~Rm+1),Rn,~Rm+1,flags);
}

void MULS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn*Rm;
    BANDERAS_2(*Rd,flags);
}

void TST(uint32_t Rn,uint32_t Rm,int *flags)
{
    BANDERAS_1(Rn&Rm,Rn,Rm,flags);
}

void NOP()
{

}

void ADCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn+Rm+*(flags+2);
    BANDERAS(*Rd,Rn,Rm,flags);
}

void SBCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn+~Rm+*(flags+2);
    BANDERAS(*Rd,Rn,Rm,flags);
}





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
    BANDERAS(*Rd,Rn,Rm,flags);
}

void EORS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn^Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void MOVS(uint32_t *Rd,uint32_t Rn)
{
    *Rd=Rn;
}

void ORRS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn|Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void SUBS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn+~Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void CMNS(uint32_t Rn,uint32_t Rm,int *flags)
{
    BANDERAS(Rn+Rm,Rn,Rm,flags);
}

void CMPS(uint32_t Rn,uint32_t Rm,int *flags)
{
    BANDERAS(Rn+~Rm,Rn,Rm,flags);
}

void MULS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn*Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
}

void TST(uint32_t Rn,uint32_t Rm,int *flags)
{
    BANDERAS(Rn&Rm,Rn,Rm,flags);
}

void NOP()
{

}

void ADCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn+Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
    *Rd=Rn+Rm+*(flags+2);
}

void SBCS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn+~Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
    *Rd=Rn+~Rm+*(flags+2);
}





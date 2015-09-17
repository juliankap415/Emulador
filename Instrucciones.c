#include "Instrucciones.h"
#include "Banderas.h"

void ADDS(uint32_t *Rd,uint32_t Rn,uint32_t Rm,int *flags)
{
    *Rd=Rn+Rm;
    BANDERAS(*Rd,Rn,Rm,flags);
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





#include "Instrucciones_saltos.h"

void EQ(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if (*(Banderas+1)==1)
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+1;
    }
}

void NE(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if (*(Banderas+1)==0)
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void CS(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if (*(Banderas+2)==1)
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void CC(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if (*(Banderas+2)==0)
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void MI(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if (*(Banderas+0)==1)
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void PL(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if (*(Banderas+0)==0)
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void VS(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if (*(Banderas+3)==1)
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void VC(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if (*(Banderas+3)==0)
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void HI(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if ((*(Banderas+2)==1)&&(*(Banderas+1)==0))
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void LS(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if ((*(Banderas+2)==0)&&(*(Banderas+1)==1))
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void GE(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if ((*(Banderas+0)==(*(Banderas+3))))
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void LT(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if ((*(Banderas+0)!=(*(Banderas+3))))
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void GT(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if ((*(Banderas+1)==0)&&(*(Banderas+0)==*(Banderas+3)))
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void LE(uint32_t *PC,uint32_t Saltos,int *Banderas)
{
    if ((*(Banderas+1)==0)||(*(Banderas+0)!=*(Banderas+3)))
    {
        *PC=*PC+Saltos;
    }
    else
    {
        *PC=*PC+2;
    }
}

void AL(uint32_t *PC,uint32_t Saltos)
{
    *PC=*PC+Saltos;
}

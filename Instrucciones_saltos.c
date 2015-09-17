
#include "Instrucciones_saltos.h"

void BEQ(uint32_t *PC,int Salto,int *Banderas)
{
    if (*(Banderas+1)==1)                           //Condicion para poder realizar el salto
    {
        *PC=*PC+Salto;                                  //Se realiza el salto a la direccion especifica
    }
    else
    {
        *PC=*PC+2;                                  //No se realiza el salto y va a la siguiente direccion
    }
}

void BNE(uint32_t *PC,int Salto,int *Banderas)
{
    if (*(Banderas+1)==0)
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BCS(uint32_t *PC,int Salto,int *Banderas)
{
    if (*(Banderas+2)==1)
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BCC(uint32_t *PC,int Salto,int *Banderas)
{
    if (*(Banderas+2)==0)
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BMI(uint32_t *PC,int Salto,int *Banderas)
{
    if (*(Banderas+0)==1)
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BPL(uint32_t *PC,int Salto,int *Banderas)
{
    if (*(Banderas+0)==0)
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BVS(uint32_t *PC,int Salto,int *Banderas)
{
    if (*(Banderas+3)==1)
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BVC(uint32_t *PC,int Salto,int *Banderas)
{
    if (*(Banderas+3)==0)
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BHI(uint32_t *PC,int Salto,int *Banderas)
{
    if ((*(Banderas+2)==1)&&(*(Banderas+1)==0))
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BLS(uint32_t *PC,int Salto,int *Banderas)
{
    if ((*(Banderas+2)==0)&&(*(Banderas+1)==1))
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BGE(uint32_t *PC,int Salto,int *Banderas)
{
    if ((*(Banderas+0)==(*(Banderas+3))))
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BLT(uint32_t *PC,int Salto,int *Banderas)
{
    if ((*(Banderas+0)!=(*(Banderas+3))))
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BGT(uint32_t *PC,int Salto,int *Banderas)
{
    if ((*(Banderas+1)==0)&&(*(Banderas+0)==*(Banderas+3)))
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void BLE(uint32_t *PC,int Salto,int *Banderas)
{
    if ((*(Banderas+1)==0)||(*(Banderas+0)!=*(Banderas+3)))
    {
        *PC=*PC+Salto;
    }
    else
    {
        *PC=*PC+2;
    }
}

void B(uint32_t *PC,int Salto)
{
    *PC=*PC+Salto;
}

void BL(uint32_t *PC,int salto,uint32_t *LR)
{
    *LR=*PC+2;
    *PC+=salto;
}

void BX(uint32_t *PC,uint32_t *LR)          //cambiamos LR por el registro 14
{
    *PC=*LR;
}

void BLX(uint32_t *PC,uint32_t registro,uint32_t *LR)          //cambiamos LR por el registro 14
{
    *LR=*PC+2;
    *PC+=registro;
}



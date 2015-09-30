
#include "Instrucciones_saltos.h"

/**\file Instrucciones_saltos.c
*\brief libreria encargada de realizar las funciones saltos
*/

void BEQ(uint32_t *registro,int Salto,int *Banderas)
{
    if (*(Banderas+1)==1)                           //Condicion para poder realizar el salto
    {
        *(registro+15)+=Salto;                                  //Se realiza el salto a la direccion especifica
    }
    else
    {
        *(registro+15)+=1;                                  //No se realiza el salto y va a la siguiente direccion
    }
}

void BNE(uint32_t *registro,int Salto,int *Banderas)
{
    if (*(Banderas+1)==0)
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BCS(uint32_t *registro,int Salto,int *Banderas)
{
    if (*(Banderas+2)==1)
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BCC(uint32_t *registro,int Salto,int *Banderas)
{
    if (*(Banderas+2)==0)
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BMI(uint32_t *registro,int Salto,int *Banderas)
{
    if (*(Banderas+0)==1)
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BPL(uint32_t *registro,int Salto,int *Banderas)
{
    if (*(Banderas+0)==0)
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BVS(uint32_t *registro,int Salto,int *Banderas)
{
    if (*(Banderas+3)==1)
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BVC(uint32_t *registro,int Salto,int *Banderas)
{
    if (*(Banderas+3)==0)
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BHI(uint32_t *registro,int Salto,int *Banderas)
{
    if ((*(Banderas+2)==1)&&(*(Banderas+1)==0))
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BLS(uint32_t *registro,int Salto,int *Banderas)
{
    if ((*(Banderas+2)==0)&&(*(Banderas+1)==1))
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BGE(uint32_t *registro,int Salto,int *Banderas)
{
    if ((*(Banderas+0)==(*(Banderas+3))))
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BLT(uint32_t *registro,int Salto,int *Banderas)
{
    if ((*(Banderas+0)!=(*(Banderas+3))))
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BGT(uint32_t *registro,int Salto,int *Banderas)
{
    if ((*(Banderas+1)==0)&&(*(Banderas+0)==*(Banderas+3)))
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void BLE(uint32_t *registro,int Salto,int *Banderas)
{
    if ((*(Banderas+1)==0)||(*(Banderas+0)!=*(Banderas+3)))
    {
        *(registro+15)+=Salto;
    }
    else
    {
        *(registro+15)+=1;
    }
}

void B(uint32_t *registro,int Salto)
{
    *(registro+15)+=Salto;
}

void BL(uint32_t *registro,int salto)
{
    *(registro+14)=*(registro+15)+2;
    *(registro+15)+=salto;
}

void BX(uint32_t *registro,uint32_t Salto)
{
    *(registro+15)=Salto;
}

void BLX(uint32_t *registro,uint32_t Registro)
{
    *(registro+14)=*(registro+15)+2;
    *(registro+15)+=Registro;
}



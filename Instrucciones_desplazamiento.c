#include "Instrucciones_desplazamiento.h"
#include "Banderas.h"

typedef union
{
    uint32_t data;
    struct
    {
        uint8_t byte0;
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
    };
}u32tobyte_t;

void LSL(uint32_t *Rdn,uint32_t Rm,int *flags) //desplazamiento hacia la izquierda
{
    *Rdn=*Rdn<<Rm; //bit de Rn se desplazan tantas veces indique Rm
    BANDERAS_DES(*Rdn,flags);
}

void LSR(uint32_t *Rdn,uint32_t Rm,int *flags) //desplazamiento hacia la derecha
{
    *Rdn=*Rdn>>Rm; //bit de Rn se desplazan tantas veces indique Rm
    BANDERAS_DES(*Rdn,flags);
}

void ROR(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    uint32_t aux1,aux2; //variables auxiiares
    aux1=*Rdn>>Rm;        //aux1 almacenara los primeros bits
    aux2=*Rdn<<(32-Rm);   //aux2 almacenara los ultimos bits
    *Rdn=aux1+aux2;
    BANDERAS_DES(*Rdn,flags);
}

void ASR(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    uint32_t aux;

    aux=*Rdn>>31;     //conocer el signo del numero
    aux=aux<<31;
    *Rdn=*Rdn>>Rm;
    *Rdn=*Rdn+aux;
    BANDERAS_DES(*Rdn,flags);
}

void BIC(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    *Rdn=*Rdn&(~Rm);
    BANDERAS_DES(*Rdn,flags);
}

void MVN(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    *Rdn=~Rm;
    BANDERAS_DES(*Rdn,flags);
}

void RSB(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    *Rdn=~Rm+1;
    BANDERAS_DES(*Rdn,flags);
}

void REV(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    u32tobyte_t R;

    R.data = Rm;
    *Rdn= (uint32_t)(R.byte0 << 24) | (uint32_t)(R.byte3) | (uint32_t)(R.byte1 << 16) | (uint32_t)(R.byte2 << 8);
    BANDERAS_DES(*Rdn,flags);
}

void REV16(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    u32tobyte_t R;
    R.data = Rm;
    *Rdn = (uint32_t)(R.byte0 << 16) | (uint32_t)(R.byte3<<8) | (uint32_t)(R.byte1 << 24) | (uint32_t)(R.byte2);
    BANDERAS_DES(*Rdn,flags);
}

void REVSH(uint32_t Rd,uint32_t Rm,int *flags)
{
}

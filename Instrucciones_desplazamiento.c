#include "Instrucciones_desplazamiento.h"

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


uint32_t LSL(uint32_t Rd,uint32_t Rn,uint32_t Rm) //desplazamiento hacia la izquierda
{
    Rd= Rn<<Rm; //bit de Rn se desplazan tantas veces indique Rm

    return Rd;
}

uint32_t LSR(uint32_t Rd,uint32_t Rn,uint32_t Rm) //desplazamiento hacia la derecha
{
    Rd= Rn>>Rm; //bit de Rn se desplazan tantas veces indique Rm

    return Rd;
}

uint32_t ROR(uint32_t Rd,uint32_t Rm)
{
    uint32_t aux1,aux2; //variables auxiiares
    aux1=Rd>>Rm;        //aux1 almacenara los primeros bits
    aux2=Rd<<(32-Rm);   //aux2 almacenara los ultimos bis

    return aux1+aux2;
}

uint32_t ASR(uint32_t Rd,uint32_t Rn,uint32_t Rm)
{
    uint32_t aux;

    aux=Rn>>31;     //conocer el signo del numero

    if(aux==0)      //numero con signo positivo
    {
        Rd=Rn>>Rm;
    }
    else            //numero con signo negativo
    {
        Rd=Rn>>Rm;
        aux=aux<<Rm;
    }
    return Rd+aux;
}

uint32_t BIC(uint32_t Rd,uint32_t Rm)
{
    return Rd&(~Rm);
}

uint32_t MVN(uint32_t Rm)
{
    return ~Rm;
}

uint32_t RSB(uint32_t Rm)
{
    return ~Rm+1;
}

uint32_t REV(uint32_t Rd,uint32_t Rm)
{
    u32tobyte_t R;

    R.data = Rm;
    Rd = (uint32_t)(R.byte0 << 24) | (uint32_t)(R.byte3) | (uint32_t)(R.byte1 << 16) | (uint32_t)(R.byte2 << 8);

    return Rd;
}

uint32_t REV16(uint32_t Rd,uint32_t Rm)
{
    u32tobyte_t R;
    R.data = Rm;
    Rd = (uint32_t)(R.byte0 << 16) | (uint32_t)(R.byte3<<8) | (uint32_t)(R.byte1 << 24) | (uint32_t)(R.byte2);

    return Rd;
}

uint32_t REVSH(uint32_t Rd,uint32_t Rm)
{

return Rd;
}

#include "SRAM.h"

void PUSH(uint32_t *registro,uint8_t *R,uint8_t *SRAM)
{
    uint32_t address,bitcount=0;    //address Direccion donde se iran almacenando los registros
                                    //bitcount contador de bits en 1, en R
    int i,j;


    for(i=0;i<=7;i++)               // verificar cuantos registros se almacenaran
    {
        if(R[i]==1)
            bitcount++;
    }

    if (*(R+14)==1)                 //verificar si se almacena LR
        bitcount+=1;

    address=registro[13]-4*bitcount;  //direccion donde se empezaran a almacenar los registros

    for(i=0;i<=14;i++)                  //Se empieza a almacenar los resgistros en SRAM
    {
        if(*(R+i)==1)
            for(j=0;j<=3;j++)
        {
                *(SRAM+address+j)=(uint8_t)((*(registro+i))>>(8*j));
        }
        address=address+4;              //luego de almacenado el primer byte, la direccion cambia a la siguiente posicion para el otro byte
    }
    registro[13]=registro[13]-4*bitcount;
}

void POP(uint32_t *registro,uint8_t *R,uint8_t *SRAM)
{
    uint32_t address=registro[13],bitcount=0;
    int i;

    for(i=0;i<=7;i++)               // verificar en cuantos registros se almacenara
    {
        if(*(R+i)==1)
            bitcount++;
    }

    if (*(R+14)==1)                 //verificar si se almacena LR
        bitcount+=1;

    for(i=0;i<=15;i++)
    {
        if(R[i]==1)
            *(registro+i)=((uint32_t)(*(SRAM+address)))+(((uint32_t)(*(SRAM+address+1)))<<8)+(((uint32_t)(*(SRAM+address+2)))<<16)+(((uint32_t)(*(SRAM+address+3)))<<24);
            address=address+4;
    }
    *(registro+13)=*(registro+13)+4*bitcount;
}

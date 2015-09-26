#include "SRAM.h"

void PUSH(uint32_t *registro,int *R,uint8_t *SRAM)
{
    uint32_t address,bitcount=0;    //address Direccion donde se iran almacenando los registros
                                    //bitcount contador de bits en 1, en R
    int i,j;
    *(registro+12)=65;              //SP


    for(i=0;i<=7;i++)               // verificar que registros se almacenaran
    {
        if(*(R+i)==1)
            bitcount++;
    }

    if (*(R+13)==1)                 //verificar si se almacena LR
        bitcount+=1;

    address=*(registro+12)-4*bitcount;  //direccion donde se empezaran a almacenar los registros

    for(i=0;i<=13;i++)                  //Se empieza a almacenar los resgistros en SRAM
    {
        if(*(R+16-i)==1)
            for(j=0;j<=3;j++)
        {
                *(SRAM+address+j)=(uint8_t)((*(registro+i))>>(8*j));
        }
        address=address+4;              //luego de almacenado el primer byte, la direccion cambia a la siguiente posicion para el otro byte
    }
    *(registro+12)=*(registro+12)-4*bitcount;
}

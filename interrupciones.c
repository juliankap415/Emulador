#include "interrupciones.h"

void NVIC(uint32_t *registro,int *Banderas,uint8_t *SRAM,int *interrupciones,int *Indicador)
{
    int i;
    uint8_t banderas;
    banderas=((*(Banderas))<<3)+((*(Banderas+1))<<2)+((*(Banderas+2))<<1)+*(Banderas+3);

    if(*Indicador==1)
    {
        if(*(registro+15)==0xFFFFFFFF)
        {
            POP_LOCAL(registro,SRAM,Banderas);
            *Indicador=0;
        }
    }
    else
    {
        for(i=0;i<32;i++)
        {
            if(interrupciones[i]==1)
            {
                PUSH_LOCAL(registro,SRAM,banderas);
                *(registro+15)=i+1;
                *(registro+14)=0xFFFFFFFF;
                *Indicador=1;
                interrupciones[i]=0;
                break;
            }
        }
    }
}

void PUSH_LOCAL(uint32_t *registro,uint8_t *SRAM,uint8_t banderas)
{
    uint32_t address,bitcount=7;    //address Direccion donde se iran almacenando los registros
    uint8_t R[16]={1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1};                                //bitcount contador de bits en 1, en R
    int i,j;

    address=registro[13]-4*bitcount-1;  //direccion donde se empezaran a almacenar los registros

    for(i=0;i<=15;i++)                  //Se empieza a almacenar los resgistros en SRAM
    {
        if(*(R+i)==1)
            for(j=0;j<=3;j++)
        {
                *(SRAM+address+j)=(uint8_t)((*(registro+i))>>(8*j));
        }
        address=address+4;              //luego de almacenado el primer byte, la direccion cambia a la siguiente posicion para el otro byte
    }
    *(SRAM+address)=banderas;
    registro[13]=registro[13]-4*bitcount;
}

void POP_LOCAL(uint32_t *registro,uint8_t *SRAM,int *Banderas)
{
    uint32_t address=registro[13],bitcount=7;
    int i;
    uint8_t R[16]={1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1},aux;

    for(i=0;i<=15;i++)
    {
        if(R[i]==1)
            *(registro+i)=((uint32_t)(*(SRAM+address)))+(((uint32_t)(*(SRAM+address+1)))<<8)+(((uint32_t)(*(SRAM+address+2)))<<16)+(((uint32_t)(*(SRAM+address+3)))<<24);
            address=address+4;
    }
    for(i=0;i<=3;i++)
    {
        aux=(*(SRAM+address))<<(4+i);
        aux=(*(SRAM+address))>>(7);
        *(Banderas+i)=(int)(aux);
    }
    *(registro+13)=*(registro+13)+4*bitcount;
}

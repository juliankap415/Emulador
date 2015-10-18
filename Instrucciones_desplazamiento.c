#include "Instrucciones_desplazamiento.h"
#include "Banderas.h"

/**\file Instrucciones_desplazamiento.c
*\brief libreria encargada de realizar las funciones de desplazamiento
*/

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

void LSLS(uint32_t *Rdn,uint32_t Rn,uint32_t Rm,int *flags) //desplazamiento hacia la izquierda
{
    *Rdn=Rn<<Rm; //bit de Rn se desplazan tantas veces indique Rm
    BANDERAS_2(*Rdn,flags);

	if((Rn<<(Rm-1)&(1<<31))==0)
		*(flags+2)=0;
	else
		*(flags+2)=1;
}

void LSRS(uint32_t *Rdn,uint32_t Rn,uint32_t Rm,int *flags) //desplazamiento hacia la derecha
{
    *Rdn=Rn>>Rm; //bit de Rn se desplazan tantas veces indique Rm
    BANDERAS_2(*Rdn,flags);

    if((Rn>>(Rm-1)&1)==0)
		*(flags+2)=0;
	else
		*(flags+2)=1;
}

void ROR(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    uint32_t aux1,aux2; //variables auxiiares
    aux1=*Rdn>>Rm;        //aux1 almacenara los primeros bits
    aux2=*Rdn<<(32-Rm);   //aux2 almacenara los ultimos bits
    *Rdn=aux1+aux2;
    BANDERAS_2(*Rdn,flags);

    if((*Rdn<<(Rm-1)&(1<<31))==0)
		*(flags+2)=0;
	else
		*(flags+2)=1;
}

void ASR(uint32_t *Rdn,uint32_t Rm,uint32_t Rn,int *flags)
{
    uint32_t aux;

    aux=Rm>>31;     //conocer el signo del numero
    aux=aux<<31;
    Rm=Rm>>Rn;
    *Rdn=Rm+aux;
    BANDERAS_2(*Rdn,flags);

	if((Rm>>(Rn-1)&(1))==0)
		*(flags+2)=0;
	else
		*(flags+2)=1;

}

void BIC(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    BANDERAS_1(*Rdn&(~Rm),*Rdn,Rm,flags);
    *Rdn=*Rdn&(~Rm);
}

void MVN(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    *Rdn=~Rm;
    BANDERAS_2(*Rdn,flags);
}

void RSB(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    BANDERAS(~Rm+1,*Rdn,*Rdn,flags);
    *Rdn=~Rm+1;
}

void REV(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    u32tobyte_t R;

    R.data = Rm;
    *Rdn= (uint32_t)(R.byte0 << 24)|(uint32_t)(R.byte3)|(uint32_t)(R.byte1 << 16)|(uint32_t)(R.byte2 << 8);
}

void REV16(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    u32tobyte_t R;
    R.data = Rm;
    *Rdn = (uint32_t)(R.byte0 << 16) | (uint32_t)(R.byte3<<8) | (uint32_t)(R.byte1 << 24) | (uint32_t)(R.byte2);
}

void REVSH(uint32_t *Rdn,uint32_t Rm,int *flags)
{
    uint32_t aux1,aux2=~0,aux3;                      //aux1 salvar segundo byte,aux2 32 bit de 1,aux3 mirar el signo

	aux1=Rm<<16;
	aux1=aux1>>24;

	aux3=Rm<<24;
	aux3=aux3>>31;

	if(aux3==1)
	{
		aux2=aux2<<8;
		*Rdn=aux1+aux2;
	}
	else
    {
    *Rdn=aux1;
    }
}

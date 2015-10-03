#include "Instrucciones_load_store.h"
#include "SRAM.h"

/**\file Instrucciones_load_store.c
*\brief Libreria que se encarga de realizar las de carga y almacenamiento (Load-Store)
*/

uint32_t address = 0,data;
int i;

//Funciones carga

void LDR(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    address = Rn+Rm;
    *Rd= *(SRAM+address);

    for (i=1 ; i<4 ; i++)
        *Rd= *Rd + (((uint32_t)(*(SRAM+address+i)))<<8*i);
}

void LDRB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    address = Rn+Rm;
    *Rd = *(SRAM+address);
}

void LDRH(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    address = Rn+Rm;
    *Rd = *(SRAM+address);
    *Rd = *Rd + (((uint32_t)(*(SRAM+address+1)))<<8);
}

void LDRSB(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t aux1,aux2,aux3=~0;

    address = Rn+Rm;
    address = *(SRAM+address);

    aux1 = address;
    aux2 = aux1>>31;

	if(aux2==1)
	{
		aux3=aux3<<8;
		*Rd=aux1+aux3;
	}
	else
        *Rd=address;
}

void LDRSH(uint32_t *Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    uint32_t aux1,aux2,aux3=~0;

    address = Rn+Rm;
    data = *(SRAM+address);
    data = data + (((uint32_t)(*(SRAM+address+1)))<<8);     // *data=SRAM[address,2]

    aux1 = data;
    aux2 = aux1>>31;

    if(aux2==1)
	{
		aux3=aux3<<16;
		*Rd=aux1+aux3;
	}
	else
        *Rd=data;
}

//Funciones de almacenamiento

void STR(uint32_t Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    address = Rn+Rm;
    for (i=0 ; i<4 ; i++)
    {
        *(SRAM+address + i) = (uint8_t) (Rd>>(i*8));
    }
}

void STRB(uint32_t Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    address = Rn+Rm;
    *(SRAM+address) = (uint8_t)Rd;
}

void STRH(uint32_t Rd,uint32_t Rn,uint32_t Rm,uint8_t *SRAM)
{
    address = Rn+Rm;
    *(SRAM+address) = (uint8_t)Rd;
    *(SRAM+address+1) = (uint8_t)(Rd>>8);
}

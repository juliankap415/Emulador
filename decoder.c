#include "decoder.h"
#include "instrucciones.h"
#include "instrucciones_desplazamiento.h"
#include "instrucciones_saltos.h"
#include "SRAM.h"
#include "Instrucciones_load_store.h"
#include "io.h"

/** \file decoder.c
 *  \brief Contiene las funciones para poder obtener las instrucciones del documento de texto, y asi poder ejecutarlas
*/

uint8_t data;

void decodeInstruction(instruction_t instruction,int *Banderas,uint32_t *registro,uint8_t *SRAM,uint16_t *mnemonico_hex)
{
	if( strcmp(instruction.mnemonic,"ADDS") == 0||strcmp(instruction.mnemonic,"ADD") == 0 )
	{
	    if(instruction.op2_type=='R' && instruction.op3_type=='R')
        {
        *mnemonico_hex=(12<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        ADDS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
        *mnemonico_hex=(14<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        ADDS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='N'))
        {
        uint8_t aux=instruction.op1_value>>3;
        aux=aux<<7;
        *mnemonico_hex=(68<<8)+(instruction.op2_value<<3)+aux+(7&instruction.op1_value);
        ADDS(&registro[instruction.op1_value],registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        }

        if(instruction.op2_type=='#'&&instruction.op3_type=='N')
        {
        *mnemonico_hex=(6<<11)+(instruction.op1_value<<8)+instruction.op2_value;
        ADDS(&registro[instruction.op1_value],registro[instruction.op1_value],instruction.op2_value,Banderas);
        }

        if(instruction.op2_type=='S'&&instruction.op3_type=='#')
        {
        *mnemonico_hex=(21<<11)+(instruction.op1_value<<8)+instruction.op2_value;
        ADDS(&registro[instruction.op1_value],registro[instruction.op1_value],registro[13],Banderas);
        }

        if(instruction.op1_type=='S' && instruction.op2_type=='S'&&instruction.op3_type=='#')
        {
        *mnemonico_hex=(352<<7)+instruction.op3_value;
        ADDS(&registro[13],registro[13],registro[instruction.op3_value],Banderas);
        }

        if(instruction.op1_type=='R' && instruction.op2_type=='S'&&instruction.op3_type=='R')
        {
        uint8_t aux=instruction.op1_value>>3;
        aux=aux<<7;
        *mnemonico_hex=(68<<8)+(13<<3)+aux+(7&instruction.op1_value);
        ADDS(&registro[instruction.op1_value],registro[13],registro[instruction.op3_value],Banderas);
        }

        if(instruction.op1_type=='S' && instruction.op2_type=='R'&&instruction.op3_type=='N')
        {
        *mnemonico_hex=(137<<7)+(5)+(instruction.op2_value<<3);
        ADDS(&registro[13],registro[13],registro[instruction.op2_value],Banderas);
        }

        registro[15]++;
	}

    if( strcmp(instruction.mnemonic,"ANDS") == 0 )
    {
        *mnemonico_hex=(1<<14)+(instruction.op2_value<<3)+(instruction.op1_value);
        ANDS(&registro[instruction.op1_value],registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"EORS") == 0 )
    {
        *mnemonico_hex=(257<<6)+(instruction.op2_value<<3)+(instruction.op1_value);
        EORS(&registro[instruction.op1_value],registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"MOV") == 0 )
    {
        uint8_t aux=instruction.op1_value>>3;
        aux=aux<<7;
        *mnemonico_hex=(70<<8)+(instruction.op2_value<<3)+aux+(7&instruction.op1_value);
        MOVS(&registro[instruction.op1_value],instruction.op2_value,Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"MOVS") == 0 )
    {
        if((instruction.op1_type=='R') && (instruction.op2_type=='#'))
		{
		    *mnemonico_hex=(4<<11)+(instruction.op1_value<<8)+(instruction.op2_value);
			MOVS(&registro[instruction.op1_value],instruction.op2_value,Banderas);
		}

        if((instruction.op1_type=='R') && (instruction.op2_type=='R'))
		{
		    *mnemonico_hex=(instruction.op2_value<<3)+(instruction.op1_value);
			MOVS(&registro[instruction.op1_value],instruction.op2_value,Banderas);
		}
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"ORR") == 0 ||strcmp(instruction.mnemonic,"ORRS") == 0)
    {
        *mnemonico_hex=(268<<6)+(instruction.op2_value<<3)+(instruction.op1_value);
        ORRS(&registro[instruction.op1_value],registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"SUB") == 0||strcmp(instruction.mnemonic,"SUBS") == 0 )
    {

        if(instruction.op2_type=='R' && instruction.op3_type=='R')
        {
        *mnemonico_hex=(13<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        SUBS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
        *mnemonico_hex=(15<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        SUBS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        }

        if(instruction.op2_type=='#'&&instruction.op3_type=='N')
        {
        *mnemonico_hex=(7<<11)+(instruction.op1_value<<8)+instruction.op2_value;
        SUBS(&registro[instruction.op1_value],registro[instruction.op1_value],instruction.op2_value,Banderas);
        }

        if(instruction.op1_type=='S' && instruction.op2_type=='S' &&instruction.op3_type=='#')
        {
        *mnemonico_hex=(353<<7)+instruction.op3_value;
        SUBS(&registro[13],registro[13],instruction.op3_value,Banderas);
        }
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"CMN") == 0|| strcmp(instruction.mnemonic,"CMNS") == 0 )
    {
        *mnemonico_hex=(267<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        CMNS(registro[instruction.op1_value],instruction.op2_value,Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"CMP") == 0|| strcmp(instruction.mnemonic,"CMPS") == 0 )
    {
        if(instruction.op2_type=='R')
        {
            *mnemonico_hex=(267<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            CMPS(registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        }

        if(instruction.op2_type=='#')
        {
            *mnemonico_hex=(5<<11)+(instruction.op1_value<<8)+instruction.op2_value;
            CMPS(registro[instruction.op1_value],instruction.op2_value,Banderas);
        }
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"MUL") == 0|| strcmp(instruction.mnemonic,"MULS") == 0 )
    {
        *mnemonico_hex=(269<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        MULS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"TST") == 0 )
    {
        *mnemonico_hex=(264<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        TST(registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"NOP") == 0 )
    {
        *mnemonico_hex=(191<<8);
        NOP();
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"ADCS") == 0 )
	{
	    *mnemonico_hex=(261<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        ADCS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        registro[15]++;
	}

	if( strcmp(instruction.mnemonic,"SBCS") == 0||strcmp(instruction.mnemonic,"SBC") == 0 )
	{
	    *mnemonico_hex=(262<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        SBCS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        registro[15]++;
	}

    if( strcmp(instruction.mnemonic,"LSLS") == 0 ||strcmp(instruction.mnemonic,"LSL") == 0 )
    {
        if(instruction.op2_type=='R' && instruction.op3_type=='#')
        {
            *mnemonico_hex=(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            LSLS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        }

        if(instruction.op2_type=='R' && instruction.op3_type=='N')
        {
            *mnemonico_hex=(258<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            LSLS(&registro[instruction.op1_value],registro[instruction.op1_value],instruction.op2_value,Banderas);
        }

        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"LSRS") == 0 ||strcmp(instruction.mnemonic,"LSR") == 0)
    {
        if(instruction.op2_type=='R' && instruction.op3_type=='#')
        {
            *mnemonico_hex=(1<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            LSRS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        }

        if(instruction.op2_type=='R' && instruction.op3_type=='N')
        {
            *mnemonico_hex=(259<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            LSRS(&registro[instruction.op1_value],registro[instruction.op1_value],instruction.op2_value,Banderas);
        }

        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"RORS") == 0 )
    {
        *mnemonico_hex=(263<<6)+(instruction.op2_value<<6)+instruction.op1_value;
         ROR(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
         registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"ASRS") == 0 )
    {
        if(instruction.op2_type=='R' && instruction.op3_type=='#')
        {
            *mnemonico_hex=(2<<12)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            ASR(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        }

        if(instruction.op2_type=='R' && instruction.op3_type=='N')
        {
            *mnemonico_hex=(260<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            ASR(&registro[instruction.op1_value],registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        }
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"BICS") == 0 )
    {
        *mnemonico_hex=(instruction.op2_value<<3)+instruction.op1_value;
        BIC(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"MVNS") == 0 )
    {
        *mnemonico_hex=(271<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        MVN(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"RSBS") == 0 )
    {
        *mnemonico_hex=(265<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        RSB(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"REV") == 0 )
    {
        *mnemonico_hex=(744<<12)+(instruction.op2_value<<3)+instruction.op1_value;
        REV(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"REV16") == 0 )
    {
        *mnemonico_hex=(745<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        REV16(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"REVSH") == 0 )
    {
        *mnemonico_hex=(747<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        REVSH(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[15]++;
    }

    if( strcmp(instruction.mnemonic,"BEQ") == 0 )
    {
        *mnemonico_hex=(208<<8)+instruction.op1_value;
        BEQ(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BNE") == 0 )
    {
        *mnemonico_hex=(209<<8)+instruction.op1_value;
        BNE(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BCC") == 0 )
    {
        *mnemonico_hex=(211<<8)+instruction.op1_value;
        BCC(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BCS") == 0 )
    {
        *mnemonico_hex=(210<<8)+instruction.op1_value;
        BCS(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BMI") == 0 )
    {
        *mnemonico_hex=(212<<8)+instruction.op1_value;
        BMI(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BPL") == 0 )
    {
        *mnemonico_hex=(213<<8)+instruction.op1_value;
        BPL(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BVS") == 0 )
    {
        *mnemonico_hex=(214<<8)+instruction.op1_value;
        BVS(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BVC") == 0 )
    {
        *mnemonico_hex=(215<<8)+instruction.op1_value;
        BVC(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BHI") == 0 )
    {
        *mnemonico_hex=(216<<8)+instruction.op1_value;
        BHI(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BLS") == 0 )
    {
        *mnemonico_hex=(217<<8)+instruction.op1_value;
        BLS(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BGE") == 0 )
    {
        *mnemonico_hex=(218<<8)+instruction.op1_value;
        BGE(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BLT") == 0 )
    {
        *mnemonico_hex=(219<<8)+instruction.op1_value;
        BLT(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BGT") == 0 )
    {
        *mnemonico_hex=(220<<8)+instruction.op1_value;
        BGT(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BLE") == 0 )
    {
        *mnemonico_hex=(221<<8)+instruction.op1_value;
        BLE(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"B") == 0)
    {
        *mnemonico_hex=(7<<13)+instruction.op1_value;
        B(registro,(int)instruction.op1_value);
    }

    if( strcmp(instruction.mnemonic,"BAL") == 0)
    {
        *mnemonico_hex=(222<<8)+instruction.op1_value;
        B(registro,(int)instruction.op1_value);
    }

    if( strcmp(instruction.mnemonic,"BL") == 0 )
    {
        *mnemonico_hex=(31<<11)+(2047&instruction.op1_value);
        BL(registro,(int)instruction.op1_value);
    }

    if( strcmp(instruction.mnemonic,"BX") == 0 )
    {
        *mnemonico_hex=(142<<7)+(instruction.op1_value<<3);
        if(instruction.op2_type=='L')
        {
            BX(registro,registro[13]);
        }

        if(instruction.op2_type=='R')
        {
            BX(registro,registro[instruction.op2_value]);
        }
    }

    if( strcmp(instruction.mnemonic,"BLX") == 0 )
    {
        *mnemonico_hex=(143<<7)+(instruction.op1_value<<3);
        BLX(registro,registro[instruction.op2_value]);
    }

    if(strcmp(instruction.mnemonic,"PUSH") == 0)
    {
        int i;
        *mnemonico_hex=0;
        for(i=0;i<=7;i++)
        {
            *mnemonico_hex+=(instruction.registers_list[i]<<i);
        }
        *mnemonico_hex+=(90<<9)+(instruction.registers_list[14]<<8);

        PUSH(registro,instruction.registers_list,SRAM);
        (*(registro+15))++;
    }

    if(strcmp(instruction.mnemonic,"POP") == 0)
    {
        int i;
        *mnemonico_hex=0;
        for(i=0;i<=7;i++)
        {
            *mnemonico_hex+=(instruction.registers_list[i]<<i);
        }
        *mnemonico_hex+=(94<<9)+(instruction.registers_list[14]<<8);
        POP(registro,instruction.registers_list,SRAM);
        (*(registro+15))++;
    }

    if( strcmp(instruction.mnemonic,"LDR") == 0)
	{
	    if(instruction.op2_type=='R' && instruction.op3_type=='R')
            {
                *mnemonico_hex=(44<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                LDR(&registro[instruction.op1_value], registro[instruction.op2_value],registro[instruction.op3_value],SRAM);
            }

        if((instruction.op2_type=='P') && (instruction.op3_type=='#'))
        {
            *mnemonico_hex=(9<<11)+(instruction.op1_value<<8)+instruction.op3_value;
            instruction.op3_value = instruction.op3_value << 2;
            LDR(&registro[instruction.op1_value],*(registro + 15),(uint32_t) instruction.op3_value,SRAM);
        }

        if((instruction.op2_type=='S' )&& (instruction.op3_type=='#'))
        {
            *mnemonico_hex=(19<<11)+(instruction.op1_value<<8)+instruction.op3_value;
            instruction.op3_value = instruction.op3_value << 2;
            LDR(&registro[instruction.op1_value],*(registro + 13),(uint32_t)instruction.op3_value,SRAM);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            *mnemonico_hex=(13<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;;
            instruction.op3_value = instruction.op3_value << 2;
            LDR(&registro[instruction.op1_value],instruction.op2_value,(uint32_t)instruction.op3_value,SRAM);
        }
        registro[15]++;
	}

	if( strcmp(instruction.mnemonic,"LDRB") == 0)
	{
	    if(instruction.op2_type=='R' && instruction.op3_type=='R')
            {
                if(((registro[instruction.op2_value]+instruction.op3_value)>0x20000000)&&((*(registro+instruction.op2_value)+instruction.op3_value)<0x200000FF))
                    {
                        *mnemonico_hex=(46<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                        LDRB(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],SRAM);
                    }

            else if((registro[instruction.op2_value]+instruction.op3_value)>=0x40000000)
                {
                    IOAccess((registro[instruction.op2_value]+instruction.op3_value)&0xFF,&data,Read);
                    *(registro+instruction.op1_value)=(uint32_t)(data);
                }
            }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
            {
                instruction.op3_value = instruction.op3_value << 2;
                if(((registro[instruction.op2_value]+instruction.op3_value)>0x20000000)&&((*(registro+instruction.op2_value)+instruction.op3_value)<0x200000FF))
                    {
                        *mnemonico_hex=(15<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                        LDRB(&registro[instruction.op1_value],registro[instruction.op2_value],(uint32_t)instruction.op3_value,SRAM);
                    }

            else if((registro[instruction.op2_value]+instruction.op3_value)>=0x40000000)
                {
                    IOAccess((registro[instruction.op2_value]+instruction.op3_value)&0xFF,&data,Read);
                    *(registro+instruction.op1_value)=(uint32_t)(data);
                }

            }
        registro[15]++;
    }

	if( strcmp(instruction.mnemonic,"LDRH") == 0)
	{
	    if(instruction.op2_type=='R' && instruction.op3_type=='R')
            {
                *mnemonico_hex=(45<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                LDRH(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],SRAM);
            }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
            *mnemonico_hex=(17<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
            instruction.op3_value = instruction.op3_value << 2;
            LDRH(&registro[instruction.op1_value],registro[instruction.op2_value],(uint32_t)instruction.op3_value,SRAM);
        }
        registro[15]++;
	}

	if( strcmp(instruction.mnemonic,"LDRSB") == 0)
	{
	    *mnemonico_hex=(43<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
        LDRSB(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],SRAM);
        registro[15]++;
	}

	if( strcmp(instruction.mnemonic,"LDRSH") == 0)
	{
	    *mnemonico_hex=(47<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
	    LDRSH(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],SRAM);
        registro[15]++;
	}

	if( strcmp(instruction.mnemonic,"STR") == 0)
	{
	    if(instruction.op2_type=='R' && instruction.op3_type=='R')
            {
                *mnemonico_hex=(5<<12)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                STR(registro[instruction.op1_value], registro[instruction.op2_value],registro[instruction.op3_value],SRAM);
            }

        if((instruction.op2_type=='S' )&& (instruction.op3_type=='#'))
            {
                *mnemonico_hex=(9<<12)+(instruction.op1_value<<8)+instruction.op3_type;
                instruction.op3_value = instruction.op3_value << 2;
                STR(registro[instruction.op1_value],*(registro + 13),(uint32_t)instruction.op3_value,SRAM);
            }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
            {
                *mnemonico_hex=(3<<13)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                instruction.op3_value = instruction.op3_value << 2;
                STR(registro[instruction.op1_value],instruction.op2_value,(uint32_t)instruction.op3_value,SRAM);
            }
        registro[15]++;
	}

	if( strcmp(instruction.mnemonic,"STRB") == 0)
	{
	    if(instruction.op2_type=='R' && instruction.op3_type=='R')
            {
                if(((registro[instruction.op2_value]+instruction.op3_value)>0x20000000)&&((*(registro+instruction.op2_value)+instruction.op3_value)<0x200000FF))
                    {
                        *mnemonico_hex=(21<<10)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                        STRB(registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],SRAM);
                    }

            else if((registro[instruction.op2_value]+instruction.op3_value)>=0x40000000)
                {
                    data=(uint8_t)(*(registro+instruction.op1_value));
                    IOAccess((registro[instruction.op2_value]+instruction.op3_value)&0xFF,&data,Write);
                }

            }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
            {
                instruction.op3_value = instruction.op3_value << 2;

            if(((registro[instruction.op2_value]+instruction.op3_value)>0x20000000)&&((*(registro+instruction.op2_value)+instruction.op3_value)<0x200000FF))
                {
                    *mnemonico_hex=(7<<12)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                    STRB(registro[instruction.op1_value],registro[instruction.op2_value],(uint32_t)instruction.op3_value,SRAM);
                }

            else if((registro[instruction.op2_value]+instruction.op3_value)>=0x40000000)
                {
                    data=(uint8_t)(*(registro+instruction.op1_value));
                    IOAccess((registro[instruction.op2_value]+instruction.op3_value)&0xFF,&data,Write);
                }
            }

        registro[15]++;
	}

	if( strcmp(instruction.mnemonic,"STRH") == 0)
	{
	    if(instruction.op2_type=='R' && instruction.op3_type=='R')
            {
                *mnemonico_hex=(41<<9)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                STRH(registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],SRAM);
            }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
            {
                *mnemonico_hex=(32<<11)+(instruction.op3_value<<6)+(instruction.op2_value<<3)+instruction.op1_value;
                instruction.op3_value = instruction.op3_value << 2;
                STRH(registro[instruction.op1_value],registro[instruction.op2_value],(uint32_t)instruction.op3_value,SRAM);
            }
        registro[15]++;
	}
}

instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;

						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}
				break;

			case 2:
				if(split[0] == '[')
					split++;

				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}
	}

	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}

	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);

	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp);	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}

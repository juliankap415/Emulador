#include "decoder.h"
#include "instrucciones.h"
#include "instrucciones_desplazamiento.h"
#include "instrucciones_saltos.h"

/**\file decoder.c
*\brief libreria encargada de obtener las instrucciones del documento de texto, ademas de ejecutar las funciones indicadas en las intrucciones
*/

void decodeInstruction(instruction_t instruction,int *Banderas,uint32_t *registro)
{
	if( strcmp(instruction.mnemonic,"ADDS") == 0||strcmp(instruction.mnemonic,"ADD") == 0 )
	{
	    if(instruction.op2_type=='R' && instruction.op3_type=='R')
        {
        ADDS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
        ADDS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        }

        if((instruction.op2_type=='#' )&& (instruction.op3_type=='R'))
        {
        ADDS(&registro[instruction.op1_value],instruction.op2_value,registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='#') && (instruction.op3_type=='#'))
        {
        ADDS(&registro[instruction.op1_value],instruction.op2_value,instruction.op3_value,Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='N'))
        {
        ADDS(&registro[instruction.op1_value],registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        }

        if(instruction.op2_type=='#'&&instruction.op3_type=='N')
        {
        ADDS(&registro[instruction.op1_value],registro[instruction.op1_value],instruction.op2_value,Banderas);
        }
        registro[14]++;
	}

    if( strcmp(instruction.mnemonic,"ANDS") == 0 ||strcmp(instruction.mnemonic,"AND") == 0 )
    {
        if(instruction.op3_value==0)
        {
            instruction.op3_value=instruction.op2_value;
            instruction.op2_value=instruction.op1_value;
        }

        ANDS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"EOR") == 0 ||strcmp(instruction.mnemonic,"EORS") == 0 )
    {
        if(instruction.op3_value==0)
        {
            instruction.op3_value=instruction.op2_value;
            instruction.op2_value=instruction.op1_value;
        }
        EORS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"MOV") == 0 || strcmp(instruction.mnemonic,"MOVS") == 0)
    {
        if( instruction.op2_type == 'R' )
        {
            instruction.op2_value=registro[instruction.op2_value];
        }

        MOVS(&registro[instruction.op1_value],instruction.op2_value);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"ORR") == 0 ||strcmp(instruction.mnemonic,"ORRS") == 0)
    {
        if(instruction.op3_value==0)
        {
            instruction.op3_value=instruction.op2_value;
            instruction.op2_value=instruction.op1_value;
        }

        ORRS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"SUB") == 0||strcmp(instruction.mnemonic,"SUBS") == 0 )
    {

        if(instruction.op2_type=='R' && instruction.op3_type=='R')
        {
        SUBS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
        SUBS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        }

        if((instruction.op2_type=='#' )&& (instruction.op3_type=='R'))
        {
        SUBS(&registro[instruction.op1_value],instruction.op2_value,registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='#') && (instruction.op3_type=='#'))
        {
        SUBS(&registro[instruction.op1_value],instruction.op2_value,instruction.op3_value,Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='N'))
        {
        SUBS(&registro[instruction.op1_value],registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        }

        if(instruction.op2_type=='#'&&instruction.op3_type=='N')
        {
        SUBS(&registro[instruction.op1_value],registro[instruction.op1_value],instruction.op2_value,Banderas);
        }
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"CMN") == 0|| strcmp(instruction.mnemonic,"CMNS") == 0 )
    {
        if(instruction.op2_type=='R')
        {
            CMNS(registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        }

        if(instruction.op2_type=='#')
        {
            CMNS(registro[instruction.op1_value],instruction.op2_value,Banderas);
        }
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"CMP") == 0|| strcmp(instruction.mnemonic,"CMPS") == 0 )
    {
        if(instruction.op2_type=='R')
        {
            CMPS(registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        }

        if(instruction.op2_type=='#')
        {
            CMPS(registro[instruction.op1_value],instruction.op2_value,Banderas);
        }
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"MUL") == 0|| strcmp(instruction.mnemonic,"MULS") == 0 )
    {
        if(instruction.op3_value==0)
        {
            instruction.op3_value=instruction.op2_value;
            instruction.op2_value=instruction.op1_value;
        }

        MULS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"TST") == 0 )
    {
        TST(registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"NOP") == 0 )
    {
        NOP();
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"ADC") == 0||strcmp(instruction.mnemonic,"ADCS") == 0 )
	{
	    if(instruction.op2_type=='R' && instruction.op3_type=='R')
        {
        ADCS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
        ADCS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        }

        if((instruction.op2_type=='#' )&& (instruction.op3_type=='R'))
        {
        ADCS(&registro[instruction.op1_value],instruction.op2_value,registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='#') && (instruction.op3_type=='#'))
        {
        ADCS(&registro[instruction.op1_value],instruction.op2_value,instruction.op3_value,Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='N'))
        {
        ADCS(&registro[instruction.op1_value],registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        }

        if(instruction.op2_type=='#'&&instruction.op3_type=='N')
        {
        ADCS(&registro[instruction.op1_value],registro[instruction.op1_value],instruction.op2_value,Banderas);
        }
        registro[14]++;
	}

	if( strcmp(instruction.mnemonic,"SBCS") == 0||strcmp(instruction.mnemonic,"SBC") == 0 )
	{
        if(instruction.op2_type=='R' && instruction.op3_type=='R')
        {
        SBCS(&registro[instruction.op1_value],registro[instruction.op2_value],registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='#'))
        {
        SBCS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        }

        if((instruction.op2_type=='#' )&& (instruction.op3_type=='R'))
        {
        SBCS(&registro[instruction.op1_value],instruction.op2_value,registro[instruction.op3_value],Banderas);
        }

        if((instruction.op2_type=='#') && (instruction.op3_type=='#'))
        {
        SBCS(&registro[instruction.op1_value],instruction.op2_value,instruction.op3_value,Banderas);
        }

        if((instruction.op2_type=='R') && (instruction.op3_type=='N'))
        {
        SBCS(&registro[instruction.op1_value],registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        }

        if(instruction.op2_type=='#'&&instruction.op3_type=='N')
        {
        SBCS(&registro[instruction.op1_value],registro[instruction.op1_value],instruction.op2_value,Banderas);
        }
        registro[14]++;
	}

    if( strcmp(instruction.mnemonic,"LSLS") == 0 ||strcmp(instruction.mnemonic,"LSL") == 0 )
    {
        if(instruction.op3_value==0)
        {
            instruction.op3_value=registro[instruction.op2_value];
            instruction.op2_value=instruction.op1_value;
        }

        LSLS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"LSRS") == 0 ||strcmp(instruction.mnemonic,"LSR") == 0)
    {
         if(instruction.op3_value==0)
        {
            instruction.op3_value=registro[instruction.op2_value];
            instruction.op2_value=instruction.op1_value;
        }

        LSRS(&registro[instruction.op1_value],registro[instruction.op2_value],instruction.op3_value,Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"ROR") == 0 )
    {
         ROR(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
         registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"ASR") == 0 )
    {
        ASR(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"BIC") == 0 )
    {
        BIC(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"MVN") == 0 )
    {
        MVN(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"RSB") == 0 )
    {
        RSB(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"REV") == 0 )
    {
        REV(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"REV16") == 0 )
    {
        REV16(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"REVSH") == 0 )
    {
        REVSH(&registro[instruction.op1_value],registro[instruction.op2_value],Banderas);
        registro[14]++;
    }

    if( strcmp(instruction.mnemonic,"BEQ") == 0 )
    {
        BEQ(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BNE") == 0 )
    {
        BNE(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BCC") == 0 )
    {
        BCC(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BCS") == 0 )
    {
        BCS(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BMI") == 0 )
    {
        BMI(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BPL") == 0 )
    {
        BPL(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BVS") == 0 )
    {
        BVS(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BVC") == 0 )
    {
        BVC(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BHI") == 0 )
    {
        BHI(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BLS") == 0 )
    {
        BLS(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BGE") == 0 )
    {
        BGE(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BLT") == 0 )
    {
        BLT(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BGT") == 0 )
    {
        BGT(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"BLE") == 0 )
    {
        BLE(registro,(int)instruction.op1_value,Banderas);
    }

    if( strcmp(instruction.mnemonic,"B") == 0 )
    {
        B(registro,(int)instruction.op1_value);
    }

    if( strcmp(instruction.mnemonic,"BL") == 0 )
    {
        BL(registro,(int)instruction.op1_value);
    }

    if( strcmp(instruction.mnemonic,"BX") == 0 )
    {
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
        BLX(registro,registro[instruction.op2_value]);
    }

}

instruction_t getInstruction(char* instStr)
{
	instruction_t instruction;
	char* split = (char*)malloc( strlen(instStr)+1);
	int num=0;

	strcpy( split, instStr);
	// Obtiene el mnemonico de la instrucción
	split = strtok( split, " ,");
	strcpy(instruction.mnemonic, split);

	// Separa los operandos
	while ( split != NULL)
	{
		switch(num){
			case 1:
				instruction.op1_type  = split[0];
				instruction.op1_value = (uint32_t)strtoll( split+1, NULL, 0);
				break;

			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll( split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll( split+1, NULL, 0);
				break;
		}
		split = strtok(NULL, " ,.");
		num++;
	}
	if(num==3){
		instruction.op3_type  = 'N';
		instruction.op3_value = 0;
	}
	free( split);
	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	// Puntero a un archivo
	int lines;	// Cantidad de líneas del archivo
	int line=0;	// Línea leida
	char buffer[50]; // Almacena la cadena leida

	fp = fopen(filename, "r");	// Abrir el archivo como solo lectura
	if( fp==NULL )
		return -1;	// Error al abrir el archivo

	lines = countLines(fp);	// Cantidad de líneas
	// Asignación dinámica de memoria para cada instrucción
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc(( strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}
	fclose(fp);	// Cierra el archivo
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

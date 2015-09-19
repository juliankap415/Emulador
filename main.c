#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>
#include "Registros.h"
#include "Instrucciones.h"
#include "Instrucciones_desplazamiento.h"
#include "decoder.h"

/**\mainpage Practica #1 Emulador ARM Cortex -M0
* Documentacion pertinente del sofware realizado para realizar el Emulador del procesador ARM Cortex -M0
*/

/**\file main.c
*\brief Codigo en el cual se ejecutaran las funciones, utilizando todas las librerias creadas para cada una de ellas
* ademas de la libreria curses.h para la interfaz del emulador, y de la libreria decoder.h para obtener las instrucciones del documento de texto
*/

int main(void)
{
    int i, num_instructions,Banderas[4]={0};
    uint32_t registro[15]={0};                  //Arreglo que contiene los registros
    ins_t read;
    char entrada;
    char** instructions;
    instruction_t instruction;

    num_instructions=readFile("code.txt",&read);

    if(num_instructions==-1)
        return 0;

    if(read.array==NULL)
        return 0;

    instructions = read.array;

    initscr();	                                //Inicia modo curses
    curs_set(0);	                            //Cursor Invisible
    raw();			                            //Activa modo raw
	keypad(stdscr, TRUE);   	                //Obtener F1, F2, etc
    noecho();	            	                //No imprimir los caracteres leidos
    start_color();	                            //Permite manejar colores
    init_pair(1,COLOR_WHITE,COLOR_CYAN); 	    // Texto blanco, fondo cyan
    attron(COLOR_PAIR(1));
    bkgd(COLOR_PAIR(1));                        //Fondo de pantalla color cyan

    mvprintw(5,47,"EMULADOR");                  //Imprime el titulo de la pantalla
    refresh();                                         //Imprime en la pantalla

    while(1)                                    //While donde se encuentran las secuencias
    {
        MostrarRegistro(registro);                      //Imprimimos en pantalla los valores de los registros
        init_pair(1,COLOR_WHITE,COLOR_CYAN);
        mvprintw(21,8,"PC: %d\t\tLR: %d",registro[14],registro[13]);
        mvprintw(10,80,"BANDERAS");                     //Imprimimos en pantalla las banderas
        mvprintw(12,80,"N=%d\n",Banderas[0]);
        mvprintw(13,80,"Z=%d\n",Banderas[1]);
        mvprintw(14,80,"C=%d\n",Banderas[2]);
        mvprintw(15,80,"S=%d\n",Banderas[3]);

        border( ACS_VLINE, ACS_VLINE,ACS_HLINE, ACS_HLINE,ACS_ULCORNER, ACS_URCORNER,ACS_LLCORNER, ACS_LRCORNER	);

        instruction = getInstruction(instructions[registro[14]]); // Instrucción en la posición PC
        decodeInstruction(instruction,Banderas,registro);

        mvprintw(21,70,"%s %c%d, %c%d %c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value);

        entrada=getch();

        if(entrada=='p')
        {
            timeout(1000);
        }

        if(entrada=='h')
        {
            timeout(-1);
        }

        if(entrada=='o')
        {
            break;
        }
    }

    for(i=0; i<num_instructions; i++)
    {
		free(read.array[i]);
	}

	free(read.array);
	refresh();
    attroff(COLOR_PAIR(1));
    endwin();	                                            //Finaliza el modo curses
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>
#include "Registros.h"
#include "Instrucciones.h"
#include "Instrucciones_desplazamiento.h"
#include "decoder.h"

int main(void)
{
    int i, num_instructions,Banderas[4]={0};
    uint32_t registro[13]={0};                  //Arreglo que contiene los registros
    ins_t read;
    char** instructions;
    instruction_t instruction;

    num_instructions = readFile("code.txt", &read);

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
    bkgd(COLOR_PAIR(1));                        //Fondo de pantalla color cyan

    mvprintw(5,47,"EMULADOR");                  //Imprime el titulo de la pantalla
    refresh();                                  //Imprime en la pantalla

    border( ACS_VLINE, ACS_VLINE,               //Poner borde a la pantalla
            ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER,
            ACS_LLCORNER, ACS_LRCORNER);

    while(1)                                    //While donde se encuentran las secuencias
    {
        instruction = getInstruction(instructions[registro[13]]); // Instrucción en la posición 0
        decodeInstruction(instruction);
        getch();
        init_pair(1,COLOR_WHITE,COLOR_CYAN);

            MostrarRegistro(registro);                      //Imprimimos en pantalla los valores de los registros
            init_pair(1,COLOR_WHITE,COLOR_CYAN);
            mvprintw(1,20,"%c",instruction);
            mvprintw(10,80,"BANDERAS");                     //Imprimimos en pantalla las banderas
            mvprintw(12,80,"N=%d\n",Banderas[0  ]);
            mvprintw(13,80,"Z=%d\n",Banderas[1]);
            mvprintw(14,80,"C=%d\n",Banderas[2]);
            mvprintw(15,80,"S=%d\n",Banderas[3]);

            border( ACS_VLINE, ACS_VLINE,
            ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER,
            ACS_LLCORNER, ACS_LRCORNER	);

            refresh();


        registro[13]++;
                                                   //Espera entrada del usuario
    }

    for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}
	free(read.array);

    //timeout(1000);
    endwin();	                                            //Finaliza el modo curses
    return 0;
}

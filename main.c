#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>
#include "Registros.h"
#include "Instrucciones.h"
#include "Instrucciones_desplazamiento.h"
#include "decoder.h"

/** \mainpage Practica #1 Emulador ARM Cortex -M0
* Documentacion pertinente del sofware realizado para realizar el Emulador del procesador ARM Cortex -M0
*/

/**\file main.c
*\brief Codigo en el cual se ejecutaran las funciones, utilizando todas las librerias creadas para cada una de ellas
* ademas de la libreria curses.h para la interfaz del emulador, y de la libreria decoder.h para obtener las instrucciones del documento de texto
*/

int main(void)
{
    int i, num_instructions,Banderas[4]={0};    //Banderas[0]=N
                                                //Banderas[0]=Z
                                                //Banderas[0]=C
                                                //Banderas[0]=V
    uint32_t registro[15]={0};                  //Arreglo que contiene los registros
                                                //registro[14]=PC
                                                //registro[13]=LR
    ins_t read;
    char entrada;                               //variable para guardar la entrada por parte del teclado
    char** instructions;
    instruction_t instruction;                  //variable en la que se almacenara cada instruccion

    num_instructions=readFile("code.txt",&read);//almacena el numero de lineas del archivo de texto

    if(num_instructions==-1)                    //Error al abrir el archivo
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
    init_pair(1,COLOR_WHITE,COLOR_CYAN); 	    //Texto blanco, fondo cyan
    attron(COLOR_PAIR(1));
    bkgd(COLOR_PAIR(1));                        //Fondo de pantalla color cyan

    mvprintw(1,40,"EMULADOR ARM Cortex M0");                          //Imprime el titulo de la pantalla
    mvprintw(4,4,"Presiones p, para ejecutar con tiempo de 1 seg");   //Se imprimen las opciones para correr el codigo en pantalla
    mvprintw(5,4,"Presiones h, para ejecutar paso a paso");
    mvprintw(6,4,"Presiones o, para salir");
    refresh();                                                       //Imprime en la pantalla

    while(1)                                                         //While donde se encuentran las secuencias
    {
        MostrarRegistro(registro);                                   //Imprimimos en pantalla los valores de los registros
        init_pair(1,COLOR_WHITE,COLOR_CYAN);
        mvprintw(21,8,"PC: %d\t\tLR: %d",registro[14]*2,registro[13]);  //Se muestra en pantalla la variacion de PC y LR
        mvprintw(10,80,"BANDERAS");                                     //Se muestra en pantalla la variacion de Banderas
        mvprintw(12,80,"N=%d\n",Banderas[0]);
        mvprintw(13,80,"Z=%d\n",Banderas[1]);
        mvprintw(14,80,"C=%d\n",Banderas[2]);
        mvprintw(15,80,"V=%d\n",Banderas[3]);

        border( ACS_VLINE, ACS_VLINE,ACS_HLINE, ACS_HLINE,ACS_ULCORNER, ACS_URCORNER,ACS_LLCORNER, ACS_LRCORNER	);  //Bordes de la pantalla

        instruction = getInstruction(instructions[registro[14]]); // Instrucción en la posición PC
        decodeInstruction(instruction,Banderas,registro);           //Realiza la funcion indicada por el mnemonico

        mvprintw(21,70,"%s %c%d, %c%d %c%d",instruction.mnemonic,instruction.op1_type,instruction.op1_value,instruction.op2_type,instruction.op2_value,instruction.op3_type,instruction.op3_value); //Se muestra la funcion que se realizara

        entrada=getch();    //Guardamos lo que se ingrese en el teclado

        if(entrada=='p')
        {
            timeout(1000);  //Si se ingresa 'p' en el teclado el codigo, las instrucciones se haran haciendo en intervalos de 1 segundo
        }

        if(entrada=='h')
        {
            timeout(-1);    //Si se ingresa 'h', se realizaran las instrucciones paso a paso, a medida que se ingrese algun caracter en el teclado
        }

        if(entrada=='o')
        {
            break;          //si se ingresa 'o', el programa termina
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

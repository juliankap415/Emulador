#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>
#include "Registros.h"
#include "decoder.h"
#include "interrupciones.h"
#include "io.h"

/** \mainpage Practica #1 Emulador ARM Cortex -M0
* Documentacion pertinente del software realizado para realizar el Emulador del procesador ARM Cortex -M0
*/

/**\file main.c
*\brief Codigo en el cual se ejecutaran las funciones, utilizando todas las librerias creadas para cada una de ellas
* ademas de la libreria curses.h para la interfaz del emulador, y de la libreria decoder.h para obtener las instrucciones del documento de texto
*/

extern uint8_t irq[16];

int main(void)
{
    int i, num_instructions,Banderas[4]={0};    //Banderas[0]=N
                                                //Banderas[0]=Z
                                                //Banderas[0]=C
                                                //Banderas[0]=V

    uint32_t registro[16]={0};                  //Arreglo que contiene los registros
                                                //registro[13]=SP
                                                //registro[15]=PC
                                                //registro[14]=LR
    uint8_t SRAM[128];
    //uint8_t data=0;
    uint16_t *mnemonico_hex=0;
   // int *Indicador=0;
                                  //variable para guardar la entrada por parte del teclado
    for(i=0;i<=15;i++)
    {
        irq[i]=0;
    }

    for(i=0;i<=127;i++)
    {
        SRAM[i]=255;
    }
    *(registro+13)=128;                         //Puntero de pila debe estar en la posicion arriba de la SRAM
    ins_t read;
    char entrada;
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
    initIO();                                    //Iniciar puertos E/S

    while(1)                                                         //While donde se encuentran las secuencias
    {


        //NVIC(&registro[0],Banderas,SRAM,&irq[0],Indicador);
        erase();
        init_pair(1,COLOR_WHITE,COLOR_CYAN);
        mvprintw(1,40,"EMULADOR ARM Cortex M0");                          //Imprime el titulo de la pantalla
        mvprintw(18,4,"Presiones p, para ejecutar con tiempo de 1 seg");   //Se imprimen las opciones para correr el codigo en pantalla
        mvprintw(19,4,"Presiones s, para detener ejecucion con tiempo");
        mvprintw(20,4,"Presiones espacio, para ejecutar paso a paso");
        mvprintw(21,4,"Presiones o, para salir");
        mvprintw(22,4,"Presiones m, para mostrar SRAM");
        MostrarSRAM(SRAM);
        showPorts();
        MostrarRegistro(registro);                                   //Imprimimos en pantalla los valores de los registros


        mvprintw(10,70,"PC: %d\tLR: %d",registro[15]*2,registro[14]*2);  //Se muestra en pantalla la variacion de PC y LR
        mvprintw(27,83,"BANDERAS");                                     //Se muestra en pantalla la variacion de Banderas
        mvprintw(26,83,"N=%d\n",Banderas[0]);
        mvprintw(27,83,"Z=%d\n",Banderas[1]);
        mvprintw(28,83,"C=%d\n",Banderas[2]);
        mvprintw(29,83,"V=%d\n",Banderas[3]);
        mvprintw(5,70,"%s",instructions[registro[15]]);                //instruccion que se ejecutara

        border( ACS_VLINE, ACS_VLINE,ACS_HLINE, ACS_HLINE,ACS_ULCORNER, ACS_URCORNER,ACS_LLCORNER, ACS_LRCORNER	);  //Bordes de la pantalla

        instruction = getInstruction(instructions[registro[15]]); // Instrucci�n en la posici�n PC
        decodeInstruction(instruction,Banderas,registro,SRAM,&mnemonico_hex);           //Realiza la funcion indicada por el mnemonico
        mvprintw(6,70,"0x%0.4X",mnemonico_hex);
        refresh();
        entrada=getch();    //Guardamos lo que se ingrese en el teclado

        if(entrada=='s')
        {
            timeout(-1);
        }

        if(entrada=='p')
        {
            timeout(1000);

        }

        if(entrada==' ')
            {
               timeout(-1);
            }

        if(entrada=='o')
        {
            erase();
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


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
    uint32_t registro[13]={0};                  //Arreglo que contiene los registros
    int Banderas[4]={0};                        //Arreglo que contiene las banderas

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
    {   getch();
        init_pair(1,COLOR_WHITE,COLOR_CYAN);

        switch(registro[12])                                //Almacena la funcion para cada direccion
        {
            case 1:                                         //Direccion 1
                ROR(&registro[0],1,Banderas);
                mvprintw(20,30,"Direccion 1:\tROR\t");
                refresh();
                break;

            case 2:                                         //Direccion 2
                ADDS(&registro[9],registro[1],3,Banderas);
                mvprintw(20,30,"Direccion 2:\tADDS\t");
                refresh();
                break;

            case 3:                                         //Direccion 3
                break;

        }

        if (registro[12]!=0)
        {
            MostrarRegistro(registro);                      //Imprimimos en pantalla los valores de los registros
            init_pair(1,COLOR_WHITE,COLOR_CYAN);
            mvprintw(10,80,"BANDERAS");                     //Imprimimos en pantalla las banderas
            mvprintw(12,80,"N=%d\n",Banderas[0]);
            mvprintw(13,80,"Z=%d\n",Banderas[1]);
            mvprintw(14,80,"C=%d\n",Banderas[2]);
            mvprintw(15,80,"S=%d\n",Banderas[3]);

            border( ACS_VLINE, ACS_VLINE,
            ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER,
            ACS_LLCORNER, ACS_LRCORNER	);

            refresh();
        }

        registro[12]+=1;
                                                   //Espera entrada del usuario
    }


    endwin();	                                            //Finaliza el modo curses
    getch();
    return 0;
}

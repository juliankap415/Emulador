#include "Registros.h"
#include <curses.h>

/**\file Registros.c
*\brief Contiene la funcion para poder imprimir en pantalla los registros
*/

void MostrarRegistro( uint32_t *registro)
{

    int j;

    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    init_pair(3, COLOR_WHITE, COLOR_CYAN);

    attron(COLOR_PAIR(2));
    mvprintw(24,5,"REGISTROS:");
    attroff(COLOR_PAIR(2));

            for (j=0;j<=4;j++)
            {
                attron(COLOR_PAIR(2));
                mvprintw(26+j,5,"Registro #%.2d:",j);
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(3));
                printw(" %.8X \t",registro[j]);
                attroff(COLOR_PAIR(3));
            }

            for (j=5;j<=9;j++)
            {
                attron(COLOR_PAIR(2));
                mvprintw(26+j-5,30,"Registro #%.2d:",j);
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(3));
                printw(" %.8X \t",registro[j]);
                attroff(COLOR_PAIR(3));
            }

            for (j=9;j<=12;j++)
            {
                attron(COLOR_PAIR(2));
                mvprintw(26+j-9,55,"Registro #%.2d:",j);
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(3));
                printw(" %.8X \t",registro[j]);
                attroff(COLOR_PAIR(3));
            }

    refresh();
}

void MostrarSRAM(uint8_t *SRAM)
{
    int i,j;
    uint8_t Posicion_SRAM=127;

    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    init_pair(3, COLOR_WHITE, COLOR_CYAN);

    attron(COLOR_PAIR(2));
    mvprintw(35,42,"SRAM");
    attroff(COLOR_PAIR(2));

    for(j=0;j<=15;j++)
    {
        for(i=0;i<=3;i++)
        {
            attron(COLOR_PAIR(3));
            mvprintw(38+j,10+8*i,"%.2X",SRAM[127-4*j-i]);
            attroff(COLOR_PAIR(3));

            attron(COLOR_PAIR(2));
            mvprintw(38+j,6+8*i,"%.2X",Posicion_SRAM);
            attroff(COLOR_PAIR(2));
            Posicion_SRAM--;
        }
    }

    for(j=16;j<=31;j++)
    {
        for(i=0;i<=3;i++)
        {
            attron(COLOR_PAIR(3));
            mvprintw(38+j-16,55+8*i,"%.2X",SRAM[127-4*j-i]);
            attroff(COLOR_PAIR(3));

            attron(COLOR_PAIR(2));
            mvprintw(38+j-16,51+8*i,"%.2X",Posicion_SRAM);
            attroff(COLOR_PAIR(2));
            Posicion_SRAM--;
        }
    }
    refresh();
}


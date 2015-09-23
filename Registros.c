#include "Registros.h"
#include <curses.h>

/**\file Registros.c
*\brief Contiene la funcion para poder imprimir en pantalla los registros
*/

void MostrarRegistro( uint32_t *registro)
{
    int j;

    start_color();
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    init_pair(3, COLOR_WHITE, COLOR_CYAN);

    attron(COLOR_PAIR(2));
    mvprintw(10,5,"REGISTROS:");
    attroff(COLOR_PAIR(2));

            for (j=0;j<=5;j++)
            {
                attron(COLOR_PAIR(2));
                mvprintw(12+j,5,"Registro #%.2d:",j);
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(3));
                printw(" %.12u \t",registro[j]);
                attroff(COLOR_PAIR(3));
            }

            for (j=6;j<=11;j++)
            {
                attron(COLOR_PAIR(2));
                mvprintw(12+j-6,35,"Registro #%.2d:",j);
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(3));
                printw(" %.12u \t",registro[j]);
                attroff(COLOR_PAIR(3));
            }

    refresh();
}



#include "Registros.h"
#include <curses.h>

void MostrarRegistro( uint32_t registro[])
{
    int i,j;

    start_color();

    init_pair(2, COLOR_GREEN, COLOR_BLACK);


    for (i=0;i<=3;i++)
    {
        move(25+i, 2);
        for (j=0;j<=2;j++){
            attron(COLOR_PAIR(2));
            printw("Registro #%.2d:",j+(i*3)+1);
            attroff(COLOR_PAIR(2));

            attron(COLOR_PAIR(1));
            printw(" %.12u \t",registro[j+(i*3)]);
            attroff(COLOR_PAIR(1));
        }
    }

    refresh();
}



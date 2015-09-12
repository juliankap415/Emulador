#include "Registros.h"
#include "Instrucciones.h"
#include "Instrucciones_desplazamiento.h"
#include <curses.h>

int main()
{
    uint32_t registro[12]={1,2,3,4,5,6,7,8,9,10,11,12},Rd=50,Rn=90,Rm=80; //variables de pruebam
    int OpcionSeleccion,Banderas[4],*puntero=Banderas;

    initscr();              //inicio del modo curses
    curs_set(0);	        // Cursor Invisible
    raw();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);

    //bkgd(COLOR_PAIR(1));
    refresh();

    border( ACS_BULLET, ACS_BULLET,
            ACS_BULLET, ACS_BULLET,
            ACS_BULLET, ACS_BULLET,
            ACS_BULLET, ACS_BULLET);

    attron(COLOR_PAIR(1));


    printw("Seleccione la funcion que desea probar:\n\na:Mostrar Registro\nb:ADDS\nc:AND\nd:MOV\ne:ORR\nf:SUBS\ng:LSL\nh:LSR\ni:ROR\nj:ASR\nk:BIC\nl:MVN\nm:RSBS\nn:REV\no:REV16\np:CMN\nq:CMP\nr:MUL\ns:TST    \n\n");
    refresh();
    attroff(COLOR_PAIR(1));

    OpcionSeleccion = getch();


    switch(OpcionSeleccion)
    {
        case 'a':
            MostrarRegistro(registro);
            break;

        case 'b':
            Rd=ADDS(Rd,Rn,Rm);          //llamado de la funcion ADDS
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'c':
            Rd=AND(Rn,Rm);              //llamado de la funcion AND
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'd':
            Rd=MOV(Rn);                 //llamado de la funcion MOV
            break;

        case 'e':
            Rd=ORR(Rn,Rm);              //llamado de la funcion ORR
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'f':
            Rd=SUBS(Rd,Rn,Rm);           //llamado de la funcion SUBS
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'g':
            Rd=LSL(Rd,Rn,Rm);           //llamado de la funcion LSL
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'h':
            Rd=LSR(Rd,Rn,Rm);           //llamado de la funcion LSR
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'i':
            Rd=ROR(Rn,Rm);           //llamado de la funcion ROR
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'j':
            Rd=ASR(Rd,Rn,Rm);           //llamado de la funcion ASR
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'k':
            Rd=BIC(Rd,Rn);              //llamado de la funcion BIC
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'l':
            Rd=MVN(Rn);              //llamado de la funcion MVN
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'm':
            Rd=RSB(Rn);              //llamado de la funcion RSB
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'n':
            Rd=REV(Rd,Rm);              //llamado de la funcion REV
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'o':
            Rd=REV16(Rd,Rm);              //llamado de la funcion REV
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 'p':
            CMN(Rd,Rn,Rm);          //llamado de la funcion CMN
            break;

        case 'q':
            CMP(Rd,Rn,Rm);          //llamado de la funcion CMP
            break;

        case 'r':
            Rd=MUL(Rd,Rn,Rm);          //llamado de la funcion MUL
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 's':
            TST(Rd,Rn,Rm);          //llamado de la funcion TST
            break;

    }

    mvprintw(30,2,"\n\nSu resultado es %d\nLas banderas son: N:%d\tZ:%d\tC:%d\tV:%d",Rd,Banderas[0],Banderas[1],Banderas[2],Banderas[3]);
    refresh();

    getch();
    endwin();

    return 0;
}

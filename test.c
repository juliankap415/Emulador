#include "Registros.h"
#include "Instrucciones.h"
#include "Instrucciones_desplazamiento.h"
#include <curses.h>

//int main()
//{
//    uint32_t registro[12]={1,2,3,4,5,6,7,8,9,10,11,12},R_d=50,*Rd=R_d,Rn=90,Rm=80; //variables de pruebam
//    int OpcionSeleccion,Banderas[4],*puntero=Banderas;
//
//    initscr();              //inicio del modo curses
//    curs_set(0);	        // Cursor Invisible
//    raw();
//    keypad(stdscr, TRUE);
//    noecho();
//    start_color();
//    init_pair(1, COLOR_WHITE, COLOR_CYAN);
//
//    bkgd(COLOR_PAIR(1));
//    refresh();
//
//    border( ACS_BULLET, ACS_BULLET,
//            ACS_BULLET, ACS_BULLET,
//            ACS_BULLET, ACS_BULLET,
//            ACS_BULLET, ACS_BULLET);
//
//    attron(COLOR_PAIR(1));
//
//    move(1,50);
//    printw("Seleccione la funcion que desea probar:\n\na:Mostrar Registro\nb:ADDS\n");
//    refresh();
//    attroff(COLOR_PAIR(1));

//    OpcionSeleccion = getch();
//
//
//    switch(OpcionSeleccion)
//    {
//        case 'a':
//            MostrarRegistro(registro);
//            break;
//
//        case 'b':
//            ADDS(*Rd,Rn,Rm,puntero);          //llamado de la funcion ADDS
//            break;
//
//        case 'c':
//            AND(Rd,Rn,Rm,puntero);              //llamado de la funcion AND
//            break;
//
//        case 'd':
//            MOV(Rd,Rn);                 //llamado de la funcion MOV
//            break;
//
//        case 'e':
//            ORR(Rd,Rn,Rm,puntero);              //llamado de la funcion ORR
//            break;
//
//        case 'f':
//            SUBS(Rd,Rn,Rm,puntero);           //llamado de la funcion SUBS
//            break;
//
//        case 'g':
//            LSL(Rd,Rn,Rm,puntero);           //llamado de la funcion LSL
//            break;
//
//        case 'h':
//            LSR(Rd,Rn,Rm,puntero);           //llamado de la funcion LSR
//            break;
//
//        case 'i':
//            ROR(Rd,Rm,puntero);              //llamado de la funcion ROR
//            break;
//
//        case 'j':
//            ASR(Rd,Rn,Rm,puntero);           //llamado de la funcion ASR
//            break;
//
//        case 'k':
//            BIC(Rd,Rn,puntero);              //llamado de la funcion BIC
//            break;
//
//        case 'l':
//            MVN(Rd,Rn,puntero);                 //llamado de la funcion MVN
//            break;
//
//        case 'm':
//            RSB(Rd,Rn,puntero);              //llamado de la funcion RSB
//            break;
//
//        case 'n':
//            REV(Rd,Rm,puntero);              //llamado de la funcion REV
//            break;
//
//        case 'o':
//            REV16(Rd,Rm,puntero);              //llamado de la funcion REV
//            break;
//
//        case 'p':
//            CMN(Rn,Rm,puntero);          //llamado de la funcion CMN
//            break;
//
//        case 'q':
//            CMP(Rn,Rm,puntero);          //llamado de la funcion CMP
//            break;
//
//        case 'r':
//            MUL(Rd,Rn,Rm,puntero);          //llamado de la funcion MUL
//            break;
//
//        case 's':
//            TST(Rn,Rm,puntero);          //llamado de la funcion TST
//            break;

//    }
//
//    start_color();
//    init_pair(4, COLOR_WHITE, COLOR_CYAN);
//    attron(COLOR_PAIR(4));
//    mvprintw(30,2,"\n\nSu resultado es %d\nLas banderas son: N:%d\tZ:%d\tC:%d\tV:%d",Rd,Banderas[0],Banderas[1],Banderas[2],Banderas[3]);
//    refresh();
//    attron(COLOR_PAIR(4));
//
//    getch();
//    endwin();

//    return 0;
//}

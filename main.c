#include <stdio.h>
#include <stdlib.h>
#include "Registros.h"
#include "Instrucciones.h"

int main()
{
long int registro[12],OpcionInstruciones;
MostrarRegistro(registro[12]);

printf("Que operacion desea realizar \n1-ADD\n2-AND\n3-EOR\n4-MOV\n5-ORR\n6-SUBS\n");
scanf("%d",&OpcionInstruciones);

switch(OpcionInstruciones)

    {
    case 1:
        registro[1] = ADDS(registro[1],registro[2]);
    break;

    case 2:
        registro[1] = AND(registro[1],registro[2]);
    break;

    case 3:
        registro[1] = EOR(registro[1],registro[2]);
    break;

    case 4:
        registro[1] = MOV(registro[1],registro[2]);
    break;

    case 5:
        registro[1] = ORR(registro[1],registro[2]);
    break;

    case 6:
        registro[1] = SUBS(registro[1],registro[2]);
    break;

    }
printf(" Su resultado es %d", registro[1]);

    return 0;
}

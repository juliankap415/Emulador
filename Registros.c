#include "Registros.h"

void MostrarRegistro(int registro[])
{
    int i;
    for (i=0;i<=12;i++)
    {
        printf("Registro # %d: %d \n",i,registro[i]);
    }
}

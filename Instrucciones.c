#include "Instrucciones.h"


int ADDS(long int Registro1,long int Registro2)
{
    return Registro1+Registro2;
}

int AND(long int Registro1,long int Registro2)
{
    return Registro1&Registro2;
}

int EOR(long int Registro1,long int Registro2)
{
    return Registro1^Registro2;
}

int MOV(long int Registro1,long int Registro2)
{
    return Registro2;
}

int ORR(long int Registro1,long int Registro2)
{
    return Registro1|Registro2;
}

int SUBS(long int Registro1,long int Registro2)
{
    return Registro1-Registro2;
}

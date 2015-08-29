#include "Registros.h"
#include "Instrucciones.h"

int main()
{
    uint32_t registro[12],Rd,Rn,Rm; //variables de prueba
    int OpcionSeleccion,Banderas[4];

    printf("Seleccione la funcion que desea probar:\n\n1:Mostrar Registro\n2:ADDS\n3:AND\n4:MOV\n5:ORR\n6:SUBS      \n\nOpcion: ");
    scanf("%d",&OpcionSeleccion);

    switch(OpcionSeleccion)
    {
        case 1:
            MostrarRegistro(registro);
            break;

        case 2:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=ADDS(Rd,Rn,Rm);          //llamado de la funcion ADDS
            break;

        case 3:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=AND(Rn,Rm);              //llamado de la funcion AND
            break;

        case 4:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            Rd=MOV(Rn);                 //llamado de la funcion MOV
            break;

        case 5:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=ORR(Rn,Rm);              //llamado de la funcion ORR
            break;

        case 6:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=SUBS(Rd,Rn,Rm);           //llamado de la funcion SUBS
            break;
    }

    printf("\nSu resultado es %d\nLas banderas son: N:%d   Z:%d   C:%d   V:%d",Rd,Banderas[0],Banderas[1],Banderas[2],Banderas[3]);


    return 0;
}

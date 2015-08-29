#include "Registros.h"
#include "Instrucciones.h"

int main()
{
    uint32_t registro[12],Rd,Rn,Rm;
    int OpcionSeleccion;

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
            Rd=ADDS(Rd,Rn,Rm);
            break;

        case 3:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=AND(Rn,Rm);
            break;

        case 4:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            Rd=MOV(Rn);
            break;

        case 5:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=ORR(Rn,Rm);
            break;

        case 6:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=SUBS(Rd,Rn,Rm);
            break;
    }

    printf("\nSu resultado es %d",Rd);


    return 0;
}

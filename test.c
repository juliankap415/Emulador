#include "Registros.h"
#include "Instrucciones.h"
#include "Instrucciones_desplazamiento.h"

int main()
{
    uint32_t registro[12],Rd,Rn,Rm; //variables de pruebam
    int OpcionSeleccion,Banderas[4],*puntero=Banderas;

    printf("Seleccione la funcion que desea probar:\n\n1:Mostrar Registro\n2:ADDS\n3:AND\n4:MOV\n5:ORR\n6:SUBS\n7:LSL\n8:LSR\n9:ROR\n10:ASR\n11:BIC\n12:MVN\n13:RSBS\n14:REV\n15:REV16\n16:CMN\n17:CMP\n18:MUL\n19:TST    \n\nOpcion: ");
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
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 3:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=AND(Rn,Rm);              //llamado de la funcion AND
            BANDERAS(Rd,Rn,Rm,puntero);
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
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 6:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=SUBS(Rd,Rn,Rm);           //llamado de la funcion SUBS
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 7:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=LSL(Rd,Rn,Rm);           //llamado de la funcion LSL
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 8:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=LSR(Rd,Rn,Rm);           //llamado de la funcion LSR
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 9:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=ROR(Rn,Rm);           //llamado de la funcion ROR
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 10:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=ASR(Rd,Rn,Rm);           //llamado de la funcion ASR
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 11:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            Rd=BIC(Rd,Rn);              //llamado de la funcion BIC
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 12:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            Rd=MVN(Rn);              //llamado de la funcion MVN
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 13:
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            Rd=RSB(Rn);              //llamado de la funcion RSB
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 14:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=REV(Rd,Rm);              //llamado de la funcion REV
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 15:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=REV16(Rd,Rm);              //llamado de la funcion REV
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 16:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            CMN(Rd,Rn,Rm);          //llamado de la funcion CMN
            break;

        case 17:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            CMP(Rd,Rn,Rm);          //llamado de la funcion CMP
            break;

        case 18:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            Rd=MUL(Rd,Rn,Rm);          //llamado de la funcion MUL
            BANDERAS(Rd,Rn,Rm,puntero);
            break;

        case 19:
            printf("Ingrese a Rd:  ");
            scanf("%d",&Rd);
            printf("Ingrese a Rn:  ");
            scanf("%d",&Rn);
            printf("Ingrese a Rm:  ");
            scanf("%d",&Rm);
            TST(Rd,Rn,Rm);          //llamado de la funcion TST
            break;

    }

    printf("\nSu resultado es %d\nLas banderas son: N:%d   Z:%d   C:%d   V:%d",Rd,Banderas[0],Banderas[1],Banderas[2],Banderas[3]);


    return 0;
}

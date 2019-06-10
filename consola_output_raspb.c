#include<stdio.h>
#include "consola_output.h"
#include "manage_bit.h"

extern puerto_D puerto;

void imprimir (){                               //Imprimo en consola
    printf("PUERTO A:  %d", puerto.bit.b7);
    printf(" %d", puerto.bit.b6);
    printf(" %d", puerto.bit.b5);
    printf(" %d", puerto.bit.b4);
    printf(" %d", puerto.bit.b3);
    printf(" %d", puerto.bit.b2);
    printf(" %d", puerto.bit.b1);
    printf(" %d", puerto.bit.b0);
    printf("\n");
}

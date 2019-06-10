#include<stdio.h>
#include "consola_output_raspb.h"
#include "manage_bit_raspb.h"

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

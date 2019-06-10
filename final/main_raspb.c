#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "manage_bit_raspb.h"
#include "consola_output_raspb.h"
#include "init_raspberry_raspb.h"

#define ERROR '.'
#define FIN '&'
#define MASK_COM 0xFF

char recepcion(void);
int verify_comand(char);

static char comandos[] = {'t','c','s','q','0','1','2','3','4','5','6','7'};
puerto_D puerto ={0x00};

int main() {
    init_raspberry();
    char e = comandos[0];
	int s;
	while(e != 'q'){
    imprimir();
    imprimir_raspberry();
    e = recepcion();
    if(e != ERROR){
        if(e == 't')
            MaskToggle((&puerto.AccA), MASK_COM, sizeof(puerto.AccA));
        if(e == 'c')
            MaskOff((&puerto.AccA), MASK_COM, sizeof(puerto.AccA));
        if(e == 's')
            MaskOn((&puerto.AccA), MASK_COM, sizeof(puerto.AccA));
        if(e >= '0' && e <= '7'){
            s = e-48;
            BitSet((&puerto.AccA), s, sizeof(puerto.AccA));
        }
    }
    else{
        printf("Vuelva a intentarlo\n\n");
    }
	
    }
    MaskOff((&puerto.AccA), MASK_COM, sizeof(puerto.AccA));
    imprimir_raspberry();
	return 0;
}

char recepcion(){
    int i = 0;
    char c, a;
    while((c=getchar()) != '\n'){
        a = c;
        i++;
    }
    if(i>1){
        printf("Comando no reconocido\n");
        return ERROR;

    }
    if(verify_comand(a))
        return a;
    else{
        printf("Comando no reconocido\n");
        return ERROR;
    }
}
int verify_comand(char c){
    int i;
    for(i=0;i<12;i++)
        if(comandos[i] == c)
            return 1;
    return 0;
}


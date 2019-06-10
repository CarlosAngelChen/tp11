#include <stdio.h>
#include "termlib.h"
#include<stdlib.h>
#include<stdint.h>
#include "manage_bit_raspb.h"
#include "consola_output_raspb.h"

#define ERROR '.'
#define FIN '&'
#define MASK_COM 0xFF

unsigned char Get_Keyboard_Status(void);
char Get_Keyboard_Data(void);
char e; 
char recepcion(void);
char verify_comand(char);

static char comandos[] = {'t','c','s','q','0','1','2','3','4','5','6','7'};
puerto_D puerto ={0x00};

void main(void)
{
	int s;
	changemode(BUFFERED_OFF);  // Turns terminal line buffering off
	
	while (e!='q')
	{
		if(Get_Keyboard_Status())
		{
			e = Get_Keyboard_Data();
			imprimir();
			e = verify_comand(e);
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
	}
	
	 changemode(BUFFERED_ON);  // Turns terminal line buffering on
	
	//if (e == 'q'){
	//	MaskOff((&puerto.AccA), MASK_COM, sizeof(puerto.AccA));
	//	return 0;
	//}
} 


unsigned char Get_Keyboard_Status(void)
{
		return(kbhit());
}

char Get_Keyboard_Data(void)
{
	
	return(getchar());
		
}

char verify_comand(char c){
    int i;
    for(i=0;i<12;i++)
        if(comandos[i] == c)
            return c;
    return ERROR;
}

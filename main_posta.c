#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "manage_bit.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <stdbool.h>


#define FPS				60.0 //�Por que se uso float aca ?
#define COLOR_INC_RATE	1
#define MAX_COLOR_VALUE	255
#define ERROR_ '.'
#define FIN '&'
#define MASK_COM 0xFF
#define SCREEN_W		640
#define SCREEN_H		480
#define CUADRADITO_SIZE	32
#define MOVE_RATE		4.0

void fill_conj_pix(int, char[20]);

typedef struct{
     uint8_t aa;
} bytesa;

typedef struct{
     uint8_t b0 :1;
     uint8_t b1 :1;
     uint8_t b2 :1;
     uint8_t b3 :1;
     uint8_t b4 :1;
     uint8_t b5 :1;
     uint8_t b6 :1;
     uint8_t b7 :1;
} bits;

typedef union{
    bytesa    AccA;
    bits    bit;
} puerto_D;


puerto_D puerto ={0x00};

int main() 
{
    const int arr_led[] = {17.4.18,23,24,25,22,27};
    
    bool erabe[8] = {false,false,false,false,false,false,false,false};
    int s;

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;	
    ALLEGRO_TIMER *timer = NULL;

    bool blink = false;
    bool redraw = false;
    bool do_exit = false;
    
    //se ejecutan los comandos de inicializacion
    if(!al_init()) 
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    if(!al_install_keyboard()) 
    {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }

    timer = al_create_timer(4.5 / FPS);
    
    if(!timer) 
    {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue) 
    {
        fprintf(stderr, "failed to create event_queue!\n");
        return -1;
    }
    
    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display) 
    {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        al_destroy_event_queue(event_queue);
        return -1;
    }

    al_clear_to_color(al_map_rgb(0,128 , 0));
    al_set_target_bitmap(al_get_backbuffer(display));

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO

    //al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();
    al_clear_to_color(al_map_rgb(0,128 , 0));

    redraw = true;
    al_start_timer(timer);

    while(!do_exit)
    {
        ALLEGRO_EVENT ev;
        if( al_get_next_event(event_queue, &ev) ) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
        {
            if(ev.type == ALLEGRO_EVENT_TIMER)
            {
                if(blink)
                {
                    int bb;
                    static bool aa = false;
                    
                    if(aa)
                    {
                        for(bb=0;bb<8;bb++)
                        {
                            if(erabe[bb])
                            {
                                BitSet((&puerto.AccA), bb , sizeof(puerto.AccA));
                                redraw = true;
                            }
                        }
                    }
                    else
                    {
                        for(bb=0;bb<8;bb++)
                        {
                            if(erabe[bb])
                            {
                                BitClr((&puerto.AccA), bb , sizeof(puerto.AccA));
                                redraw = true;
                            }
                        }
                    }
                    aa = !aa;
                }
            }
            if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                do_exit = true;

            if(ev.type == ALLEGRO_EVENT_KEY_CHAR){
                switch(ev.keyboard.unichar)
                {
                    case 't':
                        MaskToggle((&puerto.AccA), (MASK_COM), sizeof(puerto.AccA));
                        redraw = true;
                        break;
                    
                    case 'c':
                        MaskOff((&puerto.AccA), (MASK_COM), sizeof(puerto.AccA));
                        redraw = true;
                        break;

                    case 's':
                        MaskOn((&puerto.AccA), (MASK_COM), sizeof(puerto.AccA));
                        redraw = true;
                        break;

                    case 'q':
                        do_exit = true;
                        break;
                        
                    case 'b':
                        blink = !blink;
                        if(blink)
                        {
                            int bb;
                            for(bb=0;bb<8;bb++)
                            {
                                if(BitGet((&puerto.AccA), bb, sizeof(puerto.AccA)))
                                    erabe[bb] = true;
                                else
                                    erabe[bb] = false;
                            }
                               
                        }
                        else
                        {
                            int bb;
                            for(bb=0;bb<8;bb++)
                            {
                                if(erabe[bb])
                                {
                                    BitSet((&puerto.AccA), bb, sizeof(puerto.AccA));
                                    erabe[bb] = false;
                                }      
                            }
                            redraw = true;
                        }
                        break;
                    default:
                        if(ev.keyboard.unichar > 47 && ev.keyboard.unichar< 56){
                            s = ev.keyboard.unichar-48;
                            BitSet((&puerto.AccA), s, sizeof(puerto.AccA));
                            redraw = true;
                            break;
                        }
                        else{
                            printf("Comando no reconocido\n");
                            printf("%d\n", ev.keyboard.unichar);
                            break;
                        }
                        }
	}
    }
    if(redraw && al_is_event_queue_empty(event_queue)){
        int bb = 0;
        redraw = false;
            //al_clear_to_color(al_map_rgb(255,255,0));\                
        printf("%X",puerto.AccA);

            for(bb=0;bb<8;bb++){
                    if(BitGet((&puerto.AccA), bb, sizeof(puerto.AccA))){
                        fill_conj_pix(bb, "white");
                    }
                    else {
                        fill_conj_pix(bb, "black");
                    }
            }
             al_flip_display();

        printf("\n");
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);

	return 0;

}


void fill_conj_pix(int bb, char color_r[20]){
    float cuadradito_x = SCREEN_W / 2.0 - CUADRADITO_SIZE / 2.0 - 170.0;
    float cuadradito_y = SCREEN_H / 2.0 - CUADRADITO_SIZE / 2.0;
    int i, j;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            al_put_pixel(cuadradito_x+i+(50*bb), cuadradito_y+j, al_color_name(color_r));

}


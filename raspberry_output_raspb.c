#include<syscall.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "manage_bit.h"

void imprimir_raspberry(){

char *pin17 = "/sys/class/gpio/gpio17/value";
char *pin4 = "/sys/class/gpio/gpio4/value";
char *pin18 = "/sys/class/gpio/gpio18/value";
char *pin23 = "/sys/class/gpio/gpio23/value";
char *pin24 = "/sys/class/gpio/gpio24/value";
char *pin25 = "/sys/class/gpio/gpio25/value";
char *pin22 = "/sys/class/gpio/gpio22/value";
char *pin27 = "/sys/class/gpio/gpio27/value";

extern puerto_D puerto;

char *pines[16] = {pin17,pin4,pin18,pin23,pin24,pin25,pin22,pin27};
//char *nums[8] = {"17", "4", "18", "23", "24", "25", "22", "27"};
char bits_port[8] = {puerto.bit.b0, puerto.bit.b1, puerto.bit.b2, puerto.bit.b3, puerto.bit.b4, puerto.bit.b5, puerto.bit.b6, puerto.bit.b7};

FILE *handle;
int nWritten, i;
uint8_t value_ob = puerto.bit.b6;
char obj;
for(i=0;i<8;i++){
obj = bits_port[i];
if ((handle = fopen(pines[i],"w")) == NULL)
	{
		printf("Cannot open device. Try again later.\n");
		exit(1);
	}
if(fputc(obj ,handle) == -1) // Set pin low
	{
		printf("Clr_Pin: Cannot write to file. Try again later.\n");
		exit(1);
	}
fclose(handle);

}

}
/*
if ((handle =  fopen(pin22,"w")) == NULL)
{
    printf("Cannot open EXPORT File. Try again later.\n");
    exit(1);
}
nWritten = fputs("22",handle);
if (nWritten == -1)
{
    printf("Cannot EXPORT PIN . Try again later.\n");
    exit(1);
}
else
    //printf("EXPORT File opened succesfully\n");
    */

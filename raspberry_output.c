#include<syscall.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "manage_bit.h"

void imprimir_raspberry(){

char *pin22 = "/sys/class/gpio/gpio22/value";

FILE *handle;
int nWritten;
uint8_t value_ob = puerto.bit.b6;
char obj;

if(value_ob)
    obj = '1';
else
    obj = '0';

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

if ((handle = fopen(pin22,"w")) == NULL)
	{
		printf("Cannot open device. Try again later.\n");
		exit(1);
	}
	else
	{
		//printf("Device successfully opened\n");
	}
	if(fputc(obj ,handle) == -1) // Set pin low
	{
		printf("Clr_Pin: Cannot write to file. Try again later.\n");
		exit(1);
	}
	else
		//printf("Write to file %s successfully done.\n",pin22);


fclose(handle);
}

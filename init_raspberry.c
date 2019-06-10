#include<syscall.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void init_raspberry(){

char *pin22_export = "/sys/class/gpio/gpio22/value";
char *pin22_direction = "/sys/class/gpio/gpio22/direction";

FILE *handle;
int nWritten;
if ((handle =  fopen(pin22_export,"w")) == NULL)
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
    printf("EXPORT File opened succesfully\n");

fclose(handle);

if ((handle = fopen(pin22_direction,"w")) == NULL)
{
    printf("Cannot open DIRECTION File");
    exit(1);
}
	// Set pin Direction
if ((nWritten = fputs("out",handle)) == -1)
{
    printf("Cannot open DIRECTION pin. Try again later.\n");
    exit(1);
}
else
{
    printf("DIRECTION File for PIN opened succesfully\n");
}
fclose(handle); // Be carefulldo this for EACH pin !!!

}

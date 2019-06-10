#include<syscall.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void init_raspberry(){

char *pin17_export = "/sys/class/gpio/gpio17/value";
char *pin17_direction = "/sys/class/gpio/gpio17/direction";
char *pin4_export = "/sys/class/gpio/gpio4/value";
char *pin4_direction = "/sys/class/gpio/gpio4/direction";
char *pin18_export = "/sys/class/gpio/gpio18/value";
char *pin18_direction = "/sys/class/gpio/gpio18/direction";
char *pin23_export = "/sys/class/gpio/gpio23/value";
char *pin23_direction = "/sys/class/gpio/gpio23/direction";
char *pin24_export = "/sys/class/gpio/gpio24/value";
char *pin24_direction = "/sys/class/gpio/gpio24/direction";
char *pin25_export = "/sys/class/gpio/gpio25/value";
char *pin25_direction = "/sys/class/gpio/gpio25/direction";
char *pin22_export = "/sys/class/gpio/gpio22/value";
char *pin22_direction = "/sys/class/gpio/gpio22/direction";
char *pin27_export = "/sys/class/gpio/gpio27/value";
char *pin27_direction = "/sys/class/gpio/gpio27/direction";


char *pines[16] = {pin17_export,pin17_direction, pin4_export,pin4_direction,pin18_export,pin18_direction,
                    pin23_export,pin23_direction,pin24_export,pin24_direction,pin25_export,pin25_direction,
                    pin22_export,pin22_direction, pin27_export,pin27_direction};
char *nums[8] = {"17", "4", "18", "23", "24", "25", "22", "27"};

FILE *handle;
int nWritten, i;

for(i=0;i<16;i=i+2){
if ((handle =  fopen(pines[i],"w")) == NULL)
{
    printf("Cannot open EXPORT File. Try again later.\n");
    exit(1);
}
nWritten = fputs(nums[i],handle);
if (nWritten == -1)
{
    printf("Cannot EXPORT PIN . Try again later.\n");
    exit(1);
}
else
    printf("EXPORT File opened succesfully\n");

fclose(handle);

if ((handle = fopen(pines[i+1],"w")) == NULL)
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
}

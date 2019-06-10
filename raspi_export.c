#include <stdio.h>
#include <stdint.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	
/* *********************************************************** */
		//EXPORTO TODOS LOS PUERTOS DE LA RASPBERRY
	const char *arr_led[8] = {"17","4","18","23","24","25","22","27"};

	FILE *handle_export;
	int nWritten_export;
	if ((handle_export =  fopen("/sys/class/gpio/export","w")) == NULL)
	{
		printf("Cannot open EXPORT File. Try again later.\n");
		exit(1);
	}
	int i; //contador de puertos
	for (i=0; i < 8; i++)
	{
		nWritten_export=fputs(*(arr_led+i),handle_export); 	
		if (nWritten_export==-1)
		{
			printf("Cannot EXPORT PIN . Try again later.\n");
			exit(1);
		}
		else
		{
			printf("EXPORT File opened succesfully\n");
		}
		fclose(handle_export);  // Be carefulldo this for EACH pin !!!
	}
/* *********************************************************** */




/* *********************************************************** */
// TEST PIN 22
	FILE * handle_direction;
	int nWritten_direction;
	if ((handle_direction= fopen("/sys/class/gpio/gpio22/direction","w")) == NULL)
	{
		printf("Cannot open DIRECTION File");
		exit(1);
	}
	// Set pin Direction
	if ((nWritten_direction=fputs("out",handle_direction))==-1)
	{
		printf("Cannot open DIRECTION pin. Try again later.\n");
		exit(1);
	}
	else
	{
		printf("DIRECTION File for PIN opened succesfully\n");
	}
	fclose(handle_direction); // Be carefulldo this for EACH pin !!!


	FILE * handle;
	int nWritten_pin;
	char *pin22 ="/sys/class/gpio/gpio22/value";
	if ((handle = fopen(pin22,"w")) == NULL)
	{
		printf("Cannot open device. Try again later.\n");
		exit(1);
	}
	else
	{
		printf("Device successfully opened\n");
	}
	if(fputc('1' ,handle)==-1) // Set pin low
	{
		printf("Clr_Pin: Cannot write to file. Try again later.\n");
		exit(1);
	}
	else
		printf("Write to file %s successfully done.\n",pin22);
	fclose(handle);

	return 0;
}
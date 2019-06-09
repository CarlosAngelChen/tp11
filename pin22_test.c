#include<syscall.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>


FILE * handle;
int nWritten_pin;
char *pin22 ="/sys/class/gpio/gpio22/value";
int main(void)
{
	FILE *handle_export;
	int nWritten_export;
	if ((handle_export=  fopen("/sys/class/gpio/export","w")) == NULL)
	{
		printf("Cannot open EXPORT File. Try again later.\n");
		exit(1);
	}
	nWritten_export=fputs("22",handle_export); 
	if (nWritten_export==-1)
	{
		printf("Cannot EXPORT PIN . Try again later.\n");
		exit(1);
	}
	else
		printf("EXPORT File opened succesfully\n");

	fclose(handle_export);  // Be carefulldo this for EACH pin !!!


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
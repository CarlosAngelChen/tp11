#include <stdio.h>
#include <stdint.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ON 1
#define OFF 0

/* *********************************************************** */
//SET DE PINES (NO TERMINADA)

void delay(unsigned int mseconds);

int main(void)
{

/* *********************************************************** */
		//EXPORTO TODOS LOS PUERTOS DE LA RASPBERRY
	const char *arr_led[] = {"17","4","18","23","24","25","22","27"};
	//const char *arr_led[] = {'17','4','18','23','24','25','22','27'};
	
	int i; //contador de puertos
	for (i=0; i < 8; i++)
	{

		FILE *handle_export;
		int nWritten_export;
		if ((handle_export =  fopen("/sys/class/gpio/export","w")) == NULL)
		{
			printf("Cannot open EXPORT File. Try again later.\n");
			exit(1);
		}
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
		//OUTPUT DE TODOS LOS PUERTOS
	
	const char *arr_direction[] = {"/sys/class/gpio/gpio17/direction", "/sys/class/gpio/gpio4/direction",
								"/sys/class/gpio/gpio18/direction", "/sys/class/gpio/gpio23/direction",
								"/sys/class/gpio/gpio24/direction", "/sys/class/gpio/gpio25/direction",
								"/sys/class/gpio/gpio22/direction", "/sys/class/gpio/gpio27/direction"};

	int j;
	for (j = 0; j < 8; j++)
	{
		FILE * handle_direction;
		int nWritten_direction;
		if ((handle_direction= fopen(*(arr_direction + j),"w")) == NULL)
		{
			printf("Cannot open DIRECTION File\n");
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
	}
/* *********************************************************** */


/* *********************************************************** */



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
	if(fputc('0' ,handle)==-1) // Set pin low
	{
		printf("Clr_Pin: Cannot write to file. Try again later.\n");
		exit(1);
	}
	else
		printf("Write to file %s successfully done.\n",pin22);
	fclose(handle);
	FILE * handle_bit;
	int nWritten_bit;

	char *pin0 = "/sys/class/gpio/gpio17/value";
	char *pin1 = "/sys/class/gpio/gpio4/value";
	char *pin2 = "/sys/class/gpio/gpio18/value";
	char *pin3 = "/sys/class/gpio/gpio23/value";
	char *pin4 = "/sys/class/gpio/gpio24/value";
	char *pin5 = "/sys/class/gpio/gpio25/value";
	char *pin6 = "/sys/class/gpio/gpio22/value";
	char *pin7 = "/sys/class/gpio/gpio27/value";

	while(1)
	{
		if ((handle_bit = fopen(pin0,"w")) == NULL)
		{
			printf("Cannot open device. Try again later.\n");
			exit(1);
		}

		else
		{
			//printf("Device successfully opened\n");
		}

		if(fputc('1' ,handle_bit)==-1) // Set pin low
		{
			printf("Clr_Pin: Cannot write to file. Try again later.\n");
			exit(1);
		}
		else
		{
			//printf("Write to file %s successfully done.\n",pin0);
		}
		fclose(handle_bit);

		delay(5000); //1 seg

		if ((handle_bit = fopen(pin0,"w")) == NULL)
		{
			printf("Cannot open device. Try again later.\n");
			exit(1);
		}

		else
		{
			printf("Device successfully opened\n");
		}

		if(fputc('1' ,handle_bit)==-1) // Set pin low
		{
			printf("Clr_Pin: Cannot write to file. Try again later.\n");
			exit(1);
		}
		else
		{
			//printf("Write to file %s successfully done.\n",pin0);
		}
		fclose(handle_bit);
	}
/* *********************************************************** */

return 0;
}


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//int arr_pled[] = {*pin0, *pin1, *pin2, *pin3, *pin4, *pin5, *pin6, *pin7};

//typedef struct 			//defino estructura de ON OFF de pines
//{
//	uint8_t pin0 :1;
//	uint8_t pin1 :1;
//	uint8_t pin2 :1;
//	uint8_t pin3 :1;
//	uint8_t pin4 :1;
//	uint8_t pin5 :1;
//	uint8_t pin6 :1;
//	uint8_t pin7 :1;

//}pin_led_t;

//typedef struct
//{
//    uint8_t led_by; // (2 bytes)
//} led_byte_t;

//typedef union
//{
//	led_byte_t ledby;
//	led_bit_t ledbi;
//}my_led_t;

//my_led_t led_x;

//char c;
//c = 10;
//led_x.ledby.led_by = c;

//int char2bit(char c);
//switch 

/* *********************************************************** */
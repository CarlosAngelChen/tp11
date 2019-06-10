#include "manage_bit_raspb.h"
#define PAR 2
#define ON 1

void BitClr (void *pPort_i,  int i,  int longi)
{
    if (i<longi*8 && longi*8==sizeof(uchar_t)*8)			//validacion de i
    {
        uchar_t *pPort;
        pPort = pPort_i;
        *pPort=*pPort&(~(1<<i));				//mascara que permite apagar bit i
    }

    else if (i<longi*8 && longi*8==sizeof(uint16_t)*8)		//validacion de i
    {
        uint16_t *pPort;
        pPort = pPort_i;
        *pPort=*pPort&(~(1<<i));				//mascara que permite apagar bit i
    }

    else
    {
        printf("ERROR\n");
    }
}



void BitSet (void *pPort_i, int i, int longi)
{
    if (i<longi*8 && longi==sizeof(uchar_t))			//validacion de i
    {
        uchar_t *pPort;
        pPort = pPort_i;
        *pPort=*pPort | (1<<i);					//m�scara que permite prender bit i

    }

    else if (i<longi*8 && longi*8==sizeof(uint16_t)*8)		//validacion de i
    {
        uint16_t *pPort;
        pPort = pPort_i;
        *pPort=*pPort|(1<<i);
    }

    else
    {
        printf("ERROR\n");
    }
}


int BitGet (void *pPort_i, int i, int longi)
{
    if (i<longi*8 && longi*8==sizeof(uchar_t)*8)						//validacion de i
    {
        uchar_t *pPort;
        pPort = pPort_i;

        if ((*pPort>>i)%PAR==ON)				//se mueve el bit i hasta que sea el primero, y chequeo si el nuevo numero es impar
        {
            return TRUE;						//se ve la igualdad con ON para que sea mas claro
        }

        else
        {
            return FALSE;
        }
    }

    else if (i<longi*8 && longi*8==sizeof(uint16_t)*8)						//validacion de i
    {
        uint16_t *pPort;
        pPort = pPort_i;

        if ((*pPort>>i)%PAR==ON)				//se mueve el bit i hasta que sea el primero, y chequeo si el nuevo numero es impar
        {
            return TRUE;						//se ve la igualdad con ON para que sea mas claro
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        printf("ERROR\n");
        return -1;
    }
}


void BitToggle (void *pPort_i, int i, int longi)
{
    if (i<longi*8 && longi*8==sizeof(uchar_t)*8)			//validacion de i
    {
        uchar_t *pPort;
        pPort = pPort_i;

        if (BitGet (pPort, i, longi)==ON)				//check del estado del bit i
        {
            BitClr (pPort, i, longi);					//si esta prendido se apaga
        }

        else
        {
            BitSet (pPort, i, longi);					//si esta apagado se prende
        }
    }

    else if (i<longi*8 && longi*8==sizeof(uint16_t)*8)		//validacion de i
    {
        uint16_t *pPort;
        pPort = pPort_i;

        if (BitGet (pPort, i, longi)==ON)				//check del estado del bit i
        {
            BitClr (pPort, i, longi);					//si esta prendido se apaga
        }
        else
        {
            BitSet (pPort, i, longi);					//si esta apagado se prende
        }
    }

        else
        {
            printf("ERROR\n");
        }
}

void MaskOn (void *pPort_i, uint16_t elon, int longe)
{
    if (elon < longe*256 && longe*256==sizeof(uchar_t)*256)										//validacion de la m�scara
    {
        elon = (uchar_t) elon;
        uchar_t *pPort;
        pPort = pPort_i;
        *pPort=(*pPort) | (elon);					//se prenden los bits que indica la mascara
    }

    else if (elon < longe*32768 && longe*32768==sizeof(uint16_t)*32768)										//validacion de la m�scara
    {
        uint16_t *pPort;
        pPort = pPort_i;
        *pPort=(*pPort)|(elon);					//se prenden los bits que indica la mascara
    }
    else
    {
        printf("ERROR\n");
    }
}


void MaskOff (void *pPort_i, uint16_t elon, int longe)
{
    if (elon < longe*256 && longe*256==sizeof(uchar_t)*256)					//validacion de mascara
    {
        elon = (uchar_t) elon;
        uchar_t *pPort;
        pPort = pPort_i;
		*pPort=(*pPort)&(~(elon));						//se apagan los bits que indican la mascara
	}

	else if (elon < longe*32768 && longe*32768==sizeof(uint16_t)*32768)										//validacion de la m�scara
	{
		uint16_t *pPort;
    	pPort = pPort_i;
    	*pPort=(*pPort)&(~(elon));						//se apagan los bits que indican la mascara
	}

	else
	{
		printf("ERROR\n");
	}
}


void MaskToggle (void *pPort_i, uint16_t elon, int longe)
{
    if ((elon < longe*256) && ((longe*256)==(sizeof(uchar_t)*256)))					//validacion de mascara
    {
        elon = (uchar_t) elon;
        uchar_t *pPort;
        pPort = pPort_i;
        *pPort=(*pPort)^(elon);						//cambio de valor de bits que indican la mascara
    }

	else if ((elon < longe*32768) && (longe*32768==sizeof(uint16_t)*32768))										//validacion de la m�scara
	{
		uint16_t *pPort;
    	pPort = pPort_i;
    	*pPort=(*pPort)^(elon);						//cambio de valor de bits que indican la mascara
	}

	else
	{
		printf("ERROR\n");
	}
}

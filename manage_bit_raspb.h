#ifndef MANAGE_BIT_H
#define MANAGE_BIT_H
#include <stdio.h>
#include <stdint.h>

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
} puerto_D;                         //Estructura del puerto D

enum {FALSE, TRUE};
typedef unsigned char uchar_t;

//BitClr recibe un puntero a un puerto y el bit que se desea apagar.
//El puntero puede ser de cualquier tipo de dato, de modo que no importa
//el tamaño del puerto con el que se trabaja. Para vigilar que no se opere
//con un bit que no pertenezca al puerto, se multiplica el tamaño del puerto
//por 8 y se lo compara con el bit solicitado.
void BitClr (void *pPort_i, int i, int longi);

//BitSet recibe un puntero a un puerto y el bit que se desea prender.
//El puntero puede ser de cualquier tipo de dato, de modo que no importa
//el tamaño del puerto con el que se trabaja. Para vigilar que no se opere
//con un bit que no pertenezca al puerto, se multiplica el tamaño del puerto
//por 8 y se lo compara con el bit solicitado.
void BitSet (void *pPort_i, int i, int longi);

//BitToggle recibe un puntero a un puerto y el bit que se desea cambiar; si esta prendido se apagara
//y si esta aoagado se prendera. El puntero puede ser de cualquier tipo de dato, de modo que no importa
//el tamaño del puerto con el que se trabaja. Para vigilar que no se opere
//con un bit que no pertenezca al puerto, se multiplica el tamaño del puerto
//por 8 y se lo compara con el bit solicitado.
void BitToggle (void *pPort_i, int i, int longi);

//BitGet recibe un puntero a un puerto y el bit que se desea analizar.
//El puntero puede ser de cualquier tipo de dato, de modo que no importa
//el tamaño del puerto con el que se trabaja. Para vigilar que no se opere
//con un bit que no pertenezca al puerto, se multiplica el tamaño del puerto
//por 8 y se lo compara con el bit solicitado.
//BitGet devuelve un 1 si el bit se encuentra encendido, y un 0 si se encuentra apagado.
int BitGet (void *pPort_i, int i, int longi);

//MaskOn recibe un puntero a un puerto y una mascara. Se desea prender los bits que
//esten prendidos en la mascara. El puntero puede ser de cualquier tipo de dato,
//de modo que no importa el tamaño del puerto con el que se trabaja. Para vigilar que no se opere
//con una mascara que exceda al tamaño del puerto, se multiplica el tamaño del puerto por 255
//(representa el mayor digito posible) y se lo compara con la mascara solicitada.
void MaskOn (void *pPort_i, uint16_t elon, int longe);

//MaskOff recibe un puntero a un puerto y una mascara. Se desea apagar los bits que
//esten prendidos en la mascara. El puntero puede ser de cualquier tipo de dato,
//de modo que no importa el tamaño del puerto con el que se trabaja. Para vigilar que no se opere
//con una mascara que exceda al tamaño del puerto, se multiplica el tamaño del puerto por 255
//(representa el mayor digito posible) y se lo compara con la mascara solicitada.
void MaskOff (void *pPort_i, uint16_t elon, int longe);

//MaskOn recibe un puntero a un puerto y una mascara. Se desea cambiar los bits que
//esten prendidos en la mascara, es decir, si el bit del puerto esta prendido, entonces apagarlo,
// o si esta apgado entonces prenderlo. El puntero puede ser de cualquier tipo de dato,
//de modo que no importa el tamaño del puerto con el que se trabaja. Para vigilar que no se opere
//con una mascara que exceda al tamaño del puerto, se multiplica el tamaño del puerto por 255
//(representa el mayor digito posible) y se lo compara con la mascara solicitada.
void MaskToggle (void *pPort_i, uint16_t elon, int longe);

#endif

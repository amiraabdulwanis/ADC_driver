/**************************************************************/
/*********     Author : Amira Abdelwanis      ********************/
/*********     Description : REG.h   ********************/
/*********     Date :26 MARCH 2020         ********************/
/*********     Version : 1.0V              ********************/
/**************************************************************/




#define INPUT  0
#define OUTPUT 1

#define HIGH   1
#define LOW    0


#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3




void DIO_u8SetPortValue(u8 PORTID, u8 P_VALUE);
void DIO_u8PortDirection(u8 PORTID, u8 Direction);
u8 DIO_u8GetPinValue(u8 PORTID,u8 PINID);
ErrorStatus DIO_enumSetPinValue(u8 PORTID, u8 PINID, u8 LEVEL);
ErrorStatus DIO_enumSetPinDirection  (u8 PORTID, u8 PINID , u8 Direction);

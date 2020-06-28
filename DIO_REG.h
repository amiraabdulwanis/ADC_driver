/**************************************************************/
/*********     Author : Amira Abdelwanis      ********************/
/*********     Description : REG.h   ********************/
/*********     Date :26 MARCH 2020         ********************/
/*********     Version : 1.0V              ********************/
/**************************************************************/


/**************************************************************/
/*********Gard of file will call on time in the c**************/
/**************************************************************/

#ifndef _DIO_REG_H_
#define _DIO_REG_H_

// port A
#define DDRA_REG  *((volatile u8 *)0x3A)// void pointer address needs casting as register 8 bit
#define PORTA_REG *((volatile u8 *)0x3B)
#define PINA_REG  *((volatile u8 *)0x39)
//port B
#define DDRB_REG *((volatile u8 *)0x37)
#define PORTB_REG *((volatile u8 *)0x38)
#define PINB_REG *((volatile u8 *)0x36)
//port C
#define DDRC_REG *((volatile u8 *)0x34)
#define PORTC_REG *((volatile u8 *)0x35)
#define PINC_REG *((volatile u8 *)0x33)
//port D
#define DDRD_REG *((volatile u8 *)0x31)
#define PORTD_REG *((volatile u8 *)0x32)
#define PIND_REG *((volatile u8 *)0x30)

#endif

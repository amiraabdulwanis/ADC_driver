/*********     Author : Amira Abdelwanis      ********************/
/*********     Description : DIO_InT.c  ********************/
/*********     Date :26 MARCH 2020         ********************/
/*********     Version : 1.0V              ********************/
/**************************************************************/

//set pin direction
#include"STD_types.h"
#include"Bit_math.h"
#include"Error_Status.h"
#include "DIO_REG.h"
#include "DIO_Int.h"

ErrorStatus DIO_enumSetPinDirection  (u8 PORTID, u8 PINID , u8 Direction) // enum like struct but converts text to index number
{
	ErrorStatus error = NOTOK; // initialize error type ErrorStatus
	if((PORTID<4)&&(PINID<8)) // check 8aba2 el user in entering num higher than ports num or pins
	{
		if(Direction == OUTPUT)
		{
			// check num of port
			switch( PORTID) {
			case PORTA: SET_BIT(DDRA_REG,PINID);break;//set bit de macro(pre-defined in Bit_math.h) ht3ml seting lel bit 
			case PORTB: SET_BIT(DDRB_REG,PINID);break;//DDRB_REG da pointer asln by point 3la l address bta3 el port
			case PORTC: SET_BIT(DDRC_REG,PINID);break;
			case PORTD: SET_BIT(DDRD_REG,PINID);break;
			error=OK;
			}
		}
		else if(Direction == INPUT)
		{
			ErrorStatus error = NOTOK; // initialize error type ErrorStatus
			switch( PORTID)
			{
			case PORTA: CLEAR_BIT(DDRA_REG,PINID);break;//set bit de macro(pre-defined in Bit_math.h) ht3ml seting lel bit
			case PORTB: CLEAR_BIT(DDRB_REG,PINID);break;//DDRB_REG da pointer asln by point 3la l address bta3 el port
			case PORTC: CLEAR_BIT(DDRC_REG,PINID);break;
			case PORTD: CLEAR_BIT(DDRD_REG,PINID);break;

			error=OK;
			}
		}
	}
	else
	{
		error = NOTOK; // not ok status if entered out of ports num or pins num
	}
	return error;
}
//set pin value (hya b o/p wna 3awz a7ot fel port ya one(if high given) or zero(if low given)
ErrorStatus DIO_enumSetPinValue(u8 PORTID, u8 PINID, u8 LEVEL)
{
	ErrorStatus error = NOTOK; // initialize error type ErrorStatus
	if((PORTID<4)&&(PINID<8)) // check 8aba2 el user in entering num higher than ports num or pins
	{
		if (LEVEL== HIGH){
			switch( PORTID) {
			case PORTA: SET_BIT(PORTA_REG,PINID);break;//set bit de macro(pre-defined in Bit_math.h) ht3ml seting lel bit(ht5liha b 1)
			case PORTB: SET_BIT(PORTB_REG,PINID);break;//DDRB_REG da pointer asln by point 3la l address bta3 el port
			case PORTC: SET_BIT(PORTC_REG,PINID);break;
			case PORTD: SET_BIT(PORTD_REG,PINID);break;
			}
		}

		else if (LEVEL == LOW) //turn on pull up
		{
			switch( PORTID) {
			case PORTA: CLEAR_BIT(PORTA_REG,PINID);break;//clear bit de macro(pre-defined in Bit_math.h) ht3ml seting lel bit
			case PORTB: CLEAR_BIT(PORTB_REG,PINID);break;//DDRB_REG da pointer asln by point 3la l address bta3 el port
			case PORTC: CLEAR_BIT(PORTC_REG,PINID);break;
			case PORTD: CLEAR_BIT(PORTD_REG,PINID);break;
			}
		}
		else
		{
			error = Not_In_Range;// da fe 7ala law el user da5lha wla high wala law
		}
	}
	else
	{
		error = NOTOK; // not ok status if entered out of ports num or pins num
	}
	return error;
}
// get pin value hya i/p wna 3awz aqra2 el value de
u8 DIO_u8GetPinValue(u8 PORTID,u8 PINID)
{
	u8 Local_Value= 0;
	if((PORTID<4)&&(PINID<8))
	{
		switch(PORTID)
		{
		case PORTA: Local_Value = GET_BIT(PINA_REG,PINID);break;
		case PORTB: Local_Value = GET_BIT(PINB_REG,PINID);break;
		case PORTC: Local_Value = GET_BIT(PINC_REG,PINID);break;
		case PORTD: Local_Value = GET_BIT(PIND_REG,PINID);break;
		}
	}
	return Local_Value;
}
//set port direction represents the total value we can set port with it as a total
void DIO_u8PortDirection(u8 PORTID, u8 Direction)
    {
	switch(PORTID)
	{
	case PORTA: DDRA_REG= Direction;break;
	case PORTB: DDRB_REG= Direction;break;
	case PORTC: DDRC_REG= Direction;break;
	case PORTD: DDRD_REG= Direction;break;
	}
}
//set port value(give a total value to the port to be represented in all pins
void DIO_u8SetPortValue(u8 PORTID, u8 P_VALUE)// u8 to accept any decimal number to enable all the port
{
	switch(PORTID)
	{
	case PORTA: PORTA_REG=P_VALUE;break;
	case PORTB: PORTB_REG=P_VALUE;break; // VALUE da variable 3adi byktebo el user bn7oto f el address bta3el port
	case PORTC: PORTC_REG=P_VALUE;break;
	case PORTD: PORTD_REG=P_VALUE;break;
	}
}




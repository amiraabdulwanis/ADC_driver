/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Amira Abdel Wanis
 */

//test ADC program

#include"STD_types.h"
#include"Error_Status.h"
#include"Bit_math.h"

//MCAL
#include"DIO_REG.h"
#include"DIO_Int.h"
#include "ADC_REG.h"
#include "ADC_confg.h"
#include "ADC_int.h"

volatile u8 ADC_value;
u8 amira;
int main()
{
	DIO_u8PortDirection(PORTC,0xFF);//PORTC as o/p to represent the result
	DIO_enumSetPinDirection(PORTA,PIN1,INPUT);//PORTA A1 (ADC channel) PIN1
	ADC_enuInt();
	while(1)
	{
		ADC_StartConversion();//ADC start conversion
		Flag_Check();//POLING & zero flag to be 1
		ADC_value=ADC_REConvADCH();//read o/p from ADCH REG
		DIO_u8SetPortValue(PORTC,ADC_value);
	}

return 0;
}

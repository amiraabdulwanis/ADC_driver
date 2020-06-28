/*
 * ADC_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Amira Abdel Wanis
 */

#include "STD_types.h"
#include "Bit_math.h"
#include "Error_Status.h"
#include "ADC_REG.h"
#include "ADC_confg.h"
#include "ADC_int.h"


ErrorStatus ADC_enuInt(void)
{
	ErrorStatus error=NOTOK;
	ADC_enuEnable();
	ADC_Vref();
	ADC_CHannel();
	ADC_DisAutoTrig();
	ADC_DisInt();
	ADC_LeftAdjust();
	ADC_prescaler();
	return error;
}
ErrorStatus ADC_enuEnable(void)
{
	ErrorStatus error=NOTOK;
	SET_BIT(ADCSRA,7);
	return error;
}
ErrorStatus ADC_enuDisable(void) {
	ErrorStatus error = NOTOK;
	CLEAR_BIT(ADCSRA, 7);
	return error;
}
ErrorStatus ADC_Vref(void)
{
	ErrorStatus error=NOTOK;
#if V_ref== VCC
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
#elif V_ref== A_ref
	CLEAR_BIT(ADMUX,7);
	CLEAR_BIT(ADMUX,6);
#elif  V_ref== Int_Voltage
	SET_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
#endif
return error;
}
ErrorStatus ADC_CHannel(void)
{
	ErrorStatus error=NOTOK;
#if ADC_channel== ADC_0
	CLEAR_BIT(ADMUX, 0);
	CLEAR_BIT(ADMUX, 1);
	CLEAR_BIT(ADMUX, 2);
	CLEAR_BIT(ADMUX, 3);
	CLEAR_BIT(ADMUX, 4);
#elif ADC_channel== ADC_1
	SET_BIT(ADMUX,0);
	CLEAR_BIT(ADMUX,1);
	CLEAR_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);
#elif ADC_channel== ADC_2
	CLEAR_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	CLEAR_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);
#elif ADC_channel == ADC_3
	SET_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	CLEAR_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);
#elif ADC_channel == ADC_4
	CLEAR_BIT(ADMUX,0);
	CLEAR_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);
#elif ADC_channel == ADC_5
	SET_BIT(ADMUX,0);
	CLEAR_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);
#elif ADC_channel == ADC_6
	CLEAR_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);
#elif ADC_channel == ADC_7
	SET_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,4);
#endif
return error;
}
ErrorStatus ADC_LeftAdjust(void)
{
	ErrorStatus error=NOTOK;
	SET_BIT(ADMUX,5);
	return error;
}
ErrorStatus ADC_RightAdjust(void)
{
	ErrorStatus error=NOTOK;
	CLEAR_BIT(ADMUX,5);
	return error;
}
void ADC_prescaler(void)
{
#if prescaler== 64
CLEAR_BIT(ADCSRA,0);
SET_BIT(ADCSRA,1);
SET_BIT(ADCSRA,2);
#elif Prescaler ==  128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif Prescaler ==  32
	SET_BIT(ADCSRA,0);
	CLEAR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);


#endif
}
void ADC_DisAutoTrig(void)
{
	CLEAR_BIT(ADCSRA, 5);
}
void ADC_DisInt(void)
{
	CLEAR_BIT(ADCSRA, 3);
}
void ADC_StartConversion(void)
{
	SET_BIT(ADCSRA,6);
}
void Flag_Check(void)
{
	while(!(ADCSRA & (1<<4)));
    SET_BIT(ADCSRA,4);  // clear flag by putting 1 in it
}
u8 ADC_REConvADCH(void) //RETURN REG HIGH
{
	u8 ADC_value=ADCH;
	return 	ADC_value;
}
u8 ADC_REConvADCL(void) //RETURN REG LOW
{
	u8 ADC_value=ADCL;
	return 	ADC_value;
}
u16 RE_u16ADCHL(void)   //RETURN BOTH REG HIGH AND LOW
{
	u16 ADC_valueL=ADC_REConvADCL();
	u16 ADC_valueH = ADC_REConvADCH(); //read o/p from ADCH REG
	u16 x = (ADC_valueL>> 6);
	u16 ADC_value = x | (ADC_valueH << 2);
	return ADC_value;
}



/*
 * ADC_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Amira Abdel Wanis
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

ErrorStatus ADC_enuInt(void);
ErrorStatus ADC_enuEnable(void);
ErrorStatus ADC_enuDisable(void);
ErrorStatus ADC_Vref(void);
ErrorStatus ADC_CHannel(void);
ErrorStatus ADC_LeftAdjust(void);
ErrorStatus ADC_RightAdjust(void);
void ADC_StartConversion(void);
void ADC_DisInt(void);
void Flag_Check(void);
u8 ADC_REConvADCH(void);
void ADC_prescaler(void);
void ADC_DisAutoTrig(void);
u8 ADC_REConvADCL(void);
u16 RE_u16ADCHL(void);

#endif /* ADC_INT_H_ */

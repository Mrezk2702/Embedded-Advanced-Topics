/*
 * FixedPoint.c
 *
 *  Created on: Jan 14, 2025
 *      Author: mrezk
 */


#include "FixedPoint.h"


#define SCALING_FACTOR 1000
static void PrintFixedPointAsFloat(StackEntry e);


inline FP32 convertToFixed(float32 Copy_F32Number)
{
	FP32 ConvertedFP=(FP32)(Copy_F32Number * (FP32)SCALING_FACTOR);
	return ConvertedFP;

}

inline float32 convertToFloat(FP32 Copy_FP32Number)
{
	float32 convertedFloat=((float32)Copy_FP32Number)/(SCALING_FACTOR);
	return convertedFloat;
}

FP32 FixedPointAddition(float32 op1,float32 op2)
{
	FP32 FP_op1=convertToFixed(op1);
	FP32 FP_op2=convertToFixed(op2);
	FP32 result;
	if(!(FP_op1>(sint32)2147483647-FP_op2))
	{
		result=FP_op1+FP_op2;

	}
	return result;

}



void FixedPointPrintNumber(FP32 num,uint8 x,uint8 y)
{
	Stack NumStack;
	CreateStack(&NumStack);
	if(num<0)
	{
		//check sign of input
		CLCD_voidSendData('-');
		num=-num;
	}
	//we need to take the accuracy into consideration
	FP32 mantissa=num%SCALING_FACTOR;
	//push the mantissa in the stack digit by digit

	if(mantissa!=0)
	{

		/*Push digits of the mantissa into the stack*/
		while(mantissa>0)
		{
			Push(&NumStack, mantissa%10+'0');
			mantissa/=10;

		}
	}
	else
	{
		/*Handle the case of the mantissa equal to zero*/
		Push(&NumStack, '0');
	}
	/*Push dot*/
	Push(&NumStack, '.');
	/*Handle the exponent part*/
	num/=SCALING_FACTOR;
	if(num!=0)
	{

		/*Push digits of the mantissa into the stack*/
		while(num>0)
		{
			Push(&NumStack, num%10+'0');
			num/=10;

		}
	}
	else
	{
		/*Handle the case of the mantissa equal to zero*/
		Push(&NumStack, '0');
	}


	/*Traverse stack*/
	CLCD_voidGoToXY(y, x);
	TraverseStack(&NumStack, &PrintFixedPointAsFloat);


}


static void PrintFixedPointAsFloat(StackEntry e)
{
	CLCD_voidSendData(e);

}





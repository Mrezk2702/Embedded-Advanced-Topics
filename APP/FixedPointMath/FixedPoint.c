/*
 * FixedPoint.c
 *
 *  Created on: Jan 14, 2025
 *      Author: mrezk
 */


#include "FixedPoint.h"
#define SINT32_OVERFLOW  2147483647
#define SINT32_UNDERFLOW  -2147483648


#define SCALING_FACTOR 1000
static void PrintFixedPointAsFloat(StackEntry e);


inline FP32 convertToFixed(float32 Copy_F32Number)
{
	FP32 ConvertedFP=(FP32)(Copy_F32Number * (float32)SCALING_FACTOR);
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
	//Check Overflow
	if(!(FP_op1>(sint32)SINT32_OVERFLOW-FP_op2))
	{
		result=FP_op1+FP_op2;

	}
	else if(!(FP_op1<(sint32)SINT32_UNDERFLOW+FP_op2))
	{
		result=FP_op1+FP_op2;

	}

	return result;

}

FP32 FixedPointSubtraction(float32 op1,float32 op2)
{

	FP32 FP_op1=convertToFixed(op1);
	FP32 FP_op2=convertToFixed(op2);
	FP32 result;

	//Check Overflow
	if(!(FP_op1>(sint32)SINT32_OVERFLOW-FP_op2))
	{
		result=FP_op1-FP_op2;

	}
	else if(!(FP_op1<(sint32)SINT32_UNDERFLOW+FP_op2))
	{
		result=FP_op1-FP_op2;

	}
	return result;



}


FP32 FixedPointMultiplication(float32 op1,float32 op2)
{
	FP32 FP_op1=convertToFixed(op1);
	FP32 FP_op2=convertToFixed(op2);
	FP32 result;

	//Check Overflow
	if(!(FP_op1>(sint32)SINT32_OVERFLOW/FP_op2))
	{
		result=(FP32)(FP_op1*FP_op2)/SCALING_FACTOR;

	}
	else if(!(FP_op1<(sint32)SINT32_UNDERFLOW/FP_op2))
	{
		result=(FP32)(FP_op1*FP_op2)/SCALING_FACTOR;

	}
	return result;

}

FP32 FixedPointDivision(float32 op1,float32 op2)
{
	FP32 FP_op1=convertToFixed(op1);
	FP32 FP_op2=convertToFixed(op2);
	FP32 result;
	//Check division by zero
	if(FP_op2==0)
	{
		//check value of numerator
		result=FP_op1>=0?SINT32_OVERFLOW : SINT32_UNDERFLOW;
	}
	else
	{

		result=(((FP32)SCALING_FACTOR)*FP_op1)/FP_op2;
	}
	return result;

}



void FixedPointPrintNumber(FP32 num,uint8 x,uint8 y)
{
	CLCD_voidGoToXY(y, x);
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

	TraverseStack(&NumStack, &PrintFixedPointAsFloat);


}


static void PrintFixedPointAsFloat(StackEntry e)
{
	CLCD_voidSendData(e);

}





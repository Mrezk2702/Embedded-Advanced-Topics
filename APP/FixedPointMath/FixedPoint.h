/*
 * FixedPoint.h
 *
 *  Created on: Jan 16, 2025
 *      Author: mrezk
 */
#include "../../BSW/LIB/STD_TYPES.h"
#include "../../BSW/Services/Stack/Stack.h"
#include "../../BSW/HAL/CLCD/inc/CLCD_interface.h"
#ifndef APP_FIXED_POINT_MATH_FIXEDPOINT_H_
#define APP_FIXED_POINT_MATH_FIXEDPOINT_H_
typedef sint32 FP32;
FP32 convertToFixed(float32 Copy_F32Number);
float32 convertToFloat(FP32 Copy_FP32Number);
FP32 FixedPointAddition(float32 op1,float32 op2);
void FixedPointPrintNumber(FP32 num,uint8 x,uint8 y);
#endif /* APP_FIXED_POINT_MATH_FIXEDPOINT_H_ */

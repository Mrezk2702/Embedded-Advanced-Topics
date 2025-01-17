#include "../BSW/LIB/STD_TYPES.h"
#include "../BSW/LIB/BIT_MATH.h"
#include "FixedPointMath/FixedPoint.h"
#include "TrafficLights/inc/TrafficLightsControl_interface.h"

int main()
{
	TrafficLightInit();

	while(1)
	{
//		TrafficLightMainFunction();

		float32 x=10.5;
		float32 z=8;
		CLCD_voidGoToXY(0,0);
		FP32 y=FixedPointAddition(x, z);
		FixedPointPrintNumber(y,1,1);

	}



}



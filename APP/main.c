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

		float32 x=-100.0;
		float32 z=0.01;
		CLCD_voidGoToXY(0,0);
		sint32 y=FixedPointDivision(x, z);

//		CLCD_voidWriteNumber(y);
		FixedPointPrintNumber(y,0,0);

	}



}



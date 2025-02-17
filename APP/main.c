#include "../BSW/LIB/STD_TYPES.h"
#include "../BSW/LIB/BIT_MATH.h"
#include "FixedPointMath/FixedPoint.h"
#include "TrafficLights/inc/TrafficLightsControl_interface.h"
#include "EventBasedArch/EventBased.h"


#if defined(co_FIXEDPOINT)
int main()
{
	FixedPoint_voidInit();

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
#endif


#if defined(co_TRAFFIC)
int main()
{
	TrafficLightInit();

	while(1)
	{
		TrafficLightMainFunction();



	}



}
#endif

#if defined(co_EVENT_DRIVEN)
int main()
{
	EDA_voidInit();
//	DIO_SetPinVal(DIO_PORTC, DIO_Pin1,DIO_HIGH);
	while(1)
	{
		EDA_voidRunnable();

	}



}
#endif

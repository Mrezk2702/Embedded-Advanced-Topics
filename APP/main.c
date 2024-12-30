#include "../BSW/LIB/STD_TYPES.h"
#include "../BSW/LIB/BIT_MATH.h"
#include "TrafficLights/inc/TrafficLightsControl_interface.h"


int main()
{
	TrafficLightInit();

	while(1)
	{
		TrafficLightMainFunction();



	}



}



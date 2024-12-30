
#ifndef APP_TRAFFICLIGHTS_INC_TRAFFICLIGHTSCONTROL_INTERFACE_H_
#define APP_TRAFFICLIGHTS_INC_TRAFFICLIGHTSCONTROL_INTERFACE_H_
#include "../../../BSW/LIB/bit_math.h"
#include "../../../BSW/LIB/STD_TYPES.h"
#include "../../../BSW/MCAL/DIO/inc/DIO_interface.h"
#include "../../../BSW/MCAL/GIE/inc/GIE_interface.h"
#include "../../../BSW/MCAL/PORT/inc/PORT_interface.h"
#include "../../../BSW/HAL/CLCD/inc/CLCD_interface.h"
#include "../../../BSW/MCAL/TIMER1/inc/TIMER1_interface.h"
#include "../../../BSW/Services/Stack/Stack.h"









void TrafficLightInit(void);
void TrafficLightMainFunction(void);


#endif /* APP_TRAFFICLIGHTS_INC_TRAFFICLIGHTSCONTROL_INTERFACE_H_ */

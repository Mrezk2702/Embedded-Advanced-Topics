/*
 * EventBased.h
 *
 *  Created on: Feb 2, 2025
 *      Author: mrezk
 */
#include "../../BSW/LIB/STD_TYPES.h"
#include "../../BSW/Services/Queue/queue.h"
#include "../../BSW/MCAL/DIO/inc/DIO_interface.h"
#include "../../BSW/MCAL/TIMER1/inc/TIMER1_interface.h"
#include "../../BSW/MCAL/PORT/inc/PORT_interface.h"
#include "../../BSW/MCAL/GIE/inc/GIE_interface.h"
#include "../../BSW/HAL/CLCD/inc/CLCD_interface.h"
#include "../../BSW/MCAL/EXTI/EXTI_int.h"



#ifndef APP_EVENTBASEDARCH_EVENTBASED_H_
#define APP_EVENTBASEDARCH_EVENTBASED_H_

void EDA_voidInit(void);
void EDA_voidRunnable(void);

#endif /* APP_EVENTBASEDARCH_EVENTBASED_H_ */

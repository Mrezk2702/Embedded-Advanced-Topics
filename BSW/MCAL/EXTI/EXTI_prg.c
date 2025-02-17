/*
 * EXTI_prg.c
 *
 *  Created on: Feb 14, 2025
 *      Author: mrezk
 */
#include "EXTI_int.h"

static void(* INT0PFunc)(void)=NULL;
static void(* INT1PFunc)(void)=NULL;
static void(* INT2PFunc)(void)=NULL;




void EXTI_voidInit(EXTI_CONFIG copy_strEXTIConfig)
{

	EXTI_MCUCR->ISC0=copy_strEXTIConfig.ISC0;
	EXTI_MCUCR->ISC1=copy_strEXTIConfig.ISC1;

	/*INT2 sense control*/

#if INT2_SENSE_CONTROL== INT2_FALLING

	CLEAR_BIT(EXTI_MCUCSR,INT2_ISC_BIT);

#elif INT2_SENSE_CONTROL== INT2_RISING

	SET_BIT(EXTI_MCUCSR,INT2_ISC_BIT);


#else

#error "Wrong Sense control"

#endif


	/*INT 0 ENABLE/DISABLE*/
#if INT0_STATUS==ENABLE
	SET_BIT(EXTI_GICR,INT0_ENABLE_BIT);
#elif INT0_STATUS==DISABLE
	CLEAR_BIT(EXTI_GICR,INT0_ENABLE_BIT);
#else
#error "Wrong configuration for INT0_STATUS"
#endif

	/*INT 1 ENABLE/DISABLE*/
#if INT1_STATUS==ENABLE
	SET_BIT(EXTI_GICR,INT1_ENABLE_BIT);
#elif INT1_STATUS==DISABLE
	CLEAR_BIT(EXTI_GICR,INT1_ENABLE_BIT);
#else
#error "Wrong configuration for INT1_STATUS"
#endif

	/*INT 2 ENABLE/DISABLE*/
#if INT2_STATUS==ENABLE
	SET_BIT(EXTI_GICR,INT2_ENABLE_BIT);
#elif INT2_STATUS==DISABLE
	CLEAR_BIT(EXTI_GICR,INT2_ENABLE_BIT);
#else
#error "Wrong configuration for INT2_STATUS"
#endif

}


void EXTI_voidSetInt0CbkFnc(void(*pFunc)(void))
{

		INT0PFunc=pFunc;

}

void EXTI_voidSetInt1CbkFnc(void(*pFunc)(void))
{
	if(pFunc!=NULL)
	{
		INT1PFunc=pFunc;

	}
}

void EXTI_voidSetInt2CbkFnc(void(*pFunc)(void))
{
	if(pFunc!=NULL)
	{
		INT2PFunc=pFunc;

	}
}


/*INT0 ISR*/
void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	INT0PFunc();
}

/*INT1 ISR*/
void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	INT1PFunc();

}



/*INT2 ISR*/
void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
	INT2PFunc();
}




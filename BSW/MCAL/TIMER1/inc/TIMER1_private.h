/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER1                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_
/*******************************************************************/
static void (*TIMER1_pvCallBackFunc_CTC_A)(void)=NULL;
static void (*TIMER1_pvCallBackFunc_CTC_B)(void)=NULL;
static void (*TIMER1_pvCallBackFunc_OV)(void)=NULL;
static void (*TIMER1_pvCallBackFunc_CaptEvnt)(void)=NULL;


void __vector_6 (void) __attribute__((signal)); /*capture event*/
void __vector_7 (void) __attribute__((signal)); /*compare match A*/
void __vector_8 (void) __attribute__((signal)); /*compare match B*/
void __vector_9 (void) __attribute__((signal)); /*OVER FLOW*/

/**********************************************************************/
typedef struct
{
	uint8 WGM1X :2; /* Waveform Generation Mode */
	uint8 FOC1B :1; /*Force Output Compare for Channel B*/
	uint8 FOC1A :1; /*Force Output Compare for Channel A*/
	uint8 COM1BX:2; /*compare output mode for channel B*/
	uint8 COM1AX:2; /*compare output mode for channel A*/
}TCCR1A;

typedef struct
{
	uint8 CS1X   :3;  /*Clock Select bits*/
	uint8 WGM1XX :2;  /* Waveform Generation Mode */
	uint8        :1;  /*Reserved*/
	uint8 ICES1  :1;  /*Input Capture Edge Select*/
	uint8 ICNC1  :1;  /* Waveform Generation Mode */
}TCCR1B;


typedef struct
{
	uint8       :2;
	uint8 TOIE1 :1; /*Timer/Counter1, Overflow Interrupt Enable*/
	uint8 OCIE1B:1; /*Timer/Counter1, Output Compare B Match Interrupt Enable*/
	uint8 OCIE1A:1;/*Timer/Counter1, Output Compare A Match Interrupt Enable*/
	uint8 TICIE1:1;/*Timer/Counter1, Input Capture Interrupt Enable*/
	uint8       :2;
}Timer1_TIMSK;


typedef struct
{
	uint8       :2;
	uint8 TOV1  :1; /*Timer/Counter1, Overflow Flag*/
	uint8 OCF1B :1; /*Timer/Counter1, Output Compare B Match Flag*/
	uint8 OCF1A: 1; /*Timer/Counter1, Output Compare A Match Flag*/
	uint8 ICF1  :1; /*Timer/Counter1, Input Capture Flag*/
	uint8       :2;
}Timer1_TIFR;

enum clock
{
	No_clock_source= 0b000,
	no_prescalling =0b001,
	Divide_by_8  =0b010,
	Divide_by_64  =0b011,
	Divide_by_256  =0b100,
	Divide_by_1024  =0b101,
	Ext_clk_T1_pin_ON_Falling_edge =0b110,
	Ext_clk_T1_pin_ON_Rising_edge =0b111
};

enum waveform
{
	Normal=0b0000,
	PWM_PHASE_CORRECT_8BIT=0b0001,
	PWM_PHASE_CORRECT_9BIT=0b0010,
	PWM_PHASE_CORRECT_10BIT=0b0011,
	CTC=0b0100,
    FAST_PWM_8BIT=0b0101,
	FAST_PWM_9BIT=0b0110,
	FAST_PWM_10BIT=0b0111,
	PWM_PHASE_CORRECT_FREQ_CORRECT_ICR1=0b1000,
	PWM_PHASE_CORRECT_FREQ_CORRECT_OCR1A=0b1001,
	PWM_PHASE_CORRECT_ICR1=0b1010,
	PWM_PHASE_CORRECT_OCR1A=0b1011,
	CTC_ICR1=0b1100,
	/*RESERVED*/
	FAST_PWM_ICR1 =0b1110,
	FAST_PWM_OCR1A =0b1111

};

enum TIMER1_NN_PWM
{
	CTC_NORMAL_Disconnected=0b00,
	CTC_TOGGLE_OC1=0b01,
	CTC_CLEAR_OC1=0b10,
	CTC_SET_OC1=0b11
};

enum TIMER1_FST_PWM
{
	PWM_NORMAL_Disconnected=0b00,
	PWM_CLEAR_COMPARE_SET_TOP=0b10,
	PWM_set_COMPARE_clear_TOP=0b11,

};

enum TIMER1_PHSE_CORRECT
{
	PHASE_NORMAL_Disconnected=0b00,
	PHASE_CLEAR_UP_COMPARE_SET_DOWN_TOP=0b10,
	PHASE_SET_UP_COMPARE_CLEAR_DOWN_TOP=0b11,
};

enum abilit
{
	Disable,
	Enable
};

#define TIMER1_NON_PWM        1
#define TIMER1_FAST_PWM       2
#define TIMER1_PHASE_CORRECT  3
#endif /* TIMER1_PRIVATE_H_ */

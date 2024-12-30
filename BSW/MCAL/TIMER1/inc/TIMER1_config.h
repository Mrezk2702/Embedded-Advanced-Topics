/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER1                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/*
 *   No_clock_source
 *   no_prescalling
 *   Divide_by_8
 *   Divide_by_64
 *   Divide_by_256
 *   Divide_by_1024
 *   Ext_clk_T1_pin_ON_Falling_edge
 *   Ext_clk_T1_pin_ON_Rising_edge
 * */

#define CLCK_SELECT  Divide_by_256

/*check the data sheet*/
/*   Normal
 *   PWM_PHASE_CORRECT_8BIT
 *   PWM_PHASE_CORRECT_9BIT
 *   PWM_PHASE_CORRECT_10BIT
 *   CTC
 *   FAST_PWM_8BIT
 *   FAST_PWM_9BIT
 *   FAST_PWM_10BIT
 *   PWM_PHASE_CORRECT_FREQ_CORRECT_ICR1
 *   PWM_PHASE_CORRECT_FREQ_CORRECT_OCR1A
 *   PWM_PHASE_CORRECT_ICR1
 *   PWM_PHASE_CORRECT_OCR1A
 *   CTC_ICR1
 *   FAST_PWM_ICR1
 *   FAST_PWM_OCR1A
 * */
#define WAVE_GEN  CTC

/*CHANNEL_A
 * NO_SELECT
 * */

#define CHANNEL_A

/*CHANNEL_B
 * NO_SELECT
 * */

#define CHANNEL_B


/*
 * TIMER1_NON_PWM
 * TIMER1_FAST_PWM
 *TIMER1_PHASE_CORRECT
 * */
#define TIMER1A_MODE  TIMER1_NON_PWM

#define TIMER1B_MODE  TIMER1_NON_PWM


/*
 * CTC_NORMAL_Disconnected |PWM_NORMAL_Disconnected  |PHASE_NORMAL_Disconnected
 * CTC_TOGGLE_OC1          |PWM_CLEAR_COMPARE_SET_TOP|PHASE_CLEAR_UP_COMPARE_SET_DOWN_TOP
 * CTC_CLEAR_OC1           |PWM_set_COMPARE_clear_TOP|PHASE_SET_UP_COMPARE_CLEAR_DOWN_TOP
 * CTC_SET_OC1             |                         |
 * */


#define TIMER1A_OUT_MODE  CTC_NORMAL_Disconnected

#define TIMER1B_OUT_MODE  CTC_NORMAL_Disconnected


/** INTERRUPT OPTIONS :
1-TIMER1_COMPARE_MATCH_A_ISR_ENABLE
2-TIMER1_COMPARE_MATCH_B_ISR_ENABLE
2-TIMER1_OVERFLOW_ISR_ENABLE
3-TIMER1_INPUT_CAPTURE_INTERRUPT
4- Nothing
**/

#define TIMER1_COMPARE_MATCH_A_ISR_ENABLE


#endif /* TIMER1_CONFIG_H_ */

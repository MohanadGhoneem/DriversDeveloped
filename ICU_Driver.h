 /******************************************************************************
 *
 * Module: ICU
 *
 * File Name: ICU_Driver.h
 *
 * Description: Header file for the AVR ICU driver
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/

#ifndef ICU_DRIVER_H_
#define ICU_DRIVER_H_

#include "std_types.h"
#if 0
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
extern g_edgeCount;
extern g_timeHigh;
extern g_timePeriod;
extern g_timePeriodPlusHigh;
#endif
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_Clock;

typedef enum
{
	FALLING, RISING
}ICU_EdgeType;

typedef struct
{
	ICU_Clock clock;
	ICU_EdgeType edge;
}ICU_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType * Config_Ptr);

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType edgeType);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_deInit(void);

#if 0
/*
 * Description: Function to edge process the ICU Driver
 */
void APP_edgeProcessing(void);
#endif

#endif /* ICU_DRIVER_H_ */

 /******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: Ultrasonic_Driver.h
 *
 * Description: Header file for the Ultrasonic Sensor
 *
 * Author: Mohanad Adel
 *
 *******************************************************************************/


#ifndef ULTRASONIC_DRIVER_H_
#define ULTRASONIC_DRIVER_H_

#include "GPIO.h"
#include "ICU_Driver.h"
#include <avr/io.h>
#include <avr/delay.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define US_TRIGGER_PORT			 	PORTB_ID
#define US_TRIGGER_PIN				PIN5_ID
#define US_ECHO_PORT			 	PORTD_ID
#define US_ECHO_PIN					PIN6_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the Ultrasonic driver
 * 	1. Initialize the ICU Driver as required
 * 	2. Setup the ICU Callback Function
 * 	3. Setup the direction for the trigger pin as output pin through the GPIO driver
 */
void Ultrasonic_init(void);

/*
 * Description : Function to initialize the Ultrasonic driver
 * 	1. Send the Trigger pulse to the ultrasonic
 */
void Ultrasonic_Trigger(void);

/*
 * Description : Function to initialize the Ultrasonic driver
 * 	1. Send the trigger pulse by using Ultrasonic_Trigger function
 * 	2. Start the measurements by the ICU from this moment
 *  3. Return the measured distance in cm
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description : Function to initialize the Ultrasonic driver
 * 	1. This is the call back function called by the ICU driver
 * 	2. This is used to calculate the high time (pulse time) generated by the ultrasonic sensor
 */
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_DRIVER_H_ */


#include "tinpi.h"
#include <iostream>
#include <wiringPi.h>

/*
 
 This function named UdmMod_hcsr04
 it use hc-sr04 ultrasonic transmitter to check the distance
 The minimum value of this distance is 20mm,the maximum value of this distance is 4000mm,When the distance you measured is less than 2cm and greater than 4m, the return value is any value,so you need Ensure that the distance is greater than 2cm and less than 4m
 The error is 3mm
 wirte "UdmMod_hcsr04(void)" to transfer this function
 The return value of this function is the distance you measured (20 <= the retrun value <= 4000)
 make sure you transfered <wiringPi.h>
 The power supply is connected to the 5v pin, the output pin is connected to the physical pin 38 (GPIO28), and the input pin is connected to the physical pin 40 (GPIO29)
 */
int UdmMod_hcsr04(void){
	unsigned int echo_high_time = 0, echo_low_time = 0, dist = 0;//t1 is the time when the high level has just been received;t2 is the time when no high level is received;dist is the final distance
    const int PinCode_Trig=28;
    const int PinCode_Echo=29;
    
	wiringPiSetup();//initialization
	pinMode (PinCode_Trig,OUTPUT);
	pinMode (PinCode_Echo,INPUT);
	digitalWrite (PinCode_Trig,HIGH) ; //Set trig to high
	delayMicroseconds(15);//Delay of 15 microseconds, because hc-sr04 requires a delay of more than 10 microseconds
	digitalWrite (PinCode_Trig,LOW) ;//Set trig to low 
	
	while(!(digitalRead(PinCode_Echo)==1)){
		echo_high_time = micros();//When echo receives high level, get current time
	}
	while(!(digitalRead(PinCode_Echo)==0)){echo_low_time = micros();}//When echo cannot receive high level, get current time
	dist = (echo_low_time - echo_high_time)*340*1000/1000000/2;//Calculate distance
	digitalWrite (PinCode_Echo,LOW) ; //set echo to low
	return dist;
	
	
}

/*
 * This function named PriMod_hcsr501
 * it uses hcsr501 to detection of environmental infrared changes (object movement) by infrared
 * The detection angle of this module is a cone angle within 100 degrees. The maximum distance from the receiving point to the cone angle is 7m and the minimum is 3m. In addition, this equipment must be operated in an environment with a temperature higher than -15 degrees Celsius and less than 70 degrees Celsius
 * The return value is 1 or 0,if the return value is 1,it means It detects movement of an object,else it didn't detect any movement
 *  make sure you transfered <wiringPi.h>
 * The power supply is connected to the 5v pin, and the signal pin is connected to the physical pin 13 (GPIO2)
 */
 
int PriMod_hcsr501(){
const int PinCode_Trigger_Pir = 2;
	int pirvalue = 0;//This variable is used to store the read level, 1 is high level, 0 is low level
	wiringPiSetup();//initialization
	pinMode(PinCode_Trigger_Pir,INPUT);
		pirvalue = digitalRead(PinCode_Trigger_Pir);//read the level
		if(pirvalue == 1){//Determine whether it is high level
			return 1;
		}
		else{
			return 0;
			}
		digitalWrite (PinCode_Trigger_Pir,LOW);//set it to low
	}
	
/*
 * this function named BuzzMod_Passivebuzzer
 * it uses passive buzzer to make sounds
 * it hasn't any return value,when you use this function,it just to buss
 * make sure you transfered <wiringPi.h>
 * The power supply is connected to the 3.3v pin, and the signal pin is connected to the physical pin 12 (GPIO1)
 */
 
void BuzzMod_Passivebuzzer(int freq,int t_ms){
	wiringPiSetup();//initialization
	pinMode (1,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);//Set to ms mode (also has balance mode)
	pwmSetClock(32);//Set the clock base frequency to 19.2MHZ/32=600khz
	int range;
	range = 600000 / freq;//Set the range to 600KHZ/freq. That is, the freq frequency period is composed of range 1/600KHZ.
	pwmSetRange(range);//set the final frequency
	pwmWrite(1,range * 0.5);//Set the duty cycle to 50%, which means that the high level time occupies 50% of a cycle and can be changed. The larger the duty cycle, the louder the sound
	if(t_ms > 0){
		delay(t_ms);
	}
	pwmWrite(1,0);//end the buzzing
}

/*
 * This function SwMod_Powerswitch
 * it uses power switch to detect on and off to control the operation of other modules
 * it has two return value,1 means the power switch is on,and 0 means the power switch is off
 * make sure you transfered <wiringPi.h>
 * the signal pin connect physical pin 13 (GPIO 2),the Power connection 3.3v pin
 * important! Please pay attention to the description of the switch module you are using. In this function, you use the switch module that will receive a low level (0) when you press the switch button
 */
int SwMod_Powerswitch(){
	wiringPiSetup();//initialization
	pinMode (2,INPUT);
	bool flag = false;
	while(1){
	if(digitalRead(2) == 0){//Determine whether the low level is received (whether the switch button is pressed)
		if(flag == false){//If the switch state was off last time, then the switch state is changed to on this time, and return 1
			flag = true;
			return 1;
			}
			if(flag == true){//If the last switch state is on, then the state is off this time, return 0
				flag = false;
				return 0;
			}
		}
	}
}

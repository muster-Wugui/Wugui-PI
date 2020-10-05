#include "tinpi.h"
#include <iostream>
#include <wiringPi.h>
/*
 This function named UdmMod_hcsr04
 it use hc-sr04 ultrasonic transmitter to measuring the distance
 The minimum value of this distance is 20mm,the maximum value of this distance is 4000mm,When the distance you measured is less than 2cm or greater than 4m, it will return any value,so you need Ensure that the distance is greater than 2cm and less than 4m
 The error is 3mm
 wirte "UdmMod_hcsr04()" to transfer this function
 The return value of this function is the distance you measured (20 <= the retrun value <= 4000)
 make sure you transfered <wiringPi.h>
*/
int UdmMod_hcsr04(void){
	unsigned int echo_high_time = 0, echo_low_time = 0, dist = 0;//echo_high_time is the time when echo gets High level,echo_low_time is the time when echo gets low lecel,dist is the final distance
    const int PinCode_Trig=28;//the Physical pin is 38,the GPIO pin in wiringPi is 28
    const int PinCode_Echo=29;//the physical pin is 39,the GPIO pin in wiringPi is 29
    
	wiringPiSetup();//initialization
	pinMode (PinCode_Trig,OUTPUT);//Set pin
	pinMode (PinCode_Echo,INPUT);//Set pin
	digitalWrite (PinCode_Trig,HIGH) ; //set trig to high
	delayMicroseconds(15);//delay 15 microseconds because hc-sr04 need 10 microseconds to complete its Ultrasonic emission
	digitalWrite (PinCode_Trig,LOW) ;//set trig to low
	
	while(!(digitalRead(PinCode_Echo)==1)){
		echo_high_time = micros();//Capture time when echo receives high level
	}
	while(!(digitalRead(PinCode_Echo)==0)){echo_low_time = micros();}//Capture time when echo receives low level
	dist = (echo_low_time-echo_high_time)*340*1000/1000000/2;//Calculate distance
	digitalWrite (PinCode_Echo,LOW) ; //set echo to low
	return dist;
}


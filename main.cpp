#include "tinpi.h"
#include <iostream>
#include <wiringPi.h>
using namespace std;

/* 
 //the BuzzMod_Passivebuzzer
typedef struct _sound{
  int freq;
  int t_ms;
} sound;
 
#define TIME 200
#define DO 2093
#define RE  2349
#define MI 2637
#define FA 2794
#define SO 3136
#define LA 3520
#define XI 3951
#define DO1 4186
#define RI1 4698

sound tone[]=
{
{DO,TIME},
{DO,TIME},
{SO,TIME},
{SO,TIME},
{LA,TIME},
{LA,TIME},
{SO,TIME*2},
 
{FA,TIME},
{FA,TIME},
{MI,TIME},
{MI,TIME},
{RE,TIME},
{RE,TIME},
{DO,TIME*2},
 
{SO,TIME},
{SO,TIME},
{FA,TIME},
{FA,TIME},
{MI,TIME},
{MI,TIME},
{RE,TIME*2},
 
{SO,TIME},
{SO,TIME},
{FA,TIME},
{FA,TIME},
{MI,TIME},
{MI,TIME},
{RE,TIME*2},
 
{DO,TIME},
{DO,TIME},
{SO,TIME},
{SO,TIME},
{LA,TIME},
{LA,TIME},
{SO,TIME*2},
 
 
{FA,TIME},
{FA,TIME},
{MI,TIME},
{MI,TIME},
{RE,TIME},
{RE,TIME},
{DO,TIME*2},
 
 
};

sound kqs[] =
{
	{LA,TIME * 2},
	{XI,TIME},
	{DO,TIME * 2},
	{LA,TIME},
	{DO,TIME * 2},
	{XI,TIME},
	{LA,TIME},
	{XI,TIME * 2},
	{MI,TIME},
	{XI,TIME * 2},
	{DO,TIME},
	{RE,TIME * 2},
	{XI,TIME},
	{RE,TIME},
	{DO,TIME},
	{RE,TIME},
	{DO,TIME},
	{XI,TIME},
	{LA,TIME*2},
	{MI,TIME*2},
	{LA,TIME * 2},
	{SO,TIME * 2},
	{LA,TIME},
	{SO,TIME},
	{FA,TIME*2},
	{MI,TIME},
	{RE,TIME},
	{MI,TIME * 2},
	{LA,TIME},
	{FA,TIME*2},
	{RE,TIME},
	{MI,TIME*2},
	{DO,TIME},
	{XI,TIME*2},
	{MI,TIME*2},
	{DO,TIME},
	{XI,TIME},
	{LA,TIME},
};
*/
int main(){
    /*
     //the UdmMod_hcsr04,to measure the ditance
     while(1){
		int dist = UdmMod_hcsr04();
		printf("%d\n",dist);
	}
	*/
	 /*
	  //the PriMod_hcsr501,to detect object movement
		while(1){
		 int num = PriMod_hcsr501();
		printf("%d\n",num);
		delay(1000);
	}
	*/
	/*
	 //the BuzzMod_Passivebuzzer,to make sounds
	int length = sizeof(tone) / sizeof(sound);
	for (int i= 0;i < length;i++){
		BuzzMod_Passivebuzzer(tone[i].freq,tone[i].t_ms);
		delay(100);
  }

	pwmWrite(1,0);
	*/
	/* 
	//the power switch 
	while(1){
		if(SwMod_Powerswitch() == 1){
			int length = sizeof(tone) / sizeof(sound);
			for (int i= 0;i < length;i++){
				BuzzMod_Passivebuzzer(tone[i].freq,tone[i].t_ms);
				if(SwMod_Powerswitch() == 0){
					delay(1000);
					break;
				}
				delay(100);
				}
			}
		}
		*/ 
	return 0;
}


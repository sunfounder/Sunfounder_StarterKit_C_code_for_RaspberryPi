#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define   SIG   0

void servoInit(void)
{
	pinMode(SIG, OUTPUT);
	digitalWrite(SIG, 0);
}

void servoCtrl(int dutyCycle)
{
	digitalWrite(SIG, 1);
	delayMicroseconds(dutyCycle);
	digitalWrite(SIG, 0);
	delayMicroseconds(20000 - dutyCycle);
}

int main(void)
{
	int i;

	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	servoInit();

	while(1){
/*		for(i=500;i<=2500;i+=5){
			servoCtrl(i);
			delay(150);
		}

		delay(1000);
*/		
	/*	for(i=2500;i>=500;i--){
			servoCtrl(i);
			delay(100);
		}
		delay(1000);*/
		
/*		servoCtrl(500);
		sleep(1);
		servoCtrl(1000);
		sleep(1);
*/		servoCtrl(1500);
		sleep(1);
		servoCtrl(2000);
		sleep(1);
		servoCtrl(2500);
		sleep(1);
	}

	return 0;
}


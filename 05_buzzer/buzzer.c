#include <wiringPi.h>
#include <stdio.h>

#define    BEEP    0

int main(void)
{
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}

	pinMode(BEEP,  OUTPUT);
	
	while(1){
		digitalWrite(BEEP, !digitalRead(BEEP));	
		delay(1000);
	}

	return 0;
}

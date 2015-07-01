#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>

#define   LedPin     0
#define  TiltPin     1

int main(void)
{
	if(wiringPiSetup() < 0){
		fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
		return 1;
	}

	pinMode(TiltPin, INPUT);
	pinMode(LedPin, OUTPUT);
	pullUpDnControl(TiltPin, PUD_UP);

	while(1){
		if(0 == digitalRead(TiltPin)){
			digitalWrite(LedPin, LOW);	
		}	
		else{
			digitalWrite(LedPin, HIGH);	
		}
	}

	return 0;
}

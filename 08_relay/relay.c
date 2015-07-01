#include <wiringPi.h>
#include <stdio.h>

#define RelayPin 0

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(RelayPin, OUTPUT);

	while(1){
		digitalWrite(RelayPin, LOW);  //relay off
		delay(500);                   //delay
		digitalWrite(RelayPin, HIGH); //relay on
		delay(500);                   //delay
	}

	return 0;
}


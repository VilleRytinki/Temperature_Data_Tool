/* Author: Ville Rytinki
 * File: TempSensor.c
 * Description: This file represents a temperature sensor that measures temperature between -100.00 to 100.00.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "TempSensor.h"
#include "TimeStamp.h"


/*This function generates a temperature reading between -100.00 to 100.00*/
float measureTemp() {
	srand(time(NULL));
	
	float randomNumber = 0.0;
	
	randomNumber = (rand() % 1000 + (-1000)) / 10.0;
	
	return randomNumber;

}


/*This function creates a data struct for the temperature sensor. Returns TempSensor struct.*/
struct TempSensor createDataPoint() {
	struct TempSensor TempSensor;
	
	float temp = 0.0;
	char *timeStamp = NULL;
	
	
	timeStamp = malloc(TIMESTAMP_SIZE * sizeof(char));
	
	if (timeStamp != NULL) {
		temp = measureTemp();
		
		timeStamp = getTimeStamp(timeStamp, TIMESTAMP_SIZE);
		
		TempSensor.temp = temp;
		for (int index = 0; index < TIMESTAMP_SIZE; index++) {
			TempSensor.timeStamp[index] = timeStamp[index];
		}

	
		free(timeStamp);
	} else {
		printf("Memory for the times stamp was not allocated succesfully.\n");
	}
	
	return TempSensor;
}



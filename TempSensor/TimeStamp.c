/* Author: Ville Rytinki
 * File: TimeStamp.c
 * Description: This file contains the function to create a timestamp.
*/


#include <time.h>
#include <stdio.h>


/*This function takes an array pointer and fills the array with a timestamp
 *in format of DD/MM/YYYY HH:MM:SS then a pointer to the start of the array is returned.*/
char *getTimeStamp(char *timeArray, int size) {
	
	//get the raw UNIX time.
	time_t rawtime = time(NULL);
	char dateBuffer[30] = "";
	
	if (rawtime == -1) {
		printf("Could not retrieve time.\n");
	} else {
	
		//convert raw UNIX time to a localtime format.
		struct tm *timePtr = localtime(&rawtime);
		
		if (timePtr == NULL) {
			printf("Error retrieving localtime.\n");
		} else {
			//formats date and time to a standard represantation format.
			strftime(dateBuffer, size, "%d/%m/%Y %H:%M:%S", timePtr);
			
			for (int index = 0; index < size; index++) {
				timeArray[index] = dateBuffer[index];
			}
			
		
			return timeArray;
		}
	
	}

	
	return timeArray;
}

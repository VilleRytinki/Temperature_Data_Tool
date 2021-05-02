/* Author: Ville Rytinki
 * File: TempSensorMain.c
 * Description: This source code file is the main interface of a program that takes
 	10 imaginary temperature measurements every 10 seconds and then saves the datapoints
 	to a .txt file if the user permits.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


#include "TempSensor.h"
#include "TimeStamp.h"
#include "FileTool.h"
#include "InputTools.h"


#define FILENAME_SIZE 25

int main () {

	char *filePtr = NULL;
	char myFile[FILENAME_SIZE] = "temperature_readings.txt"; 
	filePtr = myFile;
	int DATAPOINTS_MAX_SIZE = 0;

	
	/*Main loop of the interface. 3 options that includes taking new measurements or printing out the contents of
	 *the txt file or end the program.*/
	while (1) {
		printf("This program takes 10 temperature measurements every 10 seconds.\n");
		printf("Do you wish to (t) Take new measurements, (p) Print out the previous results, (q) to quit.");
		
		char input;
		char c;
		
		//validate user input by reading a single character at a time and cast them to uppercase.
		while ((c = getchar()) != '\n') {
			input = toupper(c);
		}
		
		
		if (input == 'Q') {
			break;
		}
		
		//Switch case for taking measurements and saving results to a file.
		switch (input) {
			case 'T': {
				struct TempSensor *tempSensorPtr = NULL;
				
				//int inputStatus = 0;//assume that user input is false
				
				while(1) {
					char inputBuffer[3] = "";
					char *inputPtr = NULL;
					inputPtr = inputBuffer;
					int numberOfChars = 0;
					
				
					printf("Please give the amount of datapoints you wish to take:");
					while ((c = getchar()) != '\n' && numberOfChars < 3) {
						*inputPtr++ = c;
						numberOfChars++;
					}
					
					
					int inputStatus = 0;
					inputStatus = isNumbers(inputBuffer, 3);

					if (inputStatus) {
						DATAPOINTS_MAX_SIZE = atoi(inputBuffer);
						break;
					} else {
						printf("Please input a number (Press -Enter- to continue).\n");
						clearInputBuffer();
					}
				}
	
				tempSensorPtr = malloc(DATAPOINTS_MAX_SIZE * sizeof(struct TempSensor));
	
				if (tempSensorPtr != NULL) {
					printf("\n");
					printf("Lets take %d temperature measurements every ten seconds.\n", DATAPOINTS_MAX_SIZE);
		
		
					//For loop to create datapoints ie."Read the temperature"
					for (int dataIndex = 0; dataIndex < DATAPOINTS_MAX_SIZE; dataIndex++) {
						struct TempSensor TempSensor = createDataPoint();
						
						//add the datapoint to dynamic memory array.
						tempSensorPtr[dataIndex] = TempSensor;
			
						printf("Measured a reading of %.2f at %s\n", TempSensor.temp, TempSensor.timeStamp);
						
						//if temperature reading continues, sleep 10 seconds.
						if (dataIndex != (DATAPOINTS_MAX_SIZE - 1)) {
							sleep(10);
						}
					}
					
					//print out the datapoints.
					for (int dataIndex = 0; dataIndex < DATAPOINTS_MAX_SIZE; dataIndex++) {
						printf("Temperature datapoint: %s %.2f\n", tempSensorPtr[dataIndex].timeStamp, tempSensorPtr[dataIndex].temp);
		
					}
		
					printf("\n");
		
					int loopStatus = 1;
					
					//While loop to validate user input and saving the results to .txt
					while (loopStatus) {
						printf("Do you wish to save these results to a textfile?(Y/N)");
						
						//validate user input by reading a single character at a time and cast them to uppercase.
						while((c = getchar()) != '\n') {
							input = toupper(c);
						}
		
		
						//y if user wants to save the results, n to return to main interface level.
						switch (input) {
							case 'Y':
								loopStatus = 0;
								
								//for loop to write the datapoints to .txt file
								for (int dataIndex = 0; dataIndex < DATAPOINTS_MAX_SIZE; dataIndex++) {
								writeFile(filePtr, tempSensorPtr[dataIndex].timeStamp, tempSensorPtr[dataIndex].temp);
								}
								break;
							case 'N':
								loopStatus = 0;
								printf("Results were not saved.\n");
								break;
							default:
								printf("please give correct input.\n");
								break;
						}
					}
		
		
		
					free(tempSensorPtr);
			
				} else {
					printf("Memory allocation for the datapoints was not succesfull.\n");
					return 1;
				}
				
				break;
			}
			case 'P': {
				printf("Contents of %s.\n", myFile);
				readFile(filePtr);
				break;
			}
			default: {
				printf("Please give correct input.\n");
				break;
			}		
		}
	
	
	}
	
	return 0;
}

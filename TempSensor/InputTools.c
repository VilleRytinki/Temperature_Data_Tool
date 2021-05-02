/* File: InputTools.c
 * Author: Ville Rytinki
 * Description: Contains the implementations of function prototypes in InputTools.h 
 * for reading and validating user input.
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "InputTools.h"


/*Reads user input using the fgets() method. Adds a null character to the end of the array.*/
void readInput(char text[], int maxSize) {
	
	fgets(text, maxSize, stdin);
	
	//if the last character of the input is not a newline, input buffer needs to be flushed.
	if(text[maxSize -1 != '\n']) {
		clearInputBuffer();
	}
}


/*Clears the input buffer of excess input characters. Continues when a newline is found.*/
void clearInputBuffer() {
	int c;
	
	while ((c = getchar()) != '\n' && c != EOF) {};

}


/*This function tests an array of chars for numbers. Returns 1 if all characters are letters. Else returns 0.*/
int isLetters(char text[], int maxSize) {
	int status = 1;
	
	for(int charIndex = 0; charIndex < maxSize; charIndex++) {
		if (isdigit(text[charIndex])) {
			status = 0;
			break;
		}
	}
	
	return status;

}


/*This function test an array of chars for letters. Returns 1 if all characters are numbers. Else returns 0.*/
int isNumbers(char text[], int maxSize) {
	int isNumber = 0;
	
	for(int charIndex = 0; charIndex < maxSize; charIndex++) {
		switch (text[charIndex]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				isNumber = 1;
				break;
			default:
				isNumber = 0;
				break;
			case '\0':
				isNumber = 1;
				break;
			case '\n':
				isNumber = 1;
				break;
		}
		
		if(!isNumber) {
			break;
		}
	}
	
	return isNumber;

}


/* Author: Ville Rytinki
 * File: FileTool.c
 * Description: This file contains the interface methods for the txt file.
*/


#include <stdio.h>


/*This function writes timeStamp and temperature to a txt file defined by file pointer.*/
void writeFile (char *file, char *timeStamp, float temp) {
	FILE *filePtr = NULL;
	
	
	filePtr = fopen(file, "a");
	
	fprintf(filePtr, "%s %.2f\n", timeStamp, temp);
	
	fclose(filePtr);


}


/*This function prints out the contents of a txt file defined with the file pointer.*/
void readFile(char *file) {
	char readBuffer[80] = "";
	
	FILE *filePtr = NULL;
		
	if ((filePtr = fopen(file, "r"))) {
	
		while(fgets(readBuffer, sizeof(readBuffer), filePtr)) {
		printf("%s", readBuffer);
		
		}
				
		fclose(filePtr);
		
	} else {
		printf("There is no file to be read.\n");
	}
}

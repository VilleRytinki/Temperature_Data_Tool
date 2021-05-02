/* File: InputTools.h
 * Author: Ville Rytinki
 * Description: Contains the function prototypes of InputTools.c
*/


#ifndef INPUTTOOLS_H
#define INPUTTOOLS_H


void clearInputBuffer();
void readInput(char text[], int maxSize);
int isLetters(char text[], int maxSize);
int isNumbers(char text[], int maxSize);


#endif

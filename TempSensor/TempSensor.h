/* Author: Ville Rytinki
 * File: TempSensor.h
 * Description: This file contains the prototypes of functions in TempSensor.c
 * and introduction of data struct TempSensor.
*/

#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#define TIMESTAMP_SIZE 20

struct TempSensor {
	float temp; 
	char timeStamp [TIMESTAMP_SIZE];
};

struct TempSensor createDataPoint();
float measureTemp();

#endif

CC = gcc
CFLAGS = -Wextra -Wall -std=c11

default:TempSensorMain

TempSensorMain: TempSensorMain.o TempSensor.o TimeStamp.o FileTool.o
	$(CC) $(CFLAGS) -o TempSensorMain TempSensorMain.o TempSensor.o TimeStamp.o FileTool.o
	
TempSensorMain.o: TempSensorMain.c TempSensor.h TimeStamp.h FileTool.h
	$(CC) $(CFLAGS) -c TempSensorMain.c

TempSensor.o: TempSensor.c TempSensor.h TimeStamp.h
	$(CC) $(CFLAGS) -c TempSensor.c

TimeStamp.o: TimeStamp.c TimeStamp.h
	$(CC) $(CFLAGS) -c TimeStamp.c
	
FileTool.o: FileTool.c FileTool.h
	$(CC) $(CFLAGS) -c FileTool.c
    
clean:
	$(RM) TempSensorMain *.o *.~

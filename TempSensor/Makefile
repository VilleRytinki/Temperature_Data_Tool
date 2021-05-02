CC = gcc
CFLAGS = -Wextra -Wall -std=c11

default:TempSensorMain

TempSensorMain: TempSensorMain.o TempSensor.o TimeStamp.o FileTool.o InputTools.o
	$(CC) $(CFLAGS) -o TempSensorMain TempSensorMain.o TempSensor.o TimeStamp.o FileTool.o InputTools.o
	
TempSensorMain.o: TempSensorMain.c TempSensor.h TimeStamp.h FileTool.h InputTools.h
	$(CC) $(CFLAGS) -c TempSensorMain.c

TempSensor.o: TempSensor.c TempSensor.h TimeStamp.h
	$(CC) $(CFLAGS) -c TempSensor.c

TimeStamp.o: TimeStamp.c TimeStamp.h
	$(CC) $(CFLAGS) -c TimeStamp.c
	
FileTool.o: FileTool.c FileTool.h
	$(CC) $(CFLAGS) -c FileTool.c
	
InputTools.o: InputTools.c InputTools.h
	$(CC) $(CFLAGS) -c InputTools.c
    
clean:
	$(RM) TempSensorMain *.o *.~

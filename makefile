#My own makefile for fibonacci project

#Declare variables
CC=g++
LIBS=-lm

#First create ".exe" called fibonacci
StudentDatabase: StudentDatabase.o StudentDatabaseDriver.o
	$(CC) StudentDatabase.o StudentDatabaseDriver.o -o StudentDatabase $(LIBS)

#Need to make Fib.o file though
StudentDatabase.o: StudentDatabase.cpp StudentDatabase.h
	$(CC) -c StudentDatabase.cpp

#And the driver file
StudentDatabaseDriver.o: StudentDatabaseDriver.cpp
	$(CC) -c StudentDatabaseDriver.cpp

#Other rules

#Clean .o and exe
clean:
	@rm -f *.o
	@rm -f StudentDatabase

#To run program
run:
	./StudentDatabase




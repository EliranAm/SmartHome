FLAGS = -g -Werror -Wall -ansi -pedantic



libThread.a: Thread.o TempContrellerThread.o SmokeControllerThread.o RouterThread.o
	ar rcs libThread.a Thread.o TempContrellerThread.o SmokeControllerThread.o RouterThread.o


TempContrellerThread.o: TempContrellerThread.cpp TempContrellerThread.h
	g++ -c $(FLAGS) TempContrellerThread.cpp


SmokeControllerThread.o: SmokeControllerThread.cpp SmokeControllerThread.h
	g++ -c $(FLAGS) SmokeControllerThread.cpp

RouterThread.o: RouterThread.cpp RouterThread.h
	g++ -c $(FLAGS) RouterThread.cpp 	
	
Thread.o: Thread.cpp Thread.h
	g++ -c $(FLAGS) Thread.cpp



clean:
	rm -f libThread.a TempContrellerThread.o SmokeControllerThread.o RouterThread.o Thread.o *~

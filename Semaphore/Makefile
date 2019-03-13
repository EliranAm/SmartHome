FLAGS = -g -Werror -Wall -ansi -pedantic



libSemaphore.a: Semaphore.o
	ar rcs libSemaphore.a Semaphore.o


Semaphore.o: Semaphore.cpp Semaphore.h ISemaphore.h
	g++ -c $(FLAGS) Semaphore.cpp

	
clean:
	rm -f libSemaphore.a Semaphore.o *~

	

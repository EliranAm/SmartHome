FLAGS = -g -Werror -Wall -ansi -pedantic



TestMutex: MutexTest.cpp libMutex.a
	g++ $(FLAGS) -o TestMutex MutexTest.cpp libMutex.a -pthread


libMutex.a: Mutex.o Locker.o
	ar rcs libMutex.a Mutex.o Locker.o


Mutex.o: Mutex.cpp Mutex.h IMutex.h
	g++ -c $(FLAGS) Mutex.cpp

Locker.o: Locker.cpp Locker.h
	g++ -c $(FLAGS) Locker.cpp
	
	
clean:
	rm -f Mutex.o libMutex.a TestMutex Locker.o *~

	

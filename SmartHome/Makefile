FLAGS = -g -Werror -Wall -ansi -pedantic -pthread

LIBRARIES = libSmartHome.a ../Device/libDevices.a ../Parser/libParser.a ../Sensor/libSensors.a ../PubSub/libPubSub.a ../Semaphore/libSemaphore.a ../SensorController/libControllers.a ../Thread/libThread.a ../Mutex/libMutex.a



SmartHomeApp: main.o $(LIBRARIES)
	g++ $(FLAGS) -o SmartHomeApp main.o $(LIBRARIES)

main.o: main.cpp
	g++ -c $(FLAGS) main.cpp



libSmartHome.a: SmartHome.o Test_t.o MakeDevices MakeSensors MakeThreads MakeMutex MakeSensorControllers MakePubSub MakeParser MakeSemaphore
	ar rcs libSmartHome.a SmartHome.o Test_t.o

SmartHome.o: SmartHome.cpp SmartHome.h
	g++ -c $(FLAGS) SmartHome.cpp

Test_t.o: Test_t.cpp Test_t.h
	g++ -c $(FLAGS) Test_t.cpp


MakeParser: 
	cd ../Parser && $(MAKE) libParser.a

MakePubSub: 
	cd ../PubSub && $(MAKE)

MakeDevices: 
	cd ../Device && $(MAKE)

MakeSensorControllers: 
	cd ../SensorController && $(MAKE)

MakeSensors: 
	cd ../Sensor && $(MAKE)

MakeThreads: 
	cd ../Thread && $(MAKE)
	
MakeMutex: 
	cd ../Mutex && $(MAKE)

MakeSemaphore: 
	cd ../Semaphore && $(MAKE)


clean:
	rm -f SmartHome.o Test_t.o libSmartHome.a main.o SmartHomeApp *~
	cd ../Thread && $(MAKE) clean
	cd ../SensorController && $(MAKE) clean	
	cd ../Device && $(MAKE)	clean
	cd ../Sensor && $(MAKE) clean
	cd ../PubSub && $(MAKE)	clean
	cd ../Parser && $(MAKE) clean
	cd ../Mutex && $(MAKE)  clean
	cd ../Semaphore && $(MAKE) clean
	

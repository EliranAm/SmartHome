FLAGS = -g -Werror -Wall -ansi -pedantic


libControllers.a: TempSensorController.o SmokSensorController.o SensorControllerFactory.o
	ar rcs libControllers.a TempSensorController.o SmokSensorController.o SensorControllerFactory.o


SensorControllerFactory.o: SensorControllerFactory.cpp SensorControllerFactory.h
	g++ -c $(FLAGS) SensorControllerFactory.cpp


TempSensorController.o: TempSensorController.cpp TempSensorController.h ISensorController.h
	g++ -c $(FLAGS) TempSensorController.cpp


SmokSensorController.o: SmokSensorController.cpp SmokSensorController.h ISensorController.h
	g++ -c $(FLAGS) SmokSensorController.cpp


clean:
	rm -f libControllers.a TempSensorController.o SmokSensorController.o SensorControllerFactory.o *~

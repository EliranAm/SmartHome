FLAGS = -g -Werror -Wall -ansi -pedantic
OBJECTS = SmokeSensor.o TempSensor.o SmokeSensorLogic.o TempSensorLogic.o SensorLogicFactory.o SensorFactory.o Sensor.o


libSensors.a: $(OBJECTS)
	ar rcs libSensors.a $(OBJECTS)



TempSensorLogic.o: TempSensorLogic.cpp TempSensorLogic.h ISensorLogic.h Sensor.h
	g++ -c $(FLAGS) TempSensorLogic.cpp


SmokeSensorLogic.o: SmokeSensorLogic.cpp SmokeSensorLogic.h ISensorLogic.h Sensor.h
	g++ -c $(FLAGS) SmokeSensorLogic.cpp 


TempSensor.o: TempSensor.cpp TempSensor.h Sensor.h
	g++ -c $(FLAGS) TempSensor.cpp
	

SmokeSensor.o: SmokeSensor.cpp SmokeSensor.h Sensor.h
	g++ -c $(FLAGS) SmokeSensor.cpp


SensorLogicFactory.o: SensorLogicFactory.cpp SensorLogicFactory.h
	g++ -c $(FLAGS) SensorLogicFactory.cpp


SensorFactory.o: SensorFactory.cpp SensorFactory.h
	g++ -c $(FLAGS) SensorFactory.cpp


Sensor.o: Sensor.cpp Sensor.h
	g++ -c $(FLAGS) Sensor.cpp


clean:
	rm -f libSensors.a $(OBJECTS) *~
	
	

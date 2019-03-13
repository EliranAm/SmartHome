FLAGS = -g -Werror -Wall -ansi -pedantic

OBJECTS = AirCondDeviceLogic.o FireSysDeviceLogic.o AirCondDevice.o FireSysDevice.o DeviceLogicFactory.o DeviceFactory.o Device.o


libDevices.a: $(OBJECTS)
	ar rcs libDevices.a $(OBJECTS)


FireSysDeviceLogic.o: FireSysDeviceLogic.cpp FireSysDeviceLogic.h FireSysDevice.h IDeviceLogic.h Device.h
	g++ -c $(FLAGS) FireSysDeviceLogic.cpp

AirCondDeviceLogic.o: AirCondDeviceLogic.cpp AirCondDeviceLogic.h AirCondDevice.h IDeviceLogic.h Device.h
	g++ -c $(FLAGS) AirCondDeviceLogic.cpp


AirCondDevice.o: AirCondDevice.cpp AirCondDevice.h
	g++ -c $(FLAGS) AirCondDevice.cpp
	
FireSysDevice.o: FireSysDevice.cpp FireSysDevice.h
	g++ -c $(FLAGS) FireSysDevice.cpp


DeviceLogicFactory.o: DeviceLogicFactory.cpp DeviceLogicFactory.h
	g++ -c $(FLAGS) DeviceLogicFactory.cpp


DeviceFactory.o: DeviceFactory.cpp DeviceFactory.h
	g++ -c $(FLAGS) DeviceFactory.cpp

Device.o: Device.cpp Device.h
	g++ -c $(FLAGS) Device.cpp


	
clean:
	rm -f libDevices.a $(OBJECTS) *~

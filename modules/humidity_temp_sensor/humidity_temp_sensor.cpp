//=====[Libraries]=============================================================

#include "mbed.h"

#include "humidity_temp_sensor.h"

#include "greenhouse_system.h"

#include "Dht11.h"

//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

Dht11 dth11_sensor(D7);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================

void humidityTempSensorInit()
{
	int humidity = 0;    
	int temperature = 0;
}

void humidityTempSensorUpdate()
{
	temperatureDHTSensorRead();
	humidityDHTSensorRead();
	
}

int temperatureDHTSensorRead()
{
    dth11_sensor.read();
    return dth11_sensor.getCelsius();
}

int humidityDHTSensorRead()
{
    dth11_sensor.read();
    return dth11_sensor.getHumidity();
}

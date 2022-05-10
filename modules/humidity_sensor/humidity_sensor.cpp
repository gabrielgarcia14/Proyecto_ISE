//=====[Libraries]=============================================================

#include "mbed.h"

#include "humidity_sensor.h"

#include "greenhouse_system.h"

//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn humidityYL66(A2);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================

void humiditySensorInit()
{
float humidity = 0.0;    
}

void humiditySensorUpdate()
{
	humiditySensorRead();
}

float humiditySensorRead()
{
    return humidityYL66.read();
}


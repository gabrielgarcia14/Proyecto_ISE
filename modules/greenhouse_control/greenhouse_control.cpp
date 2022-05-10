//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "greenhouse_control.h"

#include "temperature_sensor.h"
#include "humidity_sensor.h"
#include "humidity_temp_sensor.h"


//=====[Declaration and initialization of public global objects]===============
DigitalInOut pump(D4);
DigitalInOut fan(D8);
DigitalOut lightBulb(D9);


//=====[Implementations of public functions]===================================

void greenhouseControlInit()
{   
    fan.mode(OpenDrain);
    fan.input();
    pump.mode(OpenDrain);
    pump.input();
    lightBulb = ON;
    humidityTempSensorInit();
    temperatureSensorInit();
}

void greenhouseControlUpdate()
{   
    temperatureSensorUpdate();
    
    // Activate light bulb if temp < 15 
     if ( temperatureSensorReadCelsius() < TEMPERATURE_C_MIN ) {
    lightBulb = OFF;
    } else {
    lightBulb = ON;
    }
    
    // Activate fan if relative humidity < 60 or temp >= 20
    if ( (humidityDHTSensorRead() < RELATIVE_HUMIDITY_MIN) || 
        (temperatureSensorReadCelsius() >= TEMPERATURE_C_MAX) ) {
    fan.output();
    fan = LOW;
    } else {
    fan.input();
    }
    
    // Activate water pump if moisture sensor read is > 0.82 (1 is fully dry)
    if ( humiditySensorRead() > GROUND_HUMIDITY_MIN ) {
    pump.output();
    pump = LOW;
    } else {
    pump.input();
    }
    
}

//=====[Implementations of private functions]==================================

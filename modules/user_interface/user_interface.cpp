//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"

#include "greenhouse_system.h"
#include "date_and_time.h"
#include "temperature_sensor.h"
#include "humidity_sensor.h"
#include "humidity_temp_sensor.h"
#include "display.h"

//=====[Declaration of private defines]======================================

#define DISPLAY_REFRESH_TIME_MS 1000

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{
    userInterfaceDisplayUpdate();
}


//=====[Implementations of private functions]==================================


static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_CONNECTION_I2C_PCF8574_IO_EXPANDER );
     
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Temperature:" );
    
    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "RH:" );
    
    displayCharPositionWrite ( 8,1 );
    displayStringWrite( "GH:" );
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    char temperatureString[2];
    char relativeHumidityString[3];
    char groundHumidityString[3];
    
    if( accumulatedDisplayTime >=
        DISPLAY_REFRESH_TIME_MS ) {

        accumulatedDisplayTime = 0;

        sprintf(temperatureString, "%.0f", temperatureSensorReadCelsius());
        displayCharPositionWrite ( 12,0 );
        displayStringWrite( temperatureString );
        displayCharPositionWrite ( 14,0 );
        displayStringWrite( "'C" );
        
        sprintf(relativeHumidityString, "%d", humidityDHTSensorRead());
        displayCharPositionWrite ( 4,1 );
        displayStringWrite( relativeHumidityString );
        displayCharPositionWrite ( 6,1 );
        displayStringWrite( "%" );
        
        sprintf(groundHumidityString, "%.2f", humiditySensorRead());
        displayCharPositionWrite ( 12,1 );
        displayStringWrite( groundHumidityString );
        
        displayCharPositionWrite ( 4,2 );

    } else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}

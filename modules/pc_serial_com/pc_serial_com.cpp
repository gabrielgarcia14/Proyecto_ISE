//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "pc_serial_com.h"

#include "date_and_time.h"
#include "temperature_sensor.h"
#include "humidity_sensor.h"
#include "humidity_temp_sensor.h"

//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

typedef enum{
    PC_SERIAL_COMMANDS,
    PC_SERIAL_GET_CODE,
    PC_SERIAL_SAVE_NEW_CODE,
} pcSerialComMode_t;

//=====[Declaration and initialization of public global objects]===============

Serial uartUsb(USBTX, USBRX);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static pcSerialComMode_t pcSerialComMode = PC_SERIAL_COMMANDS;

//=====[Declarations (prototypes) of private functions]========================

//static void pcSerialComGetCodeUpdate( char receivedChar );
//static void pcSerialComSaveNewCodeUpdate( char receivedChar );

static void pcSerialComCommandUpdate( char receivedChar );

static void availableCommands();
static void commandShowCurrentTemperatureInCelsius();
static void commandShowCurrentTemperatureInFahrenheit();
static void commandShowCurrentHumidity();
static void commandShowCurrentRelativeHumidity();
static void commandShowCurrentTemperatureDHT();
static void commandSetDateAndTime();
static void commandShowDateAndTime();

//=====[Implementations of public functions]===================================

void pcSerialComInit()
{
    availableCommands();
}

char pcSerialComCharRead()
{
    char receivedChar = '\0';
    if( uartUsb.readable() ) {
        receivedChar = uartUsb.getc();
    }
    return receivedChar;
}

void pcSerialComStringWrite( const char* str )
{
    uartUsb.printf( "%s", str );
}

void pcSerialComUpdate()
{
    char receivedChar = pcSerialComCharRead();
    if( receivedChar != '\0' ) {
        switch ( pcSerialComMode ) {
            case PC_SERIAL_COMMANDS:
                pcSerialComCommandUpdate( receivedChar );
            break;
            default:
                pcSerialComMode = PC_SERIAL_COMMANDS;
            break;
        }
    }    
}



//=====[Implementations of private functions]==================================

static void pcSerialComCommandUpdate( char receivedChar )
{
    switch (receivedChar) {
        case 'c': case 'C': commandShowCurrentTemperatureInCelsius(); break;
        case 'f': case 'F': commandShowCurrentTemperatureInFahrenheit(); break;
        case 'k': case 'K': commandShowCurrentHumidity(); break;
        case 'd': case 'D': commandShowCurrentRelativeHumidity(); break;
        case 'a': case 'A': commandShowCurrentTemperatureDHT(); break;
        case 's': case 'S': commandSetDateAndTime(); break;
        case 't': case 'T': commandShowDateAndTime(); break;
        default: availableCommands(); break;
    } 
}

static void availableCommands()
{
    uartUsb.printf( "Available commands:\r\n" );
    uartUsb.printf( "Press 'f' or 'F' to get lm35 reading in Fahrenheit\r\n" );
    uartUsb.printf( "Press 'c' or 'C' to get lm35 reading in Celsius\r\n" );
    uartUsb.printf( "Press 'k' or 'K' to get YL66 reading humidity \r\n" );
    uartUsb.printf( "Press 'd' or 'D' to get DHT11 reading relative humidity \r\n" );
    uartUsb.printf( "Press 'a' or 'A' to get DHT11 reading temperature in Celsius \r\n" );
    uartUsb.printf( "Press 's' or 'S' to set the date and time\r\n" );
    uartUsb.printf( "Press 't' or 'T' to get the date and time\r\n" );
    uartUsb.printf( "\r\n" );
}


static void commandShowCurrentTemperatureInCelsius()
{
    uartUsb.printf( "Temperature: %.2f °C\r\n",
                    temperatureSensorReadCelsius() );    
}

static void commandShowCurrentTemperatureInFahrenheit()
{
    uartUsb.printf( "Temperature: %.2f °F\r\n", 
                    temperatureSensorReadFahrenheit() );    
}

static void commandShowCurrentHumidity()
{
    uartUsb.printf( "Humidity: %.2f \r\n",
                    humiditySensorRead() );    
}

static void commandShowCurrentRelativeHumidity()
{
    uartUsb.printf( "Relative Humidity: %d \r\n",
                    humidityDHTSensorRead() );    
}

static void commandShowCurrentTemperatureDHT()
{
    uartUsb.printf( "Temp DHT: %d \r\n",
                    temperatureDHTSensorRead() );    
}


static void commandSetDateAndTime()
{
    int year   = 0;
    int month  = 0;
    int day    = 0;
    int hour   = 0;
    int minute = 0;
    int second = 0;
    
    uartUsb.printf("\r\nType de current year (YYYY) and press enter: ");
    uartUsb.scanf("%d", &year);
    uartUsb.printf("%d\r\n", year);

    uartUsb.printf("Type de current month (1-12) and press enter: ");
    uartUsb.scanf("%d", &month);
    uartUsb.printf("%d\r\n", month);

    uartUsb.printf("Type de current day (1-31) and press enter: ");
    uartUsb.scanf("%d", &day);
    uartUsb.printf("%d\r\n", day);

    uartUsb.printf("Type de current hour (0-23) and press enter: ");
    uartUsb.scanf("%d", &hour);
    uartUsb.printf("%d\r\n",hour);

    uartUsb.printf("Type de current minutes (0-59) and press enter: ");
    uartUsb.scanf("%d", &minute);
    uartUsb.printf("%d\r\n", minute);

    uartUsb.printf("Type de current seconds (0-59) and press enter: ");
    uartUsb.scanf("%d", &second);
    uartUsb.printf("%d\r\n", second);
    
    uartUsb.printf("Date and time has been set\r\n");

    while ( uartUsb.readable() ) {
        uartUsb.getc();
    }

    dateAndTimeWrite( year, month, day, hour, minute, second );
}

static void commandShowDateAndTime()
{
    uartUsb.printf("Date and Time = %s", dateAndTimeRead());
}
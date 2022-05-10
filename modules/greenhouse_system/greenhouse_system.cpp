//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "greenhouse_system.h"


#include "greenhouse_control.h"
#include "user_interface.h"
#include "pc_serial_com.h"


//=====[Declaration and initialization of public global objects]===============
// Para manejo de interrupciones mediante timers
DigitalOut myled(LED1);

Ticker ticker;

//=====[Declarations (prototypes) of private functions]========================
void tickerCallback();

//=====[Implementations of public functions]===================================

void greenhouseSystemInit()
{   

    userInterfaceInit();
    pcSerialComInit();
    greenhouseControlInit();
    ticker.attach(&tickerCallback, 1);
}

void greenhouseSystemUpdate()
{   
    userInterfaceUpdate();
    greenhouseControlUpdate();
    pcSerialComUpdate();
    delay(SYSTEM_TIME_INCREMENT_MS);
}


void tickerCallback() {
    myled = !myled;     
}

//=====[Implementations of private functions]==================================

//=====[#include guards - begin]===============================================

#ifndef _GREENHOUSE_SYSTEM_H_
#define _GREENHOUSE_SYSTEM_H_

//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

#define SYSTEM_TIME_INCREMENT_MS   100

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void greenhouseSystemInit();
void greenhouseSystemUpdate();
void tickerCallback();

//=====[#include guards - end]=================================================

#endif // _GREENHOUSE_SYSTEM_H_
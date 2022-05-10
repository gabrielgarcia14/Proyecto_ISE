//=====[#include guards - begin]===============================================

#ifndef _GREENHOUSE_CONTROL_H_
#define _GREENHOUSE_CONTROL_H_

//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

#define TEMPERATURE_C_MIN               15.0
#define TEMPERATURE_C_MAX               20.0
#define RELATIVE_HUMIDITY_MIN           60
#define GROUND_HUMIDITY_MIN             0.82

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void greenhouseControlInit();
void greenhouseControlUpdate();

//=====[#include guards - end]=================================================

#endif // _GREENHOUSE_CONTROL_H_
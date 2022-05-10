//=====[#include guards - begin]===============================================

#ifndef _HUMIDITY_TEMP_SENSOR_H_
#define _HUMIDITY_TEMP_SENSOR_H_

//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void humidityTempSensorInit();
void humidityTempSensorUpdate();
int humidityDHTSensorRead();
int temperatureDHTSensorRead();

//=====[#include guards - end]=================================================

#endif // _HUMIDITY_TEMP_SENSOR_H_
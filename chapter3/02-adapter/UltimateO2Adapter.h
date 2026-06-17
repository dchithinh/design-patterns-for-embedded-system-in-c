#ifndef ULTIMATEO2ADAPTER_H
#define ULTIMATEO2ADAPTER_H

#include "UltimateO2SensorProxy.h"
#include "iO2Sensor.h"
#include <stdlib.h>

typedef struct UltimateO2Adapter UltimateO2Adapter;
struct UltimateO2Adapter {
    iO2Sensor sensor;
    UltimateO2SensorProxy* itsUltimateO2SensorProxy;
};

void UltimateO2Adapter_Init(UltimateO2Adapter* const me);
void UltimateO2Adapter_Cleanup(UltimateO2Adapter* const me);

int UltimateO2Adapter_gimmeO2Conc(void* instance);
int UltimateO2Adapter_gimmeO2Flow(void* instance);
void UltimateO2Adapter_Destroy(void* instance);

iO2Sensor* UltimateO2Adapter_Create(void);

#endif // ULTIMATEO2ADAPTER_H

#ifndef ACMEO2ADAPTER_H
#define ACMEO2ADAPTER_H

#include "AcmeO2SensorProxy.h"
#include "iO2Sensor.h"
#include <stdlib.h>

typedef struct AcmeO2Adapter AcmeO2Adapter;
struct AcmeO2Adapter {
    iO2Sensor sensor;
    AcmeO2SensorProxy* itsAcmeO2SensorProxy;
};

void AcmeO2Adapter_Init(AcmeO2Adapter* const me);
void AcmeO2Adapter_Cleanup(AcmeO2Adapter* const me);

iO2Sensor* AcmeO2Adapter_Create(void);

int AcmeO2Adapter_gimmeO2Conc(void* instance);
int AcmeO2Adapter_gimmeO2Flow(void* instance);
void AcmeO2Adapter_Destroy(void* instance);

#endif  // ACMEO2ADAPTER_H

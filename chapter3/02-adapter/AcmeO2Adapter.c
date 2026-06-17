#include "AcmeO2Adapter.h"

void AcmeO2Adapter_Init(AcmeO2Adapter* const me) {
    me->itsAcmeO2SensorProxy = (AcmeO2SensorProxy*)malloc(sizeof(AcmeO2SensorProxy));
    if (me->itsAcmeO2SensorProxy != 0) {
        me->itsAcmeO2SensorProxy->getO2Conc = getO2Conc;
        me->itsAcmeO2SensorProxy->getO2Flow = getO2Flow;
    }

    me->sensor.instance = me;
    me->sensor.gimmeO2Conc = AcmeO2Adapter_gimmeO2Conc;
    me->sensor.gimmeO2Flow = AcmeO2Adapter_gimmeO2Flow;
    me->sensor.destroy = AcmeO2Adapter_Destroy;
}

void AcmeO2Adapter_Cleanup(AcmeO2Adapter* const me) {
    if (me->itsAcmeO2SensorProxy != 0) {
        free(me->itsAcmeO2SensorProxy);
        me->itsAcmeO2SensorProxy = 0;
    }
}

iO2Sensor* AcmeO2Adapter_Create(void) {
    AcmeO2Adapter* me = (AcmeO2Adapter*)malloc(sizeof(AcmeO2Adapter));
    if (me != 0) {
        AcmeO2Adapter_Init(me);
        return &(me->sensor);
    }
    return 0;
}

int AcmeO2Adapter_gimmeO2Conc(void* instance) {
    AcmeO2Adapter* me = (AcmeO2Adapter*)instance;
    return me->itsAcmeO2SensorProxy->getO2Conc();
}

int AcmeO2Adapter_gimmeO2Flow(void* instance) {
    AcmeO2Adapter* me = (AcmeO2Adapter*)instance;
    return (int)(me->itsAcmeO2SensorProxy->getO2Flow() * 60) / 100;
}

void AcmeO2Adapter_Destroy(void* instance) {
    AcmeO2Adapter* me = (AcmeO2Adapter*)instance;
    if (me != 0) {
        AcmeO2Adapter_Cleanup(me);
        free(me);
    }
}

#include "UltimateO2Adapter.h"

void UltimateO2Adapter_Init(UltimateO2Adapter* const me) {
    me->itsUltimateO2SensorProxy = (UltimateO2SensorProxy*)malloc(sizeof(UltimateO2SensorProxy));
    if (me->itsUltimateO2SensorProxy != 0) {
        me->itsUltimateO2SensorProxy->accessO2Conc = accessO2Conc;
        me->itsUltimateO2SensorProxy->accessGasFlow = accessGasFlow;
    }

    me->sensor.instance = me;
    me->sensor.gimmeO2Conc = UltimateO2Adapter_gimmeO2Conc;
    me->sensor.gimmeO2Flow = UltimateO2Adapter_gimmeO2Flow;
    me->sensor.destroy = UltimateO2Adapter_Destroy;
}

void UltimateO2Adapter_Cleanup(UltimateO2Adapter* const me) {
    if (me->itsUltimateO2SensorProxy != 0) {
        free(me->itsUltimateO2SensorProxy);
        me->itsUltimateO2SensorProxy = 0;
    }
}

iO2Sensor* UltimateO2Adapter_Create(void) {
    UltimateO2Adapter* me = (UltimateO2Adapter*)malloc(sizeof(UltimateO2Adapter));
    if (me != 0) {
        UltimateO2Adapter_Init(me);
        return &(me->sensor);
    }
    return 0;
}

void UltimateO2Adapter_Destroy(void* instance) {
    UltimateO2Adapter* me = (UltimateO2Adapter*)instance;
    if (me != 0) {
        UltimateO2Adapter_Cleanup(me);
        free(me);
    }
}

int UltimateO2Adapter_gimmeO2Conc(void* instance) {
    UltimateO2Adapter* me = (UltimateO2Adapter*)instance;
    return (int)(me->itsUltimateO2SensorProxy->accessO2Conc() * 100);
}

int UltimateO2Adapter_gimmeO2Flow(void* instance) {
    UltimateO2Adapter* me = (UltimateO2Adapter*)instance;
    double totalFlow;

    totalFlow = me->itsUltimateO2SensorProxy->accessGasFlow() * 1000.0 / 60.0;
    return (int)(totalFlow * me->itsUltimateO2SensorProxy->accessO2Conc());
}

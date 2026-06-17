#include "iO2Sensor.h"

int iO2Sensor_gimmeO2Flow(const iO2Sensor* const me) {
    return me->gimmeO2Flow(me->instance);
}

int iO2Sensor_gimmeO2Conc(const iO2Sensor* const me) {
    return me->gimmeO2Conc(me->instance);
}

void iO2Sensor_Destroy(iO2Sensor* const me) {
    if (me != 0 && me->destroy != 0) {
        me->destroy(me->instance);
    }
}

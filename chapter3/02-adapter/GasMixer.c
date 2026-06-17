#include "GasMixer.h"
#include "O2SensorFactory.h"
#include "iO2Sensor.h"
#include <stdio.h>

void mixerGas(void) {
    iO2Sensor* acmeSensor = O2SensorFactory_Create(O2_SENSOR_VENDOR_ACME);
    iO2Sensor* ultimateSensor = O2SensorFactory_Create(O2_SENSOR_VENDOR_ULTIMATE);

    int o2conc1 = iO2Sensor_gimmeO2Conc(acmeSensor);
    int o2flow1 = iO2Sensor_gimmeO2Flow(acmeSensor);

    int o2conc2 = iO2Sensor_gimmeO2Conc(ultimateSensor);
    int o2flow2 = iO2Sensor_gimmeO2Flow(ultimateSensor);

    printf("%d %d %d %d\n", o2conc1, o2flow1, o2conc2, o2flow2);

    iO2Sensor_Destroy(acmeSensor);
    iO2Sensor_Destroy(ultimateSensor);
}

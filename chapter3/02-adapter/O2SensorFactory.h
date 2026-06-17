#ifndef O2SENSORFACTORY_H
#define O2SENSORFACTORY_H

#include "iO2Sensor.h"

typedef enum O2SensorVendor {
    O2_SENSOR_VENDOR_ACME,
    O2_SENSOR_VENDOR_ULTIMATE
} O2SensorVendor;

iO2Sensor* O2SensorFactory_Create(O2SensorVendor vendor);

#endif // O2SENSORFACTORY_H

#include "O2SensorFactory.h"
#include "AcmeO2Adapter.h"
#include "UltimateO2Adapter.h"

iO2Sensor* O2SensorFactory_Create(O2SensorVendor vendor) {
    switch (vendor) {
        case O2_SENSOR_VENDOR_ACME:
            return AcmeO2Adapter_Create();
        case O2_SENSOR_VENDOR_ULTIMATE:
            return UltimateO2Adapter_Create();
        default:
            return 0;
    }
}

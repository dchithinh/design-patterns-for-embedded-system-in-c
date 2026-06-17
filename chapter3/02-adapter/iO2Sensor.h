#ifndef IO2SENSOR_H
#define IO2SENSOR_H

typedef struct iO2Sensor iO2Sensor;
struct iO2Sensor {
    void* instance;
    int (*gimmeO2Flow)(void* instance);
    int (*gimmeO2Conc)(void* instance);
    void (*destroy)(void* instance);
};

int iO2Sensor_gimmeO2Flow(const iO2Sensor* const me);
int iO2Sensor_gimmeO2Conc(const iO2Sensor* const me);
void iO2Sensor_Destroy(iO2Sensor* const me);

#endif // IO2SENSOR_H

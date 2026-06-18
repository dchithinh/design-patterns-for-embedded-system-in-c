#include <stdio.h>
#include "DisplayClient.h"

int main(int argc, char const *argv[])
{
    DisplayClient* p_DisplayClient = DisplayClient_Create();
    GasSensor* p_GasSensor = GasSensor_Create();

    unsigned int flow=1;
    unsigned int n2=2;
    unsigned int o2=3;

    DisplayClient_setItsGasSensor(p_DisplayClient, p_GasSensor);
    DisplayClient_register(p_DisplayClient);

    DisplayClient_alarm(p_DisplayClient, "gas sensor warning");

    GasSensor_newData(p_GasSensor, flow, n2, o2);
    GasSensor_newData(p_GasSensor, flow, n2, o2);
    GasSensor_newData(p_GasSensor, flow, n2, o2);
    GasSensor_newData(p_GasSensor, flow, n2, o2);

    GasSensor_Destroy(p_GasSensor);
    DisplayClient_Destroy(p_DisplayClient);
    return 0;
}

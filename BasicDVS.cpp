#include "BasicDVS.h"

void BasicDVS::startEngine()
{
    if (!startengine) {
        startengine = true;
    }
}

void BasicDVS::stopEngine()
{
    if (startengine) {
        startengine = false;
        M = 0;
        V = 0;
        T_engine = T_enviroment;
    }
}


double BasicDVS::getVc()
{
    return C * (T_enviroment - T_engine);
}

double BasicDVS::getVh()
{
    return (M * Hm) + (pow(V, 2) * Hv);
}

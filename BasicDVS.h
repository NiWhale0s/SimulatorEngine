#pragma once
#include "Engine.h"
class BasicDVS : public Engine
{
private:
	bool startengine = false;
public:

	BasicDVS(double I_Val, double M_Val, double V_Val, double T_overheat_Val, double Hm_Val, double Hv_Val, double C_Val, double T_enviroment_Val) :
		Engine(I_Val, M_Val, V_Val ,T_overheat_Val, Hm_Val, Hv_Val, C_Val, T_enviroment_Val) {}


	void startEngine() override;
	void stopEngine() override;

	double getVc() override;
	double getVh() override;

};


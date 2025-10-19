#pragma once
#include <cmath>
#include <stdexcept>

class Engine
{
protected:
	double I, M, V, T_overheat, Hm, Hv, C, T_enviroment, T_engine;

public:
	Engine(double I_Val, double M_Val, double V_Val, double T_overheat_Val, double Hm_Val, double Hv_Val, double C_Val, double T_enviroment_Val);
	virtual ~Engine() = default;


	double getM();
	double getV();
	double getI();
	double getTEngine();
	double getTOverhate();

	void setM(double M);
	void setV(double V);
	void setTEngine(double t);
	void setTOverheat(double t);


	virtual void startEngine() = 0;
	virtual void stopEngine() = 0;

	virtual double getVh() = 0;
	virtual double getVc() = 0;
	
}; 


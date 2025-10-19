#pragma once
#include <cmath>

class Engine
{
protected:
	double I, M, V, T_overheat, Hm, Hv, C, T_enviroment, T_engine;

public:
	Engine(double I_Val, double M_Val, double V_Val, double T_overheat_Val, double Hm_Val, double Hv_Val, double C_Val, double T_enviroment_Val) :
		I(I_Val), M(M_Val), V(V_Val), T_overheat(T_overheat_Val), Hm(Hm_Val), Hv(Hv_Val), C(C_Val), T_enviroment(T_enviroment_Val), T_engine(T_enviroment_Val) {}
	virtual ~Engine() = default;


	double getM();
	double getV();
	double getI();
	double getTEngine();
	double getTOverhate();

	void setM(double M);
	void setV(double V);
	void setTEngine(double t);
	void setTOverhate(double t);


	virtual void startEngine() = 0;
	virtual void stopEngine() = 0;

	virtual double getVh() = 0;
	virtual double getVc() = 0;
	
}; 


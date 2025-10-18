#pragma once
class Engine
{
protected:
	double I, M, V, T_overheat, Hm, Hv, C, a = 0, N = 0, time = 0, T_enviroment, T_engine;

public:
	Engine(double I_Val, double M_Val, double V_Val, double T_overheat_Val, double Hm_Val, double Hv_Val, double C_Val, double T_enviroment_Val) :
		I(I_Val), M(M_Val), V(V_Val), T_overheat(T_overheat_Val), Hm(Hm_Val), Hv(Hv_Val), C(C_Val), T_enviroment(T_enviroment_Val), T_engine(T_enviroment_Val) {}
	virtual ~Engine() = default;


	double getM();
	double getV();
	double gettime();
	double get_a();
	double getN();
	double getTEngine();

	void enginePower();
	
	virtual double getVh() = 0;
	virtual double getVc() = 0;



}; 


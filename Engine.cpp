#include "Engine.h"


Engine::Engine(double I_Val, double M_Val, double V_Val, double T_overheat_Val, double Hm_Val, double Hv_Val, double C_Val, double T_enviroment_Val) :
	I(I_Val), M(M_Val), V(V_Val), T_overheat(T_overheat_Val), Hm(Hm_Val), Hv(Hv_Val), C(C_Val), T_enviroment(T_enviroment_Val), T_engine(T_enviroment_Val) {
	
	if (I <= 0) {
		throw std::invalid_argument("I must be positive!");
	}

	if (C < 0) {
		throw std::invalid_argument("C must be positive!");
	}
	if (Hm < 0 || Hv < 0) {
		throw std::invalid_argument("Hm and Hv must be non-negative!");
	}
	if (T_enviroment < 100 && T_enviroment > 100) {
		throw std::invalid_argument("Unrealistic values for temperature!");
	}
	if (T_overheat < T_enviroment) {
		throw std::invalid_argument("The overheating value is less than the weather temperature!");
	}
}


double Engine::getM()
{
	return M;
}

double Engine::getV()
{
	return V;
}

double Engine::getI()
{
	return I;
}

double Engine::getTEngine()
{
	return T_engine;
}

double Engine::getTOverhate()
{
	return T_overheat;
}

void Engine::setM(double M)
{
	if (M < 0) {
		throw std::invalid_argument("The value of M is less than 0!");
	}
	this->M = M;
}

void Engine::setV(double V)
{
	if (V < 0) {
		throw std::invalid_argument("The value of V is less than 0");
	}
	this->V = V;
}


void Engine::setTEngine(double t)
{
	T_engine = t;
}

void Engine::setTOverheat(double t)
{
	if (T_overheat < T_enviroment) {
		throw std::invalid_argument("The overheating value is less than the weather temperature!");
	}
	T_overheat = t;
}





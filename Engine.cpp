#include "Engine.h"

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
	this->M = M;
}

void Engine::setV(double V)
{
	this->V = V;
}


void Engine::setTEngine(double t)
{
	T_engine = t;
}

void Engine::setTOverhate(double t)
{
	T_overheat = t;
}





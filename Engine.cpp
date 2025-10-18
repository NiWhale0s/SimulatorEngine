#include "Engine.h"

double Engine::getM()
{
	return M;
}

double Engine::getV()
{
	return V;
}

double Engine::gettime()
{
	return time;
}

double Engine::get_a()
{
	return a;
}

double Engine::getN()
{
	return N;
}

double Engine::getTEngine()
{
	return T_engine;
}

void Engine::enginePower()
{
	N = M * V / 1000;
}

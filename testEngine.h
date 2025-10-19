#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "Engine.h"
#include "BasicDVS.h"

const double epsilon = 1e-4;

using namespace std;

double linearInterpolation(double currentV, vector<double>M, vector<double> V) {
	if (currentV <= V[0]) return M[0];

	if (currentV >= V.back()) return M.back();

	for (int i = 0; i < V.size() - 1; i++) {
		if (V[i] < currentV && currentV < V[i + 1]) {
			double V1 = V[i];
			double V2 = V[i + 1];
			double M1 = M[i];
			double M2 = M[i + 1];
			return M1 + (M2 - M1) * (currentV - V1) / (V2 - V1);
		}
	}

	return M.back();
}

void overheatingTest(Engine& engine, vector<double> M, vector <double> V) {
	cout << "Test Overheating: " << endl;
	
	double a = 0;
	double time = 0.0;
	double deltaT = 0.1;
	double currentM;
	double currentV = V[0];
	
	engine.startEngine();
	cout << "Start engine!" << endl;
	
	while (engine.getTEngine() < engine.getTOverhate()) {
		currentM = linearInterpolation(currentV, M, V);
		a = currentM / engine.getI();
		currentV = currentV + a * deltaT;
		
		engine.setM(currentM);
		engine.setV(currentV);
		
		time += deltaT;
		double tHot = engine.getVh() ;
		double tCold = engine.getVc();
		double currentT = engine.getTEngine() + tHot + tCold;

		engine.setTEngine(currentT);
		cout << "current engine t = " << engine.getTEngine() << endl;
		
		if (time > 1000) { 
			cout << "Temperature stabilized at " << engine.getTEngine() << endl;
			break;
		}
	}
	
	engine.stopEngine();
	cout << "The test was completed successfully!" << " The overheating temperature was reached in " << time << " sec" << endl;
	return;
}

void maximumPowerTest(Engine& engine, vector <double> M, vector <double> V) {
	cout << "Test maximum power: " << endl;
	
	double a = 0;
	double maxN = 0, N = 0, V_maxN = 0;
	double time = 0.0;
	double deltaT = 0.1;
	double currentM = 0.1;
	double currentV = V[0];
	
	engine.startEngine();
	cout << "Start engine!" << endl;
	cout << setw(10) << "Time" << setw(15) << "N (kVt)" << setw(15) << "V (rad/s)" << setw(15) << "M (H/m)" << endl;
	
	while (fabs(currentM - M.back()) > epsilon) {
		currentM = linearInterpolation(currentV, M, V);
		a = currentM / engine.getI();
		currentV = currentV + a * deltaT;
		
		engine.setM(currentM);
		engine.setV(currentV);
		time += deltaT;
		N = engine.getM() * engine.getV() / 1000;
		
		if (maxN < N) {
			maxN = N;
			V_maxN = currentV;
		}
		
		cout << setw(10) << time << setw(15) << N << setw(15) << currentV << setw(15) << currentM << endl;
		if (currentV > V.back()) currentM = 0;
	}
	engine.stopEngine();
	cout << endl << "The test was completed successfully!" << " The maximum power was reached in " << time << " sec, and it is equal at " << maxN << " the speed of the crankshaft " << V_maxN << endl;
	return;
}
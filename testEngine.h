#pragma once

#include <iostream>
#include <vector>
#include "Engine.h"
#include "BasicDVS.h"

using namespace std;

double linearInterpolation(double currentV, vector<double>M, vector<double> V) {
	double V1= 0, V2 = 0, M1 = 0, M2 = 0;
	for (int i = 0; i < V.size() - 1; i++) {
		if (V[i] <= currentV <= V[i + 1]) {
			V1 = V[i];
			V2 = V[i + 1]; 
			M1 = M[i];
			M2 = M[i + 1];
			break;
		}
	}
	return M1 + (M2 - M1) * (currentV - V1) / (V2 - V1);
}

void overheatingTest(Engine& engine, vector<double> M, vector <double> V) {
	cout << "Test Overheating: " << endl;
	double a;
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
		double tHot = engine.getVh();
		double tCold = engine.getVc();
		double currentT = engine.getTEngine() + tHot + tCold;
		engine.setTEngine(currentT);
		
	}
	cout << "The test was completed successfully!" << " The overheating temperature was reached in " << time << " sec" << endl;
	return;
}
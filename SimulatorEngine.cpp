#include <iostream>
#include <vector>

#include "testEngine.h"
#include "Engine.h"
#include "BasicDVS.h"


using namespace std;


int main() {
	double temp;
	vector<double> M = { 20, 75, 100, 105, 75, 0 };
	vector<double> V = { 0, 75, 150, 200, 250, 300 };
	cout << "Enter temperature enviroment: ";
	cin >> temp;
	BasicDVS engine (10, 20, 0, 110, 0.01, 0.0001, 0.1, temp);
	overheatingTest(engine, M, V);
}
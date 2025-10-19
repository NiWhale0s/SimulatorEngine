#include <iostream>
#include <vector>
#include <stdexcept>

#include "testEngine.h"
#include "Engine.h"
#include "BasicDVS.h"


using namespace std;


int main() {
	try {
		double temp;
		vector<double> M = { 20, 75, 100, 105, 75, 0 };
		vector<double> V = { 0, 75, 150, 200, 250, 300 };
		
		cout << "Enter temperature enviroment: ";
		cin >> temp;
		if (cin.fail()) {
			throw std::invalid_argument("Invalid temperature input");
		}
		
		BasicDVS engine(10, 20, 0, 110, 0.01, 0.0001, 0.1, temp);
		overheatingTest(engine, M, V);
		maximumPowerTest(engine, M, V);
	
	}
	catch (const std::invalid_argument& e) {
		cerr << "Invalid argument: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "Unknown error" << endl;
		return 2;
	}
	return 0;
}
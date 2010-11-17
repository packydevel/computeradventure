#include <iostream>

using namespace std;

extern const int CONSTANT1; //Definition of CONSTANT1 for external linkage in GlobalConstDeinition.cpp

extern const int CONSTANT2; //No definition of CONSTANT2 for external linkage

extern const int CONSTANT3; //No definition of CONSTANT3 for external linkage

int main22() {
	cout << "The value of CONSTANT1 is: " << CONSTANT1 << endl;
	//cout << "The value of CONSTANT2 is: " << CONSTANT2; << endl; //ERROR!!! No reference to CONSTANT2
	//cout << "The value of CONSTANT3 is: " << CONSTANT3 << endl; //ERROR!!! No reference to CONSTANT3
}

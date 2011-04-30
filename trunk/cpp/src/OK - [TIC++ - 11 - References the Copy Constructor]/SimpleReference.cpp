#include <iostream>

using namespace std;

int main10() {

	int x = 0;
	int& rx = x; //You must declare and define at the same time the reference variable

	cout << "The value of x is: " << x << endl;
	cout << "The value of r is: " << rx << endl;

	x = 1;

	cout << "The value of x is: " << x << endl;
	cout << "The value of r is: " << rx << endl;

	rx = 2; //OK

	cout << "The value of x is: " << x << endl;
	cout << "The value of r is: " << rx << endl;

	const int y = 0;
	//int& ry = y; //ERROR!!! If the referred variable is declared const then also reference variable must be declared const
	const int& ry = y;

	cout << "The value of y is: " << y << endl;
	cout << "The value of ry is: " << ry << endl;

	//y = 1; //ERROR!!! Obvious, y is declared const
	//ry = 1; //ERROR!!! Also ry is declared const

	int z = 0;
	const int& rz = z;

	cout << "The value of z is: " << z << endl;
	cout << "The value of rz is: " << rz << endl;

	z = 1;

	cout << "The value of z is: " << z << endl;
	cout << "The value of rz is: " << rz << endl;

	//rz = 2; //ERROR!!! The reference variable rz is declared const
}


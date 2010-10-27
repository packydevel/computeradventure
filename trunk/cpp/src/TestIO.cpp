/*
 * TestIO.cpp
 *
 *  Created on: 27/ott/2010
 *      Author: packyuser
 */

#include <iostream>
#include <limits>

using namespace std;

int main(int argc, char **argv) {
	cout << "Output Text" << "\n";

	cout << "Another Text terminating with New Line" << endl;

	cout << "This Text is on a New Line";

	cout << endl;

	unsigned short int x; // (0 - 65535)
	signed short int a;


	cout << x << endl;

	x = -70000; // Wrong!!! It will contain (abs(x) mod 65536)
	a = -70000; // Wrong!!! It will contain sign(x)*(abs(x) mod 32768)

	cout << x << endl;
	cout << a << endl;

	const int k = 10;
	// k = 20; // Wrong!!! k is read-only variable (constant)

	cout << k << endl;

	cin.get(); // wait for user input
}

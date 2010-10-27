/*
 * TestIO.cpp
 *
 *  Created on: 27/ott/2010
 *      Author: packyuser
 */

#include <iostream>
#include <limits>;

using namespace std;

void printRange() {
	cout << "char, signed char :";
	cout << "(" << int(numeric_limits<char>::min()) << " , " << int(
			numeric_limits<char>::max()) << ")" << endl;

	cout << "unsigned char :";
	cout << "(" << int(numeric_limits<unsigned char>::min()) << " , " << int(
			numeric_limits<unsigned char>::max()) << ")" << endl;

	cout << "short, signed short, short int, signed short int :";
	cout << "(" << numeric_limits<short int>::min() << " , " << numeric_limits<
			short int>::max() << ")" << endl;

	cout << "unsigned short, unsigned short int :";
	cout << "(" << numeric_limits<unsigned short>::min() << " , "
			<< numeric_limits<unsigned short>::max() << ")" << endl;

	cout << "int, signed, signed int :";
	cout << "(" << numeric_limits<int>::min() << " , "
			<< numeric_limits<int>::max() << ")" << endl;

	cout << "unsigned, unsigned int :";
	cout << "(" << numeric_limits<unsigned int>::min() << " , "
			<< numeric_limits<unsigned int>::max() << ")" << endl;

	cout
			<< "long, signed long, long int, long long, signed long int, signed long long :";
	cout << "(" << numeric_limits<long int>::min() << " , " << numeric_limits<
			long int>::max() << ")" << endl;

	cout << "unsigned long, unsigned long int, unsigned long long :";
	cout << "(" << numeric_limits<unsigned long>::min() << " , "
			<< numeric_limits<unsigned long>::max() << ")" << endl;

	cout << "float :";
	cout << "(" << numeric_limits<float>::min() << " , " << numeric_limits<
			float>::max() << ")" << endl;

	cout << "double :";
	cout << "(" << numeric_limits<double>::min() << " , " << numeric_limits<
			double>::max() << ")" << endl;

	cout << "long double :";
	cout << "(" << numeric_limits<long double>::min() << " , "
			<< numeric_limits<long double>::max() << ")" << endl;

	cin.get();
}

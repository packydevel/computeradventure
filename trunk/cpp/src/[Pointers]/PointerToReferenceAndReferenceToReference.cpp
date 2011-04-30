#include <iostream>
using namespace std;

int main43() {
	int x = 0;
	int& ir = x;

	//legal but useless because pointing to a reference is the same thing than
	//pointing the real variable referenced by reference
	int* pir = &ir;

	//legal but useless because referencing a reference is the same thing than
	//referencing the real variable referenced by the reference
	int& rir = ir;

	//int&* pir = &ir //SYNTAX ERROR!!! Cannot create a pointer to a reference
	//int&& rir = &ir //SYNTAX ERROR!!! Cannot create a reference to another reference

	cout << "&x = " << &x << endl;
	cout << "&ir = " << &ir << endl;
	cout << "pir = " << pir << endl;
	cout << "&rir = " << &rir << endl;

	cout << "x = " << x << endl;
	cout << "ir = " << ir << endl;
	cout << "*pir = " << *pir << endl;
	cout << "rir = " << rir << endl;
}

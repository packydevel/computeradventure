#include <iostream>

using namespace std;

struct SimpleStructure {
	int a, b, c, d;
};

class SimpleClass {
public:
	int a, b, c, d;
};

int main20() {
	SimpleStructure ss;

	//This is an Array of Pointer to any int member of struct SimpleStruct;
	//ssmp is the name of that array of pointer to member
	int SimpleStructure::* ssmp[4];

	//The array of pointer ssmp can be initialized with the address of an int member of the struct SimpleStruct.
	//In this case the elements of ssmp are initialized with the address of the members of the struct SimpleStruct.
	ssmp[0] = &SimpleStructure::a;
	ssmp[1] = &SimpleStructure::b;
	ssmp[2] = &SimpleStructure::c;
	ssmp[3] = &SimpleStructure::d;

	ss.a=0;
	ss.b=1;
	ss.c=2;
	ss.d=3;

	cout << "The value of ss.a is: " << ss.*ssmp[0] << endl;
	cout << "The value of ss.b is: " << ss.*ssmp[1] << endl;
	cout << "The value of ss.b is: " << ss.*ssmp[2] << endl;
	cout << "The value of ss.d is: " << ss.*ssmp[3] << endl;

	SimpleClass sc;

	//This is an Array of Pointer to any int member of class SimpleClass;
	//scmp is the name of that array of pointer to member
	int SimpleClass::* scmp[4];

	//The array of pointer scmp can be initialized with the address of an int member of class SimpleClass.
	//In this case the elemnts of scmp are initialized with the address of the a members of class SimpleClass.
	scmp[0] = &SimpleClass::a;
	scmp[1] = &SimpleClass::b;
	scmp[2] = &SimpleClass::c;
	scmp[3] = &SimpleClass::d;

	sc.a=0;
	sc.b=1;
	sc.c=2;
	sc.d=3;

	cout << "The value of ss.a is: " << sc.*scmp[0] << endl;
	cout << "The value of ss.b is: " << sc.*scmp[1] << endl;
	cout << "The value of ss.b is: " << sc.*scmp[2] << endl;
	cout << "The value of ss.d is: " << sc.*scmp[3] << endl;
}


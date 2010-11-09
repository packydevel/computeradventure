#include <iostream>

using namespace std;

struct SimpleStructure {
	int a;
};

class SimpleClass {
public:
	int a;
};

int main17() {
	SimpleStructure ss;
	SimpleStructure* ssp = &ss;

	ssp->a = 0; //OK Accessing a through struc pointer

	cout << "The value of ssp->a is: " << ssp->a << endl;
	cout << "The value of ss.a is: " << ss.a << endl;

	ss.a = 1; //OK Accessing a through struct instance

	cout << "The value of ssp->a is: " << ssp->a << endl;
	cout << "The value of ss.a is: " << ss.a << endl;

	SimpleClass sc;
	SimpleClass* scp = &sc;

	scp->a = 0; //OK Accessing a through class pointer

	cout << "The value of scp->a is: " << scp->a << endl;
	cout << "The value of sc.a is: " << sc.a << endl;

	sc.a = 1; //OK Accessing a through class instance

	cout << "The value of scp->a is: " << scp->a << endl;
	cout << "The value of sc.a is: " << sc.a << endl;
}


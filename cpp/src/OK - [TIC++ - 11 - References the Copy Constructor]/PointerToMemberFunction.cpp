#include <iostream>

using namespace std;

struct SimpleStruct {
	int f1(int x) {
		x++;
		return x;
	}

	int f2(int x) {
		x--;
		return x;
	}
};

class SimpleClass {
public:
	int f1(int x) {
		x++;
		return x;
	}

	int f2(int x) {
		x--;
		return x;
	}
};

int main19() {
	int x = 0;

	SimpleStruct ss;
	SimpleStruct* ssp = &ss;

	//This is a Pointer to any member function of struct SimpleStruct that accept an integer parameter.
	//ssmfp is the name of that pointer to function member
	int (SimpleStruct::*ssmfp)(int);

	//The pointer ssmfp can be initialized with the address of a member function of the struct SimpleStruct
	//that accept an int parameter.
	//In this case ssmfp is initialized with the address of the f1 function member of the struct SimpleStruct.
	//In the case of overloading of member function f1 there are no problems because the compiler knows how to
	//point the correct member function through the sign of the member function used in the definition of
	//pointer to member function
	ssmfp = &SimpleStruct::f1;

	cout << "The value of ss.f1(x) is: " << ss.f1(x) << endl;
	cout << "The value of ssp->f1(x) is: " << ssp->f1(x) << endl;
	cout << "The value of (ss.*ssmfp)(x) is: " << (ss.*ssmfp)(x) << endl;
	cout << "The value of (ssp->*ssmfp)(x) is: " << (ssp->*ssmfp)(x) << endl;

	//If we need to point to another function member of the struct SimpleStruct we can do that simply
	ssmfp = &SimpleStruct::f2;

	cout << "The value of ss.f2(x) is: " << ss.f2(x) << endl;
	cout << "The value of ssp->f2(x) is: " << ssp->f2(x) << endl;
	cout << "The value of (ss.*ssmfp)(x) is: " << (ss.*ssmfp)(x) << endl;
	cout << "The value of (ssp->*ssmfp)(x) is: " << (ssp->*ssmfp)(x) << endl;

	SimpleClass sc;
	SimpleClass* scp = &sc;

	//This is a Pointer to any member function of class SimpleClass that accept an integer parameter.
	//that accept an integer parameter
	//scmfp is the name of that pointer to function member
	int (SimpleClass::*scmfp)(int);

	//The pointer scmfp can be initialized with the address of a member function of class SimpleClass
	//that accept an integer parameter
	//In this case scmfp is initialized with the address of a member function of class SimpleClass.
	scmfp = &SimpleClass::f1;

	cout << "The value of sc.f1(x) is: " << sc.f1(x) << endl;
	cout << "The value of scp->f1(x) is: " << scp->f1(x) << endl;
	cout << "The value of (sc.*scmfp)(x) is: " << (sc.*scmfp)(x) << endl;
	cout << "The value of (scp->*scmfp)(x) is: " << (scp->*scmfp)(x) << endl;

	//If we need to point to another function member of the class SimpleClass we can do that simply
	scmfp = &SimpleClass::f2;

	cout << "The value of sc.f2(x) is: " << sc.f2(x) << endl;
	cout << "The value of scp->f2(x) is: " << scp->f2(x) << endl;
	cout << "The value of (sc.*scmfp)(x) is: " << (sc.*scmfp)(x) << endl;
	cout << "The value of (scp->*scmfp)(x) is: " << (scp->*scmfp)(x) << endl;
}

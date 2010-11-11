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

int main21() {
	int x = 0;

	SimpleStruct ss;

	//This is an Array of Pointers to any member function of struct SimpleStruct that accept an integer parameter.
	//ssmfp is the name of that array of pointers to functions member
	int (SimpleStruct::*ssmfp[2])(int);

	//The array pointer ssmfp can be initialized with the addresses of the member functions of the struct SimpleStruct
	//that accept an int parameter.
	//In this case ssmfp is initialized with the addresses of the f1 and f2 member function of the struct SimpleStruct.
	ssmfp[0] = &SimpleStruct::f1;
	ssmfp[1] = &SimpleStruct::f2;

	cout << "The value of ss.f1(x) is: " << (ss.*ssmfp[0])(x) << endl;
	cout << "The value of ss.f2(x) is: " << (ss.*ssmfp[1])(x) << endl;

	SimpleClass sc;

	//This is an Array of Pointers to any member function of class SimpleClass that accept an integer parameter.
	//scmfp is the name of that array of pointers to functions member
	int (SimpleClass::*scmfp[2])(int);

	//The array of pointers scmfp can be initialized with the addresses of the member functions of class SimpleClass
	//that accept an integer parameter
	//In this case scmfp is initialized with the addresses of the f1 and f2 member function of class SimpleClass.
	scmfp[0] = &SimpleClass::f1;
	scmfp[1] = &SimpleClass::f2;

	cout << "The value of sc.f1(x) is: " << (sc.*scmfp[0])(x) << endl;
	cout << "The value of sc.f2(x) is: " << (sc.*scmfp[1])(x) << endl;
}

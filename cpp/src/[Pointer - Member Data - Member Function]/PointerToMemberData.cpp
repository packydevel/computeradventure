#include <iostream>

using namespace std;

struct SimpleStructure {
	int a, b;
};

class SimpleClass {
public:
	int a, b;
};

int main18() {
	SimpleStructure ss;
	SimpleStructure* ssp = &ss;

	//This is a Pointer to any int member of struct SimpleStruct;
	//ssmp is the name of that pointer to member
	int SimpleStructure::* ssmp;

	//The pointer ssmp can be initialized with the address of an int member of the struct SimpleStruct.
	//In this case ssmp is initialized with the address of the a member of the struct SimpleStruct.
	ssmp = &SimpleStructure::a;

	ss.a = -10;

	cout << "The value of ss.a is: " << ss.a << endl;
	cout << "The value of ssp->a is: " << ssp->a << endl;
	cout << "The value of ss.*ssmp is: " << ss.*ssmp << endl;
	cout << "The value of ssp->*ssmp is: " << ssp->*ssmp << endl;

	ss.b = 10;

	//If we need to point to another member of the struct SimpleStruct we can do that simply
	ssmp = &SimpleStructure::b;

	cout << "The value of ss.b is: " << ss.b << endl;
	cout << "The value of ssp->b is: " << ssp->b << endl;
	cout << "The value of ss.*ssmp is: " << ss.*ssmp << endl;
	cout << "The value of ssp->*ssmp is: " << ssp->*ssmp << endl;

	SimpleClass sc;
	SimpleClass* scp = &sc;

	//This is a Pointer to any int member of class SimpleClass;
	//scmp is the name of that pointer to member
	int SimpleClass::* scmp;

	//The pointer scmp can be initialized with the address of an int member of class SimpleClass.
	//In this case scmp is initialized with the address of the a member of class SimpleClass.
	scmp = &SimpleClass::a;

	sc.a = -10;

	cout << "The value of sc.a is: " << sc.a << endl;
	cout << "The value of scp->a is: " << scp->a << endl;
	cout << "The value of sc.*scmp is: " << sc.*scmp << endl;
	cout << "The value of scp->*scmp is: " << scp->*scmp << endl;

	sc.b = 10;

	//If we need to point to another member of the class SimpleClass we can do that simply
	scmp = &SimpleClass::b;

	cout << "The value of sc.b is: " << sc.b << endl;
	cout << "The value of scp->b is: " << scp->b << endl;
	cout << "The value of sc.*scmp is: " << sc.*scmp << endl;
	cout << "The value of scp->*scmp is: " << scp->*scmp << endl;

	cout << "The value of the ssp is: " << ssp << endl;
	cout << "The value of the scp is: " << scp << endl;

	//The address contained in the pointer to member of struct or class is an offset inside
	//starting at the address of the struct or class
	cout << "The value of the ssmp is: " << ssmp << endl;
	cout << "The value of the scmp is: " << scmp << endl;

	//Pointer to member struct or class have some limitations:
	//
	//1)
	//It is not possible to have a void pointer to member struct or class
	//void SimpleStructure::* sp;
	//void SimpleClass::* cp;
	//
	//2)
	//It is not possible for a pointer to member of specificied struct or class to point
	//to a member of another struct or class although the member type is equal.
	//This type of assignement will cause a compile-time error
	//ssmp = &SimpleClass::a; //ERROR!!!
	//scmp = &SimpleStructure::a; //ERROR!!!
	//
	//3)
	//It is not possible to execute arithmetic operation with such a pointer
	//ssmp++; //ERROR!!!
	//scmp++; //ERRRO!!!
	//
	//4)
	//It is not possible to compare two pointer to member struct or class each other
	//bool b = (ssmp == scmp) ? true : false; //ERROR!!!
}


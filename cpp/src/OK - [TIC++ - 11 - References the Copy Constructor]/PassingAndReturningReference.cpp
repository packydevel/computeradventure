#include <iostream>

using namespace std;

int getNumber() {
	return 0;
}

int& validReference(int& x) {
	x++;
	return x;
}

int validConstantReference(const int& x) {
	return x + 1;
}

int& danglingReference() {
	int x = 10;
	return x; //Warning!!! The variable q is destroyed when g finish, so q is a dangling reference
}

class C {
public:
	int x;

	void constMemberFunction() const {
	}

	void nonconstMemberFunction() {
	}
};

void validObjectConstantReference(const C& c) {
	//c.x = 10; //ERROR!!! x is non const member of class C

	c.constMemberFunction(); //OK. Called a const memmber function

	//c.nonconstMemberFunction(); //ERROR!!! Called a non-const member function of class C
}

int main11() {
	int x = 0;
	int y;

	x = validReference(x); //OK

	cout << "The value of x is: " << x << endl;

	//The argument passed is the number 1 but it is a temporary user constant.
	//In this case the function validReference cannot manipulate the argument
	//passed because it doesn't know the memory address of the argument passed
	//by reference since it is a constant.
	//This case will generate a compile-time error.
	//x = validReference(1); //ERROR!!! The value passed is a constant

	//As in the previous case, the parameter passed to the function validReference
	//is a temporary constant generated as return value from the function getNumber
	//This case will generate a compile-time error.
	//x = validReference(getNumber()); //ERROR!!! The value passed is a temporary constant

	//In this case it is possible to pass the number 1 as argument because the function
	//validConstantReference accept a constant reference.
	x = validConstantReference(1); //OK

	cout << "The value of x is: " << x << endl;

	//As in the previous case.
	x = validConstantReference(getNumber()); //OK

	cout << "The value of x is: " << x << endl;

	C c;

	validObjectConstantReference(c);

	y = danglingReference();

	cout << "The value of y is: " << y << endl;
}

#include <iostream>

using namespace std;

class BaseClass {
public:
	int baseFunction(void) const {
		cout << "int BaseClass::baseFunction(void)" << endl;
	}

	int baseFunction(int i) const {
		cout << "int BaseClass::baseFunction(int)" << endl;
	}
};

class DerivedClass1FromBaseClass: public BaseClass {
public:
	//Overriding hides the base class member functions baseFunction
	int baseFunction(void) const {
		cout << "int DerivedClass1FromBaseClass::baseFunction(void)" << endl;
	}
};

class DerivedClass2FromBaseClass: public BaseClass {
public:
	//Changing return type hides the base class member functions baseFunction
	void baseFunction(void) const {
		cout << "void DerivedClass2FromBaseClass::baseFunction(void)" << endl;
	}
};

class DerivedClass3FromBaseClass: public BaseClass {
public:
	//Changing signature hides the base class member functions baseFunction
	int baseFunction(int i, int j) const {
		cout << "int DerivedClass3FromBaseClass::baseFunction(int,int)" << endl;
	}
};

class DerivedClass4FromBaseClass: public BaseClass {
	//No overriding. No ridefinition.
};

int main() {
	BaseClass bc;
	bc.baseFunction();
	bc.baseFunction(0);

	DerivedClass1FromBaseClass dc1;
	dc1.baseFunction(); //OK. You see the overrided version of the function.
	//int x = dc1.baseFunction(0); //ERROR!!! The function invoked was hidden.

	DerivedClass2FromBaseClass dc2;
	dc2.baseFunction();
	//int x = dc2.baseFunction(); //ERROR!!! The function invoked was hidden.
	//int x = dc2.baseFunction(0); //ERROR!!! The function invoked was hidden.

	DerivedClass3FromBaseClass dc3;
	dc3.baseFunction(0, 0);
	//int x = dc3.baseFunction(); //ERROR!!! The function invoked was hidden.
	//int x = dc3.baseFunction(0); //ERROR!!! The function invoked was hidden.

	DerivedClass4FromBaseClass dc4;
	dc4.baseFunction(); //OK. You see the base class version of the function.
	dc4.baseFunction(); //OK. You see the base class version of the function.
}

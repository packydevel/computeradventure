#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass() :
		attribute(0) {
	}

	int* getAttributePointer() {
		return &attribute;
	}

	const int* getPointerToConstantAttribute() {
		return &attribute;
	}

private:
	int attribute;
};

int main4() {
	MyClass c;
	int* p1 = c.getAttributePointer();

	cout << "The value of attribute is: " << *p1 << endl;

	*p1 = 10; //OK, but it is possible to make change to private variable.

	cout << "The value of attribute is: " << *p1 << endl;

	const int* p2 = c.getPointerToConstantAttribute();

	cout << "The value of attribute is: " << *p2 << endl;

	//Preserving private variable
	//*p2 = 100; //ERROR!!! Impossible to change value because p2 is Pointer to Constant
}

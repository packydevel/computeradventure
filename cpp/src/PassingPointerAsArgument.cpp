#include <iostream>

using namespace std;

class MyClass {
public:
	//The Pointer can be deleted and the Value Pointed can be changed
	void unprotectedPointer(int* p) {
		*p = 100;
	}

	//The Pointer is Constant but the Value Pointed can be changed
	void protectedPointer(int* const p) {
		*p = 200;
	}

	//The Pointer can be deleted but the Value Pointed remain unchanged
	void protectedValuePointed(const int* p) {
		delete p;
	}

	//The Pointer is Constant and The Value Pointed remain unchanged
	void fullProtectedPointerAndValuePointed(const int* const p) {
		//Can Only read p and *p
	}
};

int main5() {
	MyClass c;

	int* p = new int;

	*p = 10;

	cout << "The value of *p is: " << *p << endl;

	c.unprotectedPointer(p);

	cout << "The value of *p is: " << *p << endl;

	c.protectedPointer(p);

	cout << "The value of *p is: " << *p << endl;

	c.protectedValuePointed(p);

	cout << "The value of *p is: " << *p << endl;

	c.fullProtectedPointerAndValuePointed(p);

	cout << "The value of *p is: " << *p << endl;

}

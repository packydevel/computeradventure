#include <string>
#include <iostream>

using namespace std;

namespace CopyConstructor {

class C {
	static int objectCount;
public:
	C() {
		objectCount++;
		cout << "Constructor C() is called" << endl;
		cout << "The Number of The Objects of the Class C is: " << objectCount << endl;
	}

	C(const C& c) {
		objectCount++;
		cout << "CopyConstructor C(const C& c) is called" << endl;
		cout << "The Number of The Objects of the Class C is: " << objectCount << endl;
	}

	~C() {
		objectCount--;
		cout << "Destructor ~C() is called" << endl;
		cout << "The Number of The Objects of the Class C is: " << objectCount << endl;
	}

	static int getObjectCount() {
		return objectCount;
	}
};

int C::objectCount = 0;

//Passing and returning Object By Value.
//In this case any object passed to the function f if copyconstructed to c so the copyconstructor
//is invoked.
//Then the objectCount is not incremented.
//Instead the destructor is invoked when function f finish because the variable c is
//in local scope and it does not exist anymore outside this scope and so must be destroyed
C f(C c) {
	return c;
}
}

using namespace CopyConstructor;

int main14() {
	cout << "Before creation of any Object of the Class C ..." << endl;
	cout << "The Number of The Objects of the Class C is: "
			<< C::getObjectCount() << endl;

	cout << "Creating object h1 on the stack through simply declaration ..." << endl;

	C h1;

	cout << "Creating object h2 on the stack through the call to Function f ..." << endl;

	//h2 copyconstructed from the return value of the function f so the copyconstructor is invoked.
	//Then the objectCount is not incremented.
	C h2 = f(h1);
}

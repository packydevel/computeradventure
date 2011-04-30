#include <string>
#include <iostream>

using namespace std;

class BitCopyClass {
	static int objectCount;
	int x;
public:
	BitCopyClass() {
		objectCount++;
		cout << "Constructor BitCopyClass() is called" << endl;
		cout << "The Number of The Objects of the class BitCopyClass is: " << objectCount
				<< endl;
	}

	~BitCopyClass() {
		objectCount--;
		cout << "Destructor ~BitCopyClass() is called" << endl;
		cout << "The Number of The Objects of the Class BitCopyClass is: " << objectCount
				<< endl;
	}

	static int getObjectCount() {
		return objectCount;
	}

	int getx() {
		return x;
	}

	void setx(int x) {
		this->x = x;
	}
};

int BitCopyClass::objectCount = 0;

//Passing and returning Object By Value.
//In this case any object passed to the function f if bitcopied to c so no constructor
//is invoked.
//Then the objectCount is not incremented.
//Instead the destructor is invoked when function f finish because the variable c is
//in local scope and it does not exist anymore outside this scope and so must be destroyed
BitCopyClass f(BitCopyClass c) {
	cout << "The Number of The Objects of the class BitCopyClass is: "
			<< c.getObjectCount() << endl;
	return c;
}

int main40() {
	cout << "Before creation of any Object of the class BitCopyClass ..." << endl;
	cout << "The Number of The Objects of the class BitCopyClass is: "
			<< BitCopyClass::getObjectCount() << endl;

	cout << "Creating object h1 on the stack through simply declaration ..."
			<< endl;

	BitCopyClass h1;
	h1.setx(1);

	cout
			<< "Creating object h2 on the stack through the call to Function f ..."
			<< endl;

	//h2 is bitcopied from the return value of the function f so no constructor is invoked.
	//Then the objectCount is not incremented.
	BitCopyClass h2 = f(h1);
	h2.setx(2);

	cout << "The value of the member h1.x is: " << h1.getx() << endl;
	cout << "The value of the member h2.x is: " << h2.getx() << endl;

	BitCopyClass h3 = h2;
	h3.setx(3);

	cout << "The value of the member h1.x is: " << h1.getx() << endl;
	cout << "The value of the member h2.x is: " << h2.getx() << endl;
	cout << "The value of the member h3.x is: " << h3.getx() << endl;
}

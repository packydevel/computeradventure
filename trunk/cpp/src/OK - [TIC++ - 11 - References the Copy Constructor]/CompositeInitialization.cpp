#include <string>
#include <iostream>

using namespace std;

namespace CompositeInitialization {

class BitCopyClass {
	static int objectCount;
public:
	BitCopyClass() {
		objectCount++;
		cout << "Constructor BitCopyClass() is called" << endl;
		cout << "The Number of The Objects of the Class BitCopyClass is: "
				<< objectCount << endl;
	}

	~BitCopyClass() {
		objectCount--;
		cout << "Destructor ~BitCopyClass() is called" << endl;
		cout << "The Number of The Objects of the Class BitCopyClass is: "
				<< objectCount << endl;
	}

	static int getObjectCount() {
		return objectCount;
	}
};

int BitCopyClass::objectCount = 0;

class CopyConstructorClass {
	static int objectCount;
public:
	CopyConstructorClass() {
		objectCount++;
		cout << "Constructor CopyConstructorClass() is called" << endl;
		cout
				<< "The Number of The Objects of the Class CopyConstructorClass is: "
				<< objectCount << endl;
	}

	CopyConstructorClass(const CopyConstructorClass& c) {
		objectCount++;
		cout
				<< "copyconstructor CopyConstructorClass(const CopyConstructorClass& c) is called"
				<< endl;
		cout
				<< "The Number of The Objects of the Class CopyConstructorClass is: "
				<< objectCount << endl;
	}

	~CopyConstructorClass() {
		objectCount--;
		cout << "Destructor ~CopyConstructorClass() is called" << endl;
		cout
				<< "The Number of The Objects of the Class CopyConstructorClass is: "
				<< objectCount << endl;
	}

	static int getObjectCount() {
		return objectCount;
	}
};

int CopyConstructorClass::objectCount = 0;

class Composite {
	//Embedded objects
	BitCopyClass bcp;
	CopyConstructorClass ccc;
};
}

using namespace CompositeInitialization;

int main15() {
	cout << "Before creation of any Object of the Class BitCopyClass ..."
			<< endl;
	cout << "The Number of The Objects of the Class BitCopyClass is: "
			<< BitCopyClass::getObjectCount() << endl;

	cout
			<< "Before creation of any Object of the Class CopyConstructorClass ..."
			<< endl;
	cout << "The Number of The Objects of the Class CopyConstructorClass is: "
			<< CopyConstructorClass::getObjectCount() << endl;

	cout
			<< "Creating object ci1 of the Class Composite on the stack through simply declaration ..."
			<< endl;

	Composite ci1;

	cout
			<< "Creating object ci2 of the Class Composite on the stack through copy of the object ci1  ..."
			<< endl;

	//Starting from Class Composite the compiler recursively calls the copy-constructors for all the
	//member objects and base classes. That is, if the member object also contains another object,
	//its copy-constructor is also called. So in this case, the compiler calls the copy-constructor for
	//BitCopyClass and for CopyConstructorClass.
	//But BitCopyClass have not copyconstructor so the compiler will generate automatically a default
	//copyconstructor that will perform a bitcopy.
	Composite ci2 = ci1;
}

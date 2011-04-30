#include <string>
#include <iostream>

using namespace std;

class CopyConstructorClass {
	static int objectCount;
public:
	/*
	DefaultConstructorClass() {
		objectCount++;
		cout << "Constructor BitCopyClass() is called" << endl;
		cout << "The Number of The Objects of the Class BitCopyClass is: "
				<< objectCount << endl;
	}
	*/

	CopyConstructorClass(const CopyConstructorClass& dcc) {
		objectCount++;
	}

	static int getObjectCount() {
		return objectCount;
	}
};

int CopyConstructorClass::objectCount = 0;

class NoCopyConstructorClass {
	static int objectCount;
};

int NoCopyConstructorClass::objectCount = 0;

int main45() {

	//You cannot create an object of class CopyConstructorClass because you didn't define
	//the default constructor for the class.
	//The compiler see that you have a copyconstructor so it expect that you define a
	//valid constructor for the CopyConstructorClass class.
	//CopyConstructorClass dcc; //ERROR!!! You need to define a valid constructor

	//In this case the compiler will create a default constructor for the NoCopyConstructorClass
	//class because you didn't define any constructor for this class.
	NoCopyConstructorClass noccc1; //OK

	//In this case the object noccc2 will be bitcopied from noccc1.
	//In the thruth the compiler will create for you a default copyconstructor that
	//simply will perform a bitcopy
	NoCopyConstructorClass noccc2 = noccc1; //OK. noccc2 bitcopied from default copyconstructor
}

#include <iostream>

using namespace std;

int getStaticVariable() {
	//This static variable is allocated in a static area memory not in the stack and so the value
	//of the variable is retained between different function calls.
	//The variable i is initialized only once at the first time that the program access to the function.
	//If the program never access to the function so the variable i is never created and never destroyed.
	static int i = 0;

	i++;

	return i;
}

class SimpleClass {
	int i;
	const char* name;
public:
	SimpleClass(const char* name) :
		i(0), name(name) {
		cout << "Creating SimpleClass: " << name << endl;
	}

	~SimpleClass() {
		cout << "Destroying SimpleClass: " << name << endl;
	}

	int getStaticVariable() {
		i++;
		return i;
	}
};

//This is a Global Static Object. This is always initialized before entering in main function.
//Furthermore the variable sc has file scope (internal linkage) that is the variable is not visible
//outside of this file.
static SimpleClass sc("Global Static object sc");

int getMemberDataFromStaticObject() {
	//Once the object sc is created it is retained between different function calls exactly as in
	//the previuos case of the variable i.
	//Make attention that a user-defined must be initialized by constructor and so you must provide
	//some valid constructor to invoke.
	//If the program never access to the function the object sc is never created and never destroyed.
	static SimpleClass sc("Local Static object sc");

	return sc.getStaticVariable();
}

int getMemberDataFromGlobalStaticObject() {
	return ::sc.getStaticVariable();
}

//This function too has file scope (internal linkage).
static void staticFunction() {
	cout << "staticFunction() is visible only inside this file" << endl;
}

int main36() {
	cout << "getStaticVariable() return: " << getStaticVariable() << endl;
	cout << "getStaticVariable() return: " << getStaticVariable() << endl;
	cout << "getStaticVariable() return: " << getStaticVariable() << endl;

	cout << "getMemberDataFromStaticObject() return: "
			<< getMemberDataFromStaticObject() << endl;
	cout << "getMemberDataFromStaticObject() return: "
			<< getMemberDataFromStaticObject() << endl;
	cout << "getMemberDataFromStaticObject() return: "
			<< getMemberDataFromStaticObject() << endl;

	cout << "getMemberDataFromGlobalStaticObject() return: "
			<< getMemberDataFromGlobalStaticObject() << endl;
	cout << "getMemberDataFromGlobalStaticObject() return: "
			<< getMemberDataFromGlobalStaticObject() << endl;
	cout << "getMemberDataFromGlobalStaticObject() return: "
			<< getMemberDataFromGlobalStaticObject() << endl;

	staticFunction();
}


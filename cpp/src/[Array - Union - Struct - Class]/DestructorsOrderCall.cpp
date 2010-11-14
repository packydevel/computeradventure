#include <iostream>

using namespace std;

#define GENERATE_SIMPLE_CLASS(CLASS_NAME) \
class CLASS_NAME { \
public: \
	CLASS_NAME(int i) { \
		cout << "Executing Constructor CLASS_NAME(int) of class: " \
				<< "CLASS_NAME" << endl; \
	} \
\
	~CLASS_NAME() { \
		cout << "Executing Destructor of class: " << "CLASS_NAME" << endl; \
	} \
};

GENERATE_SIMPLE_CLASS(SimpleClass1)
GENERATE_SIMPLE_CLASS(SimpleClass2)
GENERATE_SIMPLE_CLASS(SimpleClass3)
GENERATE_SIMPLE_CLASS(SimpleClass4)

class BaseClass {
public:
	BaseClass(int i) {
		cout << "Executing Constructor BaseClass(int) of class: "
				<< "BaseClass" << endl;
	}

	~BaseClass() {
		cout << "Executing Destructor of class: " << "BaseClass" << endl;
	}
};

class DerivedClassFromBaseClass: public BaseClass {
	SimpleClass1 sc1;
	SimpleClass2 sc2;
public:
	DerivedClassFromBaseClass(int i) :
		sc1(i), sc2(i), BaseClass(i) {
		cout
				<< "Executing Constructor DerivedClassFromBaseClass(int) of class: "
				<< "DerivedClassFromBaseClass" << endl;
	}
};

class DerivedClassFromDerivedClass: public DerivedClassFromBaseClass {
	SimpleClass3 sc3;
	SimpleClass4 sc4;
public:
	DerivedClassFromDerivedClass(int i) :
		sc3(i), sc4(i), DerivedClassFromBaseClass(i) {
		cout
				<< "Executing Constructor DerivedClassFromDerivedClass(int) of class: "
				<< "DerivedClassFromDerivedClass" << endl;
	}
};

int main() {
	cout << "prova";
	DerivedClassFromDerivedClass dcfdc(0);
}

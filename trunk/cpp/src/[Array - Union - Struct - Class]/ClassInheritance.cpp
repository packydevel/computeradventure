#include <iostream>

using namespace std;

class BaseClass {
	int privateInt;
	void privateFunction();

protected:
	int protectedInt;
	void protectedFunction();

public:
	BaseClass(int i) :
		privateInt(i) {
	}
	int publicInt;
	void publicFunction(){};
};

class DerivedClass: public BaseClass {
	int privateInt;
public:
	DerivedClass(int i) :
		BaseClass(i), privateInt(i) {
	}
};

int main30() {
	BaseClass bc(0);
	DerivedClass dc(0);
}

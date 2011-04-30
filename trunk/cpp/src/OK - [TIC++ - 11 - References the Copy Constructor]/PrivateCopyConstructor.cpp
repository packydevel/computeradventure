#include <iostream>

using namespace std;

class PrivateCopyConstructor {
	int x;
	PrivateCopyConstructor(const PrivateCopyConstructor& c);
public:
	PrivateCopyConstructor(int x = 0) :
		x(x) {
	}

	int getX() {
		return x;
	}
};

PrivateCopyConstructor f(PrivateCopyConstructor c);

int main16() {
	PrivateCopyConstructor pcp1;
	cout << "pcp1.x = " << pcp1.getX() << endl;

	//All of the following istructions will fail at compile-time because all of them need the
	//copyconstructor that is private.
	//In addition since you created a user defined copyconstructor, the compiler will not generate
	//one for you.
	//f(pcp1); //ERROR!!! Passing object by value will attempt to call the copyconstructor
	//pcp1 = f(pcp1); //ERROR!!! Return value of f will attempt to call the copyconstructor
	//PrivateCopyConstructor pcp2 = pcp1; //ERROR!!! Assignment will attempt to call the copyconstructor
	//PrivateCopyConstructor pcp3(pcp1); //ERROR!!! Alternative Assignment will attempt to call the copyconstructor

	//If you need anther object of the class PrivateCopyConstructor you have to declare a new one,
	//neither copying from another PrivateCopyConstructor by assignment
	//nor by copying from another function return value
	PrivateCopyConstructor pcp4;
	cout << "pcp4.x = " << pcp4.getX() << endl;
}

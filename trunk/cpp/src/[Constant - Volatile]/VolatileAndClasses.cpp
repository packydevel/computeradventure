#include <iostream>

using namespace std;

class C {
	//i is an int const that must be initialized in initializer list of any constructor.
	//i can not be initialized at the same time of declaration.
	//In this way i keep a constant value in the entire life of the object of the class C
	//but it is possible that i takes different values across different objects of the
	//class C.
	const int i;

	//j is an int compile-time const which must be initialized at the same time of declaration.
	//Once j is initialized it keep a constant value regardless how many object of the class
	//C are created.
	static const int j = 10;

	//p is a Pointer to Const but the ponter itself is a non-const pointer so p does not need
	//to be inizialized in initializer initializer list of any constructor as in the previous
	//case of the inct const i.
	const int* p;

	int k;

	mutable int w;
public:
	C(int i) :
		i(i), k(0), w(0) {
	}

	//This function is a non-cost function so can be called only from a non-const object
	//of the cass C.
	void memberFunction() {
		k++;
	}

	//This function is declared const so can also be called from const object of the class C.
	//All the functions in the class C that doesn’t modify member data should be declared as const.
	void constMemberFunction() const {
		//k++; //ERROR!!! This is a Const Member Function.
	}

	//Although this function is declared const there are two way to change a non-const variable
	//from within the function. One is the so called Cast Away Constness, the other is using
	//a mutable variable.
	//The casting away costness is achievable in two way as you can see in the following code.
	//This is bad practice.
	void discardConstMemberFunction() const {
		//k++; //Error!!! This is a const member function.
		((C*)this)->k++; //OK. Cast Away Constness. Legal but bad practice.
		(const_cast<C*>(this))->k++; //OK. Explicit Cast Away Constness. Legal but bad practice.
		w++;
	}
};

volatile int k;

volatile int f(volatile int* i);

int main() {

}

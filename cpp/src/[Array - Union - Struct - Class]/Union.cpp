#include <iostream>

using namespace std;

//This is a named Simple Union with only member data.
union SimpleUnion {
	char c;
	int i;
	float f;
};

//This is an anonymous Union with only member data and must be declared
//static so it has internal linkage.
static union {
	char c;
	int i;
	float f;
};

//Union can have like an ordinary class, access modifiers, member data,
//member functions, constructors, destructors.
//This union create a unique storage area in each modifier section to,
//to allocate the variables of type int and float.
union ComplexUnion {
private:
	int privateInt;
	float privateFloat;
	void privateFunction();

protected:
	int protectedInt;
	float protectedFloat;
	void protectedFunction();

public:
	ComplexUnion() {
	}

	~ComplexUnion() {
	}

	int publicInt;
	float publicFloat;
	void publicFunction();
};

int main34() {
	SimpleUnion su;

	su.c = 'a';

	cout << "SimpleUnion member su.c is: " << su.c << endl;

	su.i = 0;

	cout << "SimpleUnion member su.c is: " << su.i << endl;

	su.f = 1.1;

	cout << "SimpleUnion member su.f is: " << su.f << endl;

	//Now you will see that only the last value set (float) is correctly
	//interpreted. The char and int value has been overwritten.
	//This is because Union allocate a unique storage area whose size is
	//equal to the max size of its member data.
	cout << "SimpleUnion member su.c is: " << su.c << endl;
	cout << "SimpleUnion member su.i is: " << su.i << endl;
	cout << "SimpleUnion member su.f is: " << su.f << endl;

	::c = 'a';

	cout << "Anonymous Union member ::c is: " << ::c << endl;

	::i = 0;

	cout << "Anonymous Union member ::i is: " << ::i << endl;

	::f = 1.1;

	cout << "Anonymous Union member ::f is: " << ::f << endl;

	//As in the previous case you will see that only the last value set
	//(float) is correctly interpreted.
	cout << "Anonymous Union member ::c is: " << ::c << endl;
	cout << "Anonymous Union member ::i is: " << ::i << endl;
	cout << "Anonymous Union member ::f is: " << ::f << endl;

	ComplexUnion cu;

	cu.publicInt=0;

	cout << "Union member cu.publicInt is: " << cu.publicInt << endl;

	cu.publicFloat=1.1;

	cout << "Union member cu.publicFloat is: " << cu.publicFloat << endl;

	//As in the previous case you will see that only the last value set
	//(float) is correctly interpreted.
	cout << "Union member cu.publicInt is: " << cu.publicInt << endl;
	cout << "Union member cu.publicFloat is: " << cu.publicFloat << endl;
}

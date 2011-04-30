#include <iostream>;

using namespace std;

int main41() {
	void* vp;
	char c;
	int i;
	float f;
	double d;
	// The address of ANY type can be
	// assigned to a void pointer:
	vp = &c;
	vp = &i;
	vp = &f;
	vp = &d;

	//Once you assign to a void* you lose any information about what type it is.
	//This means that before you can use the pointer, you must cast it to the correct type:

	vp = &i;

	// Can't dereference a void pointer:
	// *vp = 3; // Compile-time error
	// Must cast back to int before dereferencing:
	*((int*) vp) = 3;

	cout << "The value of int-casted void pointer vp is: " << *((int*)vp) << endl;

	vp=&c;
	*((char*) vp) = 'C';

	cout << "The value of char-casted void pointer vp is: " << *((char*)vp) << endl;

	vp=&f;
	*((float*) vp) = 1.2f;

	cout << "The value of char-casted void pointer vp is: " << *((float*)vp) << endl;

	vp=&d;
	*((double*) vp) = 2.4E-1;

	cout << "The value of char-casted void pointer vp is: " << *((double*)vp) << endl;
}

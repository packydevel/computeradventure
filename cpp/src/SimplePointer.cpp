#include <iostream>

typedef int* intPointer;

int main3() {
	int x = 0;

	//Only p1 is a pointer. y is an ordinary int variable.
	int* p1, y;

	//*y = 10; //ERROR!!! Invalid use of unary operator * because y is not a pointer.

	//If you need to define more than one pointer of the same type is better
	//to define each one on single line.
	int* p2;

	//If you have a user-defined type for a classical pointer then you can
	//define multiple pointer on the same line.
	intPointer p4 = &x, p5 = &x, p6 = &x;

	*p4 = 10;
	*p5 = 20;
	*p6 = 30;
}

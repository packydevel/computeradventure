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

	//It is possible to execute mathematical operation with address of a pointer but you
	//you must know what you are doing.
	//In the following istructions the address of the variable x is assigned to p1.
	//If you manipulate p1 with p1++ or p1-- then you are assigning to p1 an unknown
	//address memory that can eventually already be occupied or non free in general.
	//It is best practice that a pointer points to a memory address that in such a way
	//was allocated for you by the compiler.
	p1 = &x;
	p1++; //OK. Warning: p1 is pointing an unknown memory address.
	p1--; //OK

	//In this case, as in the previous case, you are manipulating the p2 address with p2++
	//and p2-- but you are pointing to memory addresses that was allocated for you by the
	//compiler. In fact, these memory addresses are allocated for the element of the array
	//a. As long as you will point p2 in range of the addresses allocated to the array a,
	//you will be safe that such address is valid.
	int a[] = { 1, 2, 3, 4, 5 };
	p2 = &a[0];
	p2++; //OK
	p2--; //OK

	p2+=5; //OK. Legal but out of range.
}

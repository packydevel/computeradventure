#include <iostream>

int main3()
{
	int x = 0;
	const int y = 10;
	int z = 100;

	//Defining a Pointer to Constant
	const int* p1 = 0;

	p1 = &x; //OK
	//*p1 = 100; //ERROR!!! This pointer make the object pointed constant

	p1 = &y; //OK
	//*p1 = 100; //ERROR!!! This pointer make the object pointed constant

	//Defining a Constant Pointer
	int* const p2 = &x;

	//p2 = &z; //ERROR!!! This pointer is costant
	*p2 = 200;

	//Defining a Constant Pointer pointing to Constant
	const int* const p3 = &x;

	//p3 = &y; //ERROR!!! This pointer is costant
	//*p3 = 1000; //ERROR!!! This pointer make the object pointed constant

}

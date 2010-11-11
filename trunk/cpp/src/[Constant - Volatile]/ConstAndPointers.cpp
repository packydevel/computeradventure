#include <iostream>

using namespace std;

int main23() {
	int i = 0;
	int j = 0;

	//p1 is a Pointer to Constant. This definition must be read as
	//"p1 is a pointer, which points to a const int".
	//Here, no initialization is required because you’re saying that p1
	//can point to anything (const or not const), but the thing it points to
	//cannot be changed.
	//This definition of a Pointer to Constant is to be preferred.
	const int* p1;

	//p2 also is a Pointer to Constant. This is an alternative syntax definition
	//that must be read "p2 is a const pointer to an int".
	//The effect is the same as the previous definition.
	//To prevent this confusion you should probably choose the first form
	int const* p2;

	//It is possible to set the address of the pointers p1 and p2
	p1 = &i;
	p2 = &j;
	//*p1=10; //ERROR!!! It is not possbile to change the value pointed.
	//*p2=10; //ERROR!!! It is not possbile to change the value pointed.

	//It is possbile to change the address of the pointers p1 and p2
	p1 = &i;
	p2 = &j;

	//p3 is a Const Pointer. This definition must be read as
	//"p3 is a pointer, which is const, that points to an int".
	//Since p3 is a const it must be declared and defined at the same time.
	//The value pointed by p3 can be changed.
	int* const p3 = &i;

	//p3=&j; //ERROR!!! The address of p3 can not be changed.

	*p3 = 10; //OK. The value pointed by p3 can be changed.

	//p4 is a Const Pointer to a Constant.
	//Since p4 is a const it must be declared and defined at the same time.
	//Now neither the pointer nor the object pointed can be changed.
	//This definition of a Const Pointer to a Constant is to be preferred.
	const int* const p4 = &i;

	//p5 also is a Const Pointer to a Constant.
	//This is an alternative syntax definition.
	//The effect is the same as the previous definition.
	//To prevent this confusion you should probably choose the first form.
	int const* const p5 = &j;

	//p4 = &j; //ERROR!!! The address of p4 can not be changed.
	//p5 = &i; //ERROR!!! It is not possbile to change the value pointed.

	//*p4 = 20; //ERROR!!! The address of p5 can not be changed.
	//*p5 = 20; //ERROR!!! It is not possbile to change the value pointed.

	const int z = 0;

	//p6 is not a Pointer to Constant that attempt to point to a constant.
	//This will cause a compile-time error because you’re saying you might
	//change the object via the pointer.
	//int* p6 = &z; //ERROR!!!

	//However C++ does not protect you at all. In fact it is possible, via
	//the static cast to break this safety mechanism.
	//You shoud not use this definition.
	int* p7 = (int*) &z; //OK. Legal but bad practice.

	//The pointer p8 points to the address of the first character of the string
	//"character array" that is a character array.
	//This is technically an error because a character array is created by the
	//compiler as a constant character array.
	//As a result you would not be able to modify any character of the string
	//using the pointer, although not all compilers enforce this correctly.
	//If any compiler lets you to modify any character of the string you must
	//know that the result is unpredictible.
	//This behavior of such a compiler is allowed for compatibility reason of
	//existing C code.
	char* p8 = "character array";

	*(++p8)='X'; //OK. With actual compiler this works. Legal but bad practice.
}

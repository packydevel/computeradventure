#include <iostream>

using namespace std;

class MyClass {
public:
	//The Pointer can be deleted and the Value Pointed can be changed
	void passSimplePointer(int* p) {
		p++;
		*p = 100;
		//delete p; //OK. If p was created on the heap it can be deleted.
	}

	//The Pointer is Constant but the Value Pointed can be changed
	void passConstPointer(int* const p) {
		//p++; //ERROR!!!
		*p = 200;
		//delete p; //OK. If p was created on the heap it can be deleted no matter if it is a Const Pointer.
	}

	//The Pointer can be deleted but the Value Pointed remain unchanged
	void passPointerToConst(const int* p) {
		p++;
		//*p = 300; //ERROR!!!
		//delete p; //OK. If p was created on the heap it can be deleted no matter if it is a Pointer to Const.
	}

	//The Pointer is Constant and The Value Pointed remain unchanged
	void passConstPointerToConst(const int* const p) {
		//p++; //ERROR!!!
		//*p = 400; //ERROR!!!
		//delete p; //OK. If p was created on the heap it can be deleted no matter if it is a Const Pointer to Const.
	}

	//Pointer p is passed as non-const pointer.
	//Address of p can be changed.
	//Value pointed by p can be changed.
	//If p was created on the heap it can be deleted.
	//This function can return the same p.
	int* getSimplePointerFromSimplePointer(int* p) {
		*p++;
		return p;
	}

	//Pointer p is passed as non-const pointer.
	//Address of p can be changed.
	//Value pointed by p can be changed.
	//If p was created on the heap it can be deleted.
	//This function can return the p as Const Pointer.
	int* const getConstPointerFromSimplePointer(int* p) {
		*p++;
		return p;
	}

	//Pointer p is passed as non-const pointer.
	//Address of p can be changed.
	//Value pointed by p can be changed.
	//If p was created on the heap it can be deleted.
	//This function can return p as Pointer to Const.
	const int* getPointerToConstFromSimplePointer(int* p) {
		*p++;
		return p;
	}

	//Pointer p is passed as non-const pointer.
	//Address of p can be changed.
	//Value pointed by p can be changed.
	//If p was created on the heap it can be deleted.
	//This function can return p as Const Pointer to Const.
	const int* const getConstPointerToConstFromSimplePointer(int* p) {
		*p++;
		return p;
	}

	//Pointer p is passed as Const Pointer.
	//Address of p can not be changed.
	//Value pointed by p can be changed.
	//If p was created on the heap it can be deleted.
	//This function can return p as Simple Pointer.
	int* getSimplePointerFromConstPointer(int* const p) {
		//p++; //ERROR!!!
		(*p)++;
		return p;
	}

	//Pointer p is passed as Const Pointer.
	//Address of p can not be changed.
	//Value pointed by p can be changed.
	//If p was created on the heap it can be deleted.
	//This function can return the same p.
	int* const getConstPointerFromConstPointer(int* const p) {
		//p++; //ERROR!!!
		(*p)++;
		return p;
	}

	//Pointer p is passed as non-const pointer.
	//Address of p can not be changed.
	//Value pointed by p can be changed.
	//If p was created on the heap it can be deleted.
	//This function can return p as Pointer to Const.
	const int* getPointerToConstFromConstPointer(int* const p) {
		//p++; //ERROR!!!
		(*p)++;
		return p;
	}

	//Pointer p is passed as non-const pointer.
	//Address of p can not be changed.
	//Value pointed by p can be changed.
	//If p was created on the heap it can be deleted.
	//This function return a Const Pointer to Const.
	const int* const getConstPointerToConstFromConstPointer(int* const p) {
		//p++; //ERROR!!!
		(*p)++;
		return p;
	}

	//Pointer p is passed as Pointer to Const.
	//Address of p can be changed.
	//Value pointed by p can not be changed.
	//If p was created on the heap it can be deleted.
	//This function can return the same p.
	//This function can not return p as Simple Pointer or as Const Pointer
	const int* getPointerToConstFromPointerToConst(const int* p) {
		p++;
		//(*p)++; //ERROR!!!
		return p;
	}

	//Pointer p is passed as Const Pointer.
	//Address of p can not be changed.
	//Value pointed by p can be changed.
	//If p was created on the heap it can be deleted.
	//This function can return p as Const Pointer to Const.
	//This function can not return p as Simple Pointer or as Const Pointer
	const int* const getConstPointerToConstFromPointerToConst(const int* p) {
		p++;
		//(*p)++; //ERROR!!!
		return p;
	}

	//Pointer p is passed as Const Pointer to Const.
	//Address of p can not be changed.
	//Value pointed by p can not be changed.
	//If p was created on the heap it can be deleted.
	//This function can return p as Pointer to Const.
	//This function can not return p as Simple Pointer or as Const Pointer
	const int* getPointerToConstFromConstPointerToConst(const int* const p) {
		//p++; //ERROR!!!
		//(*p)++; //ERROR!!!
		return p;
	}

	//Pointer p is passed as Const Pointer to Const.
	//Address of p can not be changed.
	//Value pointed by p can not be changed.
	//If p was created on the heap it can be deleted.
	//This function can return the same p.
	//This function can not return p as Simple Pointer or as Const Pointer
	const int* const getConstPointerToConstFromConstPointerToConst(
			const int* const p) {
		//p++; //ERROR!!!
		//(*p)++; //ERROR!!!
		return p;
	}
};

int main5() {
	MyClass c;

	int* p = new int;

	*p = 10;

	cout << "The value of *p is: " << *p << endl;

	c.passSimplePointer(p);

	cout << "The value of *p is: " << *p << endl;

	c.passConstPointer(p);

	cout << "The value of *p is: " << *p << endl;

	c.passPointerToConst(p);

	cout << "The value of *p is: " << *p << endl;

	c.passConstPointerToConst(p);
}

#include <iostream>

using namespace std;

int* getValidPointer(int* p) {
	(*p)++;

	return p;
}

int* getDanglingPointer(int* p) {
	(*p)++;
	int x = *p;
	int* newp = &x;

	return newp;
}

int* getAnotherDanglingPointer(int* p) {
	delete p;
	return p;
}

int main7() {

	int x = 0;
	int* p = &x;

	cout << "The value of x is: " << x << endl;

	cout << "The value of *p is: " << *p << endl;

	cout << "The value of p is: " << p << endl;

	//The Pointer p1 is valid because getValidPointer return the same address of p.
	//In fact now p1 and p are two pointers that point to the same address.
	int* p1 = getValidPointer(p);

	cout << "The value of x is: " << x << endl;

	cout << "The value of *p1 is: " << *p1 << endl;

	cout << "The value of p1 is: " << p1 << endl;

	//The Pointer p2 is dangling because getDanglingPointer return the address of
	//Pointer newp that ha been destroyed automatically when the function finish.
	//p2 is pointing to an address that is deallocated.
	//Now dereferencing p2 gets an unpredicible behavior. Most likely in this simple
	//case dereferencing will get the expected value of 2 because the address in p2
	//has not been yet reallocated and the contents modified.
	int* p2 = getDanglingPointer(p);

	cout << "The value of x is: " << x << endl;

	cout << "The value of *p2 is: " << *p2 << endl;

	cout << "The value of p2 is: " << p2 << endl;
}

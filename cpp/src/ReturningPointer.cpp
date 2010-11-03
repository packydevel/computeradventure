#include <iostream>

using namespace std;

int* getExistingPointer(int* p) {
	++*p;

	return p;
}

int* getNotExistingPointer(int* p) {
	int x = ++*p;
	int* newp = &x;

	return newp;
}

int main() {

	int x = 0;
	int* p = &x;

	cout << "The value of x is: " << x << endl;

	cout << "The value of *p is: " << *p << endl;

	cout << "The value of p is: " << p << endl;

	int* p1 = getExistingPointer(p);

	cout << "The value of x is: " << x << endl;

	cout << "The value of *p is: " << *p << endl;

	cout << "The value of p is: " << p << endl;

	cout << "The value of *p1 is: " << *p1 << endl;

	cout << "The value of p1 is: " << p1 << endl;

	int* p2 = getNotExistingPointer(p);

	cout << "The value of x is: " << x << endl;

	cout << "The value of *p is: " << *p << endl;

	cout << "The value of p is: " << p << endl;

	cout << "The value of *p2 is: " << *p2 << endl;

	cout << "The value of p2 is: " << p2 << endl;
}

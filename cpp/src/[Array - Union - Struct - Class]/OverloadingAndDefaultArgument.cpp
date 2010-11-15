#include <iostream>

using namespace std;

void f() {
	cout << "Explicitly called f()" << endl;
}

//This overloading is correct but invoking f() is ambiguous with respect
//to the previous function declaration.
//Both function f() and f(int) are unusable despite correctly defined.
void f(int i = 0) {
	cout << "Explicitly called f(int i = 0)" << endl;
}

//In this case also the overloading is correct but invoking f(int) is
//ambiguous with respect to the previous function declaration.
//All the functions f() and f(int) and f(int,int) are unusable despite
//correctly defined.
void f(int i, int j = 0) {
	cout << "Calling f(int i, int j = 0)" << endl;
}

//In this other case both the overloading is correct and the invocation
//makes no ambiguity.
void f(int i, int j, int k) {
	cout << "Calling f(int i, int j, int k)" << endl;
}

//In this last case overloading is correct, default value declaration makes
//no ambiguity.
void f(int i, int j, int k, int l, int m = 0, int n = 0) {
	cout << "Calling f(int i, int j, int k, int l, int m = 0, int n = 0)" << endl;
}

int main() {
	//f(); //ERROR!!! Ambiguous invocation.

	//f(0); //ERROR!!! Ambiguous invocation.

	f(0, 0, 0); //OK

	f(0, 0, 0, 0); //OK
}

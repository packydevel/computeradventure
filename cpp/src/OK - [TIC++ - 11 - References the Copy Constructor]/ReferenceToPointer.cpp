#include <iostream>
using namespace std;

void increment(int*& i) {
	i++;
}

int main12() {
	int x = 0;
	int* i = &x;

	cout << "i = " << i << endl;

	//The pointer address is incremented not the value pointed
	increment(i); //OK

	cout << "i = " << i << endl;

	//dereferencing i return a non predicible value
	cout << "The actual dreferenced value is *i = " << *i << endl;

	//dereferencing (i-1) return the previous value when i was pointing to x
	cout << "The previous dereferenced value is untouched, *(i-1) = " << *(i-1) << endl;
}

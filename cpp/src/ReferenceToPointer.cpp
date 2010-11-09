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
}

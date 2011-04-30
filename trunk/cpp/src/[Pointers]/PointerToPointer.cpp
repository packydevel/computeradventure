#include <iostream>
using namespace std;

void increment(int** pip) {
	(*pip)++;
}

int main42() {
	int x = 0;
	int* ip = &x;

	cout << "ip = " << ip << endl;

	//The pointer address is incremented not the value pointed
	increment(&ip); //OK

	cout << "ip = " << ip << endl;

	//dereferencing i return a non predicible value
	cout << "The actual dreferenced value is *ip = " << *ip << endl;

	//dereferencing (i-1) return the previous value when i was pointing to x
	cout << "The previous dereferenced value is untouched, *(ip-1) = " << *(ip - 1) << endl;

	int** pip = &ip;
	int*** ppip = &pip;
	int**** pppip = &ppip;
	int***** ppppip = &pppip;

	cout << "The int pointer value ip = " << ip << endl;
	cout << "Dereferencing ip, *ip = " << *ip << endl;
	cout << "The pointer to int pointer value is pip = " << pip << endl;
	cout << "Dereferencing pip, *pip = " << *pip << endl;
	cout << "The pointer to pointer to int pointer value is ppip = " << ppip << endl;
	cout << "Dereferencing ppip, *ppip = " << *ppip << endl;
	cout << "The pointer to pointer to pointer to int pointer is pppip = " << pppip << endl;
	cout << "Dereferencing pppip, *pppip = " << *pppip << endl;
	cout << "The pointer to pointer to pointer to pointer int pointer is ppppip = " << ppppip << endl;
	cout << "Dereferencing ppppip, *ppppip = " << *ppppip << endl;

	cout << "1 time dereferencing pppp1p, *ppppip = " << *ppppip << endl;
	cout << "2 times dereferencing pppp1p, **ppppip = " << **ppppip << endl;
	cout << "3 times dereferencing pppp1p, ***ppppip = " << ***ppppip << endl;
	cout << "4 times dereferencing pppp1p, ****ppppip = " << ****ppppip << endl;
	cout << "5 times dereferencing pppp1p, *****ppppip = " << *****ppppip << endl;
}

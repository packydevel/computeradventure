//This const array i means "a piece of storage that cannot be changed".
//However, the value cannot be used at compile time because the compiler
//is not required to know the contents of the storage at compile time.

const int i[] = { 1, 2, 3, 4 };

//float f[i[3]]; //ERROR!!! The value of i[3] cannot be used since it is unknown at compile-time

struct S {
	int i, j;
};

//This const struct has the same mean of the previous const array
const S s[] = { { 1, 2 }, { 3, 4 } };

//float f[s[1].j]; //ERROR!!! The value of s[1].j cannot be used since it is unknown at compile-time

//This const is known at compile-time
const int k = 10;

class C {
public:
	C(int i, int j) :
		i(i), j(j) {
	}
	int i, j;
};

const C c[] = { C(1, 2), C(3, 4) };

//float f[c[1].j]; //ERROR!!! The value of c[1].j cannot be used since it is unknown at compile-time

double a[k]; //OK. It is possible to use const k

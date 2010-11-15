#include <stdio.h>

int x = 3;

template<int N>
struct Factorial
{
	enum
	{
		value = N * Factorial<N - 1>::value
	};
};

template<>
struct Factorial<0>
{
	enum
	{
		value = 1
	};
};

// Factorial<4>::value == 24
// Factorial<0>::value == 1
void foo()
{
	int x = Factorial<4>::value; // == 24
	int y = Factorial<0>::value; // == 1

	printf("The value of x: %d\n", x);
	printf("The value of y: %d\n", y);
}

int main9()
{
	foo();
}

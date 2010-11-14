/*
 * test.cpp
 *
 *  Created on: 26/ott/2010
 *      Author: packyuser
 */
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

class Person
{
private:
	int age;
	int height;

public:

	void walk();
    int getAge() const;
    void setAge(int age);
};

int main9()
{
	foo();
	int x = 5;
	printf("%d\n", x);
	printf("%d\n", ::x);

	int a[] =
	{ 1, 2, 3, 4, 5 };

	int* p = &a[0];

	printf("%d, %p\n", *p, p);

	++p;

	printf("%d, %p\n", *p, p);

	int* y = &x;

	printf("%d, %p\n", *y, y);
	printf("%d, %p\n", *(y - 1), ++y);

	Person person1, person2;
	person1.setAge(32);

	printf("%d\n", person1.getAge());

	person2.setAge(40);

	printf("%d\n", person1.getAge());

	Person* personPointer = new Person;

	printf("Person Pointer is: %p\n", personPointer);

	delete personPointer;

	printf("Person Pointer is: %p\n", personPointer);

	int r[] = {1,2,3};
	int s[3];

	//s=&r;

}

int Person::getAge() const
{
    return age;
}

void Person::setAge(int age)
{
    this->age = age;
}




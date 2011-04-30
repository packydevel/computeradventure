#include <iostream>

using namespace std;

//Each translation unit can contain only one unnamed namespace.
//This is the preferred way to obtain internal linkage. Using static is deprecated.
//The object declared in the unnamed namespace are available in the translation
//unit without scope qualifier.
namespace {
int i;

//It is possible to nest unnamed namespace into another unnamed namespace but you
//can not declare object with the same name of other object in the enclosing namespace.
namespace {
//int i; //ERROR!!! The variable i is already defined in enclosing namespace.
int j; //OK
}

namespace NestedNamedNamespace {
int i;

namespace {
int i;
int j;
int k;
}
}
}

int main44() {
	i = 0;

	cout << "The value of the i in unnamed namespace is: " << i << endl;

	j = 0;

	cout
			<< "The value of the j in nested unnamed namespace inside unnamed namespace is: "
			<< j << endl;

	NestedNamedNamespace::i = 0;

	cout
			<< "The value of the i in nested named namespace inside unnamed namespace is: "
			<< NestedNamedNamespace::i << endl;

	NestedNamedNamespace::k = 0;

	cout
			<< "The value of the k in nested unnamed namespace inside nested named namespace inside unnamed namespace is: "
			<< NestedNamedNamespace::k << endl;

	NestedNamedNamespace::j = 0;
}

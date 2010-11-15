class SimpleClass {
public:
	void overloadedFunction(void) {
	}

	//Since a function can be invoked ignoring the return value, then if
	//overloading by changing only the return value was allowed, you could
	//invoke the sc.overloadedFunction() but the compiler could not disambiguate
	//which function you are referring to.
	//It is not possible to overload function changing only the return value.
	//int overloadedFunction(void); ERROR!!! The signature is the same.

	//This overloading is possible because the signature has changed.
	void overloadedFunction(int) {
	} //OK. The signature has changed.
};

int main33() {
	SimpleClass sc;

	sc.overloadedFunction();
	sc.overloadedFunction(0);
}

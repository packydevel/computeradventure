/*
 * The use of const to specify function arguments and return values is another
 * place where the concept of constants can be confusing. If you are passing
 * objects by value, specifying const has no meaning to the client (it means
 * that the passed argument cannot be modified inside the function). If you
 * are returning an object of a user-defined type by value as a const, it
 * means the returned value cannot be modified. If you are passing and
 * returning addresses, const is a promise that the destination of the address
 * will not be changed.
 */

//The formal parameter i is declared const so it can not be modified inside
//the function.
//Since the parameter i is passed by value, the original variable passed could
//never be modified by function f1 and so specifying const in function signature
//is useful only for the function creator, not for the function caller.
//By this signature, the function creator keep in mind that he don't want to
//manipulate in any way the value passed.
void f1(const int i) {
	//i++; ERROR!!! The formal parameter can not be modified.
}

int f2() {
	return 0;
}

//Using const in return by value of a function f3 is meaningless for builtin types.
//In fact with this definition you say that a function’s return value is const.
//you are promising that the original variable (inside the function frame) will not
//be modified but it would be true also if you did not specify const because
//you are returning a result by value and so the function inside the function is
//copied.
const int f3() {
	return 0;
}

class C {
	int i;
public:
	C(int i = 0) :
		i(i) {
	}

	void modify() {
		i++;
	}
};

C f4() {
	return C();
}

const C f5() {
	return C();
}

void f6(C& c) {
	c.modify();
}

int main() {
	const int j = f2();

	//j++; //ERROR!!! j is defined const.

	int k = f3();
	k++; //OK. Does not matter that return value of f3 is defined const.

	f4() = C(1);

	//f5() = C(1);

	//f6(f5());
	//f5().modify();

	//f6(f5());
}

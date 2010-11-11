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
//you are returning a result by value and so the value inside the function is
//copied.
//For best practice avoid use of const return value for builtin types.
const int f3() {
	return 0;
}

class C {
public:
	int i;

	static const int k = 0;

	C(int i = 0) :
		i(i) {
	}

	void modify() {
		i++;
	}

	int getI() {
		return i;
	}
};

//f4 return a non-const object C that can be used as lvalue or can be modified through
//its accessible member data or its accessible member functions
C f4() {
	return C();
}

//f5 return a const object C that can not be used as lvalue and can not be modified
//through its accessible member data or its accessible member functions.
const C f5() {
	return C();
}

void f6(C& c) {
	c.modify();
}

//f7 return a Pointer to Character Array which is stored by the compiler in a static area
//as constant.
//Since f7 return a Simple Pointer to char you could modify the string returned although it
//has stored as constant
//This is bad practice.
char* f7() {
	return "This function return a Pointer to Character Array";
}

//f8 return a Pointer to Const Character Array.
//Since f8 return a Const Pointer you can not modify the string returned
//This is best practice.
const char* f8() {
	return "This function return a Pointer to Character Array";
}

int main24() {
	const int j = f2();

	//j++; //ERROR!!! j is defined const.

	int k = f3();
	k++; //OK. Does not matter that return value of f3 is defined const.

	//The following istruction that use f4 as as an lvalue is legal but is bug code.
	//f4 return a temporary object that is cleaned up by the new object C(1).
	//However the compiler does not generate any error.
	//Furthermore the original temporary object returned by f4 is lost.
	f4() = C(1); //OK. Legal but bad practice.

	//As in the previous case you are modifying a temporary object.
	//However the compiler does not generate any error.
	//Furthermore the original temporary object returned by f4 is been modified and such
	//changes are lost.
	f4().modify(); //OK. Legal but bad practice.
	f4().getI(); //OK. Legal but bad practice.

	//f5() = C(1); //ERROR!!! f5 return a const object
	//f5().modify(); //ERROR!!! f5 return a const object
	//f5().getI(); //ERROR!!! f5 return a const object
	(f5().k);

	//In the following istruction f4 return a non-const object but it is passed immediately
	//to function f6. In this case the object returned from f4 is a temporary object and the
	//the compiler by default make the temporary objects as const.
	//Since a temporary object is const it can not be passed by reference to a function f6
	//as a non-const reference.
	//See later about references ...
	//f6(f4()); //ERROR!!! f4 return a non-const object but it is passed by reference to f6as non-const reference

	//In the following istruction f5 return a const object and as in the previous case it is
	//a temporary objects that the compiler makes const and in the end it can not be passed
	//by reference to a function f6 as a non-const reference.
	//f6(f5()); //ERROR!!! f5 return a const object but it is passed by reference to f6 as non-const reference

	f7()[0]='X'; //OK. Legal but bad practice.

	//f8()[0]='X'; //ERROR!!! f8 return a const string.
}

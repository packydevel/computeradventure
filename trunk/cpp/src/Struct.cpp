#include <iostream>

using namespace std;

//Simple declaration of SimpleStruct must be place before declaration of friend global function or
//friend member function or friend struct because SimpleStruct must be visible by friend object.
//
struct SimpleStruct;

//SimpleStructFriendFunction must be declared here between simple declaration of SimpleStruct and
//full declaration of SimpleStruct.
struct SimpleStructFriendFunction {
	//To make possible for the public function publicFriendFunction which will be declared friend in
	//SimpleStruct to take an argument of type SimpleStruct it is crucial that it be only declared
	//here and not defined. The reason will be explained later.
	void publicFriendFunction(SimpleStruct ss);
	void publicFriendFunction(SimpleStruct* ssp);
};

//As in the previous case FriendStruct must be declared here between simple declaration of SimpleStruct and
//full declaration of SimpleStruct.
struct FriendStruct {
	//And again to make possible for the public function publicFunction to take an argument of type SimpleStruct
	//it is crucial that it be only declared it and not defined.
	void publicFunction(SimpleStruct ss);
};

//SimpleStruct must be newly declare here after the friend member function declaration and after the
//friend struct because this friend element must be visible inside SimpleStruct in order to be
//declared friend.
struct SimpleStruct {
	//All member data that are not static const can be initialized only in the constructor
	//initializer list.
	//There is no required order for access specifiers, and they may appear more than once.
	//They affect all the members declared after them and before the next access specifier.
	//The following members are public by default.
	//Using public modifier is only meaningful.
public:
	//int publicI = 0; //ERROR!!!
	int publicInt;
	int getPublicInt();
	int getProtectedInt();
	int getPrivateInt();

	//Does not matter if you use friend declarations in section public or protected or private
	//because friend declaration is not a member declaration. Friend declaration means that an
	//outside global function or other outside member function or other outside struct or class
	//can access all member data and member function of this struct.
	//The friend declaration are never visible from the outside of this struct.
	friend void friendFunction(SimpleStruct ss);
	friend void SimpleStructFriendFunction::publicFriendFunction(
			SimpleStruct ss);
	friend void SimpleStructFriendFunction::publicFriendFunction(
			SimpleStruct* ssp);
	friend struct FriendStruct;

protected:
	//int protectedI = 0; //ERROR!!!
	int protectedInt;
	void protectedFunction();

private:
	//int privateI = 0; //ERROR!!!
	int privateInt;
	void privateFunction();
};

void friendFunction(SimpleStruct ss) {
	ss.publicInt = 0;
	ss.protectedInt = 0;
	ss.privateInt = 0;
	cout << "The value of the public member ss.publicInt is: " << ss.publicInt
			<< endl;
	cout << "The value of the protected member ss.protectedInt is: "
			<< ss.protectedInt << endl;
	cout << "The value of the private member ss.privateInt is: "
			<< ss.privateInt << endl;
}

//In this case the overloaded public function publicFriendFunction which will also be declared friend in SimpleStruct
//takes an argument that is a pointer to an object of type SimpleStruct that was previously completely declared although
//not completely defined.
//This is already sufficient to make possible to declare and define this public function at the same time
//because in this case the argument is a pointer and the compiler always know the size of an object of the type
//pointer regardless the type of the object pointed.
void SimpleStructFriendFunction::publicFriendFunction(SimpleStruct* ssp) {
	ssp->publicInt = 3;
	ssp->protectedInt = 3;
	ssp->privateInt = 3;
	cout << "The value of the public member ss.publicInt is: "
			<< ssp->publicInt << endl;
	cout << "The value of the protected member ss.protectedInt is: "
			<< ssp->protectedInt << endl;
	cout << "The value of the private member ss.privateInt is: "
			<< ssp->privateInt << endl;
}

int SimpleStruct::getPublicInt() {
	return publicInt;
}

int SimpleStruct::getProtectedInt() {
	return protectedInt;
}

int SimpleStruct::getPrivateInt() {
	return privateInt;
}

//Be careful that the public function publicFriendFunction which was declared friend in
//SimpleStruct take an argument that is a SimpleStruct that will be passed by value. This is crucial
//because C++ to be able to pass an object by value have to know how much space to allocate.
//At the point of the declaration of SimpleStructFriendFunction the compiler does not know the entire
//definition of SimpleStruct and so it can not calculate how much space to allocate for an object of
//type SimpleStruct.
//For this reason publicFriendFunction can be defined here after the entire definition os SimpleStruct
void SimpleStructFriendFunction::publicFriendFunction(SimpleStruct ss) {
	ss.publicInt = 1;
	ss.protectedInt = 1;
	ss.privateInt = 1;
	cout << "The value of the public member ss.publicInt is: " << ss.publicInt
			<< endl;
	cout << "The value of the protected member ss.protectedInt is: "
			<< ss.protectedInt << endl;
	cout << "The value of the private member ss.privateInt is: "
			<< ss.privateInt << endl;
}

//As in the previous case, after the entire definition of SimpleStruct is possible to define the public
//member function publicFunction that take an argument of type SimpleStruct passed by value.
void FriendStruct::publicFunction(SimpleStruct ss) {
	ss.publicInt = 2;
	ss.protectedInt = 2;
	ss.privateInt = 2;
	cout << "The value of the public member ss.publicInt is: " << ss.publicInt
			<< endl;
	cout << "The value of the protected member ss.protectedInt is: "
			<< ss.protectedInt << endl;
	cout << "The value of the private member ss.privateInt is: "
			<< ss.privateInt << endl;
}

int main27() {
	SimpleStruct ss;
	SimpleStruct* ssp = &ss;

	//ss.protectedInt = 0; //ERROR!!! Member data protectedInt is protected
	//ss.privateInt = 0; //ERROR!!! Member data privateInt is private

	friendFunction(ss);

	SimpleStructFriendFunction ssff;
	ssff.publicFriendFunction(ss);
	ssff.publicFriendFunction(ssp);

	FriendStruct fs;
	fs.publicFunction(ss);
}

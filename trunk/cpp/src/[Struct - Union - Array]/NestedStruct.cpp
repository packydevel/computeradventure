#include <iostream>

using namespace std;

struct SimpleStruct {
public:
	SimpleStruct(int i = 0) :
		i(i) {
	}

	//The actual use of nested struct is conforming to the specifications of C++0X and then
	//it is different respect to the Friend Nested Struct from Tbook hinking in Java
	//(Bruce Eckel)
	struct NestedStruct {
	public:

		//Argument ss is passed as const because this function does not modify the object
		int getSimpleStructMemberData(const SimpleStruct& ss) {
			return ss.i;
		}

		void incrementNestedStructMemberData(SimpleStruct& ss) {
			ss.incrementSimpleStructMemberData();
		}
	};

private:
	int i;
	void incrementSimpleStructMemberData() {
		++i;
	}
};

int main28() {
	SimpleStruct ss;
	SimpleStruct::NestedStruct ns;

	cout << "The value of the SimpleStruct::i is: "
			<< ns.getSimpleStructMemberData(ss) << endl;

	ns.incrementNestedStructMemberData(ss);

	cout << "The value of the SimpleStruct::i is: "
			<< ns.getSimpleStructMemberData(ss) << endl;
}

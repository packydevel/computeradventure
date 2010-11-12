#include <iostream>

using namespace std;

struct SimpleStruct {
public:
	struct NestedStruct {
	public:
		int getSimpleStructMemberData(SimpleStruct ss) {
			return ss.i;
		}

		void incrementNestedStructMemberData(SimpleStruct ss) {
			ss.incrementSimpleStructMemberData();
		}
	};

	struct FriendNestedStruct;

	//friend struct FriendNestedStruct;

	struct FriendNestedStruct {
	public:
		int getSimpleStructMemberData(SimpleStruct ss) {
			return ss.i;
			cout << ss.i;
		}

		void incrementNestedStructMemberData(SimpleStruct ss) {
			ss.incrementSimpleStructMemberData();
		}
	};

private:
	int i;
	void incrementSimpleStructMemberData() {
		++i;
	}
};

//int SimpleStruct::i = 0;

int main() {
	SimpleStruct ss;
	SimpleStruct::FriendNestedStruct fns;
	cout << "The value of the SimpleStruct::i is: "
			<< fns.getSimpleStructMemberData(ss) << endl;
	fns.incrementNestedStructMemberData(ss);
	cout << "The value of the SimpleStruct::i is: "
			<< fns.getSimpleStructMemberData(ss) << endl;
}

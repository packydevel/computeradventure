class C {
public:
	explicit C(int i) {
	}
	;
};

void f(C) {
}

int main() {

	//C c1 = 37; //ERROR!!! The constructor have to be invoked explicitly. No automatic Constructor detection is performed
	C c2 = C(47); //OK
	C c3(57); //OK

	c2 = C(67); //OK

	//f(77); //ERROR!!! No automatic cast is performed
	f(C(77));
	f(c2);
	f(c3);

	//Automatic argument casting is performed
	C c4 = C(10.0); //OK


}

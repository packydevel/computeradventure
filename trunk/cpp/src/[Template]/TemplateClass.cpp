/*
#include <iostream>

using namespace std;

template<class T, int k = 0>
class TemplateClass {
	T t;
public:
	TemplateClass(T t) :
		t(t) {
	}

	T getT() {
		return t;
	}

	void setT(T t);
};

template<class T, int k = 0>
void TemplateClass<T,k>::setT(T t) {
	this->t = t;
}

int main() {
	TemplateClass<int,1> tci(0);
	TemplateClass<float,1> tcf(0.1);

	cout << "The member tci.t is: " << tci.getT() << endl;
	cout << "The member tcf.t is: " << tcf.getT() << endl;

	tci.setT(1);
	tcf.setT(1.1);

	cout << "The member tci.t is: " << tci.getT() << endl;
	cout << "The member tcf.t is: " << tcf.getT() << endl;
}
*/

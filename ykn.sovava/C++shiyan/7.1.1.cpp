#include <iostream>
using namespace std;
class Base {
protected:
	int n;
public:
	Base(int m) { n = m++; }
	virtual void g1() { cout << "Base::g1()..." << n << endl; g4(); }
	virtual	void g2() { cout << "Base::g2()..." << ++n << endl; g3(); }
	void g3() { cout << "Base::g3()..." << ++n << endl; g4(); }
	void g4() { cout << "Base::g4()..." << ++n << endl; }

};
class Derive :public Base {
	int j;
public:
	Derive(int n1, int n2) :Base(n1) { j = n2; }
	virtual void g1() { cout << "Deri::g1()..." << ++j << endl; g2(); }
	void g3() { cout << "Deri::g2()..." << ++j << endl; g4(); }
};
int main() {
	Derive Dobj(100, 0);
	Base Bobj = Dobj;
	Bobj.g1();
	cout << "------------------" << endl;
	Base* bp = &Dobj;
	bp->g1();
	cout << "------------------" << endl;
	Base& bobj2 = Dobj;
	bobj2.g1();
	cout << "------------------" << endl;
	Dobj.g1();
	return 0;
}
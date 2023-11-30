#include<iostream>
using namespace std;
class A {
public:
	A(int a) :x(a) { cout << "A constructor..." << x << endl; }
	int f() { return ++x; }
	~A() { cout << "destructor A..." << endl; }
private:
	int x;
};
class B :public virtual A {
private:
	int y;
	A Aobj;
public:
	B(int a, int b, int c) :A(a), y(b), Aobj(a) { cout << "B constructor..." << y << endl; }
	int f() {
		A::f();
		Aobj.f();
		return ++y;
	}
	void display() {
		cout << A::f() << "\t";
		cout << Aobj.f() << "\t";
		cout<< f() << endl;
		cout << A::f() << "\t";
		cout << Aobj.f() << "\t";
	}
	~B() { cout << "destructor B..." << endl; }
};
class C :public B {
public:
	C(int a, int b, int c) :B(a, b, c), A(0) { cout << "C constructor..." << endl; }
};
class D :public C, public virtual A {
public:
	D(int a, int b, int c) :C(a, b, c), A(c) { cout << "D constructor..." << endl; }
	~D() { cout << "destructor D...." << endl; }
};
int main()
{
	D d(10, 20, 40);
	d.f();
	d.display();
	return 0;
}
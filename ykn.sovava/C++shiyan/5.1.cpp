#include <iostream>
using namespace std;
class A{
public:
    //void A(int i=0){m=i;}
    A(int i = 0) { m = i; }
    void show(){cout<<m;}
    void add();
    //void ~A(){}
    ~A(){}
    //private:
protected:
    int m;
};
void A::add() {
    m += 10;
}
//--------------------------
class X{
private:
    int a = 0;
    int b=0;
    int c=0;
    
    
public:
    X();
    X(int i);
    void setA(int i) { a = i; }
    X(int i, int j, int k) { a = i; b = j; c = k; }
    void setC(int k) { c = c + k; }
    void show();
};
X::X(int i) { a = i; }
X::X() { a = b = 0; }
void X::show() {
    cout << a <<" " << b <<" "<< c << endl;
}

int main()
{
    X x1;
    X x2(2);
    X x3(1, 2, 3);
    x1.setA(3);
    x1.show();
    x2.show();
    x3.show();
    cout << "----------------------------" << endl;;

    A a(5);
    //a.m+=10;
    a.add();
    a.show();
    return 0;
}
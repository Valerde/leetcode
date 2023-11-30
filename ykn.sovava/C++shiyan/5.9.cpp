/*声明一个复数类，complex，使用友元函数add实现复数加法。*/
#include<iostream>
using namespace std;
class complex {
public:
	complex() { real = 0; imag = 0; }
	complex(double r, double i) { real = r; imag = i; }
	complex operator + (complex & c2);
	void display();
private:
	double real, imag;
};
complex complex::operator+(complex& c2) {
	complex x;
	x.real = real + c2.real;
	x.imag = imag + c2.imag;
	return x;
}
void complex::display() {
	cout << real << "," << imag << "i" << endl;
}
int main(void) {
	complex c1(3, 4), c2(5, -10), c3;
	c3 = c1 + c2;
	c3.display();
	return 0;
}
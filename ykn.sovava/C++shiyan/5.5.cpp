/* 需要求1个三角形的信息，请编写一个基于对象的程序。数据成员包括三角形的三边长a、b、c。要求用成员函数实现以下功能：
(1) 定义构造函数完成三角形的初始化；
(2) 求三角形的周长；
(3) 求三角形的面积；

(4) 输出三角形信息(包括各个边长、周长及面积)。*/
#include<iostream>
#include<cmath>
using namespace std;
class triangle {
public:
	triangle();
	triangle(double a,double b,double c):a(a),b(b),c(c){}
	double perimeter() { return a + b + c; }
	double area() { return 0.25*sqrt((a + b + c)*(a + b - c)*(a + c - b)*(b + c - a)); }
	bool settriangle();
private:
	double a;
	double b;
	double c;
};

triangle::triangle() {
	a = 0;
	b = 0;
	c = 0;
}
bool triangle::settriangle() {
	cout << "enter three sides:";
	cin >> a >> b >> c;
	if (a + b > c && a + c > b && b + c > a)
		return true;
	else
		return false;
}
int main(void) {
	triangle one(3, 4, 5);
	int ret;
	cout << "area = " << one.area() << endl;
	cout << "perimeter = " << one.perimeter() << endl;
	do {
		ret=one.settriangle();
	} while (!ret);
	cout << "area = " << one.area() << endl;
	cout << "perimeter = " << one.perimeter() << endl;
}
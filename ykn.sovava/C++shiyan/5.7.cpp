/*设计一个点类Point，再设计一个矩形类，矩形类使用Point类的两个坐标点作为矩形的对角顶点。
并可以输出矩形的4个坐标值和面积。使用测试程序验证程序。*/
#include<iostream>
#include<cmath>
using namespace std;
class point {
public:
	point();
	point(int a, int b) :x(a), y(b) {}
	void set();
	int retx() { return x; }
	int rety() { return y; }
private:
	int x;
	int y;
};
point::point() {
	x = y = 0;
}
void point::set() {
	cout << "enter the point's x,y:";
	cin >> x >> y;
	cout << "set over" << endl;
}
/*------------------------------------*/
class rectangle {
public:
	rectangle( point& a,  point& b);
	int area();
	void out();
private:
	int a[2], b[2], c[2], d[2];
};
rectangle::rectangle( point& pointa, point& pointb) {
	a[0]=pointa.retx();
	a[1]=pointa.rety();
	d[0] = pointb.retx();
	d[1] = pointb.rety();
	b[0] = pointa.retx();
	b[1] = pointb.rety();
	c[0] = pointb.retx();
	c[1] = pointa.rety();

}
void rectangle::out() {
	cout << "(" << a[0] << "," << a[1] << ")" << "     ";
	cout << "(" << b[0] << "," << b[1] << ")" << endl << endl;
	cout << "(" << c[0] << "," << c[1] << ")" << "     ";
	cout << "(" << d[0] << "," << d[1] << ")" << endl << endl;
}
int rectangle::area() {
	return abs((d[0] - a[0]) * (d[1] - a[1]));
}
/*---------------------------------------------------------------------*/
int main(void) {
	point a, b;
	a.set();
	b.set();
	rectangle c(a,b);
	c.out();
	cout << "area=" << c.area() << endl;
	return 0;
}
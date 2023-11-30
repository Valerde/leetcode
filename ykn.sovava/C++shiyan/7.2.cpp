/*
先建立一个点类Point，包含数据成员x，y（坐标点）。
以它为基类，派生出圆类Circle，增加数据成员radius（半径），
再以Cirlcle类为直接基类，派生出圆柱体类Cylinder，再增加数据成员height（高）。要求：
（1）每个类都有构造函数、用于从键盘获取数据的成员函数set()，用于显示数据的成员函数display()。
（2）用虚函数输出各类对象信息。
*/
#include <iostream>
using namespace std;
class Point {
protected:
	double x;
	double y;
public:
	Point(double a,double b):x(a),y(b){}
	virtual void set() { cout << "enter x,y:"; cin >> x >> y; }
};
class Circle :public Point {
protected:
	double radius;
public:
	Circle(double a,double b,double c):Point(a,b),radius(c){}
	virtual void set() { cout << "enter x,y,r:"; cin >> x, y, radius; }
};
class Cylinder :public Circle {
private:
	double height;
public:
	Cylinder(double a, double b, double c, double d) :Circle(a, b, c), height(d) {	}
	void set() { cout << "enter x,y,r,h:"; cin >> x >> y >> radius >> height; }
	friend ostream& operator<<(ostream &out, Cylinder &a) {
		out << "a=" << a.x << "    y=" << a.y << "   radius=" << a.radius << "    height=" << a.height << endl;
		return out;
	}
};
int main(void) {
	Cylinder a(1, 2, 3, 4);
	cout << a;
	a.set();
	cout << a;
}



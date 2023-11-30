/*
�Ƚ���һ������Point���������ݳ�Աx��y������㣩��
����Ϊ���࣬������Բ��Circle���������ݳ�Աradius���뾶����
����Cirlcle��Ϊֱ�ӻ��࣬������Բ������Cylinder�����������ݳ�Աheight���ߣ���Ҫ��
��1��ÿ���඼�й��캯�������ڴӼ��̻�ȡ���ݵĳ�Ա����set()��������ʾ���ݵĳ�Ա����display()��
��2�����麯��������������Ϣ��
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



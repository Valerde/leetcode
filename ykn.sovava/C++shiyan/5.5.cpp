/* ��Ҫ��1�������ε���Ϣ�����дһ�����ڶ���ĳ������ݳ�Ա���������ε����߳�a��b��c��Ҫ���ó�Ա����ʵ�����¹��ܣ�
(1) ���幹�캯����������εĳ�ʼ����
(2) �������ε��ܳ���
(3) �������ε������

(4) �����������Ϣ(���������߳����ܳ������)��*/
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
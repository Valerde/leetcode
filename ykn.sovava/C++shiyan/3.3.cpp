#include<iostream>
#include<cmath>
using namespace std;
int distance(int a, int b) {
	return abs(a - b);
}
double distance(double a, double b) {
	return abs(a - b);
}
int main(void) {
	int a, b;
	cout << "输入两个整数：";
	cin >> a >> b;
	cout << "距离是：" << distance(a, b) << endl;
	double c, d;
	cout << "输入两个浮点数：";
	cin >> c >> d;
	cout << "距离是" << distance(c, d) << endl;
	return 0;
}
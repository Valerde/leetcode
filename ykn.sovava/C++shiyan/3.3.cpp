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
	cout << "��������������";
	cin >> a >> b;
	cout << "�����ǣ�" << distance(a, b) << endl;
	double c, d;
	cout << "����������������";
	cin >> c >> d;
	cout << "������" << distance(c, d) << endl;
	return 0;
}
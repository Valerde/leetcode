#include<iostream>
using namespace std;
int compare(int a , int b , int c) {
	int max;
	if (a > b)
		max = a;
	else
		max = b;
	if (max > c)
		return max;
	else
		return c;

}

int compare2(int a = 0, int b = 0, int c = 100) {
	int max;
	if (a > b)
		max = a;
	else
		max = b;
	if (max > c)
		return max;
	else
		return c;
}
int main(void) {
	int  a , b , c;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	cout << "max=" << compare(a, b, c) << endl;
	cout << "max=" << compare2(a, b, c) << endl;
	cout << "max=" << compare2(a, b) << endl;
	return 0;

}
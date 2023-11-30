#include<iostream>
using namespace std;
int main(void) {
	int i;
	for (i = 0; i * 13 < 100; i++);
	cout <<13*( i - 1 )<< endl;
	return 0;
}
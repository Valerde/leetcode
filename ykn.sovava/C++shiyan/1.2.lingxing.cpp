#include<iostream>
#include<cmath>
using namespace std;
int main(void) {
	int space_Num = 0, hang_Num = 0,i,Hang_Num;
	cout << "enter the rows:";
	cin >> Hang_Num;
	for (hang_Num = 1; hang_Num < Hang_Num+2; hang_Num++) {
		for (space_Num = 0; space_Num < abs((Hang_Num+1)/2 - hang_Num); space_Num++)
			cout << " ";
		for (i = 0; i < (2 * ((Hang_Num + 1) / 2 -abs((Hang_Num + 1) / 2 -hang_Num)) - 1); i++)
			cout << "*";
		cout << endl;
	}
}
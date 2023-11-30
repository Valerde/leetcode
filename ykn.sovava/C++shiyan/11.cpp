#include<iostream>
using namespace std;
class clockType {
private:
	int s;
	int m;
	int h;
public:
	clockType() { h = 0; m = 0; s = 0; }
	clockType(int h,int m,int s):h(h),m(m),s(s){}
	void setTime(int a,int b,int c) {
		h = a;
		m = b;
		s = c;
	}
	void printTime() {
		cout << h << ":" << m << ":" << s ;
	}
	void incrementSeconds() {
		s++;
	}
	bool equalTime(clockType &a) {
		if (h * 10000 + m * 100 + s == a.h * 10000 + m * 100 + s)
			return true;
		else
			return false;
    }
};
int main()
{
    clockType myClock;
    clockType yourClock;

    int hours;
    int minutes;
    int seconds;

    cin >> hours >> minutes >> seconds;
    myClock.setTime(hours, minutes, seconds);

    cin >> hours >> minutes >> seconds;
    yourClock.setTime(hours, minutes, seconds);

    myClock.printTime();


    cout << endl << myClock.equalTime(yourClock) << endl;

    myClock.incrementSeconds();

    myClock.printTime();

    return 0;
}

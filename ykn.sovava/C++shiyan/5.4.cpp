#include <iostream>
#include<stdio.h>
using namespace std;

class Clock{
public:
    Clock();
    Clock(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }
    void set_clock();
    void printMilitary();
    void printStandard();
private:
    int hour;
    int minute;
    int second;
};
Clock::Clock() {
    hour = 0;
    minute = 0;
    second = 0;
}
void Clock::set_clock()
{
    cout << "enter the hour:";
    cin >> hour;
    cout << "enter the minute:";
    cin >> minute;
    cout << "enter the second:";
    cin >> second;
}
void Clock::printMilitary()
{
    printf("%.2d:%.2d:%.2d\n", hour,minute,second);
}
void Clock::printStandard() {
    if (hour > 12) {
        hour = hour - 12;
        cout << hour << ":" << minute << ":" << second << " PM" << endl;
    }
    else {
        cout << hour << ":" << minute << ":" << second << endl;
    }
}
int main()
{
    Clock clock;
    clock.printMilitary();
    clock.set_clock();
    clock.printMilitary();
    clock.printStandard();
    cout << "----------------------------" << endl;
    Clock clock2(13, 15, 46);
    clock2.printMilitary();
    clock2.printStandard();
    return 0;
}

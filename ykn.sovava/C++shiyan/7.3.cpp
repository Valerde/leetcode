/*
设计并实现一个日期类Date，要求：
（1）可以建立具有指定日期（年、月、日）的Date对象，默认日期是2012.1.1。
（2）可以从输出流输出一个格式为“年-月-日”的日期，其中年是四位数据，月、日可以是一位也可以是两位数据。
（3）可以动态地设置年、月、日。
（4）可以用运算符= =、!=、<和>对两个日期进行比较。
（5）可以用运算符++、--、+=、-=等完成天数的加减一天或若干天的操作
（6）Date类必须能够正确表达日期，不会出现类似于13月，32日一类的情况。
Date类还必须处理闰年的问题，闰年包括：所有能被400整除的年份，以及能被4整除同时又不能被100整除的年份。
*/
#include<iostream>
using namespace std;
class Date {
	int date;
	int year;
	int month;
public:
	Date();
	Date(int a, int b, int c) :year(a), month(b), date(c) {}
	friend ostream& operator<<(ostream& out, Date& a) { 
		if (!a.check()) {
			cout << "";
		}
		else
			cout << a.year << "-" << a.month << "-" << a.date << endl; return out; }
	void set();
	friend bool operator == (const Date& a, const Date& b);
	friend bool operator !=(const Date& a, const Date& b);
	friend bool operator <(const Date& a,const Date& b);
	friend bool operator > (const Date& a, const Date& b);
	Date& operator ++(int) { 
		date++; 
		if (check())
			return *this;
		else {
			date--;
			cout << "wrong!" << endl;
		}
	}
	friend Date& operator --(Date &a,int) { 
		a.date--;
		if (a.check())
			return a;
		else {
			a.date++;
			cout << "wrong!" << endl;
			return a;
		}
	}
	friend Date &operator +=( Date& a, int b);
	friend Date &operator -=( Date& a, int b);
	bool check();
};
void Date::set() {
	do {
		cout << "enter year,month,date:";
		cin >> year >> month >> date;
	} while (!check());
}
Date::Date() {
	year = 2021;
	month = 1;
	date = 1;
}
bool operator == (const Date& a, const Date& b) {
	int an = a.year * 10000 + a.month + a.date;
	int bn = b.year * 10000 + b.month + b.date;
	if (an == bn)
		return true;
	else
		return false;
}
bool operator != (const Date& a, const Date& b) {
	int an = a.year * 10000 + a.month + a.date;
	int bn = b.year * 10000 + b.month + b.date;
	if (an != bn)
		return true;
	else
		return false;
}
bool operator > (const Date& a, const Date& b) {
	int an = a.year * 10000 + a.month + a.date;
	int bn = b.year * 10000 + b.month + b.date;
	if (an > bn)
		return true;
	else
		return false;
}
bool operator < (const Date& a, const Date& b) {
	int an = a.year * 10000 + a.month + a.date;
	int bn = b.year * 10000 + b.month + b.date;
	if (an < bn)
		return true;
	else
		return false;
}
Date& operator +=(Date& a, int b) {
	a.date += b;
	if(a.check())
		return a;
	else {
		a.date -= b;
		cout << "wrong!" << endl;
		return a;
	}
}
Date& operator -=(Date& a, int b) {
	a.date -= b;
	if(a.check())
		return a;
	else {
		a.date -= b;
		cout << "wrong" << endl;
		return a;
	}
}
bool Date::check() {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		if (month > 12 || month < 1)
			return false;
		else if (month == 2) {
			if (date > 29||date<1)
				return false;
		}
				
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (date > 31||date<1)
				return false;
		}
		else {
			if (date > 30||date<1)
				return false;
		}
	}
	else {
		if (month > 12 || month < 1)
			return false;
		else if (month == 2) {
			if (date > 29||date<1)
				return false;
		}

		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (date > 31||date<1)
				return false;
		}
		else {
			if (date > 30||date<1)
				return false;
		}
	}
	return true;
}
int main(void) {
	Date date1;
	Date date2;
	Date date3(2021, 11, 26);
	cout << date2;
	date2.set();
	if (date2 == date3)
		cout << "date2==date3" << endl;
	if (date2 < date3)
		cout << "date2 < date3" << endl;
	if (date2 > date3)
		cout << "date2 > date3" << endl;
	if (date2 != date3)
		cout << "date2!=date3" << endl;
	date1--;
	cout << date1;
	date1++;
	cout << date1;
	date1 += 5;
	cout << date1;
	date1 += 50;
	cout << date1;
	return 0;
}
//xiezhemeduo yuexieyueduo,buxiele.
/*
某出版系统发行图书和磁带，利用继承设计管理出版物的类。
要求如下：建立一个基类Publication存储出版物的标题title、出版物名称name、单价price及出版日期date。
用Book类和Tape类分别管理图书和磁带，它们都从Publication类派生。
Book类具有保存图书页数的数据成员page，Tape类具有保存播放时间的数据成员playtime。
每个类都有构造函数、析构函数，且都有用于从键盘获取数据的成员函数inputData()，用于显示数据的成员函数display()。

*/
#include<iostream>
using namespace std;
class Publication {
public:
	Publication(string a, string b, int c, string d):title(a),name(b),price(c),date(d){}
	void inputData() {
		cout << "输入title、name、price、date：" << endl;
		cin >> title >> name >> price >> date;
	}
	void display() {
		cout << title << " " << name << " " << price << " " << date << endl;
	}
	Publication() { title = "C++";  name = "daan"; price = 1; date = "20010101"; }
	~Publication() { cout << "destructor Publication" << endl; }
private:
	string title;
	string name;
	int price;
	string date;
};
class Book :public Publication {
public:
	Book(string a,string b,int c,string d,int e):Publication(a,b,c,d),page(e){}
	void inputData() {
		Publication::inputData();
		cout << "输入page:" << endl;
		cin >> page;
	}
	void display() {
		Publication::display();
		cout << " " << page << endl;
	}
	~Book() { cout << "destructor Book" << endl; }
private:
	int page;
};
class Tape :public Publication {
public:
	Tape(string a, string b, int c, string d, int e):Publication(a,b,c,d),playtime(e){}
	void inputData() {
		Publication::inputData();
		cout << "输入playtime:" << endl;
		cin >> playtime;
	}
	void display() {
		Publication::display();
		cout << " " << playtime << endl;
	}
	~Tape() { cout << "destructor Tape" << endl; }
private:
	int playtime;
};
int main(void) {
	Tape a("jisuanji", "C++", 1, "20010101", 2002);
	Book b("niuma", "shi", 123, "wo", 250);
	Publication c("bija", "enheng", 456, "heihei");
	a.display();
	b.display();
	c.display();
	a.inputData();
	a.display();
	b.inputData();
	b.display();
	c.inputData();
	c.display();
	return 0;
}
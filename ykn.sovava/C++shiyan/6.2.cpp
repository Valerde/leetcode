/*
ĳ����ϵͳ����ͼ��ʹŴ������ü̳���ƹ����������ࡣ
Ҫ�����£�����һ������Publication�洢������ı���title������������name������price����������date��
��Book���Tape��ֱ����ͼ��ʹŴ������Ƕ���Publication��������
Book����б���ͼ��ҳ�������ݳ�Աpage��Tape����б��沥��ʱ������ݳ�Աplaytime��
ÿ���඼�й��캯���������������Ҷ������ڴӼ��̻�ȡ���ݵĳ�Ա����inputData()��������ʾ���ݵĳ�Ա����display()��

*/
#include<iostream>
using namespace std;
class Publication {
public:
	Publication(string a, string b, int c, string d):title(a),name(b),price(c),date(d){}
	void inputData() {
		cout << "����title��name��price��date��" << endl;
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
		cout << "����page:" << endl;
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
		cout << "����playtime:" << endl;
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
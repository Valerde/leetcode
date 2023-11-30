/*
假设有学生类Student，包括姓名、学校、专业、班级、电话号码、通信地址、邮政编码等数据成员。
编程完成Student类的设计，从键盘输入10个同学的通信录信息，并将这10个同学的信息写入磁盘文件address.dat中。
然后从address.dat文件中读取各同学信息并显示在屏幕上。
*/
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class Student {
private:
	char name[10];
	char school[10];
	char major[10];
	char classn[10];
	char phone[10];
	char add[10];
	char postal[10];
public:
	void set() {
		cin >> name >> school >> major >> classn >> phone >> add >> postal;
	}
	void dispaly() {
		cout << name << endl;
		cout << school << endl;
		cout << major << endl;
		cout << classn << endl;
		cout << phone << endl;
		cout << add << endl;
		cout << postal << endl;
	}
};


int main(void) {
	Student a[2];
	ofstream out("address.dat", ios::out | ios::binary);
	for (int i = 0; i < 2; i++) {
		a[i].set();
		out.write((char*)&a[i], sizeof(a[i]));
	}
	out.close();
	cout << "-------------------" << endl;
	Student s1[2];
	ifstream in("address.dat", ios::in | ios::binary);
	for (int i = 0; i < 2; i++) {
		in.seekg(i * (sizeof(s1[i])), ios::beg);
		in.read((char*)&s1[i], sizeof(s1[i]));
		s1[i].dispaly();
	}
	in.close();
	return 0;
}
pubilc class HelloWorld {
	pubilc static void main(String[] args) {
		System.out.println("HelloWorld");
	}
}



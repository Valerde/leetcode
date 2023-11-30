#include<iostream>
#include<string>
using namespace std;
class student {
public:
	student();
	student(string a,string b,string c,int age):name(a),ID(b),xingbie(c),age(age){}
	void printStd();
private:
	string name;
	string ID;
	string xingbie;
	int age;
};

student setstu() {
	string a, b, c;
	int age;
	cout << "enter the name:";
	cin >> a;
	cout << "enter the ID:";
	cin >> b;
	cout << "enter the xingbie:";
	cin >> c;
	cout << "enter the age:";
	cin >> age;
	student stu3(a, b, c, age);
	return stu3;
}
void student::printStd() {
	cout << "name:" << name << endl;
	cout << "ID:" << ID << endl;
	cout << "xingbie:" << xingbie << endl;
	cout << "age:" << age << endl;
}
student::student() {
	name = "sb";
	ID = "123456789";
	xingbie = "boy";
	age = 100;
}
int main(void) {
	student stu1;
	stu1.printStd();
	cout << "---------1------------" << endl;
	student stu2("ykn", "123", "boy", 20);
	stu2.printStd();
	cout << "------------2-----------" << endl;
	student stu3 = setstu();
	stu3.printStd();
	return 0;
}
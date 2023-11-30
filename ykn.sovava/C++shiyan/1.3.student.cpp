#include<iostream>
#include<string>
using namespace std;
struct student {
	string ID;
	string name;
	string major;
	int grade;
};
void setup(struct student &a) {
	cout << "enter the ID:";
	cin >> a.ID;
	cout << "enter the name:";
	cin >> a.name;
	cout << "enter the major:";
	cin >> a.major;
	cout << "enter the grade:";
	cin >> a.grade;
}
void display(struct student &a) {
	cout << "ID:" << a.ID << endl;
	cout << "name:" << a.name << endl;
	cout << "major:" << a.major << endl;
	cout << "grade:" << a.grade << endl;
}
int main(void) {
	struct student Stu;
	setup(Stu);
	cout << "---------out--------" << endl;
	display(Stu);
	return 0;
}
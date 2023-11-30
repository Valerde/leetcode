/*建立一个对象数组，内放5个学生的数据（学号、成绩），设立一个函数max，
用指向对象的指针作函数参数，在max函数中找出5个学生中成绩最高者，并输出其学号、成绩。*/
#include<iostream>
using namespace std;
class student {
public:
	student();
	student(int a, int b):id(a),score(b){}
	int retscore();
	void set();
	void out();
private:
	int id;
	int score;
};
student::student() {
	id = 888;
	score = 0;
}
void student::set() {
	cout << "enter the id:";
	cin >> id;
	cout << "enter the score:";
	cin >> score;
	cout << "**********************************" << endl;
}
int student::retscore() {
	return score;
}
void max(student *std) {
	int temp;
	temp = std[0].retscore();
	student tempclass;
	for (int i = 0; i < 5; i++)
		if (temp <= std[i].retscore()) {
			temp = std[i].retscore();
			tempclass = std[i];
		}
	tempclass.out();
}
void student::out() {
	cout << "id:" << id << endl;
	cout << "score:" << score << endl;
	cout << "*****************************" << endl;
}
int main(void) {
	int i = 0;
	student std[5];
	for (i; i < 5; i++){
		std[i].set();
	}
	//student* retstd;
	//retstd = std;
	max(std);
	return 0;
}
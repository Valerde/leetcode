/*
按下列要求编写程序。
（1）定义一个分数类Score。它有3个数据成员：
Chinese       //语文课成绩
English       //英语课成绩
Mathematics   //数学课成绩
2个构造函数：无参的和带参数的（三个参数）
3个成员函数：是否带参数根据需要自定
sum()         //计算三门课总成绩
print()        //输出三门课成绩和总成绩
modify()      //修改三门课成绩
（2）定义一个学生类Student。它有3个数据成员：
Num           //学号
Name          //姓名
MyScore       //成绩
2个构造函数：无参的和带参数的（三个参数）
3个成员函数：是否带参数根据需要自定
sum()         //计算某学生三门课总成绩
print()        //输出某学生学号、姓名和成绩
modify()      //修改某学生学号、姓名和成绩
（3）在主函数中，先定义一个学生类对象数组，再通过for循环给对象数组赋上实际值，最后输出对象数组个元素的值。
*/
#include<iostream>
#include<string>
using namespace std;
class Score {
private:
	int Chinese;
	int English;
	int Mathematics;
public:
	Score();
	Score(int a, int b, int c):Chinese(a),English(b),Mathematics(c){}
	int sum() {
		return Chinese + English + Mathematics;
	}
	void print() {
		cout << "Chinese:" << Chinese << endl;
		cout << "English:" << English << endl;
		cout << "Mathmatics:" << Mathematics << endl;
		cout << "sum:" << sum() << endl;
	}
	void modify() {
		cout << "enter three Scores:";
		cin >> Chinese >> English >> Mathematics;
	}
};
Score::Score() {
	Chinese = 0;
	English = 0;
	Mathematics = 0;
}
class Student :public Score {
private:
	int Num;
	string Name;
	Score MyScore;
public:
	Student();
	Student(int d,string e, int a, int b, int c):Num(d),Name(e),MyScore(a,b,c){}
	int sum() {
		return MyScore.sum();
	}
	void print() {
		cout << "Num:" << Num << endl;
		cout << "Name:" << Name << endl;
		MyScore.print();
	}
	void modify() {
		cout << "enter Num:";
		cin >> Num;
		cout << "enter Name:";
		cin >> Name;
		MyScore.modify();
	}
};
Student::Student() {
	Num = 0;
	Name = '\0';
	Score();
}
int main(void) {
	Student stu[2];
	for (int i = 0; i < 2; i++) {
		stu[i].modify();
	}
	cout << "**********************************" << endl;
	for (int i = 0; i < 2; i++) {
		cout << "第" << i+1 << "个学生" << endl;
		stu[i].print();
		cout << "***************************************"<<endl;
	}
	return 0;
}

/*
������Ҫ���д����
��1������һ��������Score������3�����ݳ�Ա��
Chinese       //���Ŀγɼ�
English       //Ӣ��γɼ�
Mathematics   //��ѧ�γɼ�
2�����캯�����޲εĺʹ������ģ�����������
3����Ա�������Ƿ������������Ҫ�Զ�
sum()         //�������ſ��ܳɼ�
print()        //������ſγɼ����ܳɼ�
modify()      //�޸����ſγɼ�
��2������һ��ѧ����Student������3�����ݳ�Ա��
Num           //ѧ��
Name          //����
MyScore       //�ɼ�
2�����캯�����޲εĺʹ������ģ�����������
3����Ա�������Ƿ������������Ҫ�Զ�
sum()         //����ĳѧ�����ſ��ܳɼ�
print()        //���ĳѧ��ѧ�š������ͳɼ�
modify()      //�޸�ĳѧ��ѧ�š������ͳɼ�
��3�����������У��ȶ���һ��ѧ����������飬��ͨ��forѭ�����������鸳��ʵ��ֵ�����������������Ԫ�ص�ֵ��
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
		cout << "��" << i+1 << "��ѧ��" << endl;
		stu[i].print();
		cout << "***************************************"<<endl;
	}
	return 0;
}

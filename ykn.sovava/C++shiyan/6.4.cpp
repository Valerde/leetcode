/*
��дһ������ʵ��С�͹�˾����Ա��Ϣ����ϵͳ��
�ù�˾��Ա��employee����������manager����������Ա��technician��������Ա��salesman�������۲�����salesmanager����
Ҫ��洢��Щ��Ա����������š����𡢵���нˮ��������н����ʾȫ����Ϣ��
����Ҫ��������Ա����������Ĺ��ܡ�Ϊ�������������Ա�ĳ�ʼ�����Ϊ1��
Ȼ�����������������Ϊ4����������Ա�����۲�������Ϊ3��������Ա��Ϊ1����
��н����취�ǣ������ù̶���н8000Ԫ��������Ա��ÿСʱ100Ԫ��ȡ��н������Ա���õ������۶�4%��ɣ�
���۾�����ù̶��¹���Ҳ��ȡ������ɣ��̶��¹���Ϊ5000Ԫ���������Ϊ����Ͻ���ŵ������۶��5�롣
*/
#include<iostream>
using namespace std;
class Employee {
protected:
	string name;
	string Num;
	int level;
	int salary;
public:
	Employee() { name = "\0"; Num = "\0"; level = 1; salary = 0; }
	
	void print() {
		cout << "display:   ";
		cout << "name:" << name << " " << "Num:" << Num << " " << "salary:" << salary << endl;
	}
};
class manager :public Employee {

public:
	manager() {
		cout << "enter the name:";
		cin >> name;
		cout << "enter the Num:";
		cin >> Num;
		level = 4; salary = 8000;
	}

};
class technician :public Employee {
	int hour;
public :
	technician() {
		cout << "enter the name:";
		cin >> name;
		cout << "enter the Num:";
		cin >> Num;
		level = 3; 
		cout << "work hours:";
		cin >> hour;
		salary = 100 * hour;
	}
	
};
class salesman :public Employee {
	int sales;
public:
	salesman() {
		cout << "enter the name:";
		cin >> name;
		cout << "enter the Num:";
		cin >> Num;
		level = 3;
		cout << "enter the sales:";
		cin >> sales;
		salary = sales * 0.04;
	}
};
class salesmanager : public Employee {
	int sales;
public:
	salesmanager() {
		cout << "enter the name:";
		cin >> name;
		cout << "enter the Num:";
		cin >> Num;
		cout << "enter the sales:";
		cin >> sales;
		salary = 5000 + sales * 0.005;
	}
};
int main(void) {
	manager a;
	a.print();
	cout << "******************************" << endl;
	technician b;
	b.print();
	cout << "******************************" << endl;
	salesman c;
	c.print();
	cout << "******************************" << endl;
	salesmanager d;
	d.print();
	return 0;
}

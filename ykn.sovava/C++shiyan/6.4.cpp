/*
编写一个程序实现小型公司的人员信息管理系统。
该公司雇员（employee）包括经理（manager），技术人员（technician）、销售员（salesman）和销售部经理（salesmanager）。
要求存储这些人员的姓名、编号、级别、当月薪水，计算月薪并显示全部信息。
程序要对所有人员有提升级别的功能。为简单起见，所有人员的初始级别均为1，
然后进行升级，经理升为4级，技术人员和销售部经理升为3级，销售员仍为1级。
月薪计算办法是：经理拿固定月薪8000元；技术人员按每小时100元领取月薪；销售员按该当月销售额4%提成；
销售经理既拿固定月工资也领取销售提成，固定月工资为5000元，销售提成为所管辖部门当月销售额的5‰。
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

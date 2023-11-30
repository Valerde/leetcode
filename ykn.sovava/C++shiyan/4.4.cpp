#include<iostream>
#include<string>
using namespace std;
class Employee {
public:
	Employee(string name=" ", string street="", string province="", string city=" ", string zip="");
	void setEmployee();
	void showEmployee();
private:
	string name;
	string street;
	string province;
	string city;
	string zip;
};
Employee::Employee(string name, string street, string province, string city, string zip) {
	name = name;
	street = street;
	province = province;
	city = city;
	zip = zip;
}
void Employee::setEmployee() {
	cout << "enter the name:";
	cin >> name;
	cout << "enter the street:";
	cin >> street;
	cout << "enter the province:";
	cin >> province;
	cout << "enter the city:";
	cin >> city;
	cout << "enter the zip:";
	cin >> zip;
}

void Employee::showEmployee() {
	cout << "name:" << name << endl;
	cout << "street:" << street << endl;
	cout << "province:" << province << endl;
	cout << "city:" << city << endl;
	cout << "zip:" << zip << endl;
}
int main(void) {
	int option;
	Employee emp;
	emp.setEmployee();
	cout << "enter the option(1 set;2 show;0 ret):";
	cin >> option;
	while (option) {
		switch (option) {
		case 1:
			cout << "reset: " << endl;
			emp.setEmployee();
			break;
		case 2:
			cout << "show: " << endl;
			emp.showEmployee();
			break;
		default:
			break;
		}
		cout << "enter the option(1 set;2 show;0 ret):";
		cin >> option;
	}
}
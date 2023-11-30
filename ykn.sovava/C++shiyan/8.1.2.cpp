#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Worker {
private:
	int number, age;
	char name[20];
	double sal;
public:
	Worker() {}
	Worker(int num, const char* Name, int Age, double Salary) :number(num), age(Age), sal(Salary)
	{
		strcpy_s(name, Name);
	}
	void display() { cout << number << "\t" << name << "\t" << age << "\t" << sal << endl; }
};
int main() {
	ofstream out("Worker.dat", ios::out | ios::binary);
	Worker man[] = { Worker(1,"����",23,2320),Worker(2,"����",32,2321),
				  Worker(3,"����",34,2322),Worker(4,"����",27,2324),
				  Worker(5,"����",23,2325),Worker(6,"����",50,2326) };
	for (int i = 0; i < 6; i++) 	out.write((char*)&man[i], sizeof(man[i]));
	out.close();
	Worker s1;
	ifstream in("Worker.dat", ios::in | ios::binary);
	in.seekg(2 * (sizeof(s1)), ios::beg);
	in.read((char*)&s1, sizeof(s1));
	s1.display();
	in.seekg(0, ios::beg);
	in.read((char*)&s1, sizeof(s1));
	s1.display();
	in.close();
	return 0;
}
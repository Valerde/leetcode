#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream out, in;
	out.open("a.dat", ios::out);
	out << "on fact\n";
	out << "operating file \n";
	out << "is the same as inputing/outputing data on screen...\n";
	out.close();
	char buffer[80];
	in.open("a.dat", ios::in);
	while (!in.eof())
	{
		in.getline(buffer, 80);
		cout << buffer << endl;
	}
	return 0;
}
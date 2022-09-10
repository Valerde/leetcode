#include <iostream>
#include <list>
using namespace std;
int main() {

	list<string> values {5, "HaiCoder"};
	for (auto i = values.begin(); i != values.end(); i++) 	{
		cout << "Value = " << *i << endl;
	}
	return 0;
}

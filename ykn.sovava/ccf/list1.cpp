#include <iostream>
#include <list>
using namespace std;
int main()
{

	list<string> values{"Hello", "HaiCoder"};
	list<string> values2(values);
	for (auto i = values2.begin(); i != values2.end(); i++) 
	{
        cout << "Value = " << *i << endl;
    }
    return 0; 
}

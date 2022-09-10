#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<string> values{"ykn","wyp"};
	values.push_back("Haicoder");
	values.push_back("haicoder.net");
	
	auto i = values.begin();
	for (vector<string>::iterator i = values.begin(); i < values.end(); i++) 
	{
        cout << "Value = " << *i << endl;
    }
    
    vector<string> values2(values);
    for (vector<string>::iterator i = values2.begin(); i < values2.end(); i++) 
	{
        cout << "Value = " << *i << endl;
    }
    return 0; 
}

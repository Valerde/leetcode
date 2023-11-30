#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class mycomp
{
public:
    bool operator()(const int& i, const int& j) 
    {
        return (i%j == 0);
    }
};
int main() 
{
	cout << "àË¿ÍÍø(www.haicoder.net)\n" << endl;	
	vector<int> myvector{11, 22, 33, 100, 99, 101, 11, 22, 3};
    int myarr[] = {11, 22, 33};
    vector<int>::iterator it = find_end(myvector.begin(), myvector.end(), myarr, myarr + 3);
    if (it != myvector.end()) 
    {
        cout << "Find£º" << it - myvector.begin() << ",*it = " << *it << endl;
    }
    int myarr2[] = {100, 99, 101};
    it = find_end(myvector.begin(), myvector.end(), myarr2, myarr2 + 3, mycomp());
    if (it != myvector.end()) 
    {
        cout << "Find£º" << it - myvector.begin() << ",*it = " << *it;
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
class mycomp1
{
public:
    bool operator() (int i, int j) 
    {
        return (i > j);
    }
};
int main() 
{
	cout << "嗨客网(www.haicoder.net)\n" << endl;	
    vector<int> myvector{1024, 99, 109, 100};
    list<int> mylist{99, 100, 109, 1024};
    if (!is_sorted(myvector.begin(), myvector.end(), mycomp1())) 
    {
        cout << "开始对 myvector 容器排序" << endl;
        sort(myvector.begin(), myvector.end(), mycomp1());
        for (auto it = myvector.begin(); it != myvector.end(); ++it) 
        {
            cout << *it << " ";
        }
    }
    cout << endl;
    if (!is_sorted(mylist.begin(), mylist.end(),greater<int>()))
    {
        cout << "开始对 mylist 排序" << endl;
    }
    else
    {
    	cout << "mylist不需要排序" << endl;
    }
    return 0;
}

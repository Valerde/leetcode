#include <iostream>
#include <set>
using namespace std;
int main()
{
    cout << "嗨客网(www.haicoder.net)\n" << endl;
    std::set<string>myset;
    myset.emplace_hint(myset.begin(), "CPP教程");
    for(auto iter = myset.begin(); iter != myset.end(); ++iter)
    {
        cout << *iter << endl;
    }
    cout << "==================================================" << endl;
   myset.emplace_hint(myset.begin(), "C语言教程");
   for(auto iter = myset.begin(); iter != myset.end(); ++iter)
   {
        cout << *iter << endl;
   }
    cout << "==================================================" << endl;
    myset.emplace_hint(myset.begin(), "Golang教程");
   for(auto iter = myset.begin(); iter != myset.end(); ++iter)
   {
        cout << *iter << endl;
   }
    return 0; 
}

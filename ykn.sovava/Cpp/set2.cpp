#include <iostream>
#include <set>
using namespace std;
int main()
{
    cout << "�˿���(www.haicoder.net)\n" << endl;
    std::set<string>myset;
    myset.emplace_hint(myset.begin(), "CPP�̳�");
    for(auto iter = myset.begin(); iter != myset.end(); ++iter)
    {
        cout << *iter << endl;
    }
    cout << "==================================================" << endl;
   myset.emplace_hint(myset.begin(), "C���Խ̳�");
   for(auto iter = myset.begin(); iter != myset.end(); ++iter)
   {
        cout << *iter << endl;
   }
    cout << "==================================================" << endl;
    myset.emplace_hint(myset.begin(), "Golang�̳�");
   for(auto iter = myset.begin(); iter != myset.end(); ++iter)
   {
        cout << *iter << endl;
   }
    return 0; 
}

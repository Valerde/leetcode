#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//�յ�vector����ʹ�õ����� 
    vector<int> vec{1,2,3};
    auto first = vec.begin();
    auto last = vec.end();
    while (first != last)
    {
       //*first = 1;
       first++;
    }
    first = vec.begin();
    while (first != last)
    {
       cout << *first << endl;
       first++;
    }
    cout << "\n";
    
    cout<<"��ַ : "<<vec.data()<<endl; 
    vec.reserve(5);
	cout<<vec.size()<<endl;
	cout<<"��ַ : "<<vec.data()<<endl; 
    return 0; 
}

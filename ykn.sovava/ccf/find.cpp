#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	char str[] = "https://www.baidu.com";
	char * p = find(str,str+strlen(str),'c');
	if(p!=str+strlen(str)){
		cout<<p<<endl;
	}
	
	vector<int> myvector{1024, 99, 100, 101};
    vector<int>::iterator it;
    it = find(myvector.begin(), myvector.end(), 99);
    if (it != myvector.end())
    {
        cout << "查找成功：" << *it;
    }
    else
    {
        cout << "查找失败";
    }
    cout << endl;
}

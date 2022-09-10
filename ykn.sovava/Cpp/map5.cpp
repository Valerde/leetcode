#include<map>
#include<iostream>
using namespace std;
int main() {
	map<string,string> map1;
	pair<string,string> pair1("ykn","uabi");
	pair<map<string,string>::iterator,bool> ret;
	
	ret = map1.insert(pair1);
	cout<<"ret.iter = <{"<<ret.first->first<<" , "<<ret.first->second<<"}>"<<ret.second<<endl;
	ret = map1.insert(pair1);
	cout<<"ret.iter = <{"<<ret.first->first<<" , "<<ret.first->second<<"}>"<<ret.second<<endl;
	
	
	ret = map1.insert({"cjq","dauabi"});
	cout<<"ret.iter = <{"<<ret.first->first<<" , "<<ret.first->second<<"}>"<<endl;
	
	
	//创建并初始化 map 容器
    std::map<string, string>mymap;
    //指定在 map 容器插入键值对
    map<string, string>::iterator iter = mymap.emplace_hint(mymap.begin(),"CPP教程", "https://haicoder.net/cpp/cpp-tutorial.html");
    cout << iter->first << " " << iter->second << endl;
    iter = mymap.emplace_hint(mymap.begin(), "C语言教程", "https://haicoder.net/c/c-tutorial.html");
    cout << iter->first << " " << iter->second << endl;
    //插入失败样例
    iter = mymap.emplace_hint(mymap.begin(), "CPP教程", "https://haicoder.net/cpp/cpp-tutorial.html");
    cout << iter->first << " " << iter->second << endl;
	return 0;
}

#include<map>
#include<iostream>
using namespace std;

int main() {
	map<int,string> map1 {{1,"Mon"},{2,"Thu"},{3,"Wed"}};

	auto iter = map1.find(2);
	if(iter!=map1.end()) {
		cout<<iter->first<<" + "<<iter->second<<endl;
	} else {
		cout<<"cannot find"<<endl;
	}

	cout<<"_______________"<<endl;
	cout<<map1[1]<<endl;
	cout<<"_______________"<<endl;
	cout<<map1.at(2)<<endl;
	

	return 0;
}

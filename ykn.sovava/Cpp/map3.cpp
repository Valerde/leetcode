#include<map>
#include<iostream>
using namespace std;

int main() {
	map<string,string> map1 {{"ykn","uabi"},{"wyp","dauabi"}};
	
	for(auto it = map1.begin(); it!=map1.end(); it++) {
		cout<<it->first<<" + "<<it->second<<endl;
	}
	cout<<endl;
	
	map<string,string> map2(map1);
		for(auto it = map1.begin(); it!=map1.end(); it++) {
		cout<<it->first<<" + "<<it->second<<endl;
	}
	cout<<endl;
	
	
	return 0;
}

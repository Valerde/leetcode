#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	map<string,string> map1;
	map1["ykn"] = "uabi";
	string name = "cxk";
	string value = "ji";
	map1[name] = value;
	for(map<string,string>::iterator it = map1.begin(); it!=map1.end(); it++) {
		cout<<it->first<<"=>"<<it->second<<endl;
	}

	return 0;
}

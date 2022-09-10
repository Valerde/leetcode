#include<map>
#include<iostream>
using namespace std;

int main(){
	map<string,string> map1;
	map1["ykn"] = "uabi";
	map1["cjq"] = "iznqma";
	map1.insert({"hmx","jiba"});
	size_t size = map1.size();
	cout<<size<<endl;
	
	
	map1.erase("hmx");
	for(auto p:map1){
		cout<<p.first<<" "<<p.second<<endl;
	}
	map<string,string>::iterator it = map1.begin();
	map1.erase(it,map1.end());
	cout<<map1.size()<<endl;
	
	return 0;
}

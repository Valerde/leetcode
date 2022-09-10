#include<map>
#include<iostream>
using namespace std;
int main(){
	multimap<int,int> mulmap1{{1,100},{2,200},{2,201},{2,200}};
	
	cout<<mulmap1.count(2)<<endl;
	
	return 0;
}

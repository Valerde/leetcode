#include<set>
#include<iostream>
using namespace std;
int main() {
	set<string> set1;
	set1.insert("Shell");
	set1.insert("Linux");
	for(auto it = set1.begin(); it !=set1.end(); it++) {
		cout<<*it<<" ";
	}
	
	
	set1.emplace("CPP");
	cout<<*it<<endl;
	
	return 0; 
}

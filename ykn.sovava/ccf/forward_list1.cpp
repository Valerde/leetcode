#include<forward_list>//只开放列表头 
#include<iostream>
using namespace std;
int main() {
	forward_list<int> fl {1,2,3,4,5};
	fl.push_front(6);
	fl.push_front(7);
	for(auto i = fl.begin(); i!=fl.end(); i++) {
		cout<<*i<<" ";
	}
	cout<<endl;
	return 0;
}

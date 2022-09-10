#include<forward_list>
#include<iostream>
using namespace std;
template<typename T>
void printAll(T& stl) {
	for(auto&& value:stl) {
		cout<<"-"<<value<<endl;
	}
}

int main() {
	forward_list<int> fl1 {4,3}; //4,3
	for(auto&& value:fl1) {
		cout<<value<<" ";
	}
	cout<<endl;

	forward_list<string> fl2 {4,"ykn"};
	printAll(fl2);


	forward_list<string> fl3(fl2);
	cout<<"------"<<endl;
	printAll(fl3);
	cout<<"------"<<endl;
	fl3.push_front("hmx");
	printAll(fl3);
	cout<<"------"<<endl;
	printAll(fl2);
	fl2.emplace_front("cxk");
	cout<<"------"<<endl;
	printAll(fl2);
	return 0;
}

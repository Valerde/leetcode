#include<forward_list>
#include<iostream>
using namespace std;
template<typename T>
void printAll(T& stl) {
	for(auto&& value:stl) {
		cout<<value<<" ";
	}
	cout<<endl;
}
int main() {
	forward_list<int > fl1 {1,2,3,4};
	printAll(fl1);

	return 0;
}

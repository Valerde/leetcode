#include <iostream>
#include <forward_list>
using namespace std;
template<typename T>
void printAll(T& stl) {
	for(auto&& value:stl) {
		cout<<value<<" ";
	}
	cout<<endl;
}
int main () {
	std::forward_list<int> mylist = {10, 20, 30, 40, 50};

	// 10 20 30 40 50
	auto it = mylist.begin();                 // ^
	cout<<*it<<endl;
	it = mylist.erase_after(it);              // 10 30 40 50
	printAll(mylist);
	it = mylist.erase_after(it,mylist.end()); // 10 30

	printAll(mylist);


	return 0;
}

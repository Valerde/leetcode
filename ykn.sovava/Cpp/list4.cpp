#include <iostream>
#include <list>
using namespace std;
bool removeLen(string node) {
	if (node.length() > 10) {
		return true;
	}
	return false;
}

bool removeInt(int i) {
	if(i>5) {
		return true;
	}
	return false;
}
int main() {
	cout << "àË¿ÍÍø(www.haicoder.net)\n" << endl;
	list<string> list1 {"Hello", "World", "HaiCoder", "www.haicoder.net"};
	list1.remove_if(removeLen);
	for (auto&& value : list1) {
		cout << value << " ";
	}
	cout << endl;



	list<int> list2 {1,2,3,4,5,6,7,8,9};
	list2.remove_if(removeInt);
	for(auto&& value:list2) {
		cout<< value<<endl;
	}
	cout<<endl;
	
	return 0;
}

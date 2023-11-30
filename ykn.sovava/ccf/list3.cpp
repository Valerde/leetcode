#include <iostream>
#include <list>
using namespace std;
int main() {
	cout << "àË¿ÍÍø(www.haicoder.net)\n" << endl;
	list<int> list1 {1, 2, 3, 4}, list2 {10, 20, 30};
	list<int>::iterator it = ++list1.begin();
	list1.splice(it, list2);
	for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	for (auto iter = list2.begin(); iter != list2.end(); ++iter) {
		cout << *iter << " ";
	}
	list2.splice(list2.begin(), list1, it);
	for (auto iter = list2.begin(); iter != list2.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
		cout << *iter << " ";
	}
	return 0;
}

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
	forward_list<int> fl1 {1,2,4};
	forward_list<int>::iterator it = fl1.begin()++;
	it++;
	fl1.insert_after(it,3);
	printAll(fl1);
	cout<<"------"<<endl;

	forward_list<int> forward_list1 {1, 2, 3, 4}, forward_list2 {10, 20, 30};
	forward_list<int>::iterator it1 = ++forward_list1.begin();
	forward_list1.splice_after(it1, forward_list2);//��forward_list2���뵽���forward_list�Ժ�,��fl��������ݾͲ�����
	cout<<"1"<<endl;
	printAll(forward_list1);
	cout<<"2"<<endl;
	printAll(forward_list2);
	cout << endl;
	
	cout<<"isEmpty"<<forward_list2.empty()<<endl;
	return 0;
}

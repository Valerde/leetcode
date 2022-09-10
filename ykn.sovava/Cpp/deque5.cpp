#include<deque>
#include<iostream>
using namespace std;

int main() {
	deque<int> deq {1,2,3,4,5};

	deq.pop_back();
	for(deque<int>::iterator it = deq.begin(); it<deq.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<endl;

	deq.pop_front();
	for(deque<int>::iterator it = deq.begin(); it<deq.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<endl;

	deq.erase(deq.begin(),deq.begin()+2);
	for(deque<int>::iterator it = deq.begin(); it<deq.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<deq.size()<<endl;
	deq.clear();
	cout<<deq.size()<<endl;

	return 0;
}

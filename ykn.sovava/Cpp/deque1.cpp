#include<iostream>
#include<deque>
using namespace std;

int main() {
	deque<string> deq;

	deq.push_back("ykn");
	deq.push_back("hmx");

	for(auto i = deq.begin(); i<deq.end(); i++) {
		cout<<*i<<" ";
	}

	return 0;
}

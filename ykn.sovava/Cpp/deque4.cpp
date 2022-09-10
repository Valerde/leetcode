#include<iostream>
#include<deque>
using namespace std;

int main(){
	deque<int> deq{1,2,3,4,5};
	
	auto front = deq.front();
	cout<<front<<endl;
	auto back = deq.back();
	cout<<back<<endl;
	
	auto it = deq.begin();


	deq.push_back(6);
	deq.push_front(0);
	
	for(auto i = deq.begin();i<deq.end();i++){
		cout<<*i<<" ";
	}
	
	cout<<endl;
	
	deq.emplace_back(7);
	deq.emplace_front(-1);
	for(auto i = deq.begin();i<deq.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl;
	
	return 0;
} 

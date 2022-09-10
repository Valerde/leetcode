#include<deque>
#include<iostream>
using namespace std;
int main() {
	deque<int > deq{1,2,3,4,5};
	for(int i = 0;i<deq.size();i++){
		cout<<deq[i]<<" ";
	}
	cout<<deq[5]<<endl;
	for(int i = 0;i<deq.size();i++){
		cout<<deq.at(i)<<" ";
	}
	cout<<endl;
	//cout<<deq.at(5)<<endl;  使用at可以判断是否溢出 
	
	return 0;
}

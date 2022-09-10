#include<deque>
#include<iostream>
using namespace std;

int main() {
	deque<string > deq {"ykn","hmx","wyp","cjq"};

	auto first = deq.crbegin();
	
	auto last = deq.crend();
	
	while(first!=last){
		cout<<*first<<endl;
		first++;
	}
	
	return 0;
}

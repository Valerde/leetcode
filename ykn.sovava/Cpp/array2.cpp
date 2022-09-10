#include<iostream>
#include<array>
using namespace std;
int main(){
	array<int , 5> arr;
	int v = 1;
	
	auto first = arr.begin();
	auto last = arr.end();
	
	while(first!=last){
		*first = v++;
		first++;
	}
	
	first = arr.begin();
	
	while(first!=last){
		cout<<*first<<" ";
		first++;
	}
	
	cout<<"\n";
	return 0;
}

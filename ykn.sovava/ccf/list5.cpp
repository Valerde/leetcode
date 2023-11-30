#include<list>
#include<iostream>
#include<stdio.h>
using namespace std;
bool isEqual(double& a,double& b){
	return (int)a==(int)b;
}
int main() {
	list<int> list1 {1,1,2,3,3,4};

	list1.unique();
	for(auto&& value:list1) {
		cout<<value<<" ";
	}
	cout<<endl;
	
	list<double> list2{1.2,3.2,3.3,1.4,2.4,5.2,1.2,1.6};
	list2.unique(isEqual);
	for(auto&& value:list2){
		cout<<value<<" ";
	}
	return 0;
}

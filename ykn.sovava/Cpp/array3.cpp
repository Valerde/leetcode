#include<iostream>
#include<array>
using namespace std;

int main(){
	array<string , 5> arr{"Hello","World","I","am","ykn"};
	
	cout<<arr[1]<<endl;
	cout<<arr.at(2)<<endl;
	cout<<get<3>(arr)<<endl;
	cout<<*(arr.data()+4)<<endl;
	
	
	cout<<arr.size()<<endl;
	
	
	cout<<arr.empty()<<endl;
	
	array<int ,0> arr1;
	cout<<arr1.empty()<<endl;
	return 0;
} 

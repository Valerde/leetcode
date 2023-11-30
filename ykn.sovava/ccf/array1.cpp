#include<iostream>
#include<array>
using namespace std;

int main(){
	array<int ,10> arr;
	
	for(array<int,10>::iterator it = arr.begin();it<arr.end();it++){
		*it = 10;
	}
	for(int i = 0;i<10;i++){
		cout<<arr.at(i)<<endl;
	}
} 

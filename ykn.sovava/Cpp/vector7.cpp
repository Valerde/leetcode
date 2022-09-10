#include<vector>
#include<iostream>
using namespace std;

int main() {

	vector<int> vec {1,2,3,4,5};
	vec.insert(vec.begin() + 1,9);
	for(auto&& value : vec) {
		cout<<value<<" ";
	}

	cout<<endl;
	vec.insert(vec.end(),2,50);
	
	vec.emplace(vec.begin(),123); //emplace 速度更快 , 但只能一次插入一个元素 
	for(auto&& value : vec) {
		cout<<value<<" ";
	}

	cout<<endl;
	return 0;
}

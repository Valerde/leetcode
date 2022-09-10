#include<vector>
#include<iostream>

using namespace std;
int main(){
	vector<int> vec;
	
	vec.push_back(2);
	
	vec.emplace_back(3);
	
	for(auto i = vec.begin();i!=vec.end();i++){
		cout << *i <<endl; 
	}
	
	return 0;
} 

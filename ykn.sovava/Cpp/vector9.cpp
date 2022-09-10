#include<vector>
#include<iostream>
using namespace std;

int main() {
	vector<int > vec {1,2,3,4,5};

	for(auto i =vec.begin(); i<vec.end(); i++) {
		cout<<*i<<" ";
	}
	cout << endl;

	vec.pop_back();

	for(auto i = vec.begin(); i<vec.end(); i++) {
		cout<<*i<<" ";
	}
	cout<<endl;
	
	vec.erase(vec.begin()); 
	auto i =  vec.erase(vec.begin(), vec.begin()+2);//É¾³ý0µ½1µÄvector 
	cout<<"erase : "<< *i<<endl;
	
	for(auto i = vec.begin(); i<vec.end(); i++) {
		cout<<*i<<" ";
	}
	cout<<endl;
	
	cout<<vec.size()<<endl;
	vec.clear();
	cout<<vec.size();
	return 0;

}

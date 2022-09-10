#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void printAll(T& stl) {
	for(auto&& value:stl) {
		cout<<value<<" ";
	}
	cout<<endl;
}
class mycomp{
	public:
		bool operator()(int i , int j){
			return (i>j);
		}
};

int main(){
	int myints[5] = {0};
	vector<int> vec{11,22,10,100,23,89,1024};
	partial_sort_copy(vec.begin(),vec.begin()+5,myints,myints+5,greater<int>());
	printAll(vec);
	printAll(myints);
}

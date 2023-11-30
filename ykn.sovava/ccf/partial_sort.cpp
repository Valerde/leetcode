#include<algorithm>
#include <iostream>
#include<vector>
using namespace std;
template<typename T>
void printAll(T& stl) {
	for(auto&& value:stl) {
		cout<<value<<" ";
	}
	cout<<"\n";
}
class mycomp {
	public:
		bool operator()(int i,int j) {
			return (i<j);
		}
};
int main() {
	vector<int> vec {11,22,10,100,23,89,1024};
	partial_sort(vec.begin(),vec.begin()+4,vec.end());
	cout<<"第一次排序:"<<endl ;
	printAll(vec);
	partial_sort(vec.begin(),vec.begin()+4,vec.end(),greater<int>()) ;
	cout<<"第二次排序:"<<endl ;
	printAll(vec);
}

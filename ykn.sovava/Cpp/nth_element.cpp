#include<algorithm>
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
template<typename T>
void printAll(T& stl) {
	for(auto&& value:stl) {
		cout<<value<<" ";
	}
	cout<<endl;
}
class mycomp {
	public:
		bool operator()(int i , int j) {
			return (i>j);
		}
};

int main() {

	vector<int> vec {11,22,10,100,23,89,1024};


	nth_element(vec.begin(),vec.begin()+3,vec.end());
	printAll(vec);

	nth_element(vec.begin(),vec.begin()+4,vec.end());
	printAll(vec);
	cout<<*(vec.begin()+4)<<endl;


	cout <<"RAND_MAX:"<< RAND_MAX << endl;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10000; i++){
		vec.push_back(rand());
	}
	sort(vec.begin(),vec.end(),less<int>());
	//printAll(vec);
	nth_element(vec.begin(),vec.begin()+4399,vec.end());
	cout<<*(vec.begin()+4399)<<endl;
}

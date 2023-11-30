#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
template<typename T>
void printAll(T& stl) {
	for(vector<int>::iterator it = stl.begin(); it!=stl.end(); it++) {
		cout<< *it << " ";
	}
	cout<<endl;
}
bool mycomp(int i,int j) {
	return(i<j);
}

class mycomp2 {
	public:
		bool operator()(int i,int j) {
			return (i>j);
		}
};

int main() {
	vector<int> myvector {11,22,10,100,23,89,1024};
	sort(myvector.begin(),myvector.end());
	printAll(myvector);
	sort(myvector.begin(),myvector.begin()+4,greater<int>());
	printAll(myvector);
	sort(myvector.begin(),myvector.end(),mycomp2());
	printAll(myvector);

	stable_sort(myvector.begin(),myvector.end());
	printAll(myvector);

	return 0;
}

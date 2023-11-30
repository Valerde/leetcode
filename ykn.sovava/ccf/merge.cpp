#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void printAll(T& vec) {
	for(auto&& value:vec) {
		cout<<value<<" ";
	}
	cout<<"\n";
}
int main() {
	vector<int> vec1 {1,3,2,7,8,4};
	vector<int> vec2 {4,5,1,3,2,5};
	sort(vec1.begin(),vec1.end(),greater<int>());
	sort(vec2.begin(),vec2.end(),greater<int>());
	cout<<"vec1 : ";
	printAll(vec1);
	cout<<"vec2 : ";
	printAll(vec2);

	vector<int> vec3(12);
	merge(vec1.begin(),vec1.end(),vec2.begin(),vec2.end(),vec3.begin(),greater<int>());
	cout<<"vec3 : ";
	printAll(vec3);


	int first[] = { 5,10,15,20,25 };
	int second[] = { 7,17,27,37,47,57 };
	vector<int> myvector(11);
	merge(first, first + 5, second, second + 6, myvector.begin());
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

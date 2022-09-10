#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
class comp {
	public:
		bool operator()(const int& i) {
			return ((i%2)==1);
		}
};
int main() {
	vector<int> vec {99,100,101,102};
	vector<int>::iterator it = find_if(vec.begin(),vec.end(),comp());
	cout<<*it<<endl;


	//find_if_not
	vector<int> myvector {99, 101, 200, 206, 301};
	vector<int>::iterator it1 = find_if_not(myvector.begin(), myvector.end(), comp());
	cout << "*it = " << *it1;
	cout << endl;
}

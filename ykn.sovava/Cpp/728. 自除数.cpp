
#include<bits/stdc++.h>
using namespace std;
bool isselfDN(int n) {
	int temp = n;

	while(temp>0) {
		int num = temp%10;
		
		if(num==0||n%num!=0)
			return false;
		temp/=10;
	}
	return true;

}

vector<int> selfDividingNumbers(int left, int right) {

	vector<int> res;
	for(int i = left; i<=right; i++) {
		if(isselfDN(i)) {
			//cout<<"--"<<i<<endl;
			res.push_back(i);
		}
	}

	return res;


}


int main() {


	int left = 1,right = 22;
	vector<int> res = selfDividingNumbers(left,right);

	for(auto&& s:res) {
		cout<<s<<" ";
	}

}

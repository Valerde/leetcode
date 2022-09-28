#include<bits/stdc++.h>
using namespace std;

long long smallestNumber(long long num) {
	if(num ==0)return 0;
	vector<int> v;
	bool flag = false;
	if(num<0) {
		flag = true;
		num = -num;
	}
	int zero = 0;
	while(num>0) {
		if(num%10==0) {
			zero++;
		} else {

			v.push_back(num%10);
		}
		num /=10;
	}


	sort(v.begin(),v.end());//ÉýÐò
	long long res = 1;
	if(!flag) {
		//auto it1 = v.begin();

		res*=*(v.begin());
		for(int i = 0; i<zero; i++)res*=10;
		for(auto it1 = ++v.begin(); it1<v.end(); it1++) {
			res*=10;
			res+=*it1;
		}
	} else {
		res*=*(v.rbegin());
		for(auto it1 = ++v.rbegin(); it1<v.rend(); it1++) {
			res*=10;
			res+=*it1;
		}
		for(int i = 0; i<zero; i++)res*=10;
		res = -res;
	}


	return res;
}

int main() {
	cout<<smallestNumber(-52003451);
}

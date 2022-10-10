#include<bits/stdc++.h>
using namespace std;

bool isMagic(vector<short>& target) {
	vector<short> N;
	short n = target.size();
	for(short i = 2; i<=n; i+=2)	 N.push_back(i);
	for(short i = 1; i<=target.size(); i+=2) N.push_back(i);
	short k = 0,i = 0;
	for(; i<N.size(); i++) {
		if(N[i] == target[i]) k++;
		else break;
	}//i--;
	
	//cout<<k<<endl;
	if(k == 0) return false;
	vector<short> b(N.begin()+k,N.end());
	//cout<<b[0]<<endl;
	while(i<target.size()) {

		vector<short> temp;
		for(short j = 1; j<b.size(); j+=2) temp.push_back(b[j]);
		for(short j = 0; j<b.size(); j+=2) temp.push_back(b[j]);

		b.clear();

		for(short j = 0; j< temp.size(); j++) {
			if(j<k) {
				if(target[i]!=temp[j]) {

					return false;
					
				}i++;
			} else b.push_back(temp[j]);


		}
		temp.clear();
	}
	return true;
}

int main() {

	vector<short> target {2,4,3,1,5};
	cout<<isMagic(target);
}

#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
	if(fruits.size()==1) return 1;
	int idx = -1;

	int fir = 0, sec = 0;

	int kind1 = -1,kind2 = -1;

	int res = 0;
	kind1 = fruits[0];
	for(sec = 1; sec<fruits.size(); sec++) {
		if(fruits[sec]!=fruits[sec-1]) idx = sec;
		if(fruits[sec]!=kind1) {
			kind2 = fruits[sec];
			break;
		}
	}
	idx = sec;
	//cout<<"kind1"<<kind1<<"kind2"<<kind2<<endl;
	res = max(res,sec-fir);
	//sec++;
	while(sec<fruits.size()) {

		if(fruits[sec]!=kind1&&fruits[sec]!=kind2) {
			res = max(res,sec-fir);
			kind1 = fruits[idx];
			kind2 = fruits[sec];
			fir = idx;
		}
		if(fruits[sec]!=fruits[sec-1]) idx = sec;
		sec++;
		//cout<<"kind1"<<kind1<<"kind2"<<kind2<<endl;
	}
	res = max(res,sec-fir);
	return res;
}

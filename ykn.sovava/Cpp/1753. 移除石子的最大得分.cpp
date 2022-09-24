#include<bits/stdc++.h>
using namespace std;
int maximumScore(int a, int b, int c) {
	int an[3] = {a,b,c};
	sort(an,an+3);
	if(an[0]+an[1]>an[2]) return (an[0]+an[1]-an[2])/2+an[2];
	return an[2];
}

int main() {
cout<<maximumScore(1,8,8); 
}
